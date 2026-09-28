#ifndef __RL_CONTROLLER_HPP
#define __RL_CONTROLLER_HPP

#include "Controller/ControllerBase.hpp"
#include <vector>
#include <string>
#include <memory>
#include <mutex>
#include <onnxruntime_cxx_api.h>

namespace Controller
{

class RLController : public ControllerBase
{
public:
    RLController();
    ~RLController() override;

    void init(const ControllerConfig& config, RobotInterface::RobotInterfacePtr robot) override;
    Eigen::VectorXd update(const RobotState& state, const Eigen::Vector3d& cmd_vel) override;
    void reset() override;
    void setCmdVel(const Eigen::Vector3d& cmd_vel) override;
    std::string getName() const override { return "RL (ONNX Policy)"; }
    bool isReady() const override { return ready_; }

private:
    // ONNX Runtime
    Ort::Env env_;
    std::unique_ptr<Ort::Session> session_;
    std::vector<std::string> input_name_strings_;
    std::vector<std::string> output_name_strings_;
    std::vector<const char*> input_names_;
    std::vector<const char*> output_names_;
    std::vector<int64_t> input_shape_;
    std::vector<int64_t> output_shape_;

    // Policy config
    std::string policy_path_;
    int obs_dim_ = 0;
    int act_dim_ = 0;
    double control_dt_ = 0.002;

    // Observation normalization (from training)
    std::vector<float> obs_mean_;
    std::vector<float> obs_std_;

    // Action scaling (from training)
    std::vector<float> action_scale_;
    std::vector<float> action_offset_;
    Eigen::VectorXd default_joint_positions_;

    // PD gains for joint position control (12 DOF)
    Eigen::VectorXd kp_joint_ = Eigen::VectorXd::Constant(12, 50.0);
    Eigen::VectorXd kd_joint_ = Eigen::VectorXd::Constant(12, 2.0);

    // Command velocity
    Eigen::Vector3d cmd_vel_{0, 0, 0};
    std::mutex cmd_mutex_;

    // Previous action for smooth transition
    Eigen::VectorXd last_action_;
    bool has_last_action_ = false;

    // Robot interface
    RobotInterface::RobotInterfacePtr robot_;

    bool ready_ = false;

    // Helper methods
    Eigen::VectorXd computeObservation(const RobotState& state);
    Eigen::VectorXd denormalizeAction(const Eigen::VectorXd& normalized_action);
    Eigen::VectorXd computePDTorque(const Eigen::VectorXd& q_target, const RobotState& state);
    void loadPolicyConfig(const std::string& config_path);
    void loadPDGains(const std::string& config_path);
};

} // namespace Controller

#endif // __RL_CONTROLLER_HPP