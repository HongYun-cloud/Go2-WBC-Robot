## 目标
把 go2/go2.xml 里 13 个 body 的惯量改成与 URDF 合并后完全一致，使 MuJoCo plant 的总质量从 15.2064 kg 变成 16.0870 kg，与控制器（pinocchio/URDF）对齐。

## 背景
- 控制器侧（URDF）：`getTotalMassInertia` 和 `computeFloatingBaseDynamics` 都读 URDF，总质量 16.0870 kg
- plant 侧（MJCF）：CAD 显式惯量，总质量 15.2064 kg，少 0.8806 kg
- 差的 0.88 kg 来自 URDF 里 12 个 rotor link（0.089×12）和 head；MJCF 没有这些
- 结果：MPC 按 16.087 kg 出力 157.8 N，plant 只需 149.2 N → 净 +8.6 N → 上飘 0.56 m/s²（已数值验证）

## 逐 body 目标值（来自固定基座 pinocchio 模型的 model.inertias[i]，合计 16.0870）

| body | mass | CoM (body 系) | 主惯量 (kg·m²) |
|---|---|---|---|
| base_link | 7.279 | (0.02015, 0, −0.00511) | 0.02571, 0.10312, 0.11284 |
| *_hip ×4 | 0.767 | (∓0.00477, ∓0.00170, −0.00009) | 0.000540, 0.000658, 0.000998 |
| *_thigh ×4 | 1.241 | (−0.00347, ∓0.02302, −0.03035) | 0.000942, 0.006004, 0.006152 |
| *_calf ×4 | 0.194 | (0.00435, ∓0.00077, −0.13521) | 0.0000434, 0.0013946, 0.0014156 |

## 实现
只改 go2/go2.xml 里 13 个 `<inertial .../>` 块（base_link + 4×(hip/thigh/calf)），改成：

```xml
<inertial pos="px py pz" mass="m" fullinertia="ixx iyy izz ixy ixz iyz" />
```

- 用 `fullinertia`（6 分量）而不是 `diaginertia`+`quat`，避免特征向量分解和四元数方向约定的风险
- 不写 `quat`/`rpy` → `fullinertia` 就是 body 系下的惯量，与 pinocchio 的 `Inertia`（lever + 绕质心的 3×3）语义一致
- 已验证 MJCF body 系与 URDF 关节系重合（FL_hip 的 MJCF `pos=-0.0054` 与 pinocchio `lever=-0.00477` 同系，差值正好由 thigh_rotor 的 0.089 kg 引起）

## 不改动
- 4 个 `*_foot` body（本来就没有 inertial、质量 0；URDF 的 foot 0.040 kg 已并入 calf）
- base_link 的 `pos="0 0 0.445"` 和 `childclass="go2"`
- 任何控制器代码；URDF 视为准

## 配套改动（必须成对，否则会走向另一个极端）
`src/Model/pinocchio.cpp:192` 的循环要从 `i = 1` 回到 `i = 0`。

因为 getTotalMassInertia 决定 MPC 用的质量，三个取值给出三种结果（已数值验证）：

| MPC 质量 | WBC 解出 Σfz | plant(16.087) 需要 157.8 N | 表现 |
|---|---|---|---|
| 8.808 (i=1) | 86.34 | −71.5 | 欠载下沉 |
| **16.087 (i=0)** | **157.66** | **≈ 0** | **保持** |

MJCF 改成 16.087 之后，只有 i=0 配对正确。这一步和 MJCF 改动是同一个修复的两半。

## 验证
1. `mj_getTotalmass` 应为 16.0870（现为 15.2064）
2. 逐个 body 对比 MuJoCo 的 `body_mass` 和 `body_inertia` 特征值与 pinocchio —— 这一条同时能验出 `fullinertia` 的 6 分量顺序和 off-diagonal 符号是否写对
3. 重跑站立力平衡：Σfz 应 ≈ 157.8 N，与 plant 需求净差 ≈ 0 → 保持
4. `colcon build --packages-select go2_robot` 确认无编译问题

## 顺带提请知悉
改完后 plant 变重 0.88 kg，腿的摆动惯量也随之增加（thigh 的 0.0060 不变但 hip 的第三分量从 0.00048 升到 0.000998），摆动腿的响应会比现在略钝。这是让 plant 与控制器一致所必需的代价。