#ifndef __PINOCCHIO_HPP
#define __PINOCCHIO_HPP

#include <string>
#include <memory>
#include <iostream>
#include <Eigen/Dense>

// Pinocchio (ROS Humble)
#include <pinocchio/parsers/urdf.hpp>
#include <pinocchio/algorithm/kinematics.hpp>
#include <pinocchio/algorithm/frames.hpp>
#include <pinocchio/algorithm/jacobian.hpp>
#include <pinocchio/algorithm/joint-configuration.hpp>
#include <pinocchio/algorithm/crba.hpp>
#include <pinocchio/algorithm/rnea.hpp>

#include "MPC/regulator.h"  // legController 结构体

namespace Pinocchio
{

/**
 * Pinocchio 运动学封装 (四足机器人 Go2)
 *
 * 使用方式:
 *   1. 构造时传入 URDF 路径，自动加载模型
 *   2. forwardKinematics(q) 传入 12 维关节角度，更新内部状态
 *   3. getFootPosition(leg) 获取第 leg 条腿的足端在世界系下的位置
 *   4. getFootJacobian(leg) 获取足端雅可比矩阵 (3×12)
 *   5. inverseKinematics(leg, target) 数值逆解，返回关节角度
 */
class PinocchioKinematics
{
public:
    PinocchioKinematics();
    explicit PinocchioKinematics(const std::string& urdf_path);
    ~PinocchioKinematics();

    // ========== 模型加载 ==========

    /** 从 URDF 文件加载模型，返回是否成功 */
    bool loadModel(const std::string& urdf_path);

    // ========== 正运动学 (Forward Kinematics) ==========

    /**
     * 计算正运动学
     * @param q  12 维关节角度
     *   [FL_hip, FL_thigh, FL_calf, FR_hip, FR_thigh, FR_calf,
     *    RL_hip, RL_thigh, RL_calf, RR_hip, RR_thigh, RR_calf]
     */
    void forwardKinematics(const Eigen::VectorXd& q);

    /**
     * 带机身位姿的正运动学
     * @param q         12 维关节角度
     * @param base_pos  机身位置 (x, y, z)
     * @param base_quat 机身姿态四元数 (x, y, z, w)
     */
    void forwardKinematics(const Eigen::VectorXd& q,
                           const Eigen::Vector3d& base_pos,
                           const Eigen::Vector4d& base_quat);

    // ========== 正解结果查询 ==========

    /** 获取第 leg 条腿的足端位置 (世界系), leg: 0=FL, 1=FR, 2=RL, 3=RR */
    Eigen::Vector3d getFootPosition(int leg) const;

    /** 获取第 leg 条腿的足端位置 (机身 base_link 系) */
    Eigen::Vector3d getFootPositionInBase(int leg) const;

    /** 获取所有 4 足端位置 (世界系), 返回 4×3 */
    Eigen::Matrix<double, 4, 3> getAllFootPositions() const;

    /** 获取所有 4 足端位置 (机身系), 返回 4×3 */
    Eigen::Matrix<double, 4, 3> getAllFootPositionsInBase() const;
    
    
    // ========== 雅可比矩阵 ==========

    /** 获取足端平动雅可比 (3×nv), 世界系对齐 */
    Eigen::MatrixXd getFootJacobian(int leg) const;

    /** 获取足端完整雅可比 (6×nv), 含平动+转动 */
    Eigen::MatrixXd getFootJacobianFull(int leg) const;

    /**
     * 获取浮动基座足端平动雅可比 (3×18)
     * J = [I₃  -skew(p_foot - p_base)  J_joint]
     * 列顺序: 基底平动(3) + 基底转动(3) + 关节(12)
     * 需在 forwardKinematics 之后调用
     */
    Eigen::Matrix<double, 3, 18> getFootJacobianFloatingBase(int leg) const;

    /**
     * 获取足端雅可比时间导数 dJ/dt (3×nv)
     * 用于计算操作空间加速度偏置项: \ddot{x} = J*\ddot{q} + dJ*\dot{q}
     * 需在 forwardKinematics 之后、且已设置 joint velocity 时调用
     */
    Eigen::MatrixXd getFootJacobianTimeVariation(int leg) const;

