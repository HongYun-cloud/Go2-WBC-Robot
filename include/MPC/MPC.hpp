#ifndef _MPC_HPP_
#define _MPC_HPP


#include "regulator.h"
#include <OsqpEigen/OsqpEigen.h>
#include <unsupported/Eigen/MatrixFunctions>
#include "Estimator/PositionVelocityEstimator.hpp"
#include <vector>

namespace Regulator{


class MPC{
    public:
        MPC(Estimator::PositionVelocityEstimator *extern_estimator){
            controller = new MPCContorller();
            controller->config = new MPCConfig();
            controller->data   = new MPCData();
            _qpconstraint = new QPConstraint(controller->config->N);
            params   = new ModelPARAMS();
            
            estimator = extern_estimator;

            params->mass = 12.0; // kg
            params->I << 0.1,  0.0,  0.0,
                         0.0,  0.1,  0.0,
                         0.0,  0.0,  0.02;
        }

        ~MPC(){

            delete controller->config;
            delete controller->data;
            delete controller;
            delete params;
            delete estimator;
        }

        void ConfigUpdata();
        void loadConfig(const std::string& yaml_path);
        void update();
        void solve();
        void run();
        void update_DesireStateCommand(Vec3d q,Vec3d p,Vec3d v,Vec3d w);
        void update_reference_trajectory();
        Vec12d getControl();

        // 连接 pin 的 leg 数据地址到 MPCData
        // 这个数据在mpc里为足端向量和足端角速度
        void setLegData(legData* leg_ptr){
            controller->data->leg = leg_ptr;
        }

        /** 用 URDF 真值替换硬编码模型参数 (质量/质心惯性) */
        void setModelParams(double mass, const Eigen::Matrix3d& I_com);

        /**
         * 设置预测时域内的滚动接触序列 (N*4 平铺, 1=支撑 0=摆动)
         * 由 GaitScheduler::GetContactSchedule 生成; 未设置时回退到复制当前接触
         */
        void setContactSchedule(const std::vector<int>& sched);

        double getDt() const { return controller->config->dt; }
        int    getHorizonN() const { return controller->config->N; }

    private:
        double gravity = -9.81;
        MPCContorller* controller;
        QPConstraint* _qpconstraint;
        ModelPARAMS*   params;
        Estimator::PositionVelocityEstimator* estimator;
        std::vector<int> contact_sched_;   // 滚动接触预测缓存 (4*N)

        // OSQP 求解器缓存 (避免每帧重建)
        OsqpEigen::Solver _solver;
        bool _solver_initialized = false;
        
    private:
        void compuseEGH();
};



};



#endif