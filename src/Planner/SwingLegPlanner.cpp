#include "Planner/SwingLegPlanner.hpp"

namespace SwingPlanner
{

// Go2 髋部 (大腿关节) 相对机身中心的偏移, 取自 go2_description.urdf
const std::array<Point,4> HIP_OFFSET = {
    Point{ 0.1934,  0.1420, 0.0},   // FL
    Point{ 0.1934, -0.1420, 0.0},   // FR
    Point{-0.1934,  0.1420, 0.0},   // RL
    Point{-0.1934, -0.1420, 0.0}    // RR
};

SwingLegPlanner::SwingLegPlanner(std::shared_ptr<Gait::GaitScheduler> scheduler,
                std::shared_ptr<Estimator::PositionVelocityEstimator> estimator)
                : _scheduler(scheduler), _estimator(estimator)
{
    Walk_H = 0.15;  // 抬腿高度 (m)
    _foot_vel.setZero();
    _foot_acc.setZero();
    for (int leg = 0; leg < 4; leg++) {
        offset[leg].setZero();
        _last_phase[leg] = 0.0;
        // 默认站立足端: 髋正下方 0.25 m (与仿真初始机身高度对应, 后续被 FK 覆盖)
        _foot_pos.row(leg) = (HIP_OFFSET[leg] + Point{0,0,-0.25}).transpose();
        // 初始站立轨迹: 停留在原地的一条抬腿曲线
        control_point[leg].Start_Point = _foot_pos.row(leg).transpose();
        control_point[leg].End_Point   = control_point[leg].Start_Point;
        control_point[leg].Mid_Point.push_back(control_point[leg].Start_Point + Point{0,0,Walk_H} + offset[leg]);
        control_point[leg].Mid_Point.push_back(control_point[leg].End_Point   + Point{0,0,Walk_H} + offset[leg]);
    }
}

SwingLegPlanner::~SwingLegPlanner() {}

void SwingLegPlanner::SetFootPositions(const Eigen::Matrix<double,4,3>& foot_pos){
    _foot_pos = foot_pos;
}

void SwingLegPlanner::Reset(){
    // 步态切换时重置: 控制点退回当前足端位置, 相位记录清零
    for (int leg = 0; leg < 4; leg++) {
        _last_phase[leg] = 0.0;
        control_point[leg].Start_Point = _foot_pos.row(leg).transpose();
        control_point[leg].End_Point   = _foot_pos.row(leg).transpose();
        control_point[leg].Mid_Point.clear();
        control_point[leg].Mid_Point.push_back(control_point[leg].Start_Point + Point{0,0,Walk_H} + offset[leg]);
        control_point[leg].Mid_Point.push_back(control_point[leg].End_Point   + Point{0,0,Walk_H} + offset[leg]);
    }
}

void SwingLegPlanner::Generate(Velocity& v_des,std::function<double(size_t)> phase_func)
{
    double k = 0.2;             // Raibert 落脚点启发式: 速度误差增益

    // phase_func(leg) 返回腿 leg 的摆动相位 [0, 1)
    // 支撑期返回 0, 摆动期 (0, 1)



    double T_stance = _scheduler->GetStanceTime();
    double T_swing  = _scheduler->GetSwingTime();
    auto est = _estimator->get_estresult();
    Velocity v_actual = est.v;

    // 机身姿态旋转矩阵 (世界系,roll-pitch-yaw)
    Eigen::Matrix3d R =
        (Eigen::AngleAxisd(est.q(2), Eigen::Vector3d::UnitZ()) *
         Eigen::AngleAxisd(est.q(1), Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(est.q(0), Eigen::Vector3d::UnitX())).toRotationMatrix();

    for (int leg = 0; leg < 4; leg++) {
        double t = phase_func(leg);

        // 抬腿边沿: 只在此刻一次性算好落脚点, 摆动中不再重规划
        bool lift_off = (_last_phase[leg] == 0.0 && t > 0.0);
        if (lift_off) {
            control_point[leg].Start_Point = _foot_pos.row(leg).transpose();  // 摆动前一刻的足端点
            control_point[leg].Mid_Point.clear();
            control_point[leg].Mid_Point.push_back(control_point[leg].Start_Point + Point{0,0,Walk_H} + offset[leg]);

            Point p_hip = est.p + R * HIP_OFFSET[leg];  // 髋部世界系位置
            control_point[leg].End_Point = p_hip + (T_stance / 2) * v_actual + k * (v_actual - v_des);
            control_point[leg].End_Point(2) = 0.023;      // 世界坐标系地面高度
            // 覆盖 xy: 以起点为基准 + 期望速度 × 摆动时间, 避免原地踏步时 x 方向加速度突变
            // control_point[leg].End_Point(0) = control_point[leg].Start_Point(0) + v_des(0) * T_swing;
            // control_point[leg].End_Point(1) = control_point[leg].Start_Point(1) + v_des(1) * T_swing;
            control_point[leg].Mid_Point[1] = control_point[leg].End_Point + Point{0,0,Walk_H} + offset[leg];
        }

        Point p = Bezier_Math::evaluatePos(t, control_point[leg]);
        Point v = Bezier_Math::evaluateVel(t, control_point[leg]);
        Point a = Bezier_Math::evaluateAcc(t, control_point[leg]);
        a = a / (T_swing * T_swing);
        if (t == 0.0) {  // 支撑期: 指令速度/加速度置零 (摆动曲线边界值不应作用于支撑腿)
            v.setZero();
            a.setZero();
        }

        _foot_pos.row(leg) = p.transpose();  // 记录指令足端位置
        pos = _foot_pos;
        _foot_vel.row(leg) = v.transpose();  // 记录指令足端位置
        vel = _foot_vel;
        _foot_acc.row(leg) = a.transpose();  // 记录指令足端位置
        acc = _foot_acc;
        
        _last_phase[leg] = t;


    }


}

DesPoint SwingLegPlanner::GetSwingPos(){
    return pos;
}

DesPoint SwingLegPlanner::GetSwingVel(){
    return vel;
}

DesPointVec SwingLegPlanner::GetSwingAccVec(){
    DesPointVec a;
    for (int i = 0; i < 4; ++i)
        a.segment<3>(i*3) = acc.row(i);
    return a;
}

Point Bezier_Math::evaluatePos(double t,const Control_Point P_control){
    Point start = P_control.Start_Point;
    Point end = P_control.End_Point;
    std::vector<Point> mid = P_control.Mid_Point;
    int degree = mid.size();
    Point p;
    if (degree == 1){ // 二阶
        p = pow((1 - t),2) * start + 2 * t * (1 - t) * mid[0] + pow(t,2) * end;
    } 
    else if (degree == 2) // 三阶
    {
        p = pow((1 - t),3) * start + 3 * t * pow((1 - t),2) * mid[0] + 3 * pow(t,2) * (1 - t) * mid[1] + pow(t,3) * end;
    }
    else if (degree == 3) // 四阶
    {
        // 待续
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluatePos: 不支持的阶数 " << degree << std::endl;
        return Point::Zero();
    }
    return p;
}

Point Bezier_Math::evaluateVel(double t,const Control_Point P_control){
    Point start = P_control.Start_Point;
    Point end = P_control.End_Point;
    std::vector<Point> mid = P_control.Mid_Point;
    int degree = mid.size();
    Point v;
    if (degree == 1){ // 二阶
        v = 2 * (1 - t) * (mid[0] - start) + 2 * t * (end - mid[0]);
    }
    else if (degree == 2) // 三阶
    {
        v = 3 * pow((1 - t),2) * (mid[0] - start) + 6 * t * (1 - t) * (mid[1] - mid[0]) + 3 * pow(t,2) * (end - mid[1]);
    }
    else if (degree == 3) // 四阶
    {
        v = 4 * pow((1 - t),3) * (mid[0] - start)
          + 12 * t * pow((1 - t),2) * (mid[1] - mid[0])
          + 12 * pow(t,2) * (1 - t) * (mid[2] - mid[1])
          + 4 * pow(t,3) * (end - mid[2]);
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluateVel: 不支持的阶数 " << degree << std::endl;
        return Point::Zero();
    }
    return v;
}

Point Bezier_Math::evaluateAcc(double t,const Control_Point P_control){
    Point start = P_control.Start_Point;
    Point end = P_control.End_Point;
    std::vector<Point> mid = P_control.Mid_Point;
    int degree = mid.size();
    Point a;
    if (degree == 1){ // 二阶
        a = 2 * (start - 2 * mid[0] + end);
    }
    else if (degree == 2) // 三阶
    {
        a = 6 * (1 - t) * (start - 2 * mid[0] + mid[1]) + 6 * t * (mid[0] - 2 * mid[1] + end);
    }
    else if (degree == 3) // 四阶
    {
        // [S, M0, M1, M2, E] = [S, S, S+H, E+H, E] 时:
        //   a(0) = 12(M1-2M0+S) = +12H (起摆加速向上)
        //   a(1) = 12(E-2M2+M1) = -12H (落地加速向下)
        a = 12 * pow((1 - t),2) * (mid[1] - 2 * mid[0] + start)
          + 24 * t * (1 - t) * (mid[2] - 2 * mid[1] + mid[0])
          + 12 * pow(t,2) * (end - 2 * mid[2] + mid[1]);
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluateAcc: 不支持的阶数 " << degree << std::endl;
        return Point::Zero();
    }
    return a;
}
} // namespace SwingPlanner
