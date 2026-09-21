#ifndef __CONTROL_FSM_HPP
#define __CONTROL_FSM_HPP

#include "fsmstate.h"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"
#include <array>
namespace fsm
{
    /**
     * 单腿的接触决策结果: 由"计划相位 + 实测足端力"共同决定。
     *
     * 规则只有两条, 且实测力只作用在**安全的方向**上:
     *   1. 计划支撑 → 恒为支撑。实测力**不会**把一条计划支撑腿降级成摆动。
     *      降级是错的: 摆动腿在 WBC 里没有足端跟踪任务, 而它又确实需要承重,
     *      于是 QP 把整机重量花在一个无法反作用的地点上(幻影支撑力), 算出的
     *      关节力矩与真实受力不符 → 机身下沉/俯仰。(注意不是"腿越抬越高" ——
     *      支撑腿的 no-slip 等式约束的是加速度, 不约束位置, 足端并不会被顶上去。)
     *   2. 计划摆动 + 已经落地 + 没有任何"真踩在地上"的腿 → 延迟抬起, 继续踩地。
     *      这是变时长的双支撑握手: 进来的脚落地之前, 不把出去的脚抬起来。
     *
     * 这样"计划支撑腿恒为支撑"本身就保证了支撑集非空 (TROT 恒 ≥2 / WALK 恒 ≥3 /
     * STAND 恒 4), WBC 不会把 12 个接触力全钉成 0。
     */
    struct LegContact
    {
        int    stance    = 1;      // 1=支撑 / 0=摆动 —— 给 estimator / MPC / WBC
        double eff_phase = 0.0;    // 给摆动规划器的有效相位 (支撑腿恒为 0.0)
        bool   hold      = false;  // 延迟抬起中 (本该摆动, 为了等对侧落地而继续踩地)
    };

    class ControlFSM
    {
    private:
        FSM_State Robot_state = FSM_State::STAND;

        std::shared_ptr<Gait::GaitScheduler> _scheduler;
        std::shared_ptr<SwingPlanner::SwingLegPlanner> _trajectory;

        Gait::GaitCmd Gait_cmd;
        Gait::GaitType _last_gait_type = Gait::GaitType::START;  // 上次应用的步态, 避免每周期重置 scheduler

        // ===== 触地检测 (config/go2_params.yaml: touchdown_force / airborne_hold_ratio) =====
        double touchdown_force_ = 5.0;   // 落地阈值 (N): 滤波后法向力超过它 → landed
        double release_force_   = 3.0;   // 离地阈值 (N): 低于它才 → not landed
                                         // 两个阈值构成施密特触发 (默认 0.6 × touchdown_force_),
                                         // 避免触地振铃/离地卸载时 landed 反复横跳 —— 每次翻转都会
                                         // 改变 WBC 的约束结构 (f=0 等式 ↔ no-slip+摩擦锥), 力矩跳变
        double hold_ratio_      = 0.5;   // 延迟抬起时长上限 = hold_ratio * T_stance

        std::array<LegContact, 4> leg_contact_;
        std::array<bool,   4> landed_{{false, false, false, false}};        // 滞回后的落地下状态
        std::array<double, 4> foot_force_filt_{{0.0, 0.0, 0.0, 0.0}};      // 足端力一阶低通
        std::array<double, 4> delay_time_{{0.0, 0.0, 0.0, 0.0}};           // 延迟抬起已持续时长

        void runStand();
        void runStopping();
        /** 按计划相位刷新 leg_contact_ 并清空触地检测状态 (用于站立/停止) */
        void setPlannedContact();
        /** 计划相位 + 实测足端力 → leg_contact_ (跑步行进用) */
        void updateContactDecision(double dt, const Eigen::Matrix<double, 4, 1>& foot_force);
    public:
        void SetCmd(Gait::GaitType type,Velocity v);
        void SetState(FSM_State state) { Robot_state = state; }
        /** 获取期望速度指令 (供 MPC 参考轨迹使用) */
        Velocity GetDesiredVelocity() const { return Gait_cmd.v; }
        /** 触地检测参数 (来自 config/go2_params.yaml) */
        void setContactDetect(double touchdown_force, double hold_ratio)
        {
            if (touchdown_force > 0.0) {
                touchdown_force_ = touchdown_force;
                release_force_   = 0.6 * touchdown_force;   // 施密特触发的下阈值
            }
            if (hold_ratio > 0.0) hold_ratio_ = hold_ratio;
        }
        /** 本拍各腿的接触决策 (stance / eff_phase / hold) */
        const std::array<LegContact, 4>& GetLegContact() const { return leg_contact_; }
        /**
         * @param dt         控制步长
         * @param foot_force 实测足端法向力 (N), 顺序 FL, FR, RL, RR
         */
        void run(double dt, const Eigen::Matrix<double, 4, 1>& foot_force);

        ControlFSM(std::shared_ptr<Gait::GaitScheduler> scheduler,
                   std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory);
        ~ControlFSM();
    };
    
    
} // namespace FSM



#endif