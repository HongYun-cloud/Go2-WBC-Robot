#ifndef __GO2_CONTROL_NODE_HPP
#define __GO2_CONTROL_NODE_HPP

// Go2 ROS 2 控制节点: 使用工厂模式支持 sim/hardware 和 traditional/RL 切换
//
// 架构:
//   RobotInterface (抽象)
//     ├─ MujocoRobotInterface (仿真)
//     └─ UnitreeRobotInterface (实机, 待实现)
//   
//   ControllerBase (抽象)
//     ├─ TraditionalController (MPC + WBC)
//     └─ RLController (ONNX Policy)
//
// 通过 ROS2 参数选择:
//   robot_backend: "mujoco" | "unitree"
//   controller_type: "traditional" | "rl"

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include "go2_robot/msg/go2_telemetry.hpp"

#include <memory>
#include <mutex>

#include "common.h"
#include "RobotInterface/RobotInterface.hpp"
#include "Controller/ControllerBase.hpp"

namespace go2
{

class Go2ControlNode : public rclcpp::Node
{
public:
    Go2ControlNode();
    ~Go2ControlNode() override;

private:
    // Selected backends
    RobotInterface::RobotInterfacePtr robot_;
    Controller::ControllerPtr controller_;

    // ROS 2 interfaces
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr foot_force_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Publisher<go2_robot::msg::Go2Telemetry>::SharedPtr telemetry_pub_;

    rclcpp::TimerBase::SharedPtr control_timer_;  // Main control loop
    rclcpp::TimerBase::SharedPtr pub_timer_;      // State publishing

    // Publishing cache
    nav_msgs::msg::Odometry odom_msg_;
    sensor_msgs::msg::JointState joint_msg_;
    std::mutex state_msg_mutex_;

    // Command velocity (from /cmd_vel)
    Eigen::Vector3d cmd_vel_{0, 0, 0};
    std::mutex cmd_mutex_;

    // Cached state for publishing
    RobotState last_state_;
    Eigen::VectorXd last_tau_;

    // Config
    double control_frequency_ = 500.0;
    double publish_frequency_ = 50.0;

    // Initialization
    void initBackends();
    void startTimers();

    // Callbacks
    void controlLoop();
    void publishState();
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);

    // Factory methods
    RobotInterface::RobotInterfacePtr createRobotInterface(const std::string& backend);
    Controller::ControllerPtr createController(const std::string& type);
};

} // namespace go2

#endif // __GO2_CONTROL_NODE_HPP