#ifndef __FSM_STATE_H
#define __FSM_STATE_H

#include <iostream>
#include <memory>

namespace fsm
{
    enum FSM_State{
        STAND = 0,      // 四腿全在支撑还没抬起
        GAIT_START,     // 摆动腿开摆
        GAIT_RUNNING,   // 摆动腿正在运行
        GAIT_STOPPING   // 摆动腿接受到结束信号，让摆动腿走完摆动轨迹，全部走完后转为STAND
    };
} // namespace FSM





#endif