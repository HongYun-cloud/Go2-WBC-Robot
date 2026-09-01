#ifndef __GAIT_H
#define __GAIT_H

#include <iostream>
#include <Eigen/Dense>
#include "common.h"

// @brief 当前的运动状态
// @warning 只有在全部触地以后才能转为PHASE

namespace Gait
{
    
    enum class GaitType { START, STAND, TROT, WALK };

    struct GaitCmd{
        GaitType type;
        Velocity v;

    };

    // 包含这个步态的支持比，相位偏移和周期时长
    struct GaitParams {
        double duty_factor = 1.0;      // 支撑比
        double offset[4] = {0,0,0,0};  // 四条腿的相位偏移 (FL, FR, RL, RR)
        double cycle_time = 0.5;       // 一个周期的时长
    };

    // 预设步态，包含这个步态的支持比，相位偏移和周期时长
    namespace Preset {
        inline const GaitParams STAND {1.0, {0.0, 0.0, 0.0, 0.0}, 1.0};
        inline const GaitParams TROT  {0.5, {0.0, 0.5, 0.5, 0.0}, 0.5};
        inline const GaitParams WALK  {0.75,{0.0, 0.25,0.5,0.75},1.0};
    }


} // namespace Gait



#endif