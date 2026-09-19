## Part A —— 关掉全接触 + 恢复 H1/H3（你要的）

**1. 删掉三处全接触 override**
- `src/ros2/go2_control_node.cpp:242-243` 的 `std::fill(state.contact_states..., true)`
- `src/MPC/MPC.cpp:113-114` 的 `std::fill(contact_expanded..., 1)`
- `src/WBC/WBC.cpp:68-69` 的 `std::fill(contact_states_..., 1)`

三处删掉后，接触统一来自 `scheduler->GetSwingPhases()`，node 写进 `state.contact_states`，MPC 用 `contact_sched_` 滚动预测，WBC 用同一份 —— 三层首次真正一致。

**2. `src/WBC/WBC.cpp` `compuseHg()` 恢复 H1 与 H3**

`H = H1 + H2 + H3`，`g = g1 + g2 + g3`，保留现有对角正则。

两个必须处理的地方：

- **原注释块里的 `row * 3` 编译不过** —— `row` 是未定义标识符（这正是它当初被整段注释掉的直接原因）。应改用 `contact_num * 3`。
- **`C` 的 12 维权重是按腿排的，而 `A_a` 是按摆动计数紧凑打包的**，直接 `topRows(contact_num*3)` 会把权重错配。`C = [200,200,500, 200,200,500, 200,200,200, 200,200,200]` 本意是"前腿 z 权重 500"。TROT 的两组摆动腿是 FL+RR 和 FR+RL，打包后第一组拿到的永远是前 6 个权重，于是 RR 会拿到本该属于 FL 的 500（2.5 倍偏差）。
  做法：在 `update()` 里记录打包顺序 `swing_row_leg_[contact_num] = leg`，`compuseHg()` 里按每条摆动腿取它自己的 `C.block<3,3>(leg*3, leg*3)` 累加，不再用 `topRows` 切片。

**3. `wbc->init()` 提到第一次 `wbc->update()` 之前**
`go2_control_node.cpp:103` 先 update、`105` 才 init，而 `WBC.cpp` 的 `@warning` 明确要求先 init。现在 `init()` 才设 `A_q`/`A_f` 的单位块，顺序反了会让首帧的 H1/H2 全为零。影响仅一帧，但既然 H1/H2 都启用了就该摆正。

**4. `/cmd_vel` 接到步幅上**
`fsm->SetCmd(type, v)` 现在只在 init 调一次，`Gait_cmd.v` 恒为 0 → 摆动规划器只会**原地踏步**，发 `/cmd_vel` 不会前进。把 `fsm->SetCmd` 移到循环里（与 `mpc->update_DesireStateCommand` 同一个 `cmd_mutex_` 锁段内）。`FSM::run()` 内部有 `_last_gait_type` 守卫，每拍调只更新速度和类型字段，不会重置相位，安全。

**Part A 验证**：`contact_fl/fr/rl/rr` 应按 TROT 相位交替；`p_ref_*_z` 应抬起而 `p_act_*_z` 跟随；`f_mpc_*_z` 在支撑腿约 79 N（半身重）。

## Part B —— 强烈建议同一轮做（姿态通道现在是错的，摆相必振）

`src/Model/pinocchio.cpp` `computeFloatingBaseDynamics()` 里：

```cpp
M_fb_.block<3,3>(3, 3) = Eigen::Matrix3d::Identity();   // 基座转动块 = I₃
h_fb_(2) = total_mass * g;                              // 只有平动重力
h_fb_.tail(12) = data_->tau;                            // 关节重力矩
                                                        // h_fb_(3:6) 恒为 0
```

两个后果，都会在迈步时直接显形：

- **角加速度约束少了 1/I**。WBC 的行是 `a_ang = Σ(r×f)`，而物理是 `Σ(r×f) = I·a_ang`。真实 `I ≈ (0.24, 0.55, 0.54)`，于是姿态环实际增益是需求的 **4.2 倍（roll）/ 1.8 倍（pitch, yaw）** —— 站立时看不出来（目标是 0），一旦摆动腿产生反作用力矩就会振荡发散。
- **重力对机身的力矩没进 h**。CoM 相对基座原点偏移 `c ≈ (0.0083, 0, -0.0285)`，`c × (m·g) ≈ +1.31 N·m`（pitch）。WBC 少算这份支撑力矩 → 恒定前倾偏置。

修法：`M_fb_(3:6,3:6)` 用绕基座原点的复合惯量 `I_origin = I_com + m(cᵀc·I − c·cᵀ)`；补上线性-转动耦合 `M_fb_(0:3,3:6) = -m·skew(c)`、`M_fb_(3:6,0:3) = m·skew(c)`；`h_fb_(3:6) = c × (m·g)`。这些量在同一函数里从 `model_->inertias` 就能算出来。

**验证方式**：项目里已经建好了自由飞轮模型 `model_fb_`，直接用 `pin.crba(model_fb_, data_fb_, q_fb)` 得到真实的 18×18 浮动基座质量矩阵（注意自由飞轮的基座速度是机体系，要转到世界系对齐），逐块对比我拼出来的 `M_fb_`。这样改完不是"看起来对"，而是能和 pinocchio 对上。

## 不改动
- `getTotalMassInertia`（上一轮已修好，16.087）
- `go2.xml`（上一轮已对齐）
- 约束矩阵布局（那 12 行零行仍留着，另案处理）

如果你只想先看 Part A 的步态表现，告诉我，我把 Part B 留到下一轮。