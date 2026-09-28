#include "Controller/RLController.hpp"
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>
#include <cmath>

namespace Controller
{

RLController::RLController()
    : env_(ORT_LOGGING_LEVEL_WARNING, "Go2RL")
{
}

RLController::~RLController() = default;

void RLController::init(const ControllerConfig& config, RobotInterface::RobotInterfacePtr robot)
{
    robot_ = robot;
    policy_path_ = config.control_config_path; // Reuse for policy path, or add separate param
    
    // For now, use the model path from config
    std::string onnx_path = "model/go2_best.onnx";
    
    Ort::SessionOptions session_options;
    session_options.SetIntraOpNumThreads(1);
    session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_ALL);

    try {
        session_ = std::make_unique<Ort::Session>(env_, onnx_path.c_str(), session_options);
    } catch (const std::exception& e) {
        std::cerr << "[RLController] Failed to load ONNX model: " << e.what() << std::endl;
        return;
    }

    // Get input/output info
    Ort::AllocatorWithDefaultOptions allocator;
    
    size_t num_inputs = session_->GetInputCount();
    size_t num_outputs = session_->GetOutputCount();

    input_names_.reserve(num_inputs);
    output_names_.reserve(num_outputs);
    input_name_strings_.clear();
    output_name_strings_.clear();
    
    for (size_t i = 0; i < num_inputs; ++i) {
        auto name = session_->GetInputNameAllocated(i, allocator);
        input_name_strings_.push_back(name.get());
        input_names_.push_back(input_name_strings_.back().c_str());
        auto type_info = session_->GetInputTypeInfo(i);
        auto tensor_info = type_info.GetTensorTypeAndShapeInfo();
        input_shape_ = tensor_info.GetShape();
        obs_dim_ = 1;
        for (auto dim : input_shape_) if (dim > 0) obs_dim_ *= dim;
    }
    
    for (size_t i = 0; i < num_outputs; ++i) {
        auto name = session_->GetOutputNameAllocated(i, allocator);
        output_name_strings_.push_back(name.get());
        output_names_.push_back(output_name_strings_.back().c_str());
        auto type_info = session_->GetOutputTypeInfo(i);
        auto tensor_info = type_info.GetTensorTypeAndShapeInfo();
        output_shape_ = tensor_info.GetShape();
        act_dim_ = 1;
        for (auto dim : output_shape_) if (dim > 0) act_dim_ *= dim;
    }

    std::cout << "[RLController] Policy loaded: " << onnx_path << std::endl;
    std::cout << "  Input shape: ["; for (auto d : input_shape_) std::cout << d << " "; std::cout << "]" << std::endl;
    std::cout << "  Output shape: ["; for (auto d : output_shape_) std::cout << d << " "; std::cout << "]" << std::endl;
    std::cout << "  Obs dim: " << obs_dim_ << ", Act dim: " << act_dim_ << std::endl;

    // Load normalization params from YAML if available
    loadPolicyConfig(config.control_config_path);
    loadPDGains(config.control_config_path);

    default_joint_positions_.resize(action_offset_.size());
    for (int i = 0;i<action_offset_.size();i++)
        default_joint_positions_(i) = action_offset_[i];
    std::cout << default_joint_positions_.transpose() << std::endl;
    // Initialize robot
    robot_->init();
    control_dt_ = robot_->getTimestep();

    last_action_.setZero(act_dim_);
    has_last_action_ = false;
    ready_ = true;

    std::cout << "[RLController] Initialized at " << 1.0/control_dt_ << " Hz" << std::endl;
}

