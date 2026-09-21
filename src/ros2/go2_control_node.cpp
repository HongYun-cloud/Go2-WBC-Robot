#include "ros2/go2_control_node.hpp"

#include <yaml-cpp/yaml.h>

// ============================================================
// 构造 / 析构
// ============================================================
namespace go2{

Go2ControlNode::Go2ControlNode() : rclcpp::Node("go2_control_node")
{
    // ===== ROS 2 参数声明 (config/go2_params.yaml) =====
    declare_parameter<std::string>("mujoco_model", "go2/scene.xml");
    declare_parameter<std::string>("urdf_path",    "go2/go2_description.urdf");
    declare_parameter<std::string>("control_config", "config/control.yaml");
    declare_parameter<std::string>("initial_gait", "TROT");
    declare_parameter<double>("control_frequency", 500.0);   // WBC 主循环 (须 == 1/mujoco timestep)
    declare_parameter<double>("mpc_frequency",     100.0);   // MPC 异步线程
    declare_parameter<double>("publish_frequency", 50.0);    // 状态发布
    declare_parameter<double>("desired_height",    0.25);    // MPC 期望机身高度
    declare_parameter<double>("max_cmd_vel",       0.05);    // /cmd_vel 限幅 (原键盘 0.05)
    // 触地检测 (摆动→支撑不再纯按相位): 足端法向力 > touchdown_force 才算落地
    declare_parameter<double>("touchdown_force",     5.0);
    declare_parameter<double>("airborne_hold_ratio", 0.5);   // 悬空强制下压上限 = ratio * T_stance

    initControlStack();
    startTimersAndThreads();
}

Go2ControlNode::~Go2ControlNode()
{
    // 停 MPC 线程 (在销毁任何控制对象之前)
    mpc_running_ = false;
    if (mpc_thread_.joinable())
        mpc_thread_.join();

    // 成员按声明逆序析构: mpc → wbc → pin → mj → fsm → trajectory → estimator → scheduler
    // MPC 析构会 delete estimator 裸指针 (原代码行为, 不可修改):
    //   estimator 堆分配 (见 initControlStack), 且声明在 mpc 之后 → MPC 先死,
    //   delete 合法, 此后无人再碰 estimator → 不 double-free
    delete mpc;
    delete wbc;
    delete pin;
    delete mj;
    mpc = nullptr; wbc = nullptr; pin = nullptr; mj = nullptr;
}

// ============================================================
// 初始化段: 对应原 main() 的对象创建与首帧初始化, 顺序原样
// ============================================================

void Go2ControlNode::initControlStack()
{
    scheduler  = std::make_shared<Gait::GaitScheduler>();
    // 注意: 堆分配。MPC 析构会 delete 这个指针 (原代码行为), 不能用 make_shared
    estimator  = std::shared_ptr<Estimator::PositionVelocityEstimator>(
        new Estimator::PositionVelocityEstimator());
    trajectory = std::make_shared<SwingPlanner::SwingLegPlanner>(scheduler, estimator);

    fsm = std::make_unique<fsm::ControlFSM>(scheduler, trajectory);
    // 触地检测参数: 足端力阈值与悬空下压时长上限 (config/go2_params.yaml)
    fsm->setContactDetect(get_parameter("touchdown_force").as_double(),
                          get_parameter("airborne_hold_ratio").as_double());

    // 路径参数: 相对路径基于运行目录 (与原 ../go2/... 行为一致, 从 build/ 运行)
    std::string xml       = get_parameter("mujoco_model").as_string();
    std::string urdf_path = get_parameter("urdf_path").as_string();
    std::string ctrl_yaml = get_parameter("control_config").as_string();

    mj  = new MJCSIM::SIM(xml);
    pin = new Pinocchio::PinocchioKinematics(urdf_path);
    mpc = new Regulator::MPC(estimator.get());
    wbc = new WBC::WBC(estimator.get());

    // 足端顺序FL,FR,RL,RR
    // ===== 通过地址连接 Pinocchio 足端数据到 MPCData =====
    mpc->setLegData(pin->getLegData());

    // ===== 任务空间 PD 增益 (TaskPD 段) =====
    // 必须在首个控制拍之前加载; 失败时保留成员默认值, 不中断启动
    loadTaskPdConfig(ctrl_yaml);

    // ===== WBC 初始化 =====
    wbc->setPinocchio(pin);
    wbc->loadConfig(ctrl_yaml);

    mj->InitMujoco();
    // mj->SimStart();
    // mj->InitViewer();

    q.setZero(); p.setZero();
    v.setZero(); w.setZero();
    p[2] = get_parameter("desired_height").as_double();
    mpc->update_DesireStateCommand(q, p, v, w);
    mpc->loadConfig(ctrl_yaml);
    mpc->update_reference_trajectory();

    // WBC 初始化必须先于首次 update (WBC.cpp 的 @warning):
    // init() 里才设 A_q/A_f 的单位块, 顺序反了会让首帧的 H1/H2 全为零
    wbc->init();

    // WBC 首次 update (设置 cmd 并初始化固定矩阵)
    {
        auto state = mj->getState();
        estimator->update(state);
        pin->setJointVelocity(state.joint_velocities);
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(state.joint_positions, state.position, state.quat.coeffs());
        trajectory->SetFootPositions(pin->getAllFootPositions());  // 用 FK 真值初始化足端位置, 避免默认 -0.25 污染首拍摆动

        mpc->update();
        mpc->solve();
        auto f_mpc = mpc->getControl();
        // 首帧快照, WBC 首拍即有有效 MPC 力
        f_mpc_buf_ = std::make_shared<FmpcSnapshot>(FmpcSnapshot{f_mpc, true});

        Eigen::Matrix<double, 18, 1> q_des = Eigen::Matrix<double, 18, 1>::Zero();
        Eigen::Matrix<double, 12, 1> a_des = Eigen::Matrix<double, 12, 1>::Zero();
        wbc->update(q_des, f_mpc, a_des, state);
    }

    // ===== MPC 模型参数: 用 URDF 真值替换硬编码 =====
    // 之前 m=12kg, I=(0.1,0.1,0.02) 是瞎猜的, I_zz 比真值小 ~20 倍 →
    // 模型以为 yaw 极容易控制, 几乎不输出侧向力差 → 真实 yaw/roll 扰动得不到纠正 → 漂移后倒向固定一侧
    {
        double m_total = 0.0;
        Eigen::Matrix3d I_com = Eigen::Matrix3d::Zero();
        pin->getTotalMassInertia(m_total, I_com);
        mpc->setModelParams(m_total, I_com.diagonal().asDiagonal());  // 简化模型: 机身系对角惯性
        std::cout << "[MPC] mass=" << m_total << " kg, I diag=" << I_com.diagonal().transpose() << std::endl;
    }

    // 初始步态: 参数选择 (原为 TROT 硬编码)
    {
        std::string gait = get_parameter("initial_gait").as_string();
        Gait::GaitType type = Gait::GaitType::TROT;
        if      (gait == "STAND") type = Gait::GaitType::STAND;
        else if (gait == "WALK")  type = Gait::GaitType::WALK;
        gait_type_ = type;
        fsm->SetCmd(gait_type_, v);
    }
    fsm->SetState(fsm::FSM_State::GAIT_RUNNING);

    // 控制步长必须等于 MuJoCo 物理步长 (InitMujoco 里设为 0.002)
    // 步态时钟与物理时间失配会造成摆动相时长错误 + 前馈错误 → 步高偏低
    sim_dt = mj->getTimestep();
    const double ctrl_freq = get_parameter("control_frequency").as_double();
    if (std::abs(ctrl_freq - 1.0 / sim_dt) > 1.0) {
        RCLCPP_WARN(get_logger(),
            "control_frequency(%.1f) != 1/timestep(%.1f), 以 1/timestep 为准",
            ctrl_freq, 1.0 / sim_dt);
    }
}

void Go2ControlNode::startTimersAndThreads()
{
    // ===== Publisher / Subscriber =====
    odom_pub_         = create_publisher<nav_msgs::msg::Odometry>("odom", 10);
    joint_state_pub_  = create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    foot_force_pub_   = create_publisher<std_msgs::msg::Float64MultiArray>("foot_forces", 10);
    cmd_sub_          = create_subscription<geometry_msgs::msg::Twist>(
        "cmd_vel", 10,
        std::bind(&Go2ControlNode::cmdVelCallback, this, std::placeholders::_1));
    
    // ===== Telemetry Publisher =====
    telemetry_pub_ = create_publisher<go2_robot::msg::Go2Telemetry>("go2_telemetry", 10);

    // ===== 主控制循环: 500Hz wall timer (executor 主线程, GLFW Render 需在此线程) =====
    double ctrl_period = sim_dt;   // 严格 = 物理步长
    wbc_timer_ = create_wall_timer(
        std::chrono::duration<double>(ctrl_period),
        std::bind(&Go2ControlNode::wbcControlLoop, this));

    // ===== MPC 异步线程: 100Hz =====
    double mpc_period = 1.0 / get_parameter("mpc_frequency").as_double();
    mpc_running_ = true;
    mpc_thread_ = std::thread([this, mpc_period]() { mpcSolveLoop(); });
    (void)mpc_period;  // 循环内部使用

    // ===== 状态发布: 50Hz (序列化不在实时循环) =====
    double pub_period = 1.0 / get_parameter("publish_frequency").as_double();
    pub_timer_ = create_wall_timer(
        std::chrono::duration<double>(pub_period),
        std::bind(&Go2ControlNode::publishState, this));

    RCLCPP_INFO(get_logger(),
        "Go2 node up: WBC %.0f Hz (sim_dt=%.4f), MPC %.0f Hz (thread), pub %.0f Hz",
        1.0 / ctrl_period, sim_dt,
        get_parameter("mpc_frequency").as_double(),
        get_parameter("publish_frequency").as_double());
}

// ============================================================
// MPC 异步线程 (100Hz): mpc->update + solve → 双缓冲
// ============================================================

void Go2ControlNode::mpcSolveLoop()
{
    const double mpc_period = 1.0 / get_parameter("mpc_frequency").as_double();

    while (rclcpp::ok() && mpc_running_.load()) {
        auto t0 = std::chrono::steady_clock::now();

        // ---- update: 读共享数据 (estimator + legData 裸指针), 与 WBC 写方互斥 ----
        {
            // 锁顺序 (全程序统一): estimator_mutex_ → fk_mpc_mutex_, 无死锁
            std::lock_guard<std::mutex> lk_est(estimator_mutex_);
            std::lock_guard<std::mutex> lk_fk(fk_mpc_mutex_);
            // MPC::update 内部: get_estresult() + ConfigUpdata(读 legData 指针) +
            // compuseEGH(矩阵指数, ~ms 级) → 整段持锁是保守但正确的做法
            mpc->update();
        }

        // ---- solve: 只碰 OSQP 内部状态和自己刚拷贝的数据 → 无锁 ----
        mpc->solve();

        // ---- 交换: 12 个 double 的不可变快照, 原子换指针 ----
        {
            auto snap = std::make_shared<FmpcSnapshot>();
            snap->f = mpc->getControl();
            snap->valid = true;
            std::lock_guard<std::mutex> lk(f_mpc_mutex_);
            f_mpc_buf_ = std::move(snap);   // WBC 循环持 shared_ptr, 旧快照延迟释放
        }

        std::this_thread::sleep_until(t0 + std::chrono::duration<double>(mpc_period));
    }
}

// ============================================================
// WBC 主控制循环 (500Hz): 原 while(1) 体, 算法逻辑零修改
// ============================================================

void Go2ControlNode::wbcControlLoop()
{   
    // for (int leg = 0; leg<4; leg++)
    //     std::cout << "Footposition:" << leg << pin->getFootPositionInBase(leg) << std::endl;
    
    // ===== 指令来源: /cmd_vel 替代原键盘 w/s =====
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        mpc->update_DesireStateCommand(q, p, v, w);
        // 每拍刷新步态速度指令: 否则 Gait_cmd.v 恒为初始化那一刻的值,
        // 摆动规划器只会原地踏步, /cmd_vel 推不动步幅
        // (FSM::run 内有 _last_gait_type 守卫, 重复 SetCmd 不会重置步态相位)
        fsm->SetCmd(gait_type_, v);
    }

