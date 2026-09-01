#ifndef __ESTIMATOR_HPP
#define __ESTIMATOR_HPP

#include "Estimator/ConvertEstimator.h"
#include "common.h"

namespace Estimator{
    
class PositionVelocityEstimator
{
public:
    PositionVelocityEstimator(/* args */);
    ~PositionVelocityEstimator();

    // 用 RobotState 更新内部估计状态
    void update(const RobotState& state);

    // 获取 MPC 所需的估计结果
    ConvertEstimatorForMPC get_estresult();

private:
    ConvertEstimatorForMPC result_;
};

inline PositionVelocityEstimator::PositionVelocityEstimator(/* args */)
{
}

inline PositionVelocityEstimator::~PositionVelocityEstimator()
{
}

}


#endif