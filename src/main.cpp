#include <SIM/MJCsim.hpp>
#include <MPC/MPC.hpp>
#include <Model/pinocchio.hpp>
#include "WBC/WBC.hpp"
#include <common.h>
#include <iomanip>
#include "fsm/ControlFSM.hpp"

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstring>
#include <sstream>
#include <vector>
#include <termios.h>

// ===== 非阻塞键盘输入 =====
// 把终端切到非规范模式 (关掉行缓冲), 按键立即送达, 长按自动连发
static struct termios _old_tio;
static bool _term_raw = false;
static void restore_term() {
    if (_term_raw) tcsetattr(STDIN_FILENO, TCSANOW, &_old_tio);
}
char get_key_noblock() {
    if (!_term_raw) {
        tcgetattr(STDIN_FILENO, &_old_tio);
        struct termios new_tio = _old_tio;
        new_tio.c_lflag &= ~(ICANON | ECHO);  // 非规范 + 不回显
        new_tio.c_cc[VMIN] = 0;               // 不阻塞
        new_tio.c_cc[VTIME] = 0;
        tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
        _term_raw = true;
        atexit(restore_term);  // 退出时恢复终端
    }
    char c = 0;
    if (read(STDIN_FILENO, &c, 1) > 0)
        return c;
    return 0;
}

// PlotJuggler UDP 流式发送 (PlotJuggler → UDP Stream 插件, 默认端口 9870)
// 格式: JSON 对象, 每行一个, 如 {"timestamp":0.02, "FL_x":0.193, "FL_z":-0.05}
// 用法: PlotSend(0.02, {{"FL_x", 0.193}, {"FL_z", -0.05}})
static int _pj_sock = -1;
static struct sockaddr_in _pj_addr;
void PlotSend(double time, const std::vector<std::pair<std::string,double>>& data){
    if (_pj_sock < 0) {
        _pj_sock = socket(AF_INET, SOCK_DGRAM, 0);
        std::memset(&_pj_addr, 0, sizeof(_pj_addr));
        _pj_addr.sin_family = AF_INET;
        _pj_addr.sin_port = htons(9870);
        inet_pton(AF_INET, "127.0.0.1", &_pj_addr.sin_addr);
    }
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4) << "{\"timestamp\":" << time;
    for (auto& kv : data)
        oss << ",\"" << kv.first << "\":" << kv.second;
    oss << "}\n";
    std::string msg = oss.str();
    sendto(_pj_sock, msg.c_str(), msg.size(), 0,
           (struct sockaddr*)&_pj_addr, sizeof(_pj_addr));
}

std::string xml = "../go2/scene.xml";
std::string urdf_path = "../go2/go2_description.urdf";

