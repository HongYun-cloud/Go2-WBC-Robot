#include "fsm/ControlFSM.hpp"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"

namespace fsm
{
    ControlFSM::ControlFSM(std::shared_ptr<Gait::GaitScheduler> scheduler,
                           std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory)
        : _scheduler(scheduler), _trajectory(trajectory) {}

    ControlFSM::~ControlFSM() {}

    void ControlFSM::SetCmd(Gait::GaitType type,Velocity v){
        Gait_cmd.type = type;
        Gait_cmd.v = v;
    }

    void ControlFSM::run(double dt, const Eigen::Matrix<double, 4, 1>& foot_force){

        switch (Robot_state)
        {
        case FSM_State::STAND:
            runStand();
            _scheduler->ResetTime();
            setPlannedContact();   // 站立 (duty=1 → 全支撑), 不参与触地判定
            break;
        case FSM_State::GAIT_RUNNING:
            // SetGaitType 内部会清零 elapsed_, 必须只在步态真正改变时调用, 否则相位无法推进
            if (_last_gait_type != Gait_cmd.type) {
                _scheduler->SetGaitType(Gait_cmd.type);
                _last_gait_type = Gait_cmd.type;
                _trajectory->Reset();     // 步态切换后重置摆动轨迹状态
                delay_time_.fill(0.0);    // 延迟抬起计时清零 (新步态的 T_stance 不同, 旧计时无意义)
            }

            _scheduler->step(dt);
            updateContactDecision(dt, foot_force);
            _trajectory->Generate(Gait_cmd.v,[this](size_t leg) {
                return leg_contact_[leg].eff_phase;
            });

            break;
        case FSM_State::GAIT_STOPPING:
            runStopping();
            setPlannedContact();
            break;
        default:
            break;
        }
    }

    void ControlFSM::setPlannedContact()
    {
        for (int leg = 0; leg < 4; leg++) {
            const double t = _scheduler->GetSwingPhases(leg);
            leg_contact_[leg] = LegContact{(t > 0.0) ? 0 : 1, t, false};
            // 站立/停止不参与触地判定, 把检测状态清空, 避免下次进 GAIT_RUNNING
            // 时沿用上次行走留下的滞回状态
            delay_time_[leg]      = 0.0;
            foot_force_filt_[leg] = 0.0;
            landed_[leg]          = false;
        }
    }

    void ControlFSM::updateContactDecision(double dt, const Eigen::Matrix<double, 4, 1>& foot_force)
    {
        // 延迟抬起的最长时间: 支撑期的一半。超过了说明对侧一直没落地,
        // 再拖下去这条腿自己的摆动就完全被跳过了 (变成拖着走的挪步),
        // 所以到点放它走 —— 此时对侧会被下面的规则作为"计划支撑腿"接住
        const double max_delay = hold_ratio_ * _scheduler->GetStanceTime();

        // ===== 1. 实测足端力 → landed (低通 + 施密特触发) =====
        bool planned_stance[4];
        for (int leg = 0; leg < 4; leg++) {
            foot_force_filt_[leg] += 0.5 * (foot_force(leg) - foot_force_filt_[leg]);

            if (foot_force_filt_[leg] > touchdown_force_)     landed_[leg] = true;
            else if (foot_force_filt_[leg] < release_force_)  landed_[leg] = false;
            // 两个阈值之间保持上一拍的状态 (滞回)

            planned_stance[leg] = (_scheduler->GetSwingPhases(leg) <= 0.0);
        }

        // ===== 2. 有没有"真踩在地上"的腿 (计划支撑 + 实测已落地) =====
        int confirmed = 0;
        for (int leg = 0; leg < 4; leg++) confirmed += (planned_stance[leg] && landed_[leg]);
        const bool need_delay = (confirmed == 0);

        // ===== 3. 逐腿决策 =====
        for (int leg = 0; leg < 4; leg++) {
            if (planned_stance[leg]) {
                // 计划支撑 → 恒为支撑。实测力不能把这条腿降级成摆动:
                // 降级后它没有足端跟踪任务, 却仍被当作承重腿, QP 会把整机重量
                // 花在一个无法反作用的地点上 → 机身下沉/俯仰。
                leg_contact_[leg] = LegContact{1, 0.0, false};
                delay_time_[leg]  = 0.0;
                continue;
            }

            // 计划摆动: 只有确实还踩在地上的腿才谈得上"延迟抬起"
            if (landed_[leg] && need_delay && delay_time_[leg] < max_delay) {
                delay_time_[leg] += dt;
                leg_contact_[leg] = LegContact{1, 0.0, true};
            } else {
                delay_time_[leg] = 0.0;
                leg_contact_[leg] = LegContact{0, _scheduler->GetSwingPhases(leg), false};
            }
        }

        // ===== 4. 硬不变量: 支撑集非空 =====
        // WBC::updateconstraint 对每条摆动腿用**等式**把三个力分量钉死为 0,
        // 四腿全摆动 ⇒ 12 个接触力全为 0 ⇒ 没有任何力托住机身 ⇒ 每步下沉。
        // 第 3 步已保证计划支撑腿恒为支撑 (任何预设都不会四腿全计划摆动),
        // 这里再兜一层: 以后有人改规则时不至于静默退化回那个状态。
        int n_stance = 0;
        for (int leg = 0; leg < 4; leg++) n_stance += leg_contact_[leg].stance;
        for (int leg = 0; leg < 4 && n_stance == 0; leg++) {
            leg_contact_[leg] = LegContact{1, 0.0, false};
            n_stance = 1;
        }
    }

    void ControlFSM::runStand(){

    }

    void ControlFSM::runStopping(){

    }
} // namespace fsm