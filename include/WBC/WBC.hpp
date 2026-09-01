#ifndef __WBC_HPP
#define __WBC_HPP


#include "WBC_Base.h"
#include <OsqpEigen/OsqpEigen.h>
#include <yaml-cpp/yaml.h>
#include "Model/pinocchio.hpp"
#include "Estimator/PositionVelocityEstimator.hpp"
// 首先说明，wbc是全状态的空间方程，考虑到了腿的重量，科氏力等，考虑了mpc里没有考虑到的一些力
// 根据动力学方程M(q)*ddot(q) + h(q,ddot(q)) = S.transpose() * τ + J.transpose() * f
// 可以推出三个约束，融合一下变成一个Ａｘ＝ｂ格式的约束
// 目标函数有三个： 1. 浮动基座（躯干）跟踪误差 2. 跟踪 MPC 算出的力 3. 摆动腿足端空间跟踪

namespace WBC
{
    class WBC
    {
    private:
        SolutionVector task_vec; // 求解的目标向量{q,f}
        // OSQP 求解器缓存 (避免每帧重建)
        OsqpEigen::Solver _solver;
        bool _solver_initialized = false;

        CMD cmd;
        Pinocchio::PinocchioKinematics* _pin;  // Pinocchio 运动学接口
        WBCConfig* config;
        QPConstraint* qpconstraint;
        Estimator::PositionVelocityEstimator* estimator;
        std::vector<int> contact_states_;       // 接触状态缓存 (0=swing, 1=stance)
        Eigen::Matrix<double, 18, 1> v_full_;   // 全状态速度缓存
        // OSQP 存裸指针, q/l/u 必须是持久对象 (c_float = double), 不能用局部变量
        // (updateLinearConstraintsMatrix 在稀疏模式变化时会自动重建求解器)
        Eigen::VectorXd osqp_gradient_;
        Eigen::VectorXd osqp_lower_;
        Eigen::VectorXd osqp_upper_;
        void compuseHg();
        void updateconstraint();
    public:
        /** 初始化 WBC 约束矩阵, 需在 setPinocchio() 之后调用 */
        void init();
        void solve();
        void update(Vec18d& q,Vec12d& f,Vec12d& a,RobotState state);
        void GetSolution(SolutionVector& result);
        /** 从 yaml 加载 W, FI, C 权重 */
        void loadConfig(const std::string& yaml_path);
        /** 设置 Pinocchio 运动学指针 (必须在 init 之前调用) */
        void setPinocchio(Pinocchio::PinocchioKinematics* pin) { _pin = pin; }

        WBC(Estimator::PositionVelocityEstimator *extern_estimator);
        ~WBC();
    };

} // namespace WBC


#endif
