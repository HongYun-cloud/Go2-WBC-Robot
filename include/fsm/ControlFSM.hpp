#ifndef __CONTROL_FSM_HPP
#define __CONTROL_FSM_HPP

#include "fsmstate.h"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"
namespace fsm
{
    class ControlFSM
    {
    private:
        FSM_State Robot_state = FSM_State::STAND;

        std::shared_ptr<Gait::GaitScheduler> _scheduler;
        std::shared_ptr<SwingPlanner::SwingLegPlanner> _trajectory;

        Gait::GaitCmd Gait_cmd;
        Gait::GaitType _last_gait_type = Gait::GaitType::START;  // 上次应用的步态, 避免每周期重置 scheduler

        void runStand();
        void runStopping();
    public:
        void SetCmd(Gait::GaitType type);
        void SetState(FSM_State state) { Robot_state = state; }
        /** 获取期望速度指令 (供 MPC 参考轨迹使用) */
        Velocity GetDesiredVelocity() const { return Gait_cmd.v; }
        void run(double dt);

        ControlFSM(std::shared_ptr<Gait::GaitScheduler> scheduler,
                   std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory);
        ~ControlFSM();
    };
    
    
} // namespace FSM



#endif