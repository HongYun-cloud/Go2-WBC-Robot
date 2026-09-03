# Go2 控制项目迁移 ROS 2 (Humble) 方案

## 目标

把 main.cpp 的单线程 while(1) 循环封装为 ROS 2 节点 `Go2ControlNode`，实现：
- **WBC 主控制循环 500Hz**（wall timer，实时层）
- **MPC 异步低频 100Hz**（独立线程 + mutex，不阻塞 WBC）
- 所有原有类、函数、变量、算法、参数**零修改**，只重新编排调用时序
- ROS 2 标准 Publisher / Subscriber / 参数机制
- 结构支持未来扩展新 Controller / Sensor

## 现状数据流（迁移必须保持的依赖关系）

```
mj->getState()  ─→ state (RobotState)
  ├─ 计划接触覆写 (scheduler->GetSwingPhases)      [WBC 线程, 500Hz]
  ├─ estimator->update(state)                       [WBC 线程] ← MPC 线程通过 get_estresult() 读!
  ├─ pin->forwardKinematics(...)                    [WBC 线程] ← MPC 通过 setLegData() 裸指针读 leg_data_!
  ├─ mpc->update() + solve()                        [MPC 线程, 100Hz] ← 读 estimator + legData 指针
  │     └─ getControl() → f_mpc                     [双缓冲交换给 WBC]
  ├─ wbc->update(q_des, f_mpc, a_des, state) + solve [WBC 线程] ← 读 pin (M-, h-, J-)
  └─ pin->getJointTorquesFromSolution → tau → mj->control + mj->Step + Render
```

**关键线程安全结论（读过源码后确认）：**
1. `MPC::update()` 调 `estimator->get_estresult()`（返回值拷贝，但 estimator 由 WBC 线程写）→ estimator 读写需 mutex
2. `MPC` 通过 `setLegData(pin->getLegData())` 持有 Pinocchio 内部 `legData` 裸指针，`ConfigUpdata()` 直接解引用 → 跨线程裸指针，需 mutex 保护（保护调用方，不改类）
3. `MPC` 析构会 `delete estimator`（MPC.cpp 析构里 `delete estimator` 是 bug，但**禁止修改原代码**）→ 迁移后用堆分配 estimator 让这个 delete 无害化
4. `WBC::update()` 大量读 `_pin`（M/h/J/dJ），与 MPC 线程通过 legData 指针读 pin 的 `leg_data_` 不冲突（不同成员），但保险起见 MPC 调用段整体加锁
5. `fsm->run(dt)` 内部 `scheduler->step` + `trajectory->Generate`（后者读 estimator + 写 control_point）→ 留在 WBC 线程
6. MuJoCo viewer (GLFW) 必须在主线程渲染 → **主循环用 500Hz wall timer，viewer 渲染放 timer 回调内**（rclcpp 单线程 spin 时 timer 即主线程）

## 目录结构（标准 ament 包）

```
Go2Robot/                          # 保持原仓库根 (git 历史不破坏)
├── CMakeLists.txt                 # 重写: ament_cmake 包
├── package.xml                    # 新增
├── config/
│   ├── mpc.yaml                   # 保留 (MPC/WBC 权重, 原样)
│   └── go2_params.yaml            # 新增: ROS 2 参数 (频率/路径/初始指令)
├── go2/                           # 原样 (URDF/scene)
├── include/                       # 原样, 新增:
│   └── ros2/
│       └── go2_control_node.hpp   # Go2ControlNode 类
├── src/
│   ├── ... (全部原有 .cpp 原样)
│   └── ros2/
│       └── go2_control_node.cpp   # 节点实现 (原 main.cpp 逻辑)
│       └── main.cpp               # 新入口: 仅 rclcpp::init + spin
└── third_party/osqp-eigen         # 原样
```

原 `src/main.cpp` 保留为 `src/main_standalone.cpp`（加 `#if 0` 或不编译），方便对照，不删除。

## Go2ControlNode 设计

