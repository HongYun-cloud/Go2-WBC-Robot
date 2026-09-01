#ifndef _LEGCONTROLLER_HPP
#define _LEGCONTROLLER_HPP

#include "controller/regulator.h"
#include "common.h"

namespace Regulator
{

class LegController
{
public:
    LegController();
    ~LegController();

    // 正运动学: 根据关节角度计算机身质心到足端的向量 p 和足端速度 w
    // 输入: RobotState (关节角度、关节速度、机身姿态)
    // 输出: 填充私有成员 leg.p (质心→足端向量) 和 leg.w (足端角速度)
    void forwardKinematics(const RobotState& state);

    // 逆运动学: 根据足端力计算关节力矩
    // 输入: foot_forces (12维, 4条腿 × 3轴力, MPC 输出的控制量)
    // 输出: 8维关节力矩 (FL_thigh, FL_calf, FR_thigh, FR_calf, RL_thigh, RL_calf, RR_thigh, RR_calf)
    Eigen::Matrix<double, 8, 1> inverseKinematics(const Vec12d& foot_forces);

    // 获取内部 leg 数据的地址，供 MPCData 通过指针连接
    legController* getLegData() { return &leg; }

private:
    legController leg;  // 正解结果: p[4] 质心到足端向量, w[4] 足端角速度
};

} // namespace Regulator

#endif
