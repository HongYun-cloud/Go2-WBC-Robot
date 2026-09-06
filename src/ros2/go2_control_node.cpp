#include "ros2/go2_control_node.hpp"

// ============================================================
// 构造 / 析构
// ============================================================
namespace go2{

Go2ControlNode::Go2ControlNode() : rclcpp::Node("go2_control_node")
{
    // ===== ROS 2 参数声明 (config/go2_params.yaml) =====
    declare_parameter<std::string>("mujoco_model", "go2/scene.xml");
    declare_parameter<std::string>("urdf_path",    "go2/go2_description.urdf");
    declare_parameter<std::string>("mpc_config",   "config/mpc.yaml");
    declare_parameter<std::string>("initial_gait", "TROT");
    declare_parameter<double>("control_frequency", 500.0);   // WBC 主循环 (须 == 1/mujoco timestep)
    declare_parameter<double>("mpc_frequency",     100.0);   // MPC 异步线程
    declare_parameter<double>("publish_frequency", 50.0);    // 状态发布
    declare_parameter<double>("desired_height",    0.25);    // MPC 期望机身高度
    declare_parameter<double>("max_cmd_vel",       0.05);    // /cmd_vel 限幅 (原键盘 0.05)

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

    // 路径参数: 相对路径基于运行目录 (与原 ../go2/... 行为一致, 从 build/ 运行)
    std::string xml       = get_parameter("mujoco_model").as_string();
    std::string urdf_path = get_parameter("urdf_path").as_string();
    std::string mpc_yaml  = get_parameter("mpc_config").as_string();

    mj  = new MJCSIM::SIM(xml);
    pin = new Pinocchio::PinocchioKinematics(urdf_path);
    mpc = new Regulator::MPC(estimator.get());
    wbc = new WBC::WBC(estimator.get());

    // 足端顺序FL,FR,RL,RR
    // ===== 通过地址连接 Pinocchio 足端数据到 MPCData =====
    mpc->setLegData(pin->getLegData());

    // ===== WBC 初始化 =====
    wbc->setPinocchio(pin);
    wbc->loadConfig(mpc_yaml);

    mj->InitMujoco();
    // mj->SimStart();
    // mj->InitViewer();

    q.setZero(); p.setZero();
    v.setZero(); w.setZero();
    p[2] = get_parameter("desired_height").as_double();
    mpc->update_DesireStateCommand(q, p, v, w);
    mpc->loadConfig(mpc_yaml);
    mpc->update_reference_trajectory();

    // WBC 首次 update + init (设置 cmd 并初始化固定矩阵)
    {
        auto state = mj->getState();
        estimator->update(state);
        pin->setJointVelocity(v8to12(state.joint_velocities));
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(q8toq12(state.joint_positions), state.position, state.quat.coeffs());
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
    wbc->init();

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
        fsm->SetCmd(type, v);
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
    // ===== 指令来源: /cmd_vel 替代原键盘 w/s =====
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        mpc->update_DesireStateCommand(q, p, v, w);
    }

    fsm->run(sim_dt);
    count++;
    auto state = mj->getState();

    // ===== 计划接触 (步态相位): 摆动/支撑划分不能用实测接触 =====
    // 静止时四足全着地 → 实测接触全 1 → 摆动任务永远不触发 (死锁: 脚不抬就永远"支撑")
    // 覆写 state.contact_states 为计划接触, 后续 estimator/MPC/PD/WBC 全部按计划划分
    for (int leg = 0; leg < 4; leg++)
        state.contact_states[leg] = (scheduler->GetSwingPhases(leg) <= 0) ? 1 : 0;

    // ===== 估计器 + FK: 写共享数据, 与 MPC 线程互斥 =====
    {
        std::lock_guard<std::mutex> lk_est(estimator_mutex_);
        estimator->update(state);
    }
    {
        // forwardKinematics 内部 _syncLegData 写 leg_data_ (MPC 经裸指针读) → 持锁
        std::lock_guard<std::mutex> lk_fk(fk_mpc_mutex_);
        pin->setJointVelocity(v8to12(state.joint_velocities));
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(q8toq12(state.joint_positions), state.position, state.quat.coeffs());
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

    // 足端实际速度: J_floating × v_full (与 WBC 摆动任务同坐标系)
    Eigen::Matrix<double, 18, 1> v_full;
    v_full << state.linear_vel, state.angular_vel, v8to12(state.joint_velocities);
    Eigen::Matrix<double, 12, 1> v_foot_act;
    for (int leg = 0; leg < 4; leg++)
        v_foot_act.segment<3>(leg * 3) = pin->getFootJacobianFloatingBase(leg) * v_full;

    // ===== 足端实际加速度 (世界系): v_foot_act 数值微分 =====
    if (have_prev_v)
        a_foot_act = (v_foot_act - v_foot_prev) / sim_dt;
    v_foot_prev = v_foot_act;
    have_prev_v = true;

    Eigen::Matrix<double, 12, 1> a_des = computeSwingAccDes(state,true);

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
    auto tau = pin->getJointTorquesFromSolution(q_des, f_mpc);
    // auto tau = pin->getJointTorquesFromSolution(test_a, f_wbc);
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
            joint_msg_.name = {"FL_thigh", "FL_calf", "FR_thigh", "FR_calf",
                               "RL_thigh", "RL_calf", "RR_thigh", "RR_calf"};
            joint_msg_.position.resize(8);
            joint_msg_.velocity.resize(8);
        }
        joint_msg_.header.stamp = this->now();
        for (int i = 0; i < 8; i++) {
            joint_msg_.position[i] = state.joint_positions(i);
            joint_msg_.velocity[i] = state.joint_velocities(i);
        }

        if (force_msg_.data.size() != 12) force_msg_.data.resize(12);
        for (int i = 0; i < 12; i++) force_msg_.data[i] = f_wbc(i);
    }