```cpp
class Go2ControlNode : public rclcpp::Node {
public:
    Go2ControlNode();   // 所有原 main() 初始化段搬进构造函数
    ~Go2ControlNode();

private:
    // ===== 原有对象 (成员化, 原名保留) =====
    std::shared_ptr<Gait::GaitScheduler> scheduler;
    std::shared_ptr<Estimator::PositionVelocityEstimator> estimator;
    std::shared_ptr<SwingPlanner::SwingLegPlanner> trajectory;
    std::unique_ptr<fsm::ControlFSM> fsm;
    MJCSIM::SIM* mj;                 // 原裸指针保留
    Pinocchio::PinocchioKinematics* pin;
    Regulator::MPC* mpc;
    WBC::WBC* wbc;

    // ===== 主循环状态 (从 main.cpp 原样搬入) =====
    Eigen::Vector3d v, w, q, p;
    double sim_dt;
    int count = 0;
    Eigen::Matrix<double,12,1> v_foot_prev, a_foot_act;
    bool have_prev_v = false;

    // ===== 双线程基础设施 =====
    std::thread mpc_thread_;
    std::atomic<bool> mpc_running_{false};
    std::atomic<bool> rclcpp_running_{true};
    std::mutex mpc_data_mutex_;       // 保护 estimator 交换 + MPC 调用段 + f_mpc 交换

    // ===== MPC ↔ WBC 交换缓冲 =====
    Eigen::Matrix<double,12,1> f_mpc_shared_;   // MPC 线程写, WBC 线程读
    bool f_mpc_valid_ = false;

    // ===== ROS 2 接口 =====
    rclcpp::Publisher<geometry_msgs::msg::Odometry>::SharedPtr odom_pub_;
    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_state_pub_;
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr foot_force_pub_;
    rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr cmd_sub_;

    // ===== 定时器 =====
    rclcpp::TimerBase::SharedPtr wbc_timer_;    // 500Hz
    rclcpp::TimerBase::SharedPtr pub_timer_;    // 50Hz 发布状态 (发布不在实时循环里做)

    // ===== 核心函数 (原 main 循环体拆分, 逻辑零修改) =====
    void wbcControlLoop();       // 500Hz: 原 while(1) 体 = FSM + 估计 + FK + WBC + 力矩 + mj_step
    void mpcSolveLoop();         // 独立线程: mpc->update + solve → 写 f_mpc_shared_
    void publishState();         // 50Hz: odom + joint_state + 足端力
    void cmdVelCallback(const geometry_msgs::msg::Twist::SharedPtr msg);  // 替代键盘 w/s
};
```

### 时序设计（重点）

**WBC timer 500Hz** (`wbcControlLoop`)：
1. `fsm->run(sim_dt)` — 步态调度 + 摆动轨迹（保持原顺序）
2. `state = mj->getState()` — 计划接触覆写
3. `{lock} estimator->update(state); pin->forwardKinematics(...); trajectory->SetFootPositions(...)` — 写共享数据，短暂持锁
4. 用 `f_mpc_shared_`（双缓冲快照，mutex 拷贝 12 double，微秒级）作为 `f_mpc`
5. 足端速度/加速度计算（原逻辑原样）
6. `wbc->update(q_des, f_mpc, a_des, state); wbc->solve(); GetSolution` → tau
7. `mj->control(tau); mj->Step(); mj->Render();` — Render 保持在与 GLFW 创建线程相同的 timer 线程