    count++;
    // 先取状态: getState() 只读 d->qpos/qvel/contact, 无副作用, 提到 fsm->run 之前
    // 是为了让触地判定用上本拍实测的足端力 (放在后面就只能用上一拍的)
    auto state = mj->getState();

    // ===== 接触判定: 计划相位 + 实测足端力 混合 =====
    // 计划摆动 → 摆动 (相位说了算: 静止时四足全着地, 纯用实测会让摆动任务永不触发,
    //   脚不抬就永远"支撑" → 死锁, 这层相位判据必须保留);
    // 计划支撑 → 必须实测足端力过阈值才算支撑, 没落地就继续当摆动下压。
    // 原来纯按相位划分: 足端没落地就被当支撑, 该腿立刻失去足端跟踪 (WBC 支撑腿不建
    //   摆动任务) → 悬在空中越抬越高, 同时支撑腿过载 → 机身下沉 (关节发软)
    // 结果给 estimator / MPC / PD / WBC 统一使用 (stance / eff_phase / hold)
    fsm->run(sim_dt, state.foot_forces);
    const auto& leg_contact = fsm->GetLegContact();
    for (int leg = 0; leg < 4; leg++)
        state.contact_states[leg] = leg_contact[leg].stance;

    // ===== 估计器 + FK: 写共享数据, 与 MPC 线程互斥 =====
    {
        std::lock_guard<std::mutex> lk_est(estimator_mutex_);
        estimator->update(state);
    }
    {
        // forwardKinematics 内部 _syncLegData 写 leg_data_ (MPC 经裸指针读) → 持锁
        std::lock_guard<std::mutex> lk_fk(fk_mpc_mutex_);
        pin->setJointVelocity(state.joint_velocities);
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(state.joint_positions, state.position, state.quat.coeffs());
    }
    trajectory->SetFootPositions(pin->getAllFootPositions());  // FK 足端位置反馈给摆动轨迹规划器

