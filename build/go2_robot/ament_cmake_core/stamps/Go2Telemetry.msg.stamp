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