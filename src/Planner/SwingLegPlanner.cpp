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
    // 抬腿高度: 根据 T_swing 自适应, 使垂直加速度不超过物理可行范围
    // z 为分段 min-jerk: a_z_max = 23.09 * Walk_H / T_swing², 约束 a_z_max ≤ 15 m/s²
    _foot_vel.setZero();
    _foot_acc.setZero();
    for (int leg = 0; leg < 4; leg++) {
        offset[leg].setZero();
        _last_phase[leg] = 0.0;
        _swing_y[leg] = 0.0;
        // 默认站立足端: 髋正下方 0.25 m (与仿真初始机身高度对应, 后续被 FK 覆盖)
        _foot_pos.row(leg) = (HIP_OFFSET[leg] + Point{0,0,-0.25}).transpose();
        // 初始站立轨迹: 停留在原地的一条抬腿曲线
        control_point_x[leg].Start_Point = _foot_pos.row(leg).transpose().x();
        control_point_x[leg].End_Point   = control_point_x[leg].Start_Point;
        control_point_x[leg].Mid_Point.assign({control_point_x[leg].Start_Point + offset[leg].x(),
                                               control_point_x[leg].End_Point   + offset[leg].x()});

        // z_up: 五阶 min-jerk, 两端速度/加速度为零
        control_point_z_up[leg].Start_Point = _foot_pos.row(leg).transpose().z();
        control_point_z_up[leg].End_Point   = control_point_z_up[leg].Start_Point + 0.08 + offset[leg].z();
        control_point_z_up[leg].Mid_Point.assign({control_point_z_up[leg].Start_Point,
                                                  control_point_z_up[leg].Start_Point,
                                                  control_point_z_up[leg].End_Point,
                                                  control_point_z_up[leg].End_Point});

        // z_down: 五阶 min-jerk, 顶点 → 地面
        control_point_z_down[leg].Start_Point = control_point_z_up[leg].End_Point;
        control_point_z_down[leg].End_Point   = control_point_z_up[leg].Start_Point;
        control_point_z_down[leg].Mid_Point.assign({control_point_z_down[leg].Start_Point,
                                                    control_point_z_down[leg].Start_Point,
                                                    control_point_z_down[leg].End_Point,
                                                    control_point_z_down[leg].End_Point});
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
        _swing_y[leg] = _foot_pos.row(leg).transpose().y();
        control_point_x[leg].Start_Point = _foot_pos.row(leg).transpose().x();
        control_point_x[leg].End_Point   = control_point_x[leg].Start_Point;
        control_point_x[leg].Mid_Point.assign({control_point_x[leg].Start_Point + offset[leg].x(),
                                               control_point_x[leg].End_Point   + offset[leg].x()});

        control_point_z_up[leg].Start_Point = _foot_pos.row(leg).transpose().z();
        control_point_z_up[leg].End_Point   = control_point_z_up[leg].Start_Point + 0.08 + offset[leg].z();
        control_point_z_up[leg].Mid_Point.assign({control_point_z_up[leg].Start_Point,
                                                  control_point_z_up[leg].Start_Point,
                                                  control_point_z_up[leg].End_Point,
                                                  control_point_z_up[leg].End_Point});

        control_point_z_down[leg].Start_Point = control_point_z_up[leg].End_Point;
        control_point_z_down[leg].End_Point   = control_point_z_up[leg].Start_Point;
        control_point_z_down[leg].Mid_Point.assign({control_point_z_down[leg].Start_Point,
                                                    control_point_z_down[leg].Start_Point,
                                                    control_point_z_down[leg].End_Point,
                                                    control_point_z_down[leg].End_Point});
    }
}