    // ===== MPC 期望力: 取最新快照 (异步, 上一拍解, 100Hz 时龄期 ≤ 10ms) =====
    std::shared_ptr<const FmpcSnapshot> snap;
    {
        std::lock_guard<std::mutex> lk(f_mpc_mutex_);
        snap = f_mpc_buf_;
    }
    Eigen::Matrix<double, 12, 1> f_mpc = snap->valid ? snap->f
                                                     : Eigen::Matrix<double, 12, 1>::Zero();

    // MPC 接触预测也交给 MPC 线程读取 → setContactSchedule 只写 mpc 内部缓存,
    // 与 mpc->update 并发会踩 contact_sched_ → 放进 fk 锁内最安全, 但那是 WBC 持锁段;
    // 实际写方唯一 (WBC 线程), 读方在 mpc->update (持 fk 锁) → 在此处不持锁写有竞争,
    // 改为写进快照逻辑不现实; 直接在 fk 锁内写 (见上段扩为下方)
    // ===== 接触预测: 按步态相位滚动到预测时域 =====
    {
        std::lock_guard<std::mutex> lk_fk(fk_mpc_mutex_);
        mpc->setContactSchedule(scheduler->GetContactSchedule(mpc->getDt(), mpc->getHorizonN()));
    }

    // // WBC: QP 求解一致的加速度和力
    // 基座 PD 处理后的期望加速度 (前馈暂传零 → 纯 PD 调节), 作为 WBC 第一代价项 q_d
    Eigen::Matrix<double, 18, 1> q_des = computePoseAccDes(state,true);
    // q_des = Eigen::Matrix<double, 18, 1>::Zero();
    double T_swing = scheduler->GetSwingTime();
    if (T_swing < 1e-3) T_swing = 1e-3;  // STAND 时 duty=1 → T_swing=0, 防除零

    Eigen::Matrix<double, 4, 3> p_ref = trajectory->GetSwingPos();
    Eigen::Matrix<double, 4, 3> v_ref = trajectory->GetSwingVel() / T_swing;   // 相位速度 → 时间速度 (m/s)
    Eigen::Matrix<double, 4, 3> p_act = pin->getAllFootPositions();

    // static int count = 0;

    // count++;

    // if (count % 100 == 0) {
    //     std::cout << "p_act:\n" << p_act << std::endl;
    // }

    // 足端实际速度: J_floating × v_full (与 WBC 摆动任务同坐标系)
    Eigen::Matrix<double, 18, 1> v_full;
    v_full << state.linear_vel, state.angular_vel, state.joint_velocities;
    Eigen::Matrix<double, 12, 1> v_foot_act;
    for (int leg = 0; leg < 4; leg++)
        v_foot_act.segment<3>(leg * 3) = pin->getFootJacobianFloatingBase(leg) * v_full;

    // ===== 足端实际加速度 (世界系): v_foot_act 数值微分 =====
    if (have_prev_v)
        a_foot_act = (v_foot_act - v_foot_prev) / sim_dt;
    v_foot_prev = v_foot_act;
    have_prev_v = true;

    Eigen::Matrix<double, 12, 1> a_des = computeFootAccDes(state,true);
    // std::cout << "a_des_z: " << a_des[2] << std::endl;
    wbc->update(q_des, f_mpc, a_des, state);
    wbc->solve();

    WBC::SolutionVector sol;
    WBC::SolForce f_wbc;
    WBC::SolAcc q_a_wbc;
    wbc->GetSolution(sol);
    wbc->GetForce(f_wbc);
    wbc->GetAcc(q_a_wbc);
    Eigen::Matrix<double, 18, 1> test_a = Eigen::Matrix<double, 18, 1>::Zero();
    // 关节力矩: τ = M·a + h − Jᵀf (WBC 逆动力学, 已包含 a_des 跟踪)
    auto tau = pin->getJointTorquesFromSolution(q_a_wbc, f_wbc);
    // auto tau = pin->getJointTorquesFromSolution(test_a, f_wbc);
    // tau.setZero();
    mj->control(tau);
    mj->Step();
    mj->Render();

