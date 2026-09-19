#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <Eigen/Dense>
#include <vector>
#include <iomanip>

using Point = Eigen::Vector3d;
using Velocity = Eigen::Vector3d;
struct Eular
{
    double Yaw;
    double Pitch;
    double Roll;
};

struct Quat
{
    double x;
    double y;
    double z;
    double w;
};

// class Point
// {
//     double x;
//     double y;
//     double z;


// };

// 完整的机器人状态，从 MuJoCo 仿真读取
struct RobotState
{
    // 机身状态
    Eigen::Vector3d position;       // x, y, z (世界坐标系)
    Eigen::Vector3d euler;          // roll, pitch, yaw (世界坐标系)
    Eigen::Quaterniond quat;           // x,y,z,w    (姿态四元数)
    Eigen::Vector3d linear_vel;     // vx, vy, vz (世界坐标系)
    Eigen::Vector3d angular_vel;    // wx, wy, wz (机体坐标系)

    // 关节状态 (Go2: 8 个关节)
    // 顺序: FL_thigh, FL_calf, FR_thigh, FR_calf, RL_thigh, RL_calf, RR_thigh, RR_calf
    Eigen::Matrix<double, 12, 1> joint_positions;
    Eigen::Matrix<double, 12, 1> joint_velocities;

    // 触地状态 (4 条腿: FL, FR, RL, RR)
    std::vector<int> contact_states;

    RobotState()
    {
        position.setZero();
        euler.setZero();
        linear_vel.setZero();
        angular_vel.setZero();
        joint_positions.setZero();
        joint_velocities.setZero();
        contact_states = {1, 1, 1, 1};
    }
};

inline void printRobotState(const RobotState& state) {
    #ifdef REFRESH_IN_PLACE
        // 将光标移回顶部的 ANSI 转义码（仅限 Linux/Mac 终端）
        std::cout << "\033[H"; 
    #endif

        std::cout << std::fixed << std::setprecision(3); // 设置精度为3位小数
        std::cout << "==================== ROBOT STATE ====================" << std::endl;

        // 1. 机身位姿与速度
        std::cout << "[Body Pose]" << std::endl;
        std::cout << "  Pos   (x, y, z): " 
                << std::setw(7) << state.position.x() << ", " 
                << std::setw(7) << state.position.y() << ", " 
                << std::setw(7) << state.position.z() << " (m)" << std::endl;
        std::cout << "  Euler (r, p, y): " 
                << std::setw(7) << state.euler.x() << ", " 
                << std::setw(7) << state.euler.y() << ", " 
                << std::setw(7) << state.euler.z() << " (rad)" << std::endl;

        std::cout << "[Body Velocity]" << std::endl;
        std::cout << "  Linear  (v): " 
                << std::setw(7) << state.linear_vel.x() << ", " 
                << std::setw(7) << state.linear_vel.y() << ", " 
                << std::setw(7) << state.linear_vel.z() << " (m/s)" << std::endl;
        std::cout << "  Angular (w): " 
                << std::setw(7) << state.angular_vel.x() << ", " 
                << std::setw(7) << state.angular_vel.y() << ", " 
                << std::setw(7) << state.angular_vel.z() << " (rad/s)" << std::endl;

        // 2. 关节状态表 (8个关节：Thigh/Calf)
        std::cout << "[Joint States]" << std::endl;
        std::cout << "  Leg | Thigh (Pos/Vel) | Calf (Pos/Vel)" << std::endl;
        std::cout << "  ----|-----------------|----------------" << std::endl;
        
        std::vector<std::string> leg_names = {"FL", "FR", "RL", "RR"};
        for (int i = 0; i < 4; ++i) {
            std::cout << "  " << leg_names[i] << "  | "
                    << std::setw(6) << state.joint_positions(i * 2) << " / " 
                    << std::setw(6) << state.joint_velocities(i * 2) << " | "
                    << std::setw(6) << state.joint_positions(i * 2 + 1) << " / " 
                    << std::setw(6) << state.joint_velocities(i * 2 + 1) << std::endl;
        }

        std::cout << "[Foot Vector]" << std::endl;
        



        // 3. 触地状态
        std::cout << "[Contact Status]" << std::endl;
        std::cout << "  FL: " << (state.contact_states[0] ? "● (ON)" : "○ (OFF)")
                << "  FR: " << (state.contact_states[1] ? "● (ON)" : "○ (OFF)")
                << "  RL: " << (state.contact_states[2] ? "● (ON)" : "○ (OFF)")
                << "  RR: " << (state.contact_states[3] ? "● (ON)" : "○ (OFF)") << std::endl;

        std::cout << "=====================================================" << std::endl;
}

inline Eigen::VectorXd q8toq12(const Eigen::Matrix<double,8,1>& q8) {
    Eigen::VectorXd q12(12);
    // Pinocchio: FL_hip,FL_thigh,FL_calf, FR_hip,FR_thigh,FR_calf, RL_hip,RL_thigh,RL_calf, RR_hip,RR_thigh,RR_calf
    // MuJoCo:              FL_thigh,FL_calf, FR_thigh,FR_calf, RL_thigh,RL_calf, RR_thigh,RR_calf
    q12 << 0, q8(0), q8(1),    // FL
           0, q8(2), q8(3),    // FR
           0, q8(4), q8(5),    // RL
           0, q8(6), q8(7);    // RR
    return q12;
}

inline Eigen::VectorXd v8to12(const Eigen::Matrix<double,8,1>& v8) {
    Eigen::VectorXd v12(12);
    v12 << 0, v8(0), v8(1),    // FL
           0, v8(2), v8(3),    // FR
           0, v8(4), v8(5),    // RL
           0, v8(6), v8(7);    // RR
    return v12;
}

#endif
