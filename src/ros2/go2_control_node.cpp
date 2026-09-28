#include "ros2/go2_control_node.hpp"

#include <yaml-cpp/yaml.h>
#include <ament_index_cpp/get_package_share_directory.hpp>
#include "RobotInterface/MujocoRobotInterface.hpp"
#include "Controller/TraditionalController.hpp"
#include "Controller/RLController.hpp"

namespace go2
{

Go2ControlNode::Go2ControlNode() : rclcpp::Node("go2_control_node")
{
    // ===== ROS 2 参数声明 =====
    declare_parameter<std::string>("robot_backend", "mujoco");      // mujoco | unitree
    declare_parameter<std::string>("controller_type", "traditional"); // traditional | rl
    declare_parameter<std::string>("mujoco_model", "go2/scene_flat.xml");
    declare_parameter<std::string>("urdf_path", "go2/go2_description.urdf");
    declare_parameter<std::string>("control_config", "config/control.yaml");
    declare_parameter<std::string>("policy_path", "model/go2_best.onnx");
    declare_parameter<double>("control_frequency", 500.0);
    declare_parameter<double>("publish_frequency", 50.0);
    declare_parameter<double>("desired_height", 0.25);
    declare_parameter<double>("max_cmd_vel", 0.05);
    declare_parameter<std::string>("initial_gait", "TROT");
    declare_parameter<double>("touchdown_force", 5.0);
    declare_parameter<double>("airborne_hold_ratio", 0.5);

    initBackends();
    startTimers();

    RCLCPP_INFO(get_logger(),
        "Go2 node up: backend=%s, controller=%s, control=%.0f Hz, pub=%.0f Hz",
        get_parameter("robot_backend").as_string().c_str(),
        get_parameter("controller_type").as_string().c_str(),
        control_frequency_, publish_frequency_);
}

Go2ControlNode::~Go2ControlNode()
{
    // Timers and controller/robot are automatically cleaned up via shared_ptr
}

void Go2ControlNode::initBackends()
{
    // Resolve package paths
    std::string pkg_share = ament_index_cpp::get_package_share_directory("go2_robot");
    
    std::string mujoco_model = get_parameter("mujoco_model").as_string();
    std::string urdf_path = get_parameter("urdf_path").as_string();
    std::string control_config = get_parameter("control_config").as_string();
    std::string policy_path = get_parameter("policy_path").as_string();

    // Make paths absolute if relative
    auto make_absolute = [&](const std::string& path) -> std::string {
        if (path.empty() || path[0] == '/') return path;
        return pkg_share + "/" + path;
    };

    mujoco_model = make_absolute(mujoco_model);
    urdf_path = make_absolute(urdf_path);
    control_config = make_absolute(control_config);
    policy_path = make_absolute(policy_path);

    // Create robot interface
    std::string robot_backend = get_parameter("robot_backend").as_string();
    robot_ = createRobotInterface(robot_backend);
    if (!robot_) {
        RCLCPP_FATAL(get_logger(), "Failed to create robot backend: %s", robot_backend.c_str());
        rclcpp::shutdown();
        return;
    }

    // Create controller
    std::string controller_type = get_parameter("controller_type").as_string();
    controller_ = createController(controller_type);
    if (!controller_) {
        RCLCPP_FATAL(get_logger(), "Failed to create controller: %s", controller_type.c_str());
        rclcpp::shutdown();
        return;
    }

    // Configure controller
    Controller::ControllerConfig ctrl_config;
    ctrl_config.control_config_path = control_config;
    ctrl_config.urdf_path = urdf_path;
    ctrl_config.control_frequency = get_parameter("control_frequency").as_double();
    ctrl_config.desired_height = get_parameter("desired_height").as_double();
    ctrl_config.initial_gait = get_parameter("initial_gait").as_string();
    ctrl_config.touchdown_force = get_parameter("touchdown_force").as_double();
    ctrl_config.airborne_hold_ratio = get_parameter("airborne_hold_ratio").as_double();
    ctrl_config.max_cmd_vel = get_parameter("max_cmd_vel").as_double();

    // Initialize controller (which also initializes robot)
    controller_->init(ctrl_config, robot_);

    control_frequency_ = get_parameter("control_frequency").as_double();
    publish_frequency_ = get_parameter("publish_frequency").as_double();
}

RobotInterface::RobotInterfacePtr Go2ControlNode::createRobotInterface(const std::string& backend)
{
    std::string pkg_share = ament_index_cpp::get_package_share_directory("go2_robot");
    std::string mujoco_model = get_parameter("mujoco_model").as_string();
    std::string urdf_path = get_parameter("urdf_path").as_string();
    
    auto make_absolute = [&](const std::string& path) -> std::string {
        if (path.empty() || path[0] == '/') return path;
        return pkg_share + "/" + path;
    };
    mujoco_model = make_absolute(mujoco_model);
    urdf_path = make_absolute(urdf_path);

    if (backend == "mujoco") {
        return RobotInterface::createMujocoRobotInterface(mujoco_model, urdf_path);
    } else if (backend == "unitree") {
        RCLCPP_WARN(get_logger(), "Unitree hardware backend not yet implemented, falling back to MuJoCo");
        return RobotInterface::createMujocoRobotInterface(mujoco_model, urdf_path);
    } else if (backend == "gow"){
        RCLCPP_WARN(get_logger(), "Gow hardware backend not yet implemented, falling back to MuJoCo");
        return RobotInterface::createMujocoRobotInterface(mujoco_model, urdf_path);
    } 
    
    else {
        RCLCPP_ERROR(get_logger(), "Unknown robot backend: %s", backend.c_str());
        return nullptr;
    }
}

Controller::ControllerPtr Go2ControlNode::createController(const std::string& type)
{
    if (type == "traditional") {
        return std::make_shared<Controller::TraditionalController>();
    } else if (type == "rl") {
        return std::make_shared<Controller::RLController>();
    } else {
        RCLCPP_ERROR(get_logger(), "Unknown controller type: %s", type.c_str());
        return nullptr;
    }
}

void Go2ControlNode::startTimers()
{
    // Control loop timer
    double ctrl_period = 1.0 / control_frequency_;
    control_timer_ = create_wall_timer(
        std::chrono::duration<double>(ctrl_period),
        std::bind(&Go2ControlNode::controlLoop, this));

    // State publishing timer
    double pub_period = 1.0 / publish_frequency_;
    pub_timer_ = create_wall_timer(
        std::chrono::duration<double>(pub_period),
        std::bind(&Go2ControlNode::publishState, this));

    // Publishers
    odom_pub_ = create_publisher<nav_msgs::msg::Odometry>("odom", 10);
    joint_state_pub_ = create_publisher<sensor_msgs::msg::JointState>("joint_states", 10);
    foot_force_pub_ = create_publisher<std_msgs::msg::Float64MultiArray>("foot_forces", 10);
    telemetry_pub_ = create_publisher<go2_robot::msg::Go2Telemetry>("go2_telemetry", 10);

    // Subscriber
    cmd_sub_ = create_subscription<geometry_msgs::msg::Twist>(
        "cmd_vel", 10,
        std::bind(&Go2ControlNode::cmdVelCallback, this, std::placeholders::_1));

    // Initialize joint message names
    joint_msg_.name = {"FL_hip", "FL_thigh", "FL_calf",
                       "FR_hip", "FR_thigh", "FR_calf",
                       "RL_hip", "RL_thigh", "RL_calf",
                       "RR_hip", "RR_thigh", "RR_calf"};
    joint_msg_.position.resize(12);
    joint_msg_.velocity.resize(12);
}

void Go2ControlNode::controlLoop()
{
    if (!controller_ || !controller_->isReady() || !robot_) return;

    // Get current robot state
    RobotState state = robot_->getState();

    // Get command velocity
    Eigen::Vector3d cmd_vel;
    {
        std::lock_guard<std::mutex> lk(cmd_mutex_);
        cmd_vel = cmd_vel_;
    }

    // Run controller update
    Eigen::VectorXd tau = controller_->update(state, cmd_vel);

    // Cache state for publishing
    {
        std::lock_guard<std::mutex> lk(state_msg_mutex_);
        last_state_ = state;
        last_tau_ = tau;
    }
}

void Go2ControlNode::publishState()
{
    if (!robot_) return;

    RobotState state;
    Eigen::VectorXd tau;
    {
        std::lock_guard<std::mutex> lk(state_msg_mutex_);
        state = last_state_;
        tau = last_tau_;
    }

    // Odometry
    nav_msgs::msg::Odometry odom;
    odom.header.stamp = this->now();
    odom.header.frame_id = "odom";
    odom.child_frame_id = "base_link";
    odom.pose.pose.position.x = state.position.x();
    odom.pose.pose.position.y = state.position.y();
    odom.pose.pose.position.z = state.position.z();
    odom.pose.pose.orientation.x = state.quat.x();
    odom.pose.pose.orientation.y = state.quat.y();
    odom.pose.pose.orientation.z = state.quat.z();
    odom.pose.pose.orientation.w = state.quat.w();
    odom.twist.twist.linear.x = state.linear_vel.x();
    odom.twist.twist.linear.y = state.linear_vel.y();
    odom.twist.twist.linear.z = state.linear_vel.z();
    odom.twist.twist.angular.x = state.angular_vel.x();
    odom.twist.twist.angular.y = state.angular_vel.y();
    odom.twist.twist.angular.z = state.angular_vel.z();
    odom_pub_->publish(odom);

    // Joint states
    sensor_msgs::msg::JointState joint = joint_msg_;
    joint.header.stamp = this->now();
    for (int i = 0; i < 12; i++) {
        joint.position[i] = state.joint_positions(i);
        joint.velocity[i] = state.joint_velocities(i);
    }
    joint_state_pub_->publish(joint);

    // Foot forces
    std_msgs::msg::Float64MultiArray force_msg;
    force_msg.data.resize(4);
    for (int i = 0; i < 4; i++) force_msg.data[i] = state.foot_forces(i);
    foot_force_pub_->publish(force_msg);

    // Telemetry (basic)
    go2_robot::msg::Go2Telemetry telemetry;
    telemetry.header.stamp = this->now();
    telemetry_pub_->publish(telemetry);
}

void Go2ControlNode::cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg)
{
    const double vmax = get_parameter("max_cmd_vel").as_double();
    std::lock_guard<std::mutex> lk(cmd_mutex_);
    cmd_vel_[0] = std::clamp(msg->linear.x, -vmax, vmax);
    cmd_vel_[1] = std::clamp(msg->linear.y, -vmax, vmax);
    cmd_vel_[2] = std::clamp(msg->angular.z, -vmax, vmax);

    // Also forward to controller
    if (controller_) {
        controller_->setCmdVel(cmd_vel_);
    }
}

} // namespace go2