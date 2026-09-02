#ifndef _REGULATOR__HPP
#define _REGULATOR__HPP

#include <iostream>
#include <math.h>
#include <Eigen/Dense>
#include <yaml-cpp/yaml.h>
#include "Estimator/ConvertEstimator.h"

namespace Regulator{
    
using Vec13d = Eigen::Vector<double,13>;
using Mat13d = Eigen::Matrix<double,13,13>;
using Vec12d = Eigen::Vector<double,12>;
using Mat12d = Eigen::Matrix<double,12,12>;
using Mat132d = Eigen::Matrix<double,13,12>;
using Mat3d = Eigen::Matrix3d;
using Mat4d = Eigen::Matrix4d;
using Vec4d = Eigen::Vector4d;
using Vec3d = Eigen::Vector3d;

constexpr double mu = 0.5;

struct DesireCMD{
    Vec3d q;
    Vec3d p;
    Vec3d v;
    Vec3d w;
};

struct legData{
    std::array<Vec3d,4> p;  // 质心到足端的向量
    std::array<Vec3d,4> w;  // 足端角速度
};

struct MPCData{
    Vec13d state;           // error of yaw,pitch,roll,x,y,z,wx,wy,wz,vx,vy,vz
    Vec12d control;         // f1,f2,f3,f4
    Vec13d desireState;     // yaw,pitch,roll,x,y,z,wx,wy,wz,vx,vy,vz
    DesireCMD state_Cmd;
    legData* leg = nullptr;  // 指向 LegController 内部 leg 的地址
    Estimator::ConvertEstimatorForMPC est_state ;
    MPCData(){
        desireState.setZero();
        control.setZero();
    }

};  




struct ModelPARAMS{
    double mass;
    Mat3d I;
};

struct MPCConfig
{
    Mat13d  A;
    Mat132d B;

    Mat13d  Q; // 目标代价
    Mat12d  R; // 输入代价
    Mat13d  P; // 终端代价
    int     N; // 预测区间
    Eigen::MatrixXd G;  // Hessian
    Eigen::MatrixXd E;  // gradient
    Eigen::MatrixXd H;  // constraint
    double dt = 0.02;
    MPCConfig(){
        A.setZero();
        B.setZero();
        Q.setIdentity();
        R.setIdentity();
        P.setIdentity();
        N = 10;
    }
};

struct MPCContorller{
    MPCConfig* config;
    MPCData*   data;
};



inline Mat3d Eular2Rotation(double roll){
    Mat3d R;
    R << 1,         0,          0,
         0,  cos(roll), -sin(roll),
         0,  sin(roll),  cos(roll);
    return R;
}

inline Mat3d SkewSymmetric(const Vec3d& v){
    Mat3d S;
    S << 0,    -v(2),  v(1),
            v(2),  0,    -v(0),
        -v(1),  v(0),  0;
    return S;
}


}

class QPConstraint{
    public:
        Eigen::MatrixXd A_constraint;
        Eigen::VectorXd L_constraint;
        Eigen::VectorXd U_constraint;

        double mu = 0.5;
        double fz_min = 0;
        double fz_max = 200;

        QPConstraint(){
            A_constraint.resize(200, 120);
            L_constraint.resize(200);
            U_constraint.resize(200);

            A_constraint.setZero();
            L_constraint.setConstant(-1e10);   // OSQP 兼容的大负数 (不用 -INFINITY)
            U_constraint.setZero();

            Eigen::Matrix<double, 5, 3> A_leg;
            A_leg <<  1,  0, -mu,
                    -1,  0, -mu,
                    0,  1, -mu,
                    0, -1, -mu,
                    0,  0,   1;
            Eigen::Matrix<double, 5, 1> L_leg;
            L_leg << -1e10, -1e10, -1e10, -1e10, fz_min;
            Eigen::Matrix<double, 5, 1> U_leg;
            U_leg << 0, 0, 0, 0, fz_max;

            for (int j = 0; j < 10; j++) {
                for (int i = 0; i < 4; ++i) {
                    A_constraint.block<5, 3>(j * 20 + i * 5, j * 12 + i * 3) = A_leg;
                }
            }
            // 初始化 L 和 U 为全支撑状态
            std::vector<int> all_contact(40, 1);
            updateConstraints(all_contact);

        }

        void updateConstraints(const std::vector<int>& contact_states) {
            // 健壮性检查
            if (contact_states.size() < 40) return; 

            for (int j = 0; j < 10; ++j) {       // 遍历时间步
                for (int i = 0; i < 4; ++i) {   // 遍历每条腿
                    int leg_idx = j * 4 + i;    // 在 contact_states 中的索引 (0~39)
                    int row_idx = j * 20 + i * 5; // 在 L/U 向量中的起始行索引 (0, 5, 10...195)

                    if (contact_states[leg_idx] == 1) {
                        // 支撑腿：恢复正常的摩擦锥和法向力范围
                        L_constraint.segment<4>(row_idx).setConstant(-1e10);
                        U_constraint.segment<4>(row_idx).setZero();
                        L_constraint(row_idx + 4) = fz_min;
                        U_constraint(row_idx + 4) = fz_max;
                    }
                    else {
                        // 摆动腿：通过限制 fz 的上下界为 0 来迫使 fx, fy 也必须为 0
                        L_constraint.segment<4>(row_idx).setConstant(-1e10);
                        U_constraint.segment<4>(row_idx).setZero();
                        L_constraint(row_idx + 4) = 0.0;
                        U_constraint(row_idx + 4) = 0.0;
                    }
                }
            }
        }
};


#endif