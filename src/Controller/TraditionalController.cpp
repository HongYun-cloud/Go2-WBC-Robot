#include "Controller/TraditionalController.hpp"
#include <iostream>
#include <chrono>
#include <algorithm>

namespace Controller
{

TraditionalController::TraditionalController() = default;

TraditionalController::~TraditionalController()
{
    mpc_running_ = false;
    if (mpc_thread_.joinable())
        mpc_thread_.join();

    delete mpc_;
    delete wbc_;
    delete pin_;
    mpc_ = nullptr; wbc_ = nullptr; pin_ = nullptr;
}

void TraditionalController::init(const ControllerConfig& config, RobotInterface::RobotInterfacePtr robot)
{
    robot_ = robot;

    // Initialize components
    scheduler_ = std::make_shared<Gait::GaitScheduler>();
    estimator_ = std::shared_ptr<Estimator::PositionVelocityEstimator>(
        new Estimator::PositionVelocityEstimator());
    trajectory_ = std::make_shared<SwingPlanner::SwingLegPlanner>(scheduler_, estimator_);

    fsm_ = std::make_unique<fsm::ControlFSM>(scheduler_, trajectory_);
    fsm_->setContactDetect(config.touchdown_force, config.airborne_hold_ratio);

    pin_ = new Pinocchio::PinocchioKinematics(config.urdf_path);
    mpc_ = new Regulator::MPC(estimator_.get());
    wbc_ = new WBC::WBC(estimator_.get());

    // Connect Pinocchio to MPC
    mpc_->setLegData(pin_->getLegData());

    // Load configs
    loadTaskPdConfig(config.control_config_path);
    wbc_->setPinocchio(pin_);
    wbc_->loadConfig(config.control_config_path);

    // Initialize robot (MuJoCo)
    robot_->init();

    // Initial state
    q_cmd_.setZero(); p_cmd_.setZero();
    v_cmd_.setZero(); w_cmd_.setZero();
    p_cmd_[2] = config.desired_height;
    mpc_->update_DesireStateCommand(q_cmd_, p_cmd_, v_cmd_, w_cmd_);
    mpc_->loadConfig(config.control_config_path);
    mpc_->update_reference_trajectory();

    // WBC init
    wbc_->init();

    // First update to set up WBC
    {
        auto state = robot_->getState();
        estimator_->update(state);
        pin_->setJointVelocity(state.joint_velocities);
        pin_->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin_->forwardKinematics(state.joint_positions, state.position, state.quat.coeffs());
        trajectory_->SetFootPositions(pin_->getAllFootPositions());

        mpc_->update();
        mpc_->solve();
        auto f_mpc = mpc_->getControl();
        f_mpc_buf_ = std::make_shared<FmpcSnapshot>(FmpcSnapshot{f_mpc, true});

        Eigen::Matrix<double, 18, 1> q_des = Eigen::Matrix<double, 18, 1>::Zero();
        Eigen::Matrix<double, 12, 1> a_des = Eigen::Matrix<double, 12, 1>::Zero();
        wbc_->update(q_des, f_mpc, a_des, state);
    }

    // Set MPC model params from URDF
    {
        double m_total = 0.0;
        Eigen::Matrix3d I_com = Eigen::Matrix3d::Zero();
        pin_->getTotalMassInertia(m_total, I_com);
        mpc_->setModelParams(m_total, I_com.diagonal().asDiagonal());
        std::cout << "[MPC] mass=" << m_total << " kg, I diag=" << I_com.diagonal().transpose() << std::endl;
    }

    // Initial gait
    {
        Gait::GaitType type = Gait::GaitType::TROT;
        if (config.initial_gait == "STAND") type = Gait::GaitType::STAND;
        else if (config.initial_gait == "WALK") type = Gait::GaitType::WALK;
        gait_type_ = type;
        fsm_->SetCmd(gait_type_, v_cmd_);
    }
    fsm_->SetState(fsm::FSM_State::GAIT_RUNNING);

    sim_dt_ = robot_->getTimestep();
    if (std::abs(config.control_frequency - 1.0 / sim_dt_) > 1.0) {
        std::cout << "[WARN] control_frequency(" << config.control_frequency
                  << ") != 1/timestep(" << 1.0 / sim_dt_ << "), using 1/timestep" << std::endl;
    }

    // Start MPC thread
    mpc_running_ = true;
    mpc_thread_ = std::thread([this]() { mpcSolveLoop(); });

    ready_ = true;
    std::cout << "[TraditionalController] Initialized at " << 1.0/sim_dt_ << " Hz" << std::endl;
}

Eigen::VectorXd TraditionalController::update(const RobotState& state, const Eigen::Vector3d& cmd_vel)
{
    if (!ready_) return Eigen::VectorXd::Zero(12);

    // Update command velocity
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        v_cmd_ = cmd_vel;
        mpc_->update_DesireStateCommand(q_cmd_, p_cmd_, v_cmd_, w_cmd_);
        fsm_->SetCmd(gait_type_, v_cmd_);
    }

