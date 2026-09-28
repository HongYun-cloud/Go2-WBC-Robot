#ifndef __TRADITIONAL_CONTROLLER_HPP
#define __TRADITIONAL_CONTROLLER_HPP

#include "Controller/ControllerBase.hpp"
#include "MPC/MPC.hpp"
#include "WBC/WBC.hpp"
#include "Dynamic/pinocchio.hpp"
#include "fsm/ControlFSM.hpp"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"
#include "Estimator/PositionVelocityEstimator.hpp"
#include "RobotInterface/RobotInterface.hpp"
#include <yaml-cpp/yaml.h>
#include <thread>
#include <mutex>
#include <atomic>
#include <memory>
#include <chrono>

namespace Controller
{

struct FmpcSnapshot
{
    Eigen::Matrix<double, 12, 1> f;
    bool valid = false;
};

struct TaskPdGains
{
    Eigen::Vector3d pose_Kp_lin{0.0, 0.0, 50.0};
    Eigen::Vector3d pose_Kd_lin{10.0, 10.0, 10.0};
    Eigen::Vector3d pose_Kp_ang{600.0, 200.0, 100.0};
    Eigen::Vector3d pose_Kd_ang{20.0, 20.0, 20.0};
    Eigen::Vector3d swing_Kp{300.0, 600.0, 500.0};
    Eigen::Vector3d swing_Kd{50.0, 60.0, 10.0};
    Eigen::Vector3d stance_Kp{150.0, 150.0, 150.0};
    Eigen::Vector3d stance_Kd{25.0, 25.0, 25.0};
};

class TraditionalController : public ControllerBase
{
public:
    TraditionalController();
    ~TraditionalController() override;

    void init(const ControllerConfig& config, RobotInterface::RobotInterfacePtr robot) override;
    Eigen::VectorXd update(const RobotState& state, const Eigen::Vector3d& cmd_vel) override;
    void reset() override;
    void setCmdVel(const Eigen::Vector3d& cmd_vel) override;
    std::string getName() const override { return "Traditional (MPC+WBC)"; }
    bool isReady() const override { return ready_; }

private:
    // Control stack components
    std::shared_ptr<Gait::GaitScheduler> scheduler_;
    std::shared_ptr<Estimator::PositionVelocityEstimator> estimator_;
    std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory_;
    std::unique_ptr<fsm::ControlFSM> fsm_;

    Regulator::MPC* mpc_ = nullptr;
    WBC::WBC* wbc_ = nullptr;
    Pinocchio::PinocchioKinematics* pin_ = nullptr;
    RobotInterface::RobotInterfacePtr robot_;

    // Control state
    Eigen::Vector3d v_cmd_{0, 0, 0}, w_cmd_{0, 0, 0}, q_cmd_{0, 0, 0}, p_cmd_{0, 0, 0};
    Gait::GaitType gait_type_ = Gait::GaitType::TROT;
    double sim_dt_ = 0.002;
    int count_ = 0;

    // Foot acceleration tracking
    Eigen::Matrix<double, 12, 1> v_foot_prev_ = Eigen::Matrix<double, 12, 1>::Zero();
    Eigen::Matrix<double, 12, 1> a_foot_act_ = Eigen::Matrix<double, 12, 1>::Zero();
    bool have_prev_v_ = false;

    // Task PD gains
    TaskPdGains pd_;

    // Stance leg position reference
    Eigen::Matrix<double, 4, 3> stance_ref_ = Eigen::Matrix<double, 4, 3>::Zero();
    std::array<bool, 4> stance_ref_valid_{{false, false, false, false}};
    std::array<int, 4> prev_stance_{{1, 1, 1, 1}};

    // MPC async thread
    std::thread mpc_thread_;
    std::atomic<bool> mpc_running_{false};
    std::shared_ptr<const FmpcSnapshot> f_mpc_buf_;
    std::mutex f_mpc_mutex_;

    // Thread safety
    std::mutex estimator_mutex_;
    std::mutex fk_mpc_mutex_;
    std::mutex cmd_mutex_;

    bool ready_ = false;

    // Private methods
    void loadTaskPdConfig(const std::string& yaml_path);
    void mpcSolveLoop();
    Eigen::Matrix<double, 18, 1> computePoseAccDes(const RobotState& state);
    Eigen::Matrix<double, 12, 1> computeFootAccDes(const RobotState& state);
    bool readVec3(const YAML::Node& parent, const char* key, Eigen::Vector3d& out);
};

} // namespace Controller

#endif // __TRADITIONAL_CONTROLLER_HPP