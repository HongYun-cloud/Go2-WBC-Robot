#include "Planner/GaitScheduler.hpp"

namespace Gait
{
    GaitScheduler::GaitScheduler() {}
    GaitScheduler::~GaitScheduler() {}

    void GaitScheduler::step(double dt){
        // 累加时间, 按 cycle_time 取模
        elapsed_ = fmod(elapsed_ + dt, Gait_Now.cycle_time);
    }

    void GaitScheduler::ResetTime(){
        elapsed_ = 0.0;
    }

    void GaitScheduler::SetGaitType(GaitType type){
        switch (type) {
            case GaitType::STAND: SetParams(Preset::STAND); break;
            case GaitType::TROT:  SetParams(Preset::TROT);  break;
            case GaitType::WALK:  SetParams(Preset::WALK);  break;
            case GaitType::START:
            default:              SetParams(Preset::STAND); break;
        }
    }

    void GaitScheduler::SetParams(const GaitParams& gp){
        Gait_Now = gp;
        elapsed_ = 0.0;  // 换步态时重置时间
    }

    // 返回归一化总相位
    double GaitScheduler::GetNormalPhases(size_t leg){
        return fmod(Gait_Now.offset[leg] + elapsed_ / Gait_Now.cycle_time, 1.0);
    }

    // 返回归一化后的摆动相位, 支撑期返回 0
    double GaitScheduler::GetSwingPhases(size_t leg){
        double phase = GetNormalPhases(leg);

        if (phase > Gait_Now.duty_factor) {
            // 摆动期: 归一化到0-1(不包含0)
            return (phase - Gait_Now.duty_factor) / (1.0 - Gait_Now.duty_factor);
        }
        return 0.0;  // 支撑期
    }

    // 返回摆动项在一个周期里有多少时间
    double GaitScheduler::GetSwingTime(){
        return Gait_Now.cycle_time * (1-Gait_Now.duty_factor);
    }

    // 返回支撑项在一个周期里有多少时间
    double GaitScheduler::GetStanceTime(){
        return Gait_Now.cycle_time * Gait_Now.duty_factor;
    }

    std::vector<int> GaitScheduler::GetContactSchedule(double dt, int N) const{
        std::vector<int> sched(N * 4, 1);
        for (int j = 0; j < N; j++) {
            double t = elapsed_ + j * dt;   // 未来第 j 步的时刻
            for (int leg = 0; leg < 4; leg++) {
                double phase = fmod(Gait_Now.offset[leg] + t / Gait_Now.cycle_time, 1.0);
                sched[j * 4 + leg] = (phase > Gait_Now.duty_factor) ? 0 : 1;
            }
        }
        return sched;
    }
} // namespace Gait