    count_++;

    // Contact detection
    fsm_->run(sim_dt_, state.foot_forces);
    const auto& leg_contact = fsm_->GetLegContact();
    // contact_states is available via leg_contact[leg].stance

    // Estimator + FK
    {
        std::lock_guard<std::mutex> lk(estimator_mutex_);
        estimator_->update(state);
    }
    {
        std::lock_guard<std::mutex> lk(fk_mpc_mutex_);
        pin_->setJointVelocity(state.joint_velocities);
        pin_->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin_->forwardKinematics(state.joint_positions, state.position, state.quat.coeffs());
    }
    trajectory_->SetFootPositions(pin_->getAllFootPositions());

    // Get MPC force from async thread
    std::shared_ptr<const FmpcSnapshot> snap;
    {
        std::lock_guard<std::mutex> lk(f_mpc_mutex_);
        snap = f_mpc_buf_;
    }
    Eigen::Matrix<double, 12, 1> f_mpc = snap->valid ? snap->f : Eigen::Matrix<double, 12, 1>::Zero();

    // Contact schedule for MPC
    {
        std::lock_guard<std::mutex> lk(fk_mpc_mutex_);
        mpc_->setContactSchedule(scheduler_->GetContactSchedule(mpc_->getDt(), mpc_->getHorizonN()));
    }

    // Compute desired accelerations
    Eigen::Matrix<double, 18, 1> q_des = computePoseAccDes(state);
    Eigen::Matrix<double, 12, 1> a_des = computeFootAccDes(state);

    // WBC update and solve
    wbc_->update(q_des, f_mpc, a_des, state);
    wbc_->solve();

    WBC::SolutionVector sol;
    WBC::SolForce f_wbc;
    WBC::SolAcc q_a_wbc;
    wbc_->GetSolution(sol);
    wbc_->GetForce(f_wbc);
    wbc_->GetAcc(q_a_wbc);

    // Compute joint torques
    auto tau = pin_->getJointTorquesFromSolution(q_a_wbc, f_wbc);

    // Send to robot
    robot_->setCommand(tau);
    robot_->step();
    robot_->render();

    return tau;
}

void TraditionalController::reset()
{
    if (ready_) {
        robot_->reset();
        q_cmd_.setZero(); p_cmd_.setZero();
        v_cmd_.setZero(); w_cmd_.setZero();
        p_cmd_[2] = 0.25;
        count_ = 0;
        have_prev_v_ = false;
        v_foot_prev_.setZero();
        a_foot_act_.setZero();
        stance_ref_.setZero();
        stance_ref_valid_.fill(false);
        prev_stance_.fill(1);
    }
}

void TraditionalController::setCmdVel(const Eigen::Vector3d& cmd_vel)
{
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    v_cmd_ = cmd_vel;
}