    // ===== 发布消息缓存 (pub_timer_ 线程序列化) =====
    {
        std::lock_guard<std::mutex> lk(state_msg_mutex_);
        odom_msg_.header.stamp = this->now();
        odom_msg_.header.frame_id = "odom";
        odom_msg_.pose.pose.position.x = state.position(0);
        odom_msg_.pose.pose.position.y = state.position(1);
        odom_msg_.pose.pose.position.z = state.position(2);
        odom_msg_.pose.pose.orientation.x = state.quat.x();
        odom_msg_.pose.pose.orientation.y = state.quat.y();
        odom_msg_.pose.pose.orientation.z = state.quat.z();
        odom_msg_.pose.pose.orientation.w = state.quat.w();
        odom_msg_.twist.twist.linear.x = state.linear_vel(0);
        odom_msg_.twist.twist.linear.y = state.linear_vel(1);
        odom_msg_.twist.twist.linear.z = state.linear_vel(2);
        odom_msg_.twist.twist.angular.x = state.angular_vel(0);
        odom_msg_.twist.twist.angular.y = state.angular_vel(1);
        odom_msg_.twist.twist.angular.z = state.angular_vel(2);


        if (joint_msg_.name.empty()) {
            joint_msg_.name = {"FL_hip", "FL_thigh", "FL_calf",
                               "FR_hip", "FR_thigh", "FR_calf",
                               "RL_hip", "RL_thigh", "RL_calf",
                               "RR_hip", "RR_thigh", "RR_calf"};
            joint_msg_.position.resize(12);
            joint_msg_.velocity.resize(12);
        }
        joint_msg_.header.stamp = this->now();
        for (int i = 0; i < 12; i++) {
            joint_msg_.position[i] = state.joint_positions(i);
            joint_msg_.velocity[i] = state.joint_velocities(i);
        }

        if (force_msg_.data.size() != 12) force_msg_.data.resize(12);
        for (int i = 0; i < 12; i++) force_msg_.data[i] = f_wbc(i);
    }

    // ===== Telemetry 缓存: 500Hz 纯内存拷贝, publishState (50Hz) 发布 =====
    // a_wbc_ang = WBC QP 解出的基座角加速度 (机体系), 与 q_des_ang 对比验证 PD 是否被执行
    fillTelemetryMessage(p_ref, p_act, v_ref, v_foot_act, a_des, f_mpc, f_wbc, q_des,
                         tau, sol.segment<3>(3), state);
}

// ============================================================
// config/control.yaml → TaskPD 段 → pd_
// 这两组增益直接进 WBC 的期望加速度, 不属于 MPC/WBC 对象的配置,
// 所以在节点层单独读, 不走 MPC::loadConfig / WBC::loadConfig
// ============================================================

namespace {
// 注意 yaml-cpp 的坑: 对 const Node 取不存在的 key, 拿到的是 "zombie" 节点
// (m_isValid=false), 对它调 IsMap()/IsSequence()/Type() 会抛 YAML::InvalidNode
// 而不是返回 false → 任何类型查询之前必须先 IsDefined() 短路, 否则 yaml 里
// 少写一个 key 就会让节点在启动阶段直接 abort
bool isMap(const YAML::Node& n)       { return n.IsDefined() && n.IsMap(); }
bool isSeq3(const YAML::Node& n)      { return n.IsDefined() && n.IsSequence() && n.size() == 3; }

// 从父 map 中读 key 对应的 3 维序列; 没读到返回 false (out 保持原值)
bool readVec3(const YAML::Node& parent, const char* key, Eigen::Vector3d& out)
{
    if (!isMap(parent)) return false;
    const YAML::Node n = parent[key];
    if (!isSeq3(n)) return false;
    // 先读到局部量: 三个元素全转成功才写回 out, 避免中途抛异常把 out 写成半截值
    Eigen::Vector3d v;
    try {
        v << n[0].as<double>(), n[1].as<double>(), n[2].as<double>();
    } catch (const std::exception&) {
        return false;   // 元素不是数 (写成字符串等) → 当作没读到, out 保持原值
    }
    out = v;
    return true;
}
}  // namespace

void Go2ControlNode::loadTaskPdConfig(const std::string& yaml_path)
{
    YAML::Node root;
    try {
        root = YAML::LoadFile(yaml_path);
    } catch (const std::exception& e) {
        RCLCPP_WARN(get_logger(), "TaskPD: 读取 %s 失败 (%s), 全部使用代码默认增益",
                    yaml_path.c_str(), e.what());
        return;
    }
    // 转成 const 再索引: 非 const 的 operator[] 遇到缺失的 key 会自动创建节点,
    // const 版只返回 zombie, 交给下面的 IsDefined 判空
    const YAML::Node croot = root;
    const YAML::Node pd    = croot["TaskPD"];

    int miss = 0;
    try {
        if (!isMap(pd)) {
            RCLCPP_WARN(get_logger(), "TaskPD: %s 缺少 TaskPD 段, 全部使用代码默认增益",
                        yaml_path.c_str());
            return;
        }
        const YAML::Node pose   = pd["pose"];
        const YAML::Node swing  = pd["swing"];
        const YAML::Node stance = pd["stance"];

        // 逐项读取, 缺项保留默认值 (成员默认值 == 原先写死的数)
        miss += !readVec3(pose,   "Kp_lin", pd_.pose_Kp_lin);
        miss += !readVec3(pose,   "Kd_lin", pd_.pose_Kd_lin);
        miss += !readVec3(pose,   "Kp_ang", pd_.pose_Kp_ang);
        miss += !readVec3(pose,   "Kd_ang", pd_.pose_Kd_ang);
        miss += !readVec3(swing,  "Kp",     pd_.swing_Kp);
        miss += !readVec3(swing,  "Kd",     pd_.swing_Kd);
        miss += !readVec3(stance, "Kp",     pd_.stance_Kp);
        miss += !readVec3(stance, "Kd",     pd_.stance_Kd);
    } catch (const std::exception& e) {
        // 兜底: 参数文件再怪也不该让 500Hz 控制节点起不来
        RCLCPP_WARN(get_logger(), "TaskPD: 解析 %s 出错 (%s), 未读到的项用代码默认值",
                    yaml_path.c_str(), e.what());
    }

    if (miss > 0)
        RCLCPP_WARN(get_logger(),
                    "TaskPD: %d/8 项未读到 (缺项或不是 3 维), 这些项沿用代码默认值", miss);

    RCLCPP_INFO(get_logger(),
                "TaskPD: pose Kp_lin=[%.1f %.1f %.1f] Kd_lin=[%.1f %.1f %.1f] "
                "Kp_ang=[%.1f %.1f %.1f] Kd_ang=[%.1f %.1f %.1f]",
                pd_.pose_Kp_lin.x(), pd_.pose_Kp_lin.y(), pd_.pose_Kp_lin.z(),
                pd_.pose_Kd_lin.x(), pd_.pose_Kd_lin.y(), pd_.pose_Kd_lin.z(),
                pd_.pose_Kp_ang.x(), pd_.pose_Kp_ang.y(), pd_.pose_Kp_ang.z(),
                pd_.pose_Kd_ang.x(), pd_.pose_Kd_ang.y(), pd_.pose_Kd_ang.z());
    RCLCPP_INFO(get_logger(), "TaskPD: swing Kp=[%.1f %.1f %.1f] Kd=[%.1f %.1f %.1f]",
                pd_.swing_Kp.x(), pd_.swing_Kp.y(), pd_.swing_Kp.z(),
                pd_.swing_Kd.x(), pd_.swing_Kd.y(), pd_.swing_Kd.z());
    RCLCPP_INFO(get_logger(), "TaskPD: stance Kp=[%.1f %.1f %.1f] Kd=[%.1f %.1f %.1f]",
                pd_.stance_Kp.x(), pd_.stance_Kp.y(), pd_.stance_Kp.z(),
                pd_.stance_Kd.x(), pd_.stance_Kd.y(), pd_.stance_Kd.z());
}