    /**
     * 获取浮动基座足端雅可比时间导数 dJ/dt (3×18)
     * dJ = [0₃  -skew(v_foot - v_base)  dJ_joint]
     * 需在 forwardKinematics 之后、且已设置 joint velocity 和 base velocity 时调用
     */
    Eigen::Matrix<double, 3, 18> getFootJacobianTimeVariationFloatingBase(int leg) const;

    /**
     * 足底力 → 关节力矩: τ = J^T · f
     * @param foot_forces  12 维足底力 [FL_Fx,FL_Fy,FL_Fz, FR..., RL..., RR...]
     * @param hip_enabled  true 返回 12 维(含hip), false 返回 8 维(仅thigh+calf, MuJoCo)
     * @return 关节力矩向量
     */
    Eigen::VectorXd getJointTorques(const Eigen::Matrix<double, 12, 1>& foot_forces,
                                    bool hip_enabled = false) const;

    /**
     * WBC 解 [a; f] → 关节力矩: 浮动基座逆动力学
     * τ = (M·a + h − J^T·f) 的关节 12 行 (摆动腿靠加速度项驱动, f=0 也能动)
     * @param a  18 维广义加速度 [基底平动, 基底转动, 关节]
     * @param f  12 维足端接触力 (地面反力, 4 腿 × 3)
     * @return 8 维关节力矩 (MuJoCo 顺序, 跳过 hip: FL_thigh,FL_calf,FR_thigh,FR_calf,...)
     * 需在 computeFloatingBaseDynamics 之后调用
     */
    Eigen::VectorXd getJointTorquesFromSolution(const Eigen::Matrix<double, 18, 1>& a,
                                                const Eigen::Matrix<double, 12, 1>& f) const;

    // ========== 逆运动学 (Inverse Kinematics) ==========

    /**
     * 单腿数值逆解 (阻尼最小二乘)
     * @return 是否收敛
     */
    bool inverseKinematics(int leg,
                           const Eigen::Vector3d& target_pos,
                           const Eigen::VectorXd& q_init,
                           Eigen::VectorXd& q_out,
                           int max_iter = 100,
                           double tol = 1e-4);

    /**
     * 全身 4 腿同时逆解 (阻尼最小二乘)
     * @return 是否收敛
     */
    bool inverseKinematicsFull(const Eigen::Matrix<double, 4, 3>& targets,
                               const Eigen::VectorXd& q_init,
                               Eigen::VectorXd& q_out,
                               int max_iter = 200,
                               double tol = 1e-4);

    /**
     * 世界系 4 腿同时逆解 (阻尼最小二乘)
     * 基底位姿取上次 forwardKinematics 存储的 base_pos_/base_quat_, 无需传位姿
     * 迭代在局部 Data 上进行, 不修改内部状态 (data_/q_), 结果仅写入 q_out
     * @param targets 4 腿足端目标 (世界系, 4×3, 行序 FL,FR,RL,RR)
     * @return 是否收敛
     */
    bool inverseKinematicsFullWorld(const Eigen::Matrix<double, 4, 3>& targets,
                                    const Eigen::VectorXd& q_init,
                                    Eigen::VectorXd& q_out,
                                    int max_iter = 200,
                                    double tol = 1e-4);

    /**
     * 足端加速度 → 关节加速度 (一步线性解, 非迭代)
     * ẍ = J·q̈ + dJ·v, 基座加速度视为 0, 只解 12 维关节加速度
     * @param foot_acc_world 4 腿足端加速度 (世界系, 12 维扁平: FL,FR,RL,RR 各 3 维)
     * @param qdd_out        12 维关节加速度
     * @return 雅可比是否满秩 (不满秩时 qdd_out 置零并返回 false)
     * 需在 forwardKinematics 之后、且已设置 joint velocity / base velocity 时调用
     */
    bool footAccelerationToJointAcceleration(const Eigen::Vector<double, 12>& foot_acc_world,
                                             Eigen::VectorXd& qdd_out) const;

    // ========== 查询接口 ==========

    int getNq() const;
    int getNv() const;
    const Eigen::VectorXd& getJointConfig() const;

    /** 设置关节速度 (需在 getFootJacobianTimeVariation 之前调用) */
    void setJointVelocity(const Eigen::VectorXd& v);