void TraditionalController::loadTaskPdConfig(const std::string& yaml_path)
{
    YAML::Node root;
    try {
        root = YAML::LoadFile(yaml_path);
    } catch (const std::exception& e) {
        std::cout << "[TaskPD] Failed to load " << yaml_path << ": " << e.what() << std::endl;
        return;
    }

    const YAML::Node croot = root;
    const YAML::Node pd = croot["TaskPD"];
    if (!pd.IsDefined() || !pd.IsMap()) {
        std::cout << "[TaskPD] Missing TaskPD section, using defaults" << std::endl;
        return;
    }

    auto tryRead = [&](const YAML::Node& parent, const char* key, Eigen::Vector3d& out) -> bool {
        if (!parent.IsDefined() || !parent.IsMap()) return false;
        const YAML::Node n = parent[key];
        if (!n.IsDefined() || !n.IsSequence() || n.size() != 3) return false;
        try {
            Eigen::Vector3d v;
            v << n[0].as<double>(), n[1].as<double>(), n[2].as<double>();
            out = v;
            return true;
        } catch (...) { return false; }
    };

    const YAML::Node pose = pd["pose"];
    const YAML::Node swing = pd["swing"];
    const YAML::Node stance = pd["stance"];

    tryRead(pose, "Kp_lin", pd_.pose_Kp_lin);
    tryRead(pose, "Kd_lin", pd_.pose_Kd_lin);
    tryRead(pose, "Kp_ang", pd_.pose_Kp_ang);
    tryRead(pose, "Kd_ang", pd_.pose_Kd_ang);
    tryRead(swing, "Kp", pd_.swing_Kp);
    tryRead(swing, "Kd", pd_.swing_Kd);
    tryRead(stance, "Kp", pd_.stance_Kp);
    tryRead(stance, "Kd", pd_.stance_Kd);
}

void TraditionalController::mpcSolveLoop()
{
    while (mpc_running_.load()) {
        auto t0 = std::chrono::steady_clock::now();

        {
            std::lock_guard<std::mutex> lk_est(estimator_mutex_);
            std::lock_guard<std::mutex> lk_fk(fk_mpc_mutex_);
            mpc_->update();
        }

        mpc_->solve();

        {
            auto snap = std::make_shared<FmpcSnapshot>();
            snap->f = mpc_->getControl();
            snap->valid = true;
            std::lock_guard<std::mutex> lk(f_mpc_mutex_);
            f_mpc_buf_ = std::move(snap);
        }

        std::this_thread::sleep_until(t0 + std::chrono::duration<double>(0.01)); // 100Hz
    }
}

Eigen::Matrix<double, 18, 1> TraditionalController::computePoseAccDes(const RobotState& state)
{
    Eigen::Vector3d a_lin = Eigen::Vector3d::Zero();
    Eigen::Vector3d a_ang = Eigen::Vector3d::Zero();
    Eigen::Matrix<double, 12, 1> a_joint_des = Eigen::Matrix<double, 12, 1>::Zero();

    auto est = estimator_->get_estresult();
    Eigen::Vector3d p_des, v_des, rpy_des, w_des;
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        p_des = p_cmd_; v_des = v_cmd_; rpy_des = q_cmd_; w_des = w_cmd_;
    }

    Eigen::Vector3d e_p(0.0, p_des.y() - est.p.y(), p_des.z() - est.p.z());
    Eigen::Vector3d e_v = v_des - est.v;
    a_lin = pd_.pose_Kp_lin.cwiseProduct(e_p) + pd_.pose_Kd_lin.cwiseProduct(e_v);

    Eigen::Matrix3d R_des = (Eigen::AngleAxisd(rpy_des(2), Eigen::Vector3d::UnitZ()) *
                     Eigen::AngleAxisd(rpy_des(1), Eigen::Vector3d::UnitY()) *
                     Eigen::AngleAxisd(rpy_des(0), Eigen::Vector3d::UnitX())).toRotationMatrix();

    Eigen::Matrix3d R_cur = (Eigen::AngleAxisd(est.q(2), Eigen::Vector3d::UnitZ()) *
                     Eigen::AngleAxisd(est.q(1), Eigen::Vector3d::UnitY()) *
                     Eigen::AngleAxisd(est.q(0), Eigen::Vector3d::UnitX())).toRotationMatrix();
    Eigen::Matrix3d R_err = R_cur.transpose() * R_des;
    Eigen::Vector3d e_rpy;
    e_rpy << 0.5 * (R_err(2, 1) - R_err(1, 2)),
             0.5 * (R_err(0, 2) - R_err(2, 0)),
             0.5 * (R_err(1, 0) - R_err(0, 1));

    Eigen::Vector3d e_w = w_des - est.w;
    a_ang = pd_.pose_Kp_ang.cwiseProduct(e_rpy) + pd_.pose_Kd_ang.cwiseProduct(e_w);

    Eigen::Matrix<double, 18, 1> a_out;
    a_out << a_lin, a_ang, a_joint_des;
    return a_out;
}