void RLController::loadPolicyConfig(const std::string& config_path)
{
    // Try to load normalization params from a YAML file
    // Expected format:
    // policy:
    //   obs_mean: [...]
    //   obs_std: [...]
    //   action_scale: [...]
    //   action_offset: [...]
    
    try {
        YAML::Node root = YAML::LoadFile(config_path);
        if (root["policy"]) {
            auto policy_node = root["policy"];
            if (policy_node["obs_mean"]) {
                for (auto v : policy_node["obs_mean"]) obs_mean_.push_back(v.as<float>());
            }
            if (policy_node["obs_std"]) {
                for (auto v : policy_node["obs_std"]) obs_std_.push_back(v.as<float>());
            }
            if (policy_node["action_scale"]) {
                for (auto v : policy_node["action_scale"]) action_scale_.push_back(v.as<float>());
            }
            if (policy_node["action_offset"]) {
                for (auto v : policy_node["action_offset"]) action_offset_.push_back(v.as<float>());
            }
        }
    } catch (...) {
        // Use defaults if config not found
    }

    assert(obs_mean_.size() == 48 && "obs_mean_ is empty");
    assert(!obs_std_.empty() && "obs_std_ is empty");
    assert(!action_scale_.empty() && "action_scale_ is empty");
    assert(!action_offset_.empty() && "action_offset_ is empty");
    // Defaults for typical Go2 policy (Isaac Lab / RL Games style)
    if (obs_mean_.empty()) obs_mean_.assign(obs_dim_, 0.0f);
    if (obs_std_.empty()) obs_std_.assign(obs_dim_, 1.0f);
    if (action_scale_.empty()) action_scale_.assign(act_dim_, 1.0f);
    if (action_offset_.empty()) action_offset_.assign(act_dim_, 0.0f);
}

Eigen::VectorXd RLController::update(const RobotState& state, const Eigen::Vector3d& cmd_vel)
{
    if (!ready_) return Eigen::VectorXd::Zero(act_dim_);

    // Update command
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        cmd_vel_ = cmd_vel;
    }

    // Compute observation
    Eigen::VectorXd obs = computeObservation(state);

        // std::cout << "[OBS_RAW] "
        //   << obs.transpose()
        //   << std::endl;

    std::vector<float> obs_input(obs_dim_);
    for (int i = 0; i < obs_dim_; ++i) {
        obs_input[i] = obs(i);
    }


    // Run inference
    Ort::MemoryInfo mem_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
    Ort::Value input_tensor = Ort::Value::CreateTensor<float>(
        mem_info, obs_input.data(), obs_input.size(), input_shape_.data(), input_shape_.size()
    );

    std::vector<Ort::Value> outputs;
    try {
        outputs = session_->Run(Ort::RunOptions{nullptr}, input_names_.data(), &input_tensor, 1, output_names_.data(), output_names_.size());
    
    } catch (const std::exception& e) {
        std::cerr << "[RLController] Inference failed: " << e.what() << std::endl;
        return Eigen::VectorXd::Zero(act_dim_);
    }

    // Get action
    float* action_data = outputs[0].GetTensorMutableData<float>();
    
    // std::cout << "[ONNX_ACTION] ";
    // for (int i = 0; i < act_dim_; ++i) {
    //     std::cout << action_data[i] << " ";
    // }
    // std::cout << std::endl;


    Eigen::VectorXd normalized_action(act_dim_);
    for (int i = 0; i < act_dim_; ++i) normalized_action(i) = action_data[i];

    // Denormalize to target joint positions
    Eigen::VectorXd q_target = denormalizeAction(normalized_action);

    // std::cout << "[RLController] raw action: ";
    // for (int i = 0; i < act_dim_; ++i) {
    //     std::cout << action_data[i] << " ";
    // }
    // std::cout << std::endl;

    // Eigen::VectorXd action = denormalizeAction(normalized_action);

    // std::cout << "[RLController] denormalized action: ";
    // for (int i = 0; i < act_dim_; ++i) {
    //     std::cout << action[i] << " ";
    // }
    // std::cout << std::endl;


    // Compute PD torque: tau = Kp * (q_target - q_current) + Kd * (0 - qd_current)
    Eigen::VectorXd tau = computePDTorque(q_target, state);
    // tau.setZero();
    // last_action_ = normalized_action;
    last_action_.setZero();
    has_last_action_ = true;

    // Send torque to robot
    robot_->setCommand(tau);
    robot_->step();
    robot_->render();

    return tau;
}

