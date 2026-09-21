## 目标
全接触站立，WBC 只用 H1（姿态/高度 PD 经 `q_d` 驱动），不用 MPC 的力跟踪，也不做摆动腿跟踪。

## 已完成（plan mode 生效前已落盘，尚未编译）
1. `src/WBC/WBC.cpp` `compuseHg()`：`H += H1; g += g1;`，H2/H3 连同代码注释保留（含 `swing_row_leg_` 逐腿取权重的 H3 循环，便于以后再启用）
2. `src/WBC/WBC.cpp` `update()`：恢复 `std::fill(contact_states_, ..., 1)`

## 剩余改动

**3. `src/MPC/MPC.cpp`** — 在 `contact_expanded` 组装完成后恢复 `std::fill(contact_expanded..., 1)`（位置在 `_qpconstraint->updateConstraints(...)` 之前）

**4. `src/ros2/go2_control_node.cpp`** — 在 `state.contact_states[leg] = (scheduler->GetSwingPhases(leg) <= 0) ? 1 : 0;` 之后恢复 `std::fill(state.contact_states..., true)`

**5. 步态切 STAND（关闭迈步）**
- `launch/go2_sim.launch.py:47` 的 `'gait'` 默认值 `TROT` → `STAND`
- `config/go2_params.yaml:17` 的 `initial_gait: "TROT"` → `"STAND"`（保持一致，不经过 launch 直接跑时也对）
- `Preset::STAND {duty=1.0}`，相位恒不超过 duty → `GetSwingPhases` 永不返回摆动 → 调度器本身就给出全接触；所以第 3、4 条的强制全接触在这个模式下是冗余的，但按你的要求一并恢复（也防着手滑改回 TROT）

**6. 编译**：`colcon build --packages-select go2_robot`

## 为什么只用 H1 能站住

H1 是 `A_qᵀ W A_q` 配 `b_q = q_d`，即把决策变量里的加速度 `a` 拉向 `q_d`。而 `q_d` 来自 `computePoseAccDes` 的高度/姿态 PD：
- `a_lin = Kp_lin(0,0,50)·e_p_z + Kd_lin(10,10,10)·e_v`（位置只管 z）
- `a_ang = Kp_ang(500,100,100)·e_rpy + Kd_ang(20,20,20)·e_w`

高度到位、速度为零时 `q_d_z = 0`，于是 QP 把 `a_z` 钉在 0，**接触力由硬约束的动力学方程解出来**：`m·a_z + m·g = Σfz` ⇒ `Σfz = 157.8 N = mg`。这跟 H2 走的是两条路 —— H2 是"跟踪 MPC 给的力"，H1 是"钉住加速度、让动力学反解出力"。后者完全不依赖 MPC，也不需要 MPC 的质量参数准确。

H2/H3 关掉后接触力的代价项只剩 1e-3 的对角正则，所以四足力分配接近最小范数解；站立是对称的，摩擦锥余量充足。

## 起来后重点看
- `body_z` 稳在 0.25 m（不再是 0.27 起步后漂）
- `f_wbc_*_z` 四条约 39.4 N，且四腿基本均匀
- `a_wbc_ang_*` 与 `q_des_ang_*` **符号应同向** —— 这是本轮修掉雅可比符号后第一次能对上的地方，之前必然反号

## 切回迈步时需要做的（三处）
1. 取消 `compuseHg()` 里 H2/H3 的注释
2. 删掉三处 `std::fill(...)` 全接触
3. `gait:=TROT`

## 仍在的已知问题（本轮不动）
`state.angular_vel` 是机体系（已用 MuJoCo 实测确认），而 WBC 的 `v_full_` 配的是世界系雅可比，角速度项存在 `(Rᵀ−I)ω×r` 的二阶失配；`setBaseVelocity` 的语义也需要一起理清。属独立问题，trot 时约百分之几量级。