// ============================================================
// 基座加速度层 PD: 输出作为 WBC 第一代价项的期望加速度 q_d
// 18 维顺序与 WBC 全状态一致: [基座线加速度3; 角加速度3; 关节加速度12]
// ============================================================

Eigen::Matrix<double, 18, 1> Go2ControlNode::computePoseAccDes(
    const RobotState& state, bool pd_open)
{

    Eigen::Vector3d a_lin;
    Eigen::Vector3d a_ang;
    Eigen::Matrix<double,12,1> a_joint_des;
    a_lin = Eigen::Vector3d::Zero();
    a_ang = Eigen::Vector3d::Zero();
    // 必须显式置零: Eigen 定长矩阵不初始化, 漏了这句 a_out.tail(12) 就是栈上垃圾,
    // 而 WBC 的 H1 会让 QP 去跟踪它 → 支撑腿关节被要求跟踪随机加速度 (关节发软)
    a_joint_des.setZero();
    if (pd_open) {
        // 期望值: 节点成员 q/p/v/w (调试期手动设置, 与 MPC DesireCMD 同源)
        // 实际值: 估计器 p, v, q(世界系roll-pitch-yaw), w
        auto est = estimator->get_estresult();
        Eigen::Vector3d p_des, v_des, rpy_des, w_des;
        {
            std::lock_guard<std::mutex> lk(cmd_mutex_);
            p_des = p; v_des = v; rpy_des = q; w_des = w;
        }

        // 线加速度: 位置 PD 取 y/z 轴, x 轴不用 (x 做位置 PD 会把行走中的机身拉回原点)。
        // y 要做: 侧移指令 v[1] 恒为 0, 机身横向就该守在 p_des.y()=0 —— 不锁 y 时
        // 横向只剩速度阻尼 (Kd_lin.y), 它压得住速度但压不住常值侧向力偏置, 于是机身
        // 只能匀速平移出去 ("机身向左平移, hip 关节被别弯"), 直到重心出支撑多边形侧翻。
        // 增益来自 control.yaml 的 TaskPD.pose; Kp_lin.y = 0 即退回改动前 (只做 z)
        Eigen::Vector3d e_p(0.0, p_des.y() - est.p.y(), p_des.z() - est.p.z());
        Eigen::Vector3d e_v = v_des - est.v;
        a_lin = pd_.pose_Kp_lin.cwiseProduct(e_p) + pd_.pose_Kd_lin.cwiseProduct(e_v);

        // 目标姿态都是世界系
        Eigen::Matrix3d R_des = (Eigen::AngleAxisd(rpy_des(2), Eigen::Vector3d::UnitZ()) *
                         Eigen::AngleAxisd(rpy_des(1), Eigen::Vector3d::UnitY()) *
                         Eigen::AngleAxisd(rpy_des(0), Eigen::Vector3d::UnitX())).toRotationMatrix();

        Eigen::Matrix3d R_cur = (Eigen::AngleAxisd(est.q(2), Eigen::Vector3d::UnitZ()) *
                         Eigen::AngleAxisd(est.q(1), Eigen::Vector3d::UnitY()) *
                         Eigen::AngleAxisd(est.q(0), Eigen::Vector3d::UnitX())).toRotationMatrix();    
        Eigen::Matrix3d R_err = R_cur.transpose() * R_des;
        Eigen::Vector3d e_rpy;
        e_rpy << 0.5 * (R_err(2, 1) - R_err(1, 2)),  // 机身系 Roll 轴需要扭多少度
                0.5 * (R_err(0, 2) - R_err(2, 0)),  // 机身系 Pitch 轴需要抬头多少度
                0.5 * (R_err(1, 0) - R_err(0, 1));  // 机身系 Yaw 轴需要转多少度   
                
        Eigen::Vector3d e_w = w_des - est.w;

        Eigen::Vector3d a_ang_ref;
        a_ang_ref.setZero();
        a_ang = -a_ang;
        // 这里不再取负: 原先的 a_ang = -a_ang 是给 getFootJacobianFloatingBase
        // 角速度块符号写反 (Σ(r×f) 变成 -Σ(r×f)) 打的补丁, 那个根因已修
        // 增益来自 control.yaml 的 TaskPD.pose
        a_ang = a_ang_ref + pd_.pose_Kp_ang.cwiseProduct(e_rpy) + pd_.pose_Kd_ang.cwiseProduct(e_w);
    }

    // 关节加速度: 暂无期望关节位置/速度参考 → 前馈直通。
    // 后续接入期望关节轨迹后在此加: Kp_j·(qj_des − qj_act) + Kd_j·(qd_des − qd_act)
    Eigen::Matrix<double, 18, 1> a_out;
    a_out << a_lin, a_ang, a_joint_des;
    return a_out;
}

