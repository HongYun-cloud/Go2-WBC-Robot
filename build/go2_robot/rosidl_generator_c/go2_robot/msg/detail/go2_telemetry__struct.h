// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice

#ifndef GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_H_
#define GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/Go2Telemetry in the package go2_robot.
/**
  * Go2 控制遥测: 供 PlotJuggler (ROS2 Topic Subscriber) 绘图
  * 字段名与原 PlotSend UDP JSON key 一一对应 (contract_* 笔误已改为 contact_*)
  * 足端字段顺序均为 FL, FR, RL, RR × x, y, z (世界系)
 */
typedef struct go2_robot__msg__Go2Telemetry
{
  std_msgs__msg__Header header;
  /// 摆动轨迹参考/实际足端位置
  double p_ref_fl_x;
  double p_ref_fl_y;
  double p_ref_fl_z;
  double p_ref_fr_x;
  double p_ref_fr_y;
  double p_ref_fr_z;
  double p_ref_rl_x;
  double p_ref_rl_y;
  double p_ref_rl_z;
  double p_ref_rr_x;
  double p_ref_rr_y;
  double p_ref_rr_z;
  double p_act_fl_x;
  double p_act_fl_y;
  double p_act_fl_z;
  double p_act_fr_x;
  double p_act_fr_y;
  double p_act_fr_z;
  double p_act_rl_x;
  double p_act_rl_y;
  double p_act_rl_z;
  double p_act_rr_x;
  double p_act_rr_y;
  double p_act_rr_z;
  /// 摆动轨迹参考/实际足端速度
  double v_ref_fl_x;
  double v_ref_fl_y;
  double v_ref_fl_z;
  double v_ref_fr_x;
  double v_ref_fr_y;
  double v_ref_fr_z;
  double v_ref_rl_x;
  double v_ref_rl_y;
  double v_ref_rl_z;
  double v_ref_rr_x;
  double v_ref_rr_y;
  double v_ref_rr_z;
  double v_act_fl_x;
  double v_act_fl_y;
  double v_act_fl_z;
  double v_act_fr_x;
  double v_act_fr_y;
  double v_act_fr_z;
  double v_act_rl_x;
  double v_act_rl_y;
  double v_act_rl_z;
  double v_act_rr_x;
  double v_act_rr_y;
  double v_act_rr_z;
  /// a_ref = a_des (摆动前馈加速度 + 阻抗修正), a_act = v_act 数值微分
  double a_ref_fl_x;
  double a_ref_fl_y;
  double a_ref_fl_z;
  double a_ref_fr_x;
  double a_ref_fr_y;
  double a_ref_fr_z;
  double a_ref_rl_x;
  double a_ref_rl_y;
  double a_ref_rl_z;
  double a_ref_rr_x;
  double a_ref_rr_y;
  double a_ref_rr_z;
  double a_act_fl_x;
  double a_act_fl_y;
  double a_act_fl_z;
  double a_act_fr_x;
  double a_act_fr_y;
  double a_act_fr_z;
  double a_act_rl_x;
  double a_act_rl_y;
  double a_act_rl_z;
  double a_act_rr_x;
  double a_act_rr_y;
  double a_act_rr_z;
  /// MPC / WBC 足端接触力
  double f_mpc_fl_x;
  double f_mpc_fl_y;
  double f_mpc_fl_z;
  double f_mpc_fr_x;
  double f_mpc_fr_y;
  double f_mpc_fr_z;
  double f_mpc_rl_x;
  double f_mpc_rl_y;
  double f_mpc_rl_z;
  double f_mpc_rr_x;
  double f_mpc_rr_y;
  double f_mpc_rr_z;
  double f_wbc_fl_x;
  double f_wbc_fl_y;
  double f_wbc_fl_z;
  double f_wbc_fr_x;
  double f_wbc_fr_y;
  double f_wbc_fr_z;
  double f_wbc_rl_x;
  double f_wbc_rl_y;
  double f_wbc_rl_z;
  double f_wbc_rr_x;
  double f_wbc_rr_y;
  double f_wbc_rr_z;
  /// 计划接触状态 (1=支撑, 0=摆动)
  double contact_fl;
  double contact_fr;
  double contact_rl;
  double contact_rr;
  /// 机身位置/速度 (x, z) 与期望速度 (body_x_v_d = v[0], body_z_v_d = v[2])
  double body_x;
  double body_z;
  double body_x_v;
  double body_z_v;
  double body_x_v_d;
  double body_z_v_d;
} go2_robot__msg__Go2Telemetry;

// Struct for a sequence of go2_robot__msg__Go2Telemetry.
typedef struct go2_robot__msg__Go2Telemetry__Sequence
{
  go2_robot__msg__Go2Telemetry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} go2_robot__msg__Go2Telemetry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_H_
