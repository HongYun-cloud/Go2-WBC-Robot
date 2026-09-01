#ifndef __GAITSCHEDULER_HPP
#define __GAITSCHEDULER_HPP
// 这个头文件用于步态的调度和规划

#include <iostream>
#include <vector>
#include "Gait.h"
namespace Gait
{
    class GaitScheduler
    {
    private:
        double elapsed_ = 0.0;  // 当前周期已用时 (秒)
        GaitParams Gait_Now = Preset::STAND;
    public:
        void ResetTime();
        void SetParams(const GaitParams& gt);
        void SetGaitType(GaitType type);
        void step(double dt);
        double GetNormalPhases(size_t leg);
        double GetSwingPhases(size_t leg);
        double GetSwingTime();
        double GetStanceTime();
        /**
         * 预测未来 N 步 (每步 dt 秒) 的计划接触序列
         * 返回 N*4 平铺: [step0 的 4 腿, step1 的 4 腿, ...], 1=支撑 0=摆动
         * 语义与 GetSwingPhases 一致: 相位 > duty_factor 为摆动
         * 供 MPC 预测时域内的接触约束滚动更新 (替代"复制当前接触"的近似)
         */
        std::vector<int> GetContactSchedule(double dt, int N) const;
        GaitScheduler();
        ~GaitScheduler();
    };

} // namespace Gait



#endif