Eigen::Matrix<double, 12, 1> TraditionalController::computeFootAccDes(const RobotState& state)
{
    double T_swing = scheduler_->GetSwingTime();
    if (T_swing < 1e-3) T_swing = 1e-3;

    Eigen::Matrix<double, 4, 3> p_ref = trajectory_->GetSwingPos();
    Eigen::Matrix<double, 4, 3> v_ref = trajectory_->GetSwingVel() / T_swing;
    Eigen::Matrix<double, 4, 3> p_act = pin_->getAllFootPositions();

    Eigen::Matrix<double, 18, 1> v_full;
    v_full << state.linear_vel, state.angular_vel, state.joint_velocities;
    Eigen::Matrix<double, 12, 1> v_foot_act;
    for (int leg = 0; leg < 4; leg++)
        v_foot_act.segment<3>(leg * 3) = pin_->getFootJacobianFloatingBase(leg) * v_full;

    Eigen::Matrix<double, 12, 1> a_des = trajectory_->GetSwingAccVec();

    const auto& leg_contact = fsm_->GetLegContact();
    for (int leg = 0; leg < 4; leg++) {
        const int st = state.contact_states[leg];

        if (st == 1 && (prev_stance_[leg] == 0 || !stance_ref_valid_[leg])) {
            stance_ref_.row(leg) = p_act.row(leg);
            stance_ref_valid_[leg] = true;
        }
        prev_stance_[leg] = st;

        if (st == 1) {
            a_des.segment<3>(leg * 3).setZero();
            Eigen::Vector3d e_p = stance_ref_.row(leg).transpose() - p_act.row(leg).transpose();
            const double ep_max = 0.05;
            e_p = e_p.cwiseMax(-ep_max).cwiseMin(ep_max);
            Eigen::Vector3d e_v = -v_foot_act.segment<3>(leg * 3);
            a_des.segment<3>(leg * 3) = pd_.stance_Kp.cwiseProduct(e_p) + pd_.stance_Kd.cwiseProduct(e_v);
            continue;
        }

        double t = leg_contact[leg].eff_phase;
        double blend = (t < 0.1) ? (t / 0.1) : 1.0;

        Eigen::Vector3d e_p = p_ref.row(leg).transpose() - p_act.row(leg).transpose();
        const double ep_max = 0.05;
        e_p = e_p.cwiseMax(-ep_max).cwiseMin(ep_max);
        Eigen::Vector3d e_v = v_ref.row(leg).transpose() - v_foot_act.segment<3>(leg * 3);
        a_des.segment<3>(leg * 3) += blend * (pd_.swing_Kp.cwiseProduct(e_p) + pd_.swing_Kd.cwiseProduct(e_v));
    }

    return a_des;
}

} // namespace Controller