void SwingLegPlanner::Generate(Velocity& v_des,std::function<double(size_t)> phase_func)
{
    double k = 0.05;             // Raibert 落脚点启发式: 速度误差增益

    // phase_func(leg) 返回腿 leg 的摆动相位 [0, 1)
    // 支撑期返回 0, 摆动期 (0, 1)



    double T_stance = _scheduler->GetStanceTime();
    double T_swing  = _scheduler->GetSwingTime();
    // 自适应步高: z 为分段 min-jerk (前 0.5T 上升, 后 0.5T 下降),
    // 峰值垂直加速度 a_z = 5.7735*H/(0.5*T_swing)² = 23.09*H/T_swing², 约束 a_z ≤ 15 m/s²
    auto est = _estimator->get_estresult();
    // Walk_H = std::min(0.05, 15.0 * T_swing * T_swing / 23.09);
    Walk_H = 0.07;
    Velocity v_actual = est.v;

    // 机身姿态旋转矩阵 (世界系,roll-pitch-yaw)
    Eigen::Matrix3d R =
        (Eigen::AngleAxisd(est.q(2), Eigen::Vector3d::UnitZ()) *
         Eigen::AngleAxisd(est.q(1), Eigen::Vector3d::UnitY()) *
         Eigen::AngleAxisd(est.q(0), Eigen::Vector3d::UnitX())).toRotationMatrix();

    for (int leg = 0; leg < 4; leg++) {
        double t = phase_func(leg);

        // 抬腿边沿: 只在此刻一次性算好落脚点,
        bool lift_off = (_last_phase[leg] == 0.0 && t > 0.0);
        if (lift_off) {
            control_point_x[leg].Mid_Point.clear();
            control_point_z_up[leg].Mid_Point.clear();
            control_point_z_down[leg].Mid_Point.clear();

            control_point_x[leg].Start_Point = _foot_pos.row(leg).transpose().x();  // 摆动前一刻的足端点
            control_point_x[leg].Mid_Point.push_back(control_point_x[leg].Start_Point + offset[leg].x());

            control_point_z_up[leg].Start_Point = _foot_pos.row(leg).transpose().z();  // 摆动前一刻的足端点
            
            control_point_z_up[leg].Mid_Point.push_back(0.023);
            control_point_z_up[leg].Mid_Point.push_back(0.023);
            control_point_z_up[leg].Mid_Point.push_back(Walk_H + offset[leg].z());
            control_point_z_up[leg].End_Point = Walk_H + offset[leg].z();

            control_point_z_down[leg].Start_Point = control_point_z_up[leg].End_Point;
            control_point_z_down[leg].Mid_Point.push_back(Walk_H + offset[leg].z());
            control_point_z_down[leg].Mid_Point.push_back(0.023);
            control_point_z_down[leg].Mid_Point.push_back(0.023);
            control_point_z_down[leg].End_Point   = 0.023;

            Point p_hip = est.p + R * HIP_OFFSET[leg];  // 髋部世界系位置
            control_point_x[leg].End_Point = p_hip[0] + (T_stance / 2) * v_actual.x() + k * (v_actual.x() - v_des.x());

            // 落脚点 x 不下于髋部, 防止起步时 v_actual≈0 落脚点在髋后 → 前倾摔倒
            if (control_point_x[leg].End_Point < p_hip(0))
                control_point_x[leg].End_Point = p_hip(0);
            control_point_x[leg].Mid_Point.push_back(control_point_x[leg].End_Point + offset[leg].x());

            // y 全程保持抬腿前的足端位置
            _swing_y[leg] = _foot_pos.row(leg).transpose().y();
        }

        // x: 三阶贝塞尔, 时间 0~T
        double p_x = Bezier_Math::evaluatePos(t, control_point_x[leg]);
        double v_x = Bezier_Math::evaluateVel(t, control_point_x[leg]);
        double a_x = Bezier_Math::evaluateAcc(t, control_point_x[leg]);

        // z: 前 0.5T 走 z_up, 后 0.5T 走 z_down
        // 局部时长 0.5T, 相位速率是 x 的 2 倍: 速度 ×2, 加速度 ×4
        double p_z, v_z, a_z;
        if (t < 0.5) {
            double tau = 2.0 * t;
            p_z = Bezier_Math::evaluatePos(tau, control_point_z_up[leg]);
            v_z = Bezier_Math::evaluateVel(tau, control_point_z_up[leg]);
            a_z = Bezier_Math::evaluateAcc(tau, control_point_z_up[leg]);
        } else {
            double tau = 2.0 * t - 1.0;
            p_z = Bezier_Math::evaluatePos(tau, control_point_z_down[leg]);
            v_z = Bezier_Math::evaluateVel(tau, control_point_z_down[leg]);
            a_z = Bezier_Math::evaluateAcc(tau, control_point_z_down[leg]);
        }
        v_z *= 2.0;
        a_z *= 4.0;

        Point p(p_x, _swing_y[leg], p_z);
        Point v(v_x, 0.0, v_z);
        Point a(a_x, 0.0, a_z);
        a = a / (T_swing * T_swing);
        if (t == 0.0) {  // 支撑期: 保持 FK 反馈足端位置, 指令速度/加速度置零 (摆动曲线边界值不应作用于支撑腿)
            p = _foot_pos.row(leg).transpose();
            v.setZero();
            a.setZero();
        }

        _foot_pos.row(leg) = p.transpose();  // 记录指令足端位置
        pos = _foot_pos;
        _foot_vel.row(leg) = v.transpose();  // 记录指令足端速度
        vel = _foot_vel;
        _foot_acc.row(leg) = a.transpose();  // 记录指令足端加速度
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

double Bezier_Math::evaluatePos(double t,const Control_Point P_control){
    double start = P_control.Start_Point;
    double end = P_control.End_Point;
    std::vector<double> mid = P_control.Mid_Point;
    int degree = mid.size();
    double p;
    if (degree == 1){ // 二阶
        p = pow((1 - t),2) * start + 2 * t * (1 - t) * mid[0] + pow(t,2) * end;
    } 
    else if (degree == 2) // 三阶
    {
        p = pow((1 - t),3) * start + 3 * t * pow((1 - t),2) * mid[0] + 3 * pow(t,2) * (1 - t) * mid[1] + pow(t,3) * end;
    }
    else if (degree == 3) // 四阶: 控制点 [S, M0, M1, M2, E]
    {
        p = pow((1 - t),4) * start
          + 4 * t * pow((1 - t),3) * mid[0]
          + 6 * pow(t,2) * pow((1 - t),2) * mid[1]
          + 4 * pow(t,3) * (1 - t) * mid[2]
          + pow(t,4) * end;
    }
    else if (degree == 4) // 五阶: 控制点 [S, M0, M1, M2, M3, E]
    {
        p = pow((1 - t),5) * start
          + 5 * t * pow((1 - t),4) * mid[0]
          + 10 * pow(t,2) * pow((1 - t),3) * mid[1]
          + 10 * pow(t,3) * pow((1 - t),2) * mid[2]
          + 5 * pow(t,4) * (1 - t) * mid[3]
          + pow(t,5) * end;
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluatePos: 不支持的阶数 " << degree << std::endl;
        return 0.0;
    }
    return p;
}

double Bezier_Math::evaluateVel(double t,const Control_Point P_control){
    double start = P_control.Start_Point;
    double end = P_control.End_Point;
    std::vector<double> mid = P_control.Mid_Point;
    int degree = mid.size();
    double v;
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
    else if (degree == 4) // 五阶: B' = 5·Σ C(4,i)(1-t)^(4-i)·t^i·(P_(i+1)-P_i)
    {
        v = 5 * pow((1 - t),4) * (mid[0] - start)
          + 20 * t * pow((1 - t),3) * (mid[1] - mid[0])
          + 30 * pow(t,2) * pow((1 - t),2) * (mid[2] - mid[1])
          + 20 * pow(t,3) * (1 - t) * (mid[3] - mid[2])
          + 5 * pow(t,4) * (end - mid[3]);
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluateVel: 不支持的阶数 " << degree << std::endl;
        return 0.0;
    }
    return v;
}

double Bezier_Math::evaluateAcc(double t,const Control_Point P_control){
    double start = P_control.Start_Point;
    double end = P_control.End_Point;
    std::vector<double> mid = P_control.Mid_Point;
    int degree = mid.size();
    double a;
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
    else if (degree == 4) // 五阶: B'' = 20·Σ C(3,i)(1-t)^(3-i)·t^i·(P_(i+2)-2P_(i+1)+P_i)
    {
        // [S, M0..M3, E] = [S,S,S,E,E,E] (min-jerk) 时:
        //   a(t) = 60·t·(1-t)·(1-2t)·(E-S), 峰值 5.7735·(E-S) 于 t≈0.211/0.789
        a = 20 * pow((1 - t),3) * (mid[1] - 2 * mid[0] + start)
          + 60 * t * pow((1 - t),2) * (mid[2] - 2 * mid[1] + mid[0])
          + 60 * pow(t,2) * (1 - t) * (mid[3] - 2 * mid[2] + mid[1])
          + 20 * pow(t,3) * (end - 2 * mid[3] + mid[2]);
    }
    else // 不支持的阶数
    {
        std::cerr << "[Bezier_Math] evaluateAcc: 不支持的阶数 " << degree << std::endl;
        return 0.0;
    }
    return a;
}
} // namespace SwingPlanner
