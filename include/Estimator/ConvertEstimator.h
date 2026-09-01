#ifndef __CONVERT_ESTIMATOR_H
#define __CONVERT_ESTIMATOR_H

#include <iostream>
#include "Eigen/Dense"

namespace Estimator
{
using Vec3d = Eigen::Vector3d;


struct ConvertEstimatorForMPC
{
    Vec3d p; // 位置 
    Vec3d v; // 机身线速度
    Vec3d q; // 世界坐标系下欧拉角
    Vec3d w; // 机身角速度

    std::vector<int> contact_states;
};
    
} // namespace Estimator








#endif // __CONVERT_ESTIMATOR_H