    // ===== Telemetry 缓存: 500Hz 纯内存拷贝, publishState (50Hz) 发布 =====
    // a_wbc_ang = WBC QP 解出的基座角加速度 (机体系), 与 q_des_ang 对比验证 PD 是否被执行
    fillTelemetryMessage(p_ref, p_act, v_ref, v_foot_act, a_des, f_mpc, f_wbc, q_des,
                         sol.segment<3>(3), state);
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
    if (pd_open) {
        // 期望值: 节点成员 q/p/v/w (调试期手动设置, 与 MPC DesireCMD 同源)
        // 实际值: 估计器 p, v, q(世界系roll-pitch-yaw), w
        auto est = estimator->get_estresult();
        Eigen::Vector3d p_des, v_des, rpy_des, w_des;
        {
            std::lock_guard<std::mutex> lk(cmd_mutex_);
            p_des = p; v_des = v; rpy_des = q; w_des = w;
        }

        // 线加速度: 位置 PD 只取 z 轴 (x/y 做位置 PD 会把行走中的机身拉回原点),
        // 速度 PD 三轴全做 (跟踪 /cmd_vel)
        Eigen::Vector3d Kp_lin(0.0, 0.0, 50.0);
        Eigen::Vector3d Kd_lin(10.0, 10.0, 10.0);
        Eigen::Vector3d e_p_z(0.0, 0.0, p_des.z() - est.p.z());
        Eigen::Vector3d e_v = v_des - est.v;
        a_lin = Kp_lin.cwiseProduct(e_p_z) + Kd_lin.cwiseProduct(e_v);

        // 角加速度: rpy 位置 PD + 角速度 PD, 全在世界系计算, 末尾转机体系
        // WBC QP 的基座角加速度是 Pinocchio free-flyer 机体系量, 而 rpy 误差是世界系;
        // yaw 漂移时两系的 roll/pitch 轴不重合, 不转系则纠偏力矩方向歪 (表现为 roll 越纠越偏)
        // 增益正值量级: 坐标系 bug 已修 (输出已转机体系), 无需负号补偿;
        // 配合 FI=10 / C动力学=100, PD 输出已能传导到接触力
        Eigen::Vector3d Kp_ang(70.0, 50.0, 30.0);
        Eigen::Vector3d Kd_ang(6.0, 10.0, 5.0);
        // 机体系角速度 → 世界系 (MuJoCo free joint 角速度是机体系)
        Eigen::Matrix3d R =
        (Eigen::AngleAxisd(est.q(2), Eigen::Vector3d::UnitZ()) *
        Eigen::AngleAxisd(est.q(1), Eigen::Vector3d::UnitY()) *
        Eigen::AngleAxisd(est.q(0), Eigen::Vector3d::UnitX())).toRotationMatrix();
        
        Eigen::Vector3d e_rpy = R.transpose() * (rpy_des - est.q);
        Eigen::Vector3d e_w = w_des - est.w;
        a_ang = Kp_ang.cwiseProduct(e_rpy) + Kd_ang.cwiseProduct(e_w);  // 机身系
        a_ang = R.transpose() * a_ang;  // 世界系 → 机体系喂 WBC (忽略 ω×ω 小量)
    }

