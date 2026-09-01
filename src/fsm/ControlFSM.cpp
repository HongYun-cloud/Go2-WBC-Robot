#include "fsm/ControlFSM.hpp"
#include "Planner/GaitScheduler.hpp"
#include "Planner/SwingLegPlanner.hpp"

namespace fsm
{
    ControlFSM::ControlFSM(std::shared_ptr<Gait::GaitScheduler> scheduler,
                           std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory)
        : _scheduler(scheduler), _trajectory(trajectory) {}

    ControlFSM::~ControlFSM() {}

    void ControlFSM::SetCmd(Gait::GaitType type){
        Gait_cmd.type = type;
        Gait_cmd.v = Velocity{0.0,0,0};
    }

    void ControlFSM::run(double dt){

        switch (Robot_state)
        {
        case FSM_State::STAND:
            runStand();
            _scheduler->ResetTime();
            break;
        case FSM_State::GAIT_RUNNING:
            // SetGaitType 内部会清零 elapsed_, 必须只在步态真正改变时调用, 否则相位无法推进
            if (_last_gait_type != Gait_cmd.type) {
                _scheduler->SetGaitType(Gait_cmd.type);
                _last_gait_type = Gait_cmd.type;
                _trajectory->Reset();  // 步态切换后重置摆动轨迹状态
            }
            
            _scheduler->step(dt);
            _trajectory->Generate(Gait_cmd.v,[this](size_t leg) {
                return _scheduler->GetSwingPhases(leg);
            });
            
            break;
        case FSM_State::GAIT_STOPPING:
            runStopping();
            break;
        default:
            break;
        }
    }

    void ControlFSM::runStand(){

    }

    void ControlFSM::runStopping(){

    }
} // namespace fsm