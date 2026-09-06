#ifndef __WBCBASE_H
#define __WBCBASE_H

#include <iostream>
#include "Eigen/Dense"
namespace WBC
{
    using Mat30d = Eigen::Matrix<double,30,30>;
    using Mat18d = Eigen::Matrix<double,18,18>;
    using Mat12d = Eigen::Matrix<double,12,12>;

    
    using WA = Eigen::Matrix<double,18,30>;
    using WB = Eigen::Vector<double,18>;
    using BA = Eigen::Matrix<double,12,30>;   // f 跟踪: 12 行 = 4 腿 × 3 维力
    using BB = Eigen::Vector<double,12>;
    using CA = Eigen::Matrix<double,30,30>;   // 摆动腿足端跟踪(行0-11) + 动力学软约束(行12-29)
    using CB = Eigen::Vector<double,30>;      // 摆动腿 12 维 + 动力学 18 维

    using Vec30d = Eigen::Vector<double,30>;
    using Vec18d = Eigen::Vector<double,18>;
    using Vec12d = Eigen::Vector<double,12>;
    using Vec3d  = Eigen::Vector3d;

    using ContactJac =  Eigen::Matrix<double,18,12>;
    using SolutionVector = Eigen::Vector<double,30>;
    using SolAcc = Eigen::Vector<double,18>;
    using SolForce = Eigen::Vector<double,12>;
    using BounderVector = Eigen::Vector<double,30>;

    // QP 约束总行数: 18(保留) + 12(腿级: 支撑不打滑/摆动 f=0) + 20(摩擦锥, 4腿×5行)
    using QPAMat = Eigen::Matrix<double,50,30>;
    using QPBVec = Eigen::Matrix<double,50,1>;


    struct QPConstraint {
        QPAMat A;       // 约束矩阵
        QPBVec lower;   // 下界 (lower bound)
        QPBVec upper;   // 上界 (upper bound)
        double mu = 0.5;        // 摩擦系数 (与 MPC QPConstraint 一致)
        double fz_max = 200.0;  // 支撑腿法向力上限 (与 MPC 一致)
    };

    struct CMD
    {
        Vec18d q_d;                     // 12维的关节加速度（ ）
        Vec12d f_d;                     // 12维的足端力（mpc计算得出）
        Eigen::Vector<double, 12> a_d;  // 4 腿 × 3 维足端加速度(轨迹规划得出)
    };
    
    struct WBCConfig{
        WA A_q;
        WB b_q;

        BA A_f;
        BB b_f;

        CA A_a;
        CB b_a;
        Mat30d H;
        Vec30d g;

        Mat18d W;   // 跟踪关节加速度 (18×18)
        Mat12d FI;  // 跟踪 MPC 算出的力 (12×12)
        Mat30d C;   // 摆动腿足端跟踪(12) + 动力学软约束(18) (30×30)
        WBCConfig(){
            A_q.setZero();
            b_q.setZero();
            A_f.setZero();
            b_f.setZero();
            A_a.setZero();
            b_a.setZero();
            W.setZero();
            FI.setZero();
            C.setZero();
            H.setZero();
            g.setZero();
        }
    };

    
} // namespace WBC








#endif