    // 关节加速度: 暂无期望关节位置/速度参考 → 前馈直通。
    // 后续接入期望关节轨迹后在此加: Kp_j·(qj_des − qj_act) + Kd_j·(qd_des − qd_act)
    Eigen::Matrix<double, 18, 1> a_out;
    a_out << a_lin, a_ang, a_joint_des;
    return a_out;
}
// ============================================================
// 加速度层阻抗: 原主循环内嵌段, 逻辑零修改抽出
// ============================================================

Eigen::Matrix<double, 12, 1> Go2ControlNode::computeSwingAccDes(const RobotState& state,bool pd_open)
{
    double T_swing = scheduler->GetSwingTime();
    if (T_swing < 1e-3) T_swing = 1e-3;

    Eigen::Matrix<double, 4, 3> p_ref = trajectory->GetSwingPos();
    Eigen::Matrix<double, 4, 3> v_ref = trajectory->GetSwingVel() / T_swing;
    Eigen::Matrix<double, 4, 3> p_act = pin->getAllFootPositions();

    Eigen::Matrix<double, 18, 1> v_full;
    v_full << state.linear_vel, state.angular_vel, v8to12(state.joint_velocities);
    Eigen::Matrix<double, 12, 1> v_foot_act;
    for (int leg = 0; leg < 4; leg++)
        v_foot_act.segment<3>(leg * 3) = pin->getFootJacobianFloatingBase(leg) * v_full;

    // ===== 加速度层阻抗: a_des = a_ff + 阻抗修正 =====
    // 阻抗修正放在加速度层, 让 WBC QP 统一处理, 保持动力学一致性
    // 支撑腿: a_des 置零, 不跟踪摆动加速度
    Eigen::Matrix<double, 12, 1> a_des = trajectory->GetSwingAccVec();

    if (pd_open){
        for (int leg = 0; leg < 4; leg++) {
            if (state.contact_states[leg] == 1) {
                // 支撑相为0
                a_des.segment<3>(leg*3).setZero();
                continue;
            }

            double t = scheduler->GetSwingPhases(leg);
            double blend = 1.0;
            if (t < 0.1)      blend = t / 0.1;
            else if (t > 0.9) blend = (1.0 - t) / 0.1;

            Eigen::Vector3d e_p = p_ref.row(leg).transpose() - p_act.row(leg).transpose();
            Eigen::Vector3d e_v = v_ref.row(leg).transpose() - v_foot_act.segment<3>(leg * 3);
            Eigen::Vector3d Kp_vec(50, 300, 1000);
            Eigen::Vector3d Kd_vec(2, 10, 20);
            // 速度误差只取足端实际速度 (不缩放 v_ref), 避免摆动入地时阻抗主动对抗足端运动
            // blend 用于起落阶段平滑衰减阻抗, 避免接地瞬间冲击
            a_des.segment<3>(leg * 3) += blend * (Kp_vec.cwiseProduct(e_p) + Kd_vec.cwiseProduct(e_v));
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
