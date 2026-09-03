#include "ros2/go2_control_node.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <vector>

namespace go2
{

// PlotJuggler UDP 流式发送 (PlotJuggler → UDP Stream 插件, 默认端口 9870)
// 格式: JSON 对象, 每行一个, 如 {"timestamp":0.02, "FL_x":0.193, "FL_z":-0.05}
// 用法: PlotSend(0.02, {{"FL_x", 0.193}, {"FL_z", -0.05}})
static int _pj_sock = -1;
static struct sockaddr_in _pj_addr;
static void PlotSend(double time, const std::vector<std::pair<std::string,double>>& data){
    if (_pj_sock < 0) {
        _pj_sock = socket(AF_INET, SOCK_DGRAM, 0);
        std::memset(&_pj_addr, 0, sizeof(_pj_addr));
        _pj_addr.sin_family = AF_INET;
        _pj_addr.sin_port = htons(9870);
        inet_pton(AF_INET, "127.0.0.1", &_pj_addr.sin_addr);
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4) << "{\"timestamp\":" << time;
    for (auto& kv : data)
        oss << ",\"" << kv.first << "\":" << kv.second;
    oss << "}\n";
    std::string msg = oss.str();
    sendto(_pj_sock, msg.c_str(), msg.size(), 0,
           (struct sockaddr*)&_pj_addr, sizeof(_pj_addr));
}

// ============================================================
// 构造 / 析构
// ============================================================

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
    Eigen::Matrix<double, 18, 1> q_des = Eigen::Matrix<double, 18, 1>::Zero();

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

    Eigen::Matrix<double, 12, 1> a_des = computeSwingAccDes(state);

    wbc->update(q_des, f_mpc, a_des, state);
    wbc->solve();

    WBC::SolutionVector sol;
    wbc->GetSolution(sol);
    Eigen::Matrix<double, 12, 1> f_wbc = sol.tail(12);

    // 关节力矩: τ = M·a + h − Jᵀf (WBC 逆动力学, 已包含 a_des 跟踪)
    auto tau = pin->getJointTorquesFromSolution(sol.head(18), f_wbc);

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

    // ===== PlotJuggler UDP 发送 (每 10 帧 0.02s 一次, 非阻塞) =====
    {
        double t = count * sim_dt;
        if (count % 10 == 0)
            publishPlotJuggler(t, p_ref, p_act, v_ref, v_foot_act, a_des, f_mpc, f_wbc, state);
    }
}

// ============================================================
// 加速度层阻抗: 原主循环内嵌段, 逻辑零修改抽出
// ============================================================

Eigen::Matrix<double, 12, 1> Go2ControlNode::computeSwingAccDes(const RobotState& state)
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
    for (int leg = 0; leg < 4; leg++) {
        if (state.contact_states[leg] == 1) {
            a_des.segment<3>(leg*3).setZero();
            continue;
        }

        double t = scheduler->GetSwingPhases(leg);
        double blend = 1.0;
        if (t < 0.1)      blend = t / 0.1;
        else if (t > 0.9) blend = (1.0 - t) / 0.1;

        Eigen::Vector3d e_p = p_ref.row(leg).transpose() - p_act.row(leg).transpose();
        Eigen::Vector3d e_v = v_ref.row(leg).transpose() - v_foot_act.segment<3>(leg * 3);
        Eigen::Vector3d Kp_vec(300, 300, 1000);
        Eigen::Vector3d Kd_vec(10, 10, 20);
        Eigen::Vector3d Kt(10, 10, 20);
        // 速度误差只取足端实际速度 (不缩放 v_ref), 避免摆动入地时阻抗主动对抗足端运动
        // blend 用于起落阶段平滑衰减阻抗, 避免接地瞬间冲击
        a_des.segment<3>(leg * 3) += blend * (Kp_vec.cwiseProduct(e_p) + Kd_vec.cwiseProduct(e_v));
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
    {
        std::lock_guard<std::mutex> lk(state_msg_mutex_);
        odom  = odom_msg_;
        joint = joint_msg_;
        force = force_msg_;
    }
    odom_pub_->publish(odom);
    joint_state_pub_->publish(joint);
    foot_force_pub_->publish(force);
}