**MPC 线程 100Hz** (`mpcSolveLoop`)：
```cpp
while (rclcpp_running_) {
    auto t0 = steady_clock::now();
    {
        std::lock_guard lk(mpc_data_mutex_);
        // 拷贝 estimator 快照 + 保护 legData 裸指针读取段
        mpc->update();      // 内部 get_estresult() + ConfigUpdata 读 legData 指针
        mpc->solve();
        f_mpc_shared_ = mpc->getControl();
        f_mpc_valid_ = true;
    }
    std::this_thread::sleep_until(t0 + 10ms);
}
```
- MPC QP 求解（N=20, dt=0.02）物理上不可能在 2ms 内完成 → 异步线程是唯一能让 WBC 跑满 500Hz 的方式，正好符合任务要求
- 持锁时间 = MPC 求解时间（~5-15ms）。WBC 线程每 2ms 要锁一次 → **WBC 会被 MPC 阻塞**。
  对策：**细化锁**。拆两把锁：
  - `estimator_mutex_`：只保护 `estimator->update()` / `get_estresult()`（WBC 写 0.1ms，MPC 读拷贝）
  - `mpc_call_mutex_`：保护 `mpc->update()+solve()` 整段（包含 legData 裸指针读取）
  - WBC 线程只在第 3 步拿 `estimator_mutex_`（微秒级），**不拿 `mpc_call_mutex_`**
  - legData 裸指针：MPC 的 `ConfigUpdata` 读 `pin->leg_data_`（FK 后由 WBC 线程写）→ 让 WBC 在 `pin->forwardKinematics` 段与 MPC 的 `mpc->update()` 段互斥（都拿 `mpc_call_mutex_`，持锁都在 ms 级以下…实际上 MPC update 只是读 12 个 vector + 组矩阵，solve 才慢 → **把 update 和 solve 拆开持锁**：`update()` 拿 `mpc_call_mutex_`（快），`solve()` 不拿锁（纯计算,不碰共享数据,只有 OSQP 内部状态 + 刚拷贝的本地数据）
  
  最终锁协议：
  ```
  WBC 500Hz:  lock(estimator_mutex_) estimator->update + est 快照
              lock(mpc_call_mutex_)  pin->forwardKinematics + trajectory->SetFootPositions
              ... WBC 全部计算 (无锁, 只读本地快照) ...
              mj->control/Step/Render (无锁)
  MPC 100Hz:  lock(estimator_mutex_) est = estimator->get_estresult()   // 已在 mpc->update 内, 外面包一把
              lock(mpc_call_mutex_)  mpc->update()   // 读 est 快照 + legData 指针, 组 QP 数据
              (无锁) mpc->solve()                    // 纯计算: OSQP 迭代, 只碰自己内存
              lock(f_mutex_) f_mpc_shared_ = getControl()
  ```
  WBC 持锁最长的操作是 `pin->forwardKinematics`（~0.1ms 级）→ MPC 最多等 0.1ms，可接受。
  MPC 持 `mpc_call_mutex_` 的是 update（~0.2ms），solve 不持锁 → WBC 最多等 0.2ms。

  ⚠️ 但 `mpc->update()` 内部调 `estimator->get_estresult()` 直接读 estimator，与 WBC 的 `estimator->update()` 并发 → 需在同一把 `estimator_mutex_` 下。MPC 线程拿锁顺序：`estimator_mutex_` → `mpc_call_mutex_`，WBC 相同顺序 → 无死锁。

**发布 50Hz** (`publishState`)：单独 timer，从最新 state 快照发布 odom / joint_states / 足端力，序列化不占实时循环。

**指令 Sub**：`/cmd_vel` (geometry_msgs/Twist) → 写 `v`（原子或小 mutex），完全替代原键盘 w/s 逻辑；键盘代码不搬（terminal raw 模式与 ROS 日志冲突）。

### 与原逻辑的差异清单（仅时序，非算法）

| 原 main.cpp | 迁移后 | 理由 |
|---|---|---|
| 每圈 `mpc->update()+solve()` (500Hz) | MPC 线程 100Hz | 任务要求; QP 本来跑不满 500Hz |
| `f_mpc` 当圈用 | 上一拍 MPC 解 + 0.01s 龄期 | MPC 异步的固有代价, 100Hz 时 10ms 延迟对 0.02s 步长 MPC 可接受 |
| 键盘 w/s | `/cmd_vel` sub | ROS 标准化; 键盘与节点化冲突 |
| PlotJuggler UDP | 保留在 WBC 循环内(每10帧) | 原逻辑原样, 非阻塞 sendto |
| `while(1)` 无退出 | SIGINT → rclcpp shutdown + 线程 join | ROS 生命周期 |