int main(){
    auto scheduler  = std::make_shared<Gait::GaitScheduler>();
    auto estimator  = std::make_shared<Estimator::PositionVelocityEstimator>();
    auto trajectory = std::make_shared<SwingPlanner::SwingLegPlanner>(scheduler, estimator);

    auto fsm = std::make_unique<fsm::ControlFSM>(scheduler,trajectory);
    auto mj  = new MJCSIM::SIM(xml);
    auto pin = new Pinocchio::PinocchioKinematics(urdf_path);
    auto mpc = new Regulator::MPC(estimator.get());
    auto wbc = new WBC::WBC(estimator.get());

    // 足端顺序FL,FR,RL,RR
    // ===== 通过地址连接 Pinocchio 足端数据到 MPCData =====
    mpc->setLegData(pin->getLegData());

    // ===== WBC 初始化 =====
    wbc->setPinocchio(pin);
    wbc->loadConfig("../config/mpc.yaml");

    mj->InitMujoco();
    // mj->SimStart();
    // mj->InitViewer();

    Eigen::Vector3d v, w;
    Eigen::Vector3d q, p;
    q.setZero(); p.setZero();
    v.setZero(); w.setZero();
    v[0] = 0.0;
    p[2] = 0.25;
    mpc->update_DesireStateCommand(q,p,v,w);
    mpc->loadConfig("../config/mpc.yaml");
    mpc->update_reference_trajectory();

    // WBC 首次 update + init (设置 cmd 并初始化固定矩阵)
    {
        auto state = mj->getState();
        estimator->update(state);
        pin->setJointVelocity(v8to12(state.joint_velocities));
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(q8toq12(state.joint_positions), state.position, state.quat.coeffs());
        trajectory->SetFootPositions(pin->getAllFootPositions());  // 用 FK 真值初始化足端位置, 避免默认 -0.25 污染首拍摆动

        mpc->update();
        mpc->solve();
        auto f_mpc = mpc->getControl();

        Eigen::Matrix<double, 18, 1> q_des = Eigen::Matrix<double, 18, 1>::Zero();
        Eigen::Matrix<double, 12, 1> a_des = Eigen::Matrix<double, 12, 1>::Zero();
        wbc->update(q_des, f_mpc, a_des, state);
    }
    wbc->init();

    // ===== MPC 模型参数: 用 URDF 真值替换硬编码 =====
    // 模型以为 yaw 极容易控制, 几乎不输出侧向力差 → 真实 yaw/roll 扰动得不到纠正 → 漂移后倒向固定一侧
    {
        double m_total = 0.0;
        Eigen::Matrix3d I_com = Eigen::Matrix3d::Zero();
        pin->getTotalMassInertia(m_total, I_com);
        mpc->setModelParams(m_total, I_com.diagonal().asDiagonal());  // 简化模型: 机身系对角惯性
        std::cout << "[MPC] mass=" << m_total << " kg, I diag=" << I_com.diagonal().transpose() << std::endl;
    }

    // DEBUG: FSM: 设置初始步态为 TROT, 进入跑步状态
    fsm->SetCmd(Gait::GaitType::TROT,v);
    fsm->SetState(fsm::FSM_State::GAIT_RUNNING);

    // 控制步长必须等于 MuJoCo 物理步长 (InitMujoco 里设为 0.01)
    // 之前硬编码 0.002 与物理 0.01 失配: 步态时钟慢 5 倍 → 摆动相实际 1.25s;
    // 且 v_ref/a 前馈按 T_swing=0.25s 换算 (虚大 5/25 倍) 干扰跟踪 → 步高偏低
    const double sim_dt = mj->getTimestep();
    int count = 0;

    // ===== 足端实际加速度 (世界系): v_foot_act 数值微分 =====
    Eigen::Matrix<double, 12, 1> v_foot_prev = Eigen::Matrix<double, 12, 1>::Zero();
    Eigen::Matrix<double, 12, 1> a_foot_act = Eigen::Matrix<double, 12, 1>::Zero();
    bool have_prev_v = false;

    while (1){
        fsm->run(sim_dt);
        count++;
        auto state = mj->getState();

        // ===== 键盘控制: 按 w 前进, 松手停止 =====
        {
            char key = get_key_noblock();
            if (key == 'w')
                v[0] = 0.05;
            else if (key == 's')
                v[0] = -0.05;
            else
                v[0] = 0.0;
            mpc->update_DesireStateCommand(q,p,v,w);
        }

        // ===== 计划接触 (步态相位): 摆动/支撑划分不能用实测接触 =====
        // 静止时四足全着地 → 实测接触全 1 → 摆动任务永远不触发 (死锁: 脚不抬就永远"支撑")
        // 覆写 state.contact_states 为计划接触, 后续 estimator/MPC/PD/WBC 全部按计划划分
        for (int leg = 0; leg < 4; leg++)
            state.contact_states[leg] = (scheduler->GetSwingPhases(leg) <= 0) ? 1 : 0;

        estimator->update(state);
        pin->setJointVelocity(v8to12(state.joint_velocities));
        pin->setBaseVelocity(state.linear_vel, state.angular_vel);
        pin->forwardKinematics(q8toq12(state.joint_positions), state.position, state.quat.coeffs());
        trajectory->SetFootPositions(pin->getAllFootPositions());  // FK 足端位置反馈给摆动轨迹规划器

        // MPC 计算期望力
        // 接触预测: 按步态相位滚动到预测时域 (之前复制当前接触, 接触切换点附近预测模型错误)
        mpc->setContactSchedule(scheduler->GetContactSchedule(mpc->getDt(), mpc->getHorizonN()));
        mpc->update();
        mpc->solve();
        auto f_mpc = mpc->getControl();

        // // WBC: QP 求解一致的加速度和力
        Eigen::Matrix<double, 18, 1> q_des = Eigen::Matrix<double, 18, 1>::Zero();

        double T_swing = scheduler->GetSwingTime();
        if (T_swing < 1e-3) T_swing = 1e-3;  // STAND 时 duty=1 → T_swing=0, 防除零

        Eigen::Matrix<double, 4, 3> p_ref = trajectory->GetSwingPos();
        Eigen::Matrix<double, 4, 3> v_ref = trajectory->GetSwingVel() / T_swing;   // 相位速度 → 时间速度 (m/s)
        Eigen::Matrix<double, 4, 3> p_act = pin->getAllFootPositions();

        // 足端实际速度: J_floating × v_full (与 WBC 摆动任务同坐标系)
        Eigen::Matrix<double, 18, 1> v_full;
        v_full << state.linear_vel, state.angular_vel, v8to12(state.joint_velocities);
        Eigen::Matrix<double, 12, 1> v_foot_act;
        for (int leg = 0; leg < 4; leg++)
            v_foot_act.segment<3>(leg * 3) = pin->getFootJacobianFloatingBase(leg) * v_full;

        // ===== 足端实际加速度 (世界系): v_foot_act 数值微分 =====
        if (have_prev_v)
            a_foot_act = (v_foot_act - v_foot_prev) / sim_dt;
        v_foot_prev = v_foot_act;
        have_prev_v = true;

        // ===== 加速度层阻抗: a_des = a_ff + 阻抗修正 =====
        // 阻抗修正放在加速度层, 让 WBC QP 统一处理, 保持动力学一致性
        // 支撑腿: a_des 置零, 不跟踪摆动加速度
        Eigen::Matrix<double, 12, 1> a_des = trajectory->GetSwingAccVec();
        for (int leg = 0; leg < 4; leg++) {
            if (state.contact_states[leg] == 1) {
                a_des.segment<3>(leg*3).setZero();
                continue;
            }

            double t = scheduler->GetSwingPhases(leg);
            double blend = 1.0;
            if (t < 0.1)      blend = t / 0.1;
            else if (t > 0.9) blend = (1.0 - t) / 0.1;

            Eigen::Vector3d e_p = p_ref.row(leg).transpose() - p_act.row(leg).transpose();
            Eigen::Vector3d e_v = v_ref.row(leg).transpose() - v_foot_act.segment<3>(leg * 3);
            Eigen::Vector3d Kp_vec(300, 300, 1000);
            Eigen::Vector3d Kd_vec(10, 10, 20);
            Eigen::Vector3d Kt(10, 10, 20);
            // 速度误差只取足端实际速度 (不缩放 v_ref), 避免摆动入地时阻抗主动对抗足端运动
            // blend 用于起落阶段平滑衰减阻抗, 避免接地瞬间冲击
            a_des.segment<3>(leg * 3) += blend * (Kp_vec.cwiseProduct(e_p) + Kd_vec.cwiseProduct(e_v));
        }

        wbc->update(q_des, f_mpc, a_des, state);
        wbc->solve();

        WBC::SolutionVector sol;
        wbc->GetSolution(sol);
        Eigen::Matrix<double, 12, 1> f_wbc = sol.tail(12);

        // 关节力矩: τ = M·a + h − Jᵀf (WBC 逆动力学, 已包含 a_des 跟踪)
        auto tau = pin->getJointTorquesFromSolution(sol.head(18), f_wbc);

        mj->control(tau);
        mj->Step();
        mj->Render();

        // ===== PlotJuggler UDP 发送 (PlotJuggler → UDP Stream, 127.0.0.1:9870) =====
        // 用 foot_time 为时间戳 (秒), 每 10 帧 (0.02s) 发一次
        {
            double t = count * sim_dt;
            std::vector<std::pair<std::string,double>> pj;
            const char* legN[] = {"FL","FR","RL","RR"};
            for (int leg = 0; leg < 4; leg++) {
                pj.push_back({std::string("p_ref_") + legN[leg] + "_x", p_ref(leg,0)});
                pj.push_back({std::string("p_ref_") + legN[leg] + "_y", p_ref(leg,1)});
                pj.push_back({std::string("p_ref_") + legN[leg] + "_z", p_ref(leg,2)});

                pj.push_back({std::string("p_act_") + legN[leg] + "_x", p_act(leg,0)});
                pj.push_back({std::string("p_act_") + legN[leg] + "_y", p_act(leg,1)});
                pj.push_back({std::string("p_act_") + legN[leg] + "_z", p_act(leg,2)});

                pj.push_back({std::string("v_ref_") + legN[leg] + "_x", v_ref(leg,0)});
                pj.push_back({std::string("v_ref_") + legN[leg] + "_y", v_ref(leg,1)});
                pj.push_back({std::string("v_ref_") + legN[leg] + "_z", v_ref(leg,2)});

                pj.push_back({std::string("v_act_") + legN[leg] + "_x", v_foot_act(leg*3+0)});
                pj.push_back({std::string("v_act_") + legN[leg] + "_y", v_foot_act(leg*3+1)});
                pj.push_back({std::string("v_act_") + legN[leg] + "_z", v_foot_act(leg*3+2)});

                pj.push_back({std::string("a_ref_") + legN[leg] + "_x", a_des(leg*3 + 0)});
                pj.push_back({std::string("a_ref_") + legN[leg] + "_y", a_des(leg*3 + 1)});
                pj.push_back({std::string("a_ref_") + legN[leg] + "_z", a_des(leg*3 + 2)});

                
                pj.push_back({std::string("a_act_") + legN[leg] + "_x", a_foot_act(leg*3+0)});
                pj.push_back({std::string("a_act_") + legN[leg] + "_y", a_foot_act(leg*3+1)});
                pj.push_back({std::string("a_act_") + legN[leg] + "_z", a_foot_act(leg*3+2)});

                pj.push_back({std::string("f_mpc_") + legN[leg] + "_x", f_mpc(leg*3+0)});
                pj.push_back({std::string("f_mpc_") + legN[leg] + "_y", f_mpc(leg*3+1)});
                pj.push_back({std::string("f_mpc_") + legN[leg] + "_z", f_mpc(leg*3+2)});

                pj.push_back({std::string("f_wbc_") + legN[leg] + "_x", f_wbc(leg*3+0)});
                pj.push_back({std::string("f_wbc_") + legN[leg] + "_y", f_wbc(leg*3+1)});
                pj.push_back({std::string("f_wbc_") + legN[leg] + "_z", f_wbc(leg*3+2)});
                
                pj.push_back({std::string("contract_") + legN[leg] + "_z", state.contact_states[leg]});
            }
            pj.push_back({"body_x", state.position[0]});
            pj.push_back({"body_z", state.position[2]});

            pj.push_back({"body_x_v", state.linear_vel[0]});
            pj.push_back({"body_z_v", state.linear_vel[2]});

            pj.push_back({"body_x_v_d", v[0]});
            pj.push_back({"body_z_v_d", v[2]});
            if (count % 10 == 0) PlotSend(t, pj);
        }
    }
}