    /** 获取当前关节速度 */
    const Eigen::VectorXd& getJointVelocity() const;

    /** 设置基底速度 (需在 getFootJacobianTimeVariationFloatingBase 之前调用) */
    void setBaseVelocity(const Eigen::Vector3d& base_vel, const Eigen::Vector3d& base_ang);

    /** 设置基底姿态四元数 (需在 computeFloatingBaseDynamics 之前调用) */
    void setBaseQuaternion(const Eigen::Quaterniond& quat);

    // ========== 浮动基座动力学 ==========

    /** 计算浮动基座质量矩阵 M(18×18) 和偏置力 h(18) */
    void computeFloatingBaseDynamics();

    /** 获取浮动基座质量矩阵 (18×18), 需先调 computeFloatingBaseDynamics */
    Eigen::Matrix<double, 18, 18> getMassMatrix() const;

    /** 获取偏置力 h(18) = C(q,q̇)*q̇ + g(q), 需先调 computeFloatingBaseDynamics */
    Eigen::Matrix<double, 18, 1> getBiasForces() const;

    /** 获取关节名称列表 (按内部顺序) */
    std::vector<std::string> getJointNames() const;

    /** 打印关节和 frame 信息 */
    void printJointInfo() const;

    /**
     * 获取内部 legController 数据的地址
     * 每次 forwardKinematics() 后自动更新 p(世界系 质心→足端 向量)
     * 将此指针传给 MPC::setLegData() 即可实现自动同步
     */
    Regulator::legController* getLegData();

    /**
     * 计算整机总质量与关于质心的惯性 (CRBA + CoM 平移, 在当前 q_ 配置下)
     * @param mass   输出: 总质量 (kg)
     * @param I_com  输出: 关于质心的转动惯量 (基座系, 3×3)
     * 供 MPC 简化模型替换硬编码参数 (m=12, I=(0.1,0.1,0.02) 与真机差一个量级)
     */
    void getTotalMassInertia(double& mass, Eigen::Matrix3d& I_com) const;

    // 足端 frame 名称常量
    static constexpr const char* FOOT_FL = "FL_foot";
    static constexpr const char* FOOT_FR = "FR_foot";
    static constexpr const char* FOOT_RL = "RL_foot";
    static constexpr const char* FOOT_RR = "RR_foot";

private:
    std::shared_ptr<pinocchio::Model> model_;
    std::shared_ptr<pinocchio::Data>  data_;
    
    int nq_ = 0;  // 关节位置维度 (=12)
    int nv_ = 0;  // 关节速度维度 (=12)

    Eigen::VectorXd q_;  // 当前关节位置
    Eigen::VectorXd v_;  // 当前关节速度

    Eigen::Vector3d base_pos_  = Eigen::Vector3d::Zero();  // 当前基底世界位置
    Eigen::Vector4d base_quat_ = Eigen::Vector4d(0,0,0,1); // 当前基底姿态 (x,y,z,w)
    Eigen::Vector3d base_vel_  = Eigen::Vector3d::Zero();  // 当前基底世界线速度
    Eigen::Vector3d base_ang_  = Eigen::Vector3d::Zero();  // 当前基底世界角速度

    // 浮动基座动力学缓存
    std::shared_ptr<pinocchio::Model> model_fb_;   // 带自由飞轮的模型 (nv=18)
    std::shared_ptr<pinocchio::Data>  data_fb_;
    Eigen::Matrix<double, 18, 18> M_fb_;            // 质量矩阵
    Eigen::Matrix<double, 18, 1>  h_fb_;            // 偏置力 C*q̇+g

    std::vector<std::string> foot_names_;
    std::vector<int>         foot_frame_ids_;

    // 足端数据 (供 MPC 通过指针直接读取)
    // forwardKinematics() 后自动更新
    Regulator::legController leg_data_;

    /** 去除 URDF 中引用 package:// 的 visual/collision 标签 */
    std::string stripPackageTags(const std::string& urdf_path) const;

    /** FK 后同步足端位置到 leg_data_ (供 MPC 指针读取) */
    void _syncLegData();
};

} // namespace Pinocchio

#endif
