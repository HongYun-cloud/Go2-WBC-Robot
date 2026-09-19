# 模型
go2和gow文件夹分别存放模型不要混用，新模型建议新建文件夹并加入go2_params

# config
go2_params存放urdf和xml的模型路径，还有ros2的控制频率等
mpc存放wbc和mpc相关参数，名字之后改吧
# src/fsm
未完成：
存放状态机部分（stand,run,stop）

# src/Planner
已完成：
scheduler是步态的调度器，计算相位等信息
SwingLegPlanner是轨迹生成，返回当前移动的一个point
未完成：
BaseTrajectoryPlanner机身的移动规划器，用于之后接雷达等规划路线，也可以接手柄

# Estimator
未完成：
PositionVelocityEstimator估计当前位置和速度的估计器，目前暂时直接使用的sim里的数据，做了一个装饰器进入
之后写的时候可以直接修改get_estresult来使用实际估计值