// ============================================================
// PlotJuggler UDP: 原主循环末段, 逻辑零修改抽出
// ============================================================

void Go2ControlNode::publishPlotJuggler(double t,
                                        const Eigen::Matrix<double,4,3>& p_ref,
                                        const Eigen::Matrix<double,4,3>& p_act,
                                        const Eigen::Matrix<double,4,3>& v_ref,
                                        const Eigen::Matrix<double,12,1>& v_foot_act,
                                        const Eigen::Matrix<double,12,1>& a_des,
                                        const Eigen::Matrix<double,12,1>& f_mpc,
                                        const Eigen::Matrix<double,12,1>& f_wbc,
                                        const RobotState& state)
{
    std::vector<std::pair<std::string,double>> pj;
    const char* legN[] = {"FL","FR","RL","RR"};
    for (int leg = 0; leg < 4; leg++) {
        pj.push_back({std::string("p_ref_") + legN[leg] + "_x", p_ref(leg,0)});
        pj.push_back({std::string("p_ref_") + legN[leg] + "_y", p_ref(leg,1)});
        pj.push_back({std::string("p_ref_") + legN[leg] + "_z", p_ref(leg,2)});

        pj.push_back({std::string("p_act_") + legN[leg] + "_x", p_act(leg,0)});
        pj.push_back({std::string("p_act_") + legN[leg] + "_y", p_act(leg,1)});
        pj.push_back({std::string("p_act_") + legN[leg] + "_z", p_act(leg,2)});

        pj.push_back({std::string("v_ref_") + legN[leg] + "_x", v_ref(leg,0)});
        pj.push_back({std::string("v_ref_") + legN[leg] + "_y", v_ref(leg,1)});
        pj.push_back({std::string("v_ref_") + legN[leg] + "_z", v_ref(leg,2)});

        pj.push_back({std::string("v_act_") + legN[leg] + "_x", v_foot_act(leg*3+0)});
        pj.push_back({std::string("v_act_") + legN[leg] + "_y", v_foot_act(leg*3+1)});
        pj.push_back({std::string("v_act_") + legN[leg] + "_z", v_foot_act(leg*3+2)});

        pj.push_back({std::string("a_ref_") + legN[leg] + "_x", a_des(leg*3 + 0)});
        pj.push_back({std::string("a_ref_") + legN[leg] + "_y", a_des(leg*3 + 1)});
        pj.push_back({std::string("a_ref_") + legN[leg] + "_z", a_des(leg*3 + 2)});

        pj.push_back({std::string("a_act_") + legN[leg] + "_x", a_foot_act(leg*3+0)});
        pj.push_back({std::string("a_act_") + legN[leg] + "_y", a_foot_act(leg*3+1)});
        pj.push_back({std::string("a_act_") + legN[leg] + "_z", a_foot_act(leg*3+2)});

        pj.push_back({std::string("f_mpc_") + legN[leg] + "_x", f_mpc(leg*3+0)});
        pj.push_back({std::string("f_mpc_") + legN[leg] + "_y", f_mpc(leg*3+1)});
        pj.push_back({std::string("f_mpc_") + legN[leg] + "_z", f_mpc(leg*3+2)});

        pj.push_back({std::string("f_wbc_") + legN[leg] + "_x", f_wbc(leg*3+0)});
        pj.push_back({std::string("f_wbc_") + legN[leg] + "_y", f_wbc(leg*3+1)});
        pj.push_back({std::string("f_wbc_") + legN[leg] + "_z", f_wbc(leg*3+2)});

        pj.push_back({std::string("contract_") + legN[leg] + "_z", state.contact_states[leg]});
    }
    pj.push_back({"body_x", state.position[0]});
    pj.push_back({"body_z", state.position[2]});

    pj.push_back({"body_x_v", state.linear_vel[0]});
    pj.push_back({"body_z_v", state.linear_vel[2]});

    pj.push_back({"body_x_v_d", v[0]});
    pj.push_back({"body_z_v_d", v[2]});
    PlotSend(t, pj);
}

} // namespace go2
