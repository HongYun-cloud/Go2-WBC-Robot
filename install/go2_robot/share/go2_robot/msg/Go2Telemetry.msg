# Go2 控制遥测: 供 PlotJuggler (ROS2 Topic Subscriber) 绘图
# 字段名与原 PlotSend UDP JSON key 一一对应 (contract_* 笔误已改为 contact_*)
# 足端字段顺序均为 FL, FR, RL, RR × x, y, z (世界系)
std_msgs/Header header

# 摆动轨迹参考/实际足端位置
float64 p_ref_fl_x
float64 p_ref_fl_y
float64 p_ref_fl_z
float64 p_ref_fr_x
float64 p_ref_fr_y
float64 p_ref_fr_z
float64 p_ref_rl_x
float64 p_ref_rl_y
float64 p_ref_rl_z
float64 p_ref_rr_x
float64 p_ref_rr_y
float64 p_ref_rr_z

float64 p_act_fl_x
float64 p_act_fl_y
float64 p_act_fl_z
float64 p_act_fr_x
float64 p_act_fr_y
float64 p_act_fr_z
float64 p_act_rl_x
float64 p_act_rl_y
float64 p_act_rl_z
float64 p_act_rr_x
float64 p_act_rr_y
float64 p_act_rr_z

# 摆动轨迹参考/实际足端速度
float64 v_ref_fl_x
float64 v_ref_fl_y
float64 v_ref_fl_z
float64 v_ref_fr_x
float64 v_ref_fr_y
float64 v_ref_fr_z
float64 v_ref_rl_x
float64 v_ref_rl_y
float64 v_ref_rl_z
float64 v_ref_rr_x
float64 v_ref_rr_y
float64 v_ref_rr_z

float64 v_act_fl_x
float64 v_act_fl_y
float64 v_act_fl_z
float64 v_act_fr_x
float64 v_act_fr_y
float64 v_act_fr_z
float64 v_act_rl_x
float64 v_act_rl_y
float64 v_act_rl_z
float64 v_act_rr_x
float64 v_act_rr_y
float64 v_act_rr_z

# a_ref = a_des (摆动前馈加速度 + 阻抗修正), a_act = v_act 数值微分
float64 a_ref_fl_x
float64 a_ref_fl_y
float64 a_ref_fl_z
float64 a_ref_fr_x
float64 a_ref_fr_y
float64 a_ref_fr_z
float64 a_ref_rl_x
float64 a_ref_rl_y
float64 a_ref_rl_z
float64 a_ref_rr_x
float64 a_ref_rr_y
float64 a_ref_rr_z

float64 a_act_fl_x
float64 a_act_fl_y
float64 a_act_fl_z
float64 a_act_fr_x
float64 a_act_fr_y
float64 a_act_fr_z
float64 a_act_rl_x
float64 a_act_rl_y
float64 a_act_rl_z
float64 a_act_rr_x
float64 a_act_rr_y
float64 a_act_rr_z

# MPC / WBC 足端接触力
float64 f_mpc_fl_x
float64 f_mpc_fl_y
float64 f_mpc_fl_z
float64 f_mpc_fr_x
float64 f_mpc_fr_y
float64 f_mpc_fr_z
float64 f_mpc_rl_x
float64 f_mpc_rl_y
float64 f_mpc_rl_z
float64 f_mpc_rr_x
float64 f_mpc_rr_y
float64 f_mpc_rr_z

float64 f_wbc_fl_x
float64 f_wbc_fl_y
float64 f_wbc_fl_z
float64 f_wbc_fr_x
float64 f_wbc_fr_y
float64 f_wbc_fr_z
float64 f_wbc_rl_x
float64 f_wbc_rl_y
float64 f_wbc_rl_z
float64 f_wbc_rr_x
float64 f_wbc_rr_y
float64 f_wbc_rr_z

# 计划接触状态 (1=支撑, 0=摆动)
float64 contact_fl
float64 contact_fr
float64 contact_rl
float64 contact_rr

# 机身位置/速度 (x, z) 与期望速度 (body_x_v_d = v[0], body_z_v_d = v[2])
float64 body_x
float64 body_z
float64 body_x_v
float64 body_z_v
float64 body_x_v_d
float64 body_z_v_d
# WBC 期望加速度 q_des (computePoseAccDes 输出: 基座线3 + 角3 + 关节12)
float64 q_des_lin_x
float64 q_des_lin_y
float64 q_des_lin_z
float64 q_des_ang_x
float64 q_des_ang_y
float64 q_des_ang_z
float64 q_des_joint_0
float64 q_des_joint_1
float64 q_des_joint_2
float64 q_des_joint_3
float64 q_des_joint_4
float64 q_des_joint_5
float64 q_des_joint_6
float64 q_des_joint_7
float64 q_des_joint_8
float64 q_des_joint_9
float64 q_des_joint_10
float64 q_des_joint_11

# 诊断: 偏航力矩 Σ(x·fy − y·fx) (世界系, 足端相对机身) 与摩擦锥利用率 |ft|/(μ·fz), μ=0.5
float64 tau_yaw_mpc
float64 tau_yaw_wbc
float64 f_cone_fl
float64 f_cone_fr
float64 f_cone_rl
float64 f_cone_rr

# 诊断: roll/pitch 力矩 Σ(r × f) (世界系, 足端相对机身), 与 tau_yaw 配套
float64 tau_roll_mpc
float64 tau_roll_wbc
float64 tau_pitch_mpc
float64 tau_pitch_wbc

# 诊断: WBC QP 解出的基座角加速度 (机体系, sol.head(18) 第3~5维), 与 q_des_ang 对比用
float64 a_wbc_ang_x
float64 a_wbc_ang_y
float64 a_wbc_ang_z

# 关节力矩 τ = M·a + h − Jᵀf (WBC 逆动力学, 即 mj->control(tau) 的输入)
# 顺序: FL_hip,FL_thigh,FL_calf, FR_hip,FR_thigh,FR_calf, RL_*, RR_* (12 维, 与 q_des_joint_* 同序)
float64 tau_joint_0
float64 tau_joint_1
float64 tau_joint_2
float64 tau_joint_3
float64 tau_joint_4
float64 tau_joint_5
float64 tau_joint_6
float64 tau_joint_7
float64 tau_joint_8
float64 tau_joint_9
float64 tau_joint_10
float64 tau_joint_11
