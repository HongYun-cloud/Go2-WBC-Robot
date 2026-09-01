#include "Estimator/PositionVelocityEstimator.hpp"

namespace Estimator
{

void PositionVelocityEstimator::update(const RobotState& state)
{
    // 将 RobotState 转换为 MPC 所需的格式
    result_.p = state.position;
    result_.v = state.linear_vel;
    result_.q = state.euler;
    result_.w = state.angular_vel;
    result_.contact_states = state.contact_states;
}

ConvertEstimatorForMPC PositionVelocityEstimator::get_estresult()
{
    return result_;
}

} // namespace Estimator
