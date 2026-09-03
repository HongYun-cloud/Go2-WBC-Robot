#ifndef __GO2_CONTROL_NODE_HPP
#define __GO2_CONTROL_NODE_HPP
// Go2 ROS 2 控制节点: 封装原 main.cpp 的全部控制逻辑
//
// 线程模型 (时序与周期管理, 迁移重点):
//   ┌─ WBC 主控制循环 (wbc_timer_, 500Hz, executor 主线程)
//   │    FSM → MuJoCo 状态 → 估计器/FK → WBC QP → 关节力矩 → mj_step/Render
//   │    GLFW 窗口在主线程创建, Render 必须留在本线程
//   ├─ MPC 异步线程 (mpc_thread_, 100Hz, std::thread)
//   │    mpc->update() + solve() → f_mpc 双缓冲交换
//   │    QP 求解 (N=20, 240 变量) 耗时 > 2ms, 绝不能放在 500Hz 循环里
//   └─ 发布定时器 (pub_timer_, 50Hz): odom / joint_states / 足端力, 序列化不占实时循环
//
// 线程安全 (原类代码零修改, 锁全部在节点层):
//   estimator_mutex_  : estimator 的 update(WBC写) ↔ get_estresult(MPC读)
//   fk_mpc_mutex_     : pinocchio legData 裸指针 (MPC ConfigUpdata 读 ↔ WBC forwardKinematics 写)
//                       同一把锁保护 MPC::update() 整段 (含 compuseEGH 读共享数据)
//                       MPC::solve() 只碰 OSQP 内部状态 → 不持锁
//   cmd_mutex_        : /cmd_vel 回调 (executor 线程) ↔ WBC 循环读 v
//   f_mpc_            : std::shared_ptr 双缓冲, 原子换指针, 读写永不互等
//
// 析构顺序 (成员声明顺序, 倒序销毁): mpc 必须先于 estimator 死亡
//   (MPC 析构会 delete estimator 裸指针, 原代码行为, 不可修改)

#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <sensor_msgs/msg/joint_state.hpp>
#include <std_msgs/msg/float64_multi_array.hpp>
#include "go2_robot/msg/go2_telemetry.hpp"

#include <thread>
#include <mutex>
#include <atomic>
#include <memory>

#include "common.h"
#include "SIM/MJCsim.hpp"
#include "MPC/MPC.hpp"
#include "Model/pinocchio.hpp"
#include "WBC/WBC.hpp"
#include "fsm/ControlFSM.hpp"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"
#include "Estimator/PositionVelocityEstimator.hpp"

namespace go2
{

class Go2ControlNode : public rclcpp::Node
{
public:
    Go2ControlNode();
    ~Go2ControlNode() override;

private:
    // ===== 原有对象 (原 main.cpp 中的变量名原样保留为成员) =====
    std::shared_ptr<Gait::GaitScheduler> scheduler;
    std::shared_ptr<Estimator::PositionVelocityEstimator> estimator;  // 见析构顺序注释
    std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory;

    std::unique_ptr<fsm::ControlFSM> fsm;
    MJCSIM::SIM* mj;                 // 原裸指针保留 (Render 需要窗口线程)
    Pinocchio::PinocchioKinematics* pin;
    Regulator::MPC* mpc;
    WBC::WBC* wbc;

    // ===== 主循环状态 (原 main.cpp 循环变量原样迁入) =====
    Eigen::Vector3d v, w, q, p;
    double sim_dt;
    int count = 0;

    // 足端实际加速度 (世界系): v_foot_act 数值微分
    Eigen::Matrix<double, 12, 1> v_foot_prev = Eigen::Matrix<double, 12, 1>::Zero();
    Eigen::Matrix<double, 12, 1> a_foot_act  = Eigen::Matrix<double, 12, 1>::Zero();
    bool have_prev_v = false;

    // ===== MPC ↔ WBC 交换 (双缓冲, 原子指针交换) =====
    // MPC 线程产出一个不可变快照, WBC 线程原子取走, 无锁
    struct FmpcSnapshot {
        Eigen::Matrix<double, 12, 1> f;
        bool valid = false;
    };
    std::shared_ptr<const FmpcSnapshot> f_mpc_buf_;   // const: 发布后不可变
    std::mutex f_mpc_mutex_;                          // 只保护指针本身 (纳秒级)

    // ===== 线程基础设施 =====
    std::thread mpc_thread_;
    std::atomic<bool> mpc_running_{false};

    std::mutex estimator_mutex_;   // estimator->update ↔ get_estresult
    std::mutex fk_mpc_mutex_;      // FK 写 legData ↔ MPC::update 读 legData 裸指针
    std::mutex cmd_mutex_;         // cmd_vel 回调写 v ↔ WBC 循环读 v

    // ===== ROS 2 接口 =====
    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr foot_force_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;
    rclcpp::Publisher<go2_robot::msg::Go2Telemetry>::SharedPtr telemetry_pub_;

    rclcpp::TimerBase::SharedPtr wbc_timer_;   // 500Hz 主控制循环
    rclcpp::TimerBase::SharedPtr pub_timer_;   // 50Hz  状态发布

    // ===== 发布缓存 (WBC 循环写, pub 定时器读) =====
    nav_msgs::msg::Odometry   odom_msg_;
    sensor_msgs::msg::JointState   joint_msg_;
    std_msgs::msg::Float64MultiArray force_msg_;
    go2_robot::msg::Go2Telemetry telemetry_msg_;
    std::mutex state_msg_mutex_;

    // ===== 原初始化段 (构造函数里按原顺序调用) =====
    void initControlStack();        // 对应 main() 的对象创建 + 首帧初始化
    void startTimersAndThreads();

    // ===== 核心函数: 原 while(1) 体拆分, 内部算法逻辑零修改 =====
    void wbcControlLoop();          // 500Hz: 原 while(1) 主体
    void mpcSolveLoop();            // MPC 线程: mpc->update + solve → 双缓冲
    void publishState();            // 50Hz:  从快照发布 odom/joint/力
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);  // 替代键盘 w/s

    // 原循环内的功能段 (拆成私有函数便于阅读, 代码原样)
    void computeFootKinematics(RobotState& state);       // FK + 足端速度/加速度
    Eigen::Matrix<double, 12, 1> computeSwingAccDes(const RobotState& state);  // 加速度层阻抗
    void fillTelemetryMessage(const Eigen::Matrix<double,4,3>& p_ref,
                          const Eigen::Matrix<double,4,3>& p_act,
                          const Eigen::Matrix<double,4,3>& v_ref,
                          const Eigen::Matrix<double,12,1>& v_foot_act,
                          const Eigen::Matrix<double,12,1>& a_des,
                          const Eigen::Matrix<double,12,1>& f_mpc,
                          const Eigen::Matrix<double,12,1>& f_wbc,
                          const RobotState& state);    // Telemetry message filling
};

} // namespace go2

#endif