**初始化段（构造函数）零修改搬入**：包括首次 `wbc->update/solve`、`setModelParams`（URDF 真值）、`fsm->SetCmd(TROT)`、`fsm->SetState(GAIT_RUNNING)`、`sim_dt = mj->getTimestep()`。

## ROS 2 参数 (config/go2_params.yaml)

```yaml
go2_control_node:
  ros__parameters:
    control_frequency: 500.0     # WBC 频率 (必须 == 1/mujoco timestep)
    mpc_frequency: 100.0
    publish_frequency: 50.0
    mujoco_model: "go2/scene.xml"
    urdf_path: "go2/go2_description.urdf"
    mpc_config: "config/mpc.yaml"
    initial_gait: "TROT"
    desired_height: 0.25
```
路径解析：参数给相对路径时基于 `package share` 目录或工作区根（用 `ament_index_cpp` 或运行目录探测，简单起见先支持绝对路径 + 相对 CWD 双回退，与原行为一致）。
频率类参数运行时声明为 `declare_parameter` + `get_parameter`。

## CMakeLists.txt / package.xml

- `find_package(ament_cmake REQUIRED)` + rclcpp / geometry_msgs / sensor_msgs / std_msgs
- 保留原有全部依赖段（MuJoCo / GLFW / GLEW / OpenGL / Threads / yaml-cpp / osqp-eigen 子目录 / pinocchio ROS 路径）
- 库目标 `go2_core` STATIC：MPC.cpp / WBC.cpp / pinocchio.cpp / GaitScheduler.cpp / SwingLegPlanner.cpp / ControlFSM.cpp / MJCsim.cpp / Estimator.cpp（**全部原样**）
- 可执行 `go2_control_node`：ros2/go2_control_node.cpp + ros2/main.cpp，链 go2_core + rclcpp 等
- `install(TARGETS ... DESTINATION lib/${PROJECT_NAME})` + config/go2_params.yaml install 到 share
- package.xml：depend rclcpp, geometry_msgs, sensor_msgs, std_msgs, pinocchio, eigen3_cmake_module

## 验证步骤

1. `colcon build --packages-select go2_robot` (在 Go2Robot 目录直接 colcon, 或软链到独立 ws)
2. `ros2 run go2_robot go2_control_node` → viewer 弹出, 原地踏步行为与迁移前一致
3. `ros2 topic hz /odom` ≈ 50Hz; `ros2 topic echo /cmd_vel` 打字发布验证速度指令
4. 观察无锁竞争导致的段错误 (跑 30s+)
5. 对比迁移前后 PlotJuggler 曲线 (步高/摆动周期一致)

## 风险与备注

- **MPC delete estimator bug**：MPC 析构 `delete estimator`，estimator 若是栈/共享对象会 double-free → 节点里 estimator 用 `new` 堆分配裸指针交给 shared_ptr + 自定义 deleter 不拦截……**最稳妥：estimator `new` 出来不 delete（泄漏一个对象无所谓），或节点析构顺序保证 MPC 先死**。采用：estimator 堆分配 + MPC 先析构（成员声明顺序控制），析构链 MPC→WBC→…→estimator，MPC delete estimator 后节点不再 touch，最后 estimator 指针置空不重复 delete。
- GLFW context：所有 `mj->Render()` 必须在创建窗口的线程 → WBC timer 用主线程 spin（单线程 executor），节点构造（InitMujoco 创建窗口）在 main 主线程 → 一致。
- 500Hz wall timer 抖动：Linux 非实时调度下 timer 精度 ~50-100μs，物理 0.002s 步长足够。若实测 WBC 循环耗时 > 2ms（WBC QP + FK），降 timestep 至 0.005 或 WBC 频率参数化后调 250Hz。
- osqp-eigen `add_subdirectory` 与 ament 全局变量污染：CMake 里 `add_subdirectory(third_party/osqp-eigen)` 需在其前 `set(...EXCLUDE_FROM_ALL)` 视情况处理,保持原样优先。
