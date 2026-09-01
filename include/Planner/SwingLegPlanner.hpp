#ifndef __SWINGPLANNER_HPP
#define __SWINGPLANNER_HPP
// 这个头文件用来规划摆动腿的轨迹

#include <iostream>
#include "common.h"
#include <functional>
#include <memory>
#include <Eigen/Dense>
#include "Planner/GaitScheduler.hpp"
#include "Estimator/PositionVelocityEstimator.hpp"
#include <math.h>
namespace SwingPlanner
{
    using Point = Eigen::Vector3d;
    using DesPoint = Eigen::Matrix<double,4,3>;
    using DesPointVec = Eigen::Vector<double,12>;
    class Bezier_Math
    {
        public:
            struct Control_Point{
                Point Start_Point;
                std::vector<Point> Mid_Point;  // 便于以后扩展成多阶贝塞尔
                Point End_Point;
            };


            static Point evaluatePos(double t,const Control_Point P_control);
            static Point evaluateVel(double t,const Control_Point P_control);
            static Point evaluateAcc(double t,const Control_Point P_control);

    };

    class SwingLegPlanner
    {
    private:
        std::shared_ptr<Gait::GaitScheduler> _scheduler;
        std::shared_ptr<Estimator::PositionVelocityEstimator> _estimator;
        double phase_;
        double Walk_H;
        std::array<Point,4> offset;

        DesPoint pos;
        DesPoint vel;
        DesPoint acc;
        Bezier_Math::Control_Point control_point[4];

        std::array<double,4> _last_phase;             // 上一周期的摆动相位, 用于抬腿边沿检测
        DesPoint _foot_pos;          // 当前足端位置 (世界系, 行序 FL,FR,RL,RR)
        DesPoint _foot_vel;
        DesPoint _foot_acc;

    public:
        // phase_func(leg) → 摆动相位 [0,1), 4 条腿各不同
        void Generate(Point& v_des,std::function<double(size_t)> phase_func);
        DesPoint GetSwingPos();
        DesPoint GetSwingVel();
        DesPointVec GetSwingAccVec();
        void SetFootPositions(const Eigen::Matrix<double,4,3>& foot_pos);  // FK 更新实际足端位置
        void Reset();                                                     // 步态切换时重置轨迹状态
        SwingLegPlanner(std::shared_ptr<Gait::GaitScheduler> scheduler,std::shared_ptr<Estimator::PositionVelocityEstimator> estimator);
        ~SwingLegPlanner();
    };
} // namespace SwingPlanner


#endif