Eigen::VectorXd RLController::computeObservation(const RobotState& state)
{
    // Typical Go2 observation (48 dims):
    // [base_lin_vel(3), base_ang_vel(3), projected_gravity(3), 
    //  joint_pos(12), joint_vel(12), last_action(12), cmd_vel(3)]
    
    Eigen::VectorXd obs(obs_dim_);
    int idx = 0;
    
    // Base linear velocity (world frame)
    if (idx + 3 <= obs_dim_) {
        obs.segment<3>(idx) = state.linear_vel;
        idx += 3;
    }
    
    // Base angular velocity (body frame)
    if (idx + 3 <= obs_dim_) {
        obs.segment<3>(idx) = state.angular_vel;
        idx += 3;
    }
    
    // Projected gravity (body frame z-axis in world frame)
    if (idx + 3 <= obs_dim_) {
        Eigen::Vector3d gravity_world(0, 0, -1);
        Eigen::Vector3d gravity_body = state.quat.toRotationMatrix().transpose() * gravity_world;
        obs.segment<3>(idx) = gravity_body;
        idx += 3;
    }
    
    // Joint positions (12)
    if (idx + 12 <= obs_dim_) {
        obs.segment<12>(idx) =
            state.joint_positions - default_joint_positions_;
        idx += 12;
    }
    
    // Joint velocities (12)
    if (idx + 12 <= obs_dim_) {
        obs.segment<12>(idx) = state.joint_velocities;
        idx += 12;
    }
    
    // Last action (12)
    if (idx + 12 <= obs_dim_) {
        if (has_last_action_) {
            obs.segment<12>(idx) = last_action_.head(12);
        } else {
            obs.segment<12>(idx).setZero();
        }
        idx += 12;
    }
    
    // Command velocity (3)
    if (idx + 3 <= obs_dim_) {
        Eigen::Vector3d cmd;
        {
            std::lock_guard<std::mutex> lk(cmd_mutex_);
            cmd = cmd_vel_;
        }
        obs.segment<3>(idx) = cmd;
        idx += 3;
    }
    
    // Pad remaining with zeros if obs_dim_ is larger
    if (idx < obs_dim_) {
        obs.tail(obs_dim_ - idx).setZero();
    }
    
    return obs;
}

Eigen::VectorXd RLController::denormalizeAction(const Eigen::VectorXd& normalized_action)
{
    Eigen::VectorXd action(act_dim_);
    for (int i = 0; i < act_dim_; ++i) {
        float scale = (i < (int)action_scale_.size()) ? action_scale_[i] : 1.0f;
        float offset = (i < (int)action_offset_.size()) ? action_offset_[i] : 0.0f;
        action(i) = normalized_action(i) * scale + offset;
    }
    return action;
}

void RLController::reset()
{
    if (ready_) {
        robot_->reset();
        last_action_.setZero();
        has_last_action_ = false;
    }
}

void RLController::setCmdVel(const Eigen::Vector3d& cmd_vel)
{
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    cmd_vel_ = cmd_vel;
}

Eigen::VectorXd RLController::computePDTorque(const Eigen::VectorXd& q_target, const RobotState& state)
{
    Eigen::VectorXd tau(12);
    for (int i = 0; i < 12; ++i) {
        double q_err = q_target(i) - state.joint_positions(i);
        double qd_err = 0.0 - state.joint_velocities(i);  // target velocity = 0
        tau(i) = kp_joint_(i) * q_err + kd_joint_(i) * qd_err;
    }
    return tau;
}

void RLController::loadPDGains(const std::string& config_path)
{
    try {
        YAML::Node root = YAML::LoadFile(config_path);
        if (root["policy"] && root["policy"]["pd_gains"]) {
            auto pd = root["policy"]["pd_gains"];
            if (pd["kp"]) {
                int i = 0;
                for (auto v : pd["kp"]) {
                    if (i < 12) kp_joint_(i++) = v.as<double>();
                }
            }
            if (pd["kd"]) {
                int i = 0;
                for (auto v : pd["kd"]) {
                    if (i < 12) kd_joint_(i++) = v.as<double>();
                }
            }
            std::cout << "[RLController] PD gains loaded: Kp=" << kp_joint_.transpose() << std::endl;
            std::cout << "[RLController] PD gains loaded: Kd=" << kd_joint_.transpose() << std::endl;
        } else {
            std::cout << "[RLController] Using default PD gains: Kp=" << kp_joint_.transpose() << ", Kd=" << kd_joint_.transpose() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "[RLController] Failed to load PD gains, using defaults: " << e.what() << std::endl;
    }
}

} // namespace Controller