// ============================================================
// 加速度层足端阻抗: 摆动腿跟踪摆动轨迹, 支撑腿以落地点为参考保持不动
//
// 为什么支撑腿需要这一项: WBC 的决策变量是加速度, 任何代价项最多只能说
// "我希望这个加速度是多少", 说不出"hip 现在角度不对"。位置误差只能从两个口子进:
// 基底 PD (computePoseAccDes) 与足端阻抗 (本函数)。支撑腿原先两个都没有 ——
// 在 WBC 里它只有 no-slip **等式** J·a = −dJ·v, 约束的是加速度, 对位置是双积分
// → 支撑腿关节角误差没有任何回复力。模型误差 (MuJoCo 的 frictionloss/damping/
// armature 在 pinocchio 模型里都没有) 造成的力矩偏置就直接变成不会恢复的角度偏移,
// 表现为 "hip 没有刚度、跟崴脚一样"。
// ============================================================

Eigen::Matrix<double, 12, 1> Go2ControlNode::computeFootAccDes(const RobotState& state,bool pd_open)
{
    double T_swing = scheduler->GetSwingTime();
    if (T_swing < 1e-3) T_swing = 1e-3;

    Eigen::Matrix<double, 4, 3> p_ref = trajectory->GetSwingPos();
    Eigen::Matrix<double, 4, 3> v_ref = trajectory->GetSwingVel() / T_swing;
    Eigen::Matrix<double, 4, 3> p_act = pin->getAllFootPositions();

    Eigen::Matrix<double, 18, 1> v_full;
    v_full << state.linear_vel, state.angular_vel, state.joint_velocities;
    Eigen::Matrix<double, 12, 1> v_foot_act;
    for (int leg = 0; leg < 4; leg++)
        v_foot_act.segment<3>(leg * 3) = pin->getFootJacobianFloatingBase(leg) * v_full;

    // ===== 加速度层阻抗: a_des = a_ff + 阻抗修正 =====
    // 阻抗修正放在加速度层, 让 WBC QP 统一处理, 保持动力学一致性
    Eigen::Matrix<double, 12, 1> a_des = trajectory->GetSwingAccVec();

    if (pd_open){
        const auto& leg_contact = fsm->GetLegContact();
        for (int leg = 0; leg < 4; leg++) {
            const int st = state.contact_states[leg];

            // ===== 摆动→支撑 上升沿: 记录落地瞬间的实际足端位置作为位置参考 =====
            // 取实际位置而非规划落点 ⇒ e_p 在落地那一刻恒为 0, 该项天然连续。
            // !valid 兜底: 起步时四足都已在支撑 (没有上升沿), 用当前 p_act 记一次
            if (st == 1 && (prev_stance_[leg] == 0 || !stance_ref_valid_[leg])) {
                stance_ref_.row(leg)    = p_act.row(leg);
                stance_ref_valid_[leg]  = true;
            }
            prev_stance_[leg] = st;

            if (st == 1) {
                // 支撑相: 不吃摆动前馈, 只做"保持在落地点"的位置/速度反馈
                a_des.segment<3>(leg*3).setZero();

                Eigen::Vector3d e_p = stance_ref_.row(leg).transpose()
                                    - p_act.row(leg).transpose();
                // 逐轴限幅 ±5cm: 参考点万一失效 (脚被抬起等) 误差会很大, 而
                // WBC 的 solveProblem() 返回值从未被检查、也没有 allFinite() 守卫,
                // 巨大的 a_des 会被静默当成有效解用掉。限幅把指令上界钉在 Kp*0.05
                const double ep_max = 0.05;
                e_p = e_p.cwiseMax(-ep_max).cwiseMin(ep_max);
                // 速度项只取足端实际速度 (期望速度恒为 0 = 脚不动)
                Eigen::Vector3d e_v = -v_foot_act.segment<3>(leg * 3);
                a_des.segment<3>(leg * 3) =
                    pd_.stance_Kp.cwiseProduct(e_p) + pd_.stance_Kd.cwiseProduct(e_v);
                continue;
            }

            // ===== 摆动相 =====

            // 有效相位取自 FSM 的接触判定 (摆动腿即真实摆动相位)
            double t = leg_contact[leg].eff_phase;
            // 只保留**起摆端**的平滑衰减: t→0 时足端还停在支撑位置上,
            // 阻抗满值会与抬腿指令对抗。
            // 落地端**不做**衰减 —— 原实现在 t→1 时把阻抗收到 0, 而那正是需要力矩
            // 把足端压到地面的时刻, 足端因此带着零权威停在半空 ("没落地"的直接原因
            // 之一)。现在接触切换由实测足端力驱动, 足端一落地该腿立刻转为支撑
            // (摆动任务整体消失), 所以"接地瞬间冲击"已被接触切换本身覆盖, 不需要
            // 这个衰减。
            double blend = (t < 0.1) ? (t / 0.1) : 1.0;

            Eigen::Vector3d e_p = p_ref.row(leg).transpose() - p_act.row(leg).transpose();
            // 与支撑支路同样的逐轴限幅: eff_phase 跳变 (hold 释放 / 重同步) 时, 摆动
            // 参考会被按新相位求值 —— t 跳到摆动中段就是半个步高 (最多 4.7cm), 不设限
            // 会直接变成 Kp*e_p = 20~30 m/s² 的踢腿指令 (摆动腿 f≡0, 没有地面反力吸收).
            // 限幅把上界钉在 Kp*0.05
            const double ep_max = 0.05;
            e_p = e_p.cwiseMax(-ep_max).cwiseMin(ep_max);
            Eigen::Vector3d e_v = v_ref.row(leg).transpose() - v_foot_act.segment<3>(leg * 3);
            // 增益来自 control.yaml 的 TaskPD.swing
            // 速度误差只取足端实际速度 (不缩放 v_ref), 避免摆动入地时阻抗主动对抗足端运动
            a_des.segment<3>(leg * 3) +=
                blend * (pd_.swing_Kp.cwiseProduct(e_p) + pd_.swing_Kd.cwiseProduct(e_v));
        }
    }      
    return a_des;
}

// ============================================================
// /cmd_vel 回调: 替代原键盘 w/s (linear.x = 前后速度指令)
// ============================================================

void Go2ControlNode::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    const double vmax = get_parameter("max_cmd_vel").as_double();
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    v[0] = std::clamp(msg->linear.x, -vmax, vmax);   // 原键盘: w→+0.05, s→-0.05
    // v[1], v[2], w 留作侧移/升降/转向扩展, 保持 0
}

// ============================================================
// 状态发布 (50Hz): 从 WBC 循环维护的快照发布
// ============================================================

void Go2ControlNode::publishState()
{
    nav_msgs::msg::Odometry odom;
    sensor_msgs::msg::JointState joint;
    std_msgs::msg::Float64MultiArray force;
    go2_robot::msg::Go2Telemetry telemetry;
    {
        std::lock_guard<std::mutex> lk(state_msg_mutex_);
        odom  = odom_msg_;
        joint = joint_msg_;
        force = force_msg_;
        telemetry = telemetry_msg_;
    }
    odom_pub_->publish(odom);
    joint_state_pub_->publish(joint);
    foot_force_pub_->publish(force);
    telemetry_pub_->publish(telemetry);
}

// ============================================================
// Telemetry 填充: 500Hz WBC 循环写缓存, 50Hz publishState 发布
// 字段与原 PlotSend UDP JSON key 一致 (供 PlotJuggler ROS2 插件绘图)
// ============================================================

void Go2ControlNode::fillTelemetryMessage(const Eigen::Matrix<double,4,3>& p_ref,
                                        const Eigen::Matrix<double,4,3>& p_act,
                                        const Eigen::Matrix<double,4,3>& v_ref,
                                        const Eigen::Matrix<double,12,1>& v_foot_act,
                                        const Eigen::Matrix<double,12,1>& a_des,
                                        const Eigen::Matrix<double,12,1>& f_mpc,
                                        const Eigen::Matrix<double,12,1>& f_wbc,
                                        const Eigen::Matrix<double,18,1>& q_des,
                                        const Eigen::VectorXd& tau,
                                        const Eigen::Vector3d& a_wbc_ang,
                                        const RobotState& state)
{
    // 成员指针表: [leg*3+axis] → 消息字段, 足端顺序 FL,FR,RL,RR × x,y,z (世界系)
    using Msg = go2_robot::msg::Go2Telemetry;
    using Field = double Msg::*;
    static const Field p_ref_f[12] = {
        &Msg::p_ref_fl_x, &Msg::p_ref_fl_y, &Msg::p_ref_fl_z,
        &Msg::p_ref_fr_x, &Msg::p_ref_fr_y, &Msg::p_ref_fr_z,
        &Msg::p_ref_rl_x, &Msg::p_ref_rl_y, &Msg::p_ref_rl_z,
        &Msg::p_ref_rr_x, &Msg::p_ref_rr_y, &Msg::p_ref_rr_z,
    };
    static const Field p_act_f[12] = {
        &Msg::p_act_fl_x, &Msg::p_act_fl_y, &Msg::p_act_fl_z,
        &Msg::p_act_fr_x, &Msg::p_act_fr_y, &Msg::p_act_fr_z,
        &Msg::p_act_rl_x, &Msg::p_act_rl_y, &Msg::p_act_rl_z,
        &Msg::p_act_rr_x, &Msg::p_act_rr_y, &Msg::p_act_rr_z,
    };
    static const Field v_ref_f[12] = {
        &Msg::v_ref_fl_x, &Msg::v_ref_fl_y, &Msg::v_ref_fl_z,
        &Msg::v_ref_fr_x, &Msg::v_ref_fr_y, &Msg::v_ref_fr_z,
        &Msg::v_ref_rl_x, &Msg::v_ref_rl_y, &Msg::v_ref_rl_z,
        &Msg::v_ref_rr_x, &Msg::v_ref_rr_y, &Msg::v_ref_rr_z,
    };
    static const Field v_act_f[12] = {
        &Msg::v_act_fl_x, &Msg::v_act_fl_y, &Msg::v_act_fl_z,
        &Msg::v_act_fr_x, &Msg::v_act_fr_y, &Msg::v_act_fr_z,
        &Msg::v_act_rl_x, &Msg::v_act_rl_y, &Msg::v_act_rl_z,
        &Msg::v_act_rr_x, &Msg::v_act_rr_y, &Msg::v_act_rr_z,
    };
    static const Field a_ref_f[12] = {   // a_ref = a_des (摆动前馈 + 阻抗修正)
        &Msg::a_ref_fl_x, &Msg::a_ref_fl_y, &Msg::a_ref_fl_z,
        &Msg::a_ref_fr_x, &Msg::a_ref_fr_y, &Msg::a_ref_fr_z,
        &Msg::a_ref_rl_x, &Msg::a_ref_rl_y, &Msg::a_ref_rl_z,
        &Msg::a_ref_rr_x, &Msg::a_ref_rr_y, &Msg::a_ref_rr_z,
    };
    static const Field a_act_f[12] = {   // a_act = 足端速度数值微分 (成员 a_foot_act)
        &Msg::a_act_fl_x, &Msg::a_act_fl_y, &Msg::a_act_fl_z,
        &Msg::a_act_fr_x, &Msg::a_act_fr_y, &Msg::a_act_fr_z,
        &Msg::a_act_rl_x, &Msg::a_act_rl_y, &Msg::a_act_rl_z,
        &Msg::a_act_rr_x, &Msg::a_act_rr_y, &Msg::a_act_rr_z,
    };
    static const Field f_mpc_f[12] = {
        &Msg::f_mpc_fl_x, &Msg::f_mpc_fl_y, &Msg::f_mpc_fl_z,
        &Msg::f_mpc_fr_x, &Msg::f_mpc_fr_y, &Msg::f_mpc_fr_z,
        &Msg::f_mpc_rl_x, &Msg::f_mpc_rl_y, &Msg::f_mpc_rl_z,
        &Msg::f_mpc_rr_x, &Msg::f_mpc_rr_y, &Msg::f_mpc_rr_z,
    };
    static const Field f_wbc_f[12] = {
        &Msg::f_wbc_fl_x, &Msg::f_wbc_fl_y, &Msg::f_wbc_fl_z,
        &Msg::f_wbc_fr_x, &Msg::f_wbc_fr_y, &Msg::f_wbc_fr_z,
        &Msg::f_wbc_rl_x, &Msg::f_wbc_rl_y, &Msg::f_wbc_rl_z,
        &Msg::f_wbc_rr_x, &Msg::f_wbc_rr_y, &Msg::f_wbc_rr_z,
    };
    static const Field q_des_f[18] = {   // q_des = computePoseAccDes 输出 [线3; 角3; 关节12]
        &Msg::q_des_lin_x, &Msg::q_des_lin_y, &Msg::q_des_lin_z,
        &Msg::q_des_ang_x, &Msg::q_des_ang_y, &Msg::q_des_ang_z,
        &Msg::q_des_joint_0,  &Msg::q_des_joint_1,  &Msg::q_des_joint_2,
        &Msg::q_des_joint_3,  &Msg::q_des_joint_4,  &Msg::q_des_joint_5,
        &Msg::q_des_joint_6,  &Msg::q_des_joint_7,  &Msg::q_des_joint_8,
        &Msg::q_des_joint_9,  &Msg::q_des_joint_10, &Msg::q_des_joint_11,
    };
    static const Field tau_f[12] = {   // tau = mj->control(tau) 的输入, 顺序同 q_des_joint_*
        &Msg::tau_joint_0,  &Msg::tau_joint_1,  &Msg::tau_joint_2,
        &Msg::tau_joint_3,  &Msg::tau_joint_4,  &Msg::tau_joint_5,
        &Msg::tau_joint_6,  &Msg::tau_joint_7,  &Msg::tau_joint_8,
        &Msg::tau_joint_9,  &Msg::tau_joint_10, &Msg::tau_joint_11,
    };

    std::lock_guard<std::mutex> lock(state_msg_mutex_);
    telemetry_msg_.header.stamp = now();

    for (int leg = 0; leg < 4; leg++) {
        for (int axis = 0; axis < 3; axis++) {
            const int i = leg * 3 + axis;
            telemetry_msg_.*p_ref_f[i] = p_ref(leg, axis);
            telemetry_msg_.*p_act_f[i] = p_act(leg, axis);
            telemetry_msg_.*v_ref_f[i] = v_ref(leg, axis);
            telemetry_msg_.*v_act_f[i] = v_foot_act(i);
            telemetry_msg_.*a_ref_f[i] = a_des(i);
            telemetry_msg_.*a_act_f[i] = a_foot_act(i);
            telemetry_msg_.*f_mpc_f[i] = f_mpc(i);
            telemetry_msg_.*f_wbc_f[i] = f_wbc(i);
        }
    }

    for (int i = 0; i < 18; i++)
        telemetry_msg_.*q_des_f[i] = q_des(i);

    // 关节力矩 (WBC 逆动力学输出)
    for (int i = 0; i < 12; i++)
        telemetry_msg_.*tau_f[i] = tau(i);

    // ===== 姿态诊断: 接触力合成力矩 Σ(r×f) 与摩擦锥利用率 =====
    // r = 足端 − 机身 (世界系), 力取世界系 (z 向上, 与 MPC 模型一致)
    // roll ≈ Σ(y·fz − z·fy), pitch ≈ Σ(z·fx − x·fz), yaw = Σ(x·fy − y·fx)
    // 摩擦锥利用率 = |ft|/(μ·fz), >1 表示 WBC 要求的切向力超出摩擦锥 → 足端打滑
    static const Field f_cone_f[4] = {&Msg::f_cone_fl, &Msg::f_cone_fr,
                                      &Msg::f_cone_rl, &Msg::f_cone_rr};
    constexpr double mu_cone = 0.5;  // 与 MPC QPConstraint 的 mu 一致
    Eigen::Vector3d tau_mpc = Eigen::Vector3d::Zero();
    Eigen::Vector3d tau_wbc = Eigen::Vector3d::Zero();
    for (int leg = 0; leg < 4; leg++) {
        Eigen::Vector3d r = p_act.row(leg).transpose() - state.position;
        tau_mpc += r.cross(f_mpc.segment<3>(leg * 3));
        tau_wbc += r.cross(f_wbc.segment<3>(leg * 3));

        double fz = f_wbc(leg * 3 + 2);
        double util = 0.0;
        if (fz > 1e-6) {
            double fx = f_wbc(leg * 3), fy = f_wbc(leg * 3 + 1);
            util = std::sqrt(fx * fx + fy * fy) / (mu_cone * fz);
        }
        telemetry_msg_.*f_cone_f[leg] = util;
    }
    telemetry_msg_.tau_roll_mpc  = tau_mpc.x();
    telemetry_msg_.tau_pitch_mpc = tau_mpc.y();
    telemetry_msg_.tau_yaw_mpc   = tau_mpc.z();
    telemetry_msg_.tau_roll_wbc  = tau_wbc.x();
    telemetry_msg_.tau_pitch_wbc = tau_wbc.y();
    telemetry_msg_.tau_yaw_wbc   = tau_wbc.z();

    // WBC QP 解出的基座角加速度 (机体系), 供与 q_des_ang 逐段对比
    telemetry_msg_.a_wbc_ang_x = a_wbc_ang.x();
    telemetry_msg_.a_wbc_ang_y = a_wbc_ang.y();
    telemetry_msg_.a_wbc_ang_z = a_wbc_ang.z();

    // 计划接触状态 (1=支撑, 0=摆动)
    telemetry_msg_.contact_fl = state.contact_states[0];
    telemetry_msg_.contact_fr = state.contact_states[1];
    telemetry_msg_.contact_rl = state.contact_states[2];
    telemetry_msg_.contact_rr = state.contact_states[3];

    // 机身位置/速度与期望速度 (v 与 WBC 循环同在 executor 线程, 读安全)
    telemetry_msg_.body_x     = state.position(0);
    telemetry_msg_.body_z     = state.position(2);
    telemetry_msg_.body_x_v   = state.linear_vel(0);
    telemetry_msg_.body_z_v   = state.linear_vel(2);
    telemetry_msg_.body_x_v_d = v(0);
    telemetry_msg_.body_z_v_d = v(2);
}

} // namespace go2
