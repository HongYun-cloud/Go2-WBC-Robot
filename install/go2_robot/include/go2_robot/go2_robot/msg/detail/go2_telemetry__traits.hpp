// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice

#ifndef GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__TRAITS_HPP_
#define GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "go2_robot/msg/detail/go2_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace go2_robot
{

namespace msg
{

inline void to_flow_style_yaml(
  const Go2Telemetry & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: p_ref_fl_x
  {
    out << "p_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_x, out);
    out << ", ";
  }

  // member: p_ref_fl_y
  {
    out << "p_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_y, out);
    out << ", ";
  }

  // member: p_ref_fl_z
  {
    out << "p_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_z, out);
    out << ", ";
  }

  // member: p_ref_fr_x
  {
    out << "p_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_x, out);
    out << ", ";
  }

  // member: p_ref_fr_y
  {
    out << "p_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_y, out);
    out << ", ";
  }

  // member: p_ref_fr_z
  {
    out << "p_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_z, out);
    out << ", ";
  }

  // member: p_ref_rl_x
  {
    out << "p_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_x, out);
    out << ", ";
  }

  // member: p_ref_rl_y
  {
    out << "p_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_y, out);
    out << ", ";
  }

  // member: p_ref_rl_z
  {
    out << "p_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_z, out);
    out << ", ";
  }

  // member: p_ref_rr_x
  {
    out << "p_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_x, out);
    out << ", ";
  }

  // member: p_ref_rr_y
  {
    out << "p_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_y, out);
    out << ", ";
  }

  // member: p_ref_rr_z
  {
    out << "p_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_z, out);
    out << ", ";
  }

  // member: p_act_fl_x
  {
    out << "p_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_x, out);
    out << ", ";
  }

  // member: p_act_fl_y
  {
    out << "p_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_y, out);
    out << ", ";
  }

  // member: p_act_fl_z
  {
    out << "p_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_z, out);
    out << ", ";
  }

  // member: p_act_fr_x
  {
    out << "p_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_x, out);
    out << ", ";
  }

  // member: p_act_fr_y
  {
    out << "p_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_y, out);
    out << ", ";
  }

  // member: p_act_fr_z
  {
    out << "p_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_z, out);
    out << ", ";
  }

  // member: p_act_rl_x
  {
    out << "p_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_x, out);
    out << ", ";
  }

  // member: p_act_rl_y
  {
    out << "p_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_y, out);
    out << ", ";
  }

  // member: p_act_rl_z
  {
    out << "p_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_z, out);
    out << ", ";
  }

  // member: p_act_rr_x
  {
    out << "p_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_x, out);
    out << ", ";
  }

  // member: p_act_rr_y
  {
    out << "p_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_y, out);
    out << ", ";
  }

  // member: p_act_rr_z
  {
    out << "p_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_z, out);
    out << ", ";
  }

  // member: v_ref_fl_x
  {
    out << "v_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_x, out);
    out << ", ";
  }

  // member: v_ref_fl_y
  {
    out << "v_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_y, out);
    out << ", ";
  }

  // member: v_ref_fl_z
  {
    out << "v_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_z, out);
    out << ", ";
  }

  // member: v_ref_fr_x
  {
    out << "v_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_x, out);
    out << ", ";
  }

  // member: v_ref_fr_y
  {
    out << "v_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_y, out);
    out << ", ";
  }

  // member: v_ref_fr_z
  {
    out << "v_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_z, out);
    out << ", ";
  }

  // member: v_ref_rl_x
  {
    out << "v_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_x, out);
    out << ", ";
  }

  // member: v_ref_rl_y
  {
    out << "v_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_y, out);
    out << ", ";
  }

  // member: v_ref_rl_z
  {
    out << "v_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_z, out);
    out << ", ";
  }

  // member: v_ref_rr_x
  {
    out << "v_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_x, out);
    out << ", ";
  }

  // member: v_ref_rr_y
  {
    out << "v_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_y, out);
    out << ", ";
  }

  // member: v_ref_rr_z
  {
    out << "v_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_z, out);
    out << ", ";
  }

  // member: v_act_fl_x
  {
    out << "v_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_x, out);
    out << ", ";
  }

  // member: v_act_fl_y
  {
    out << "v_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_y, out);
    out << ", ";
  }

  // member: v_act_fl_z
  {
    out << "v_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_z, out);
    out << ", ";
  }

  // member: v_act_fr_x
  {
    out << "v_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_x, out);
    out << ", ";
  }

  // member: v_act_fr_y
  {
    out << "v_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_y, out);
    out << ", ";
  }

  // member: v_act_fr_z
  {
    out << "v_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_z, out);
    out << ", ";
  }

  // member: v_act_rl_x
  {
    out << "v_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_x, out);
    out << ", ";
  }

  // member: v_act_rl_y
  {
    out << "v_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_y, out);
    out << ", ";
  }

  // member: v_act_rl_z
  {
    out << "v_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_z, out);
    out << ", ";
  }

  // member: v_act_rr_x
  {
    out << "v_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_x, out);
    out << ", ";
  }

  // member: v_act_rr_y
  {
    out << "v_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_y, out);
    out << ", ";
  }

  // member: v_act_rr_z
  {
    out << "v_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_z, out);
    out << ", ";
  }

  // member: a_ref_fl_x
  {
    out << "a_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_x, out);
    out << ", ";
  }

  // member: a_ref_fl_y
  {
    out << "a_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_y, out);
    out << ", ";
  }

  // member: a_ref_fl_z
  {
    out << "a_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_z, out);
    out << ", ";
  }

  // member: a_ref_fr_x
  {
    out << "a_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_x, out);
    out << ", ";
  }

  // member: a_ref_fr_y
  {
    out << "a_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_y, out);
    out << ", ";
  }

  // member: a_ref_fr_z
  {
    out << "a_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_z, out);
    out << ", ";
  }

  // member: a_ref_rl_x
  {
    out << "a_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_x, out);
    out << ", ";
  }

  // member: a_ref_rl_y
  {
    out << "a_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_y, out);
    out << ", ";
  }

  // member: a_ref_rl_z
  {
    out << "a_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_z, out);
    out << ", ";
  }

  // member: a_ref_rr_x
  {
    out << "a_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_x, out);
    out << ", ";
  }

  // member: a_ref_rr_y
  {
    out << "a_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_y, out);
    out << ", ";
  }

  // member: a_ref_rr_z
  {
    out << "a_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_z, out);
    out << ", ";
  }

  // member: a_act_fl_x
  {
    out << "a_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_x, out);
    out << ", ";
  }

  // member: a_act_fl_y
  {
    out << "a_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_y, out);
    out << ", ";
  }

  // member: a_act_fl_z
  {
    out << "a_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_z, out);
    out << ", ";
  }

  // member: a_act_fr_x
  {
    out << "a_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_x, out);
    out << ", ";
  }

  // member: a_act_fr_y
  {
    out << "a_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_y, out);
    out << ", ";
  }

  // member: a_act_fr_z
  {
    out << "a_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_z, out);
    out << ", ";
  }

  // member: a_act_rl_x
  {
    out << "a_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_x, out);
    out << ", ";
  }

  // member: a_act_rl_y
  {
    out << "a_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_y, out);
    out << ", ";
  }

  // member: a_act_rl_z
  {
    out << "a_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_z, out);
    out << ", ";
  }

  // member: a_act_rr_x
  {
    out << "a_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_x, out);
    out << ", ";
  }

  // member: a_act_rr_y
  {
    out << "a_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_y, out);
    out << ", ";
  }

  // member: a_act_rr_z
  {
    out << "a_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_z, out);
    out << ", ";
  }

  // member: f_mpc_fl_x
  {
    out << "f_mpc_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_x, out);
    out << ", ";
  }

  // member: f_mpc_fl_y
  {
    out << "f_mpc_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_y, out);
    out << ", ";
  }

  // member: f_mpc_fl_z
  {
    out << "f_mpc_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_z, out);
    out << ", ";
  }

  // member: f_mpc_fr_x
  {
    out << "f_mpc_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_x, out);
    out << ", ";
  }

  // member: f_mpc_fr_y
  {
    out << "f_mpc_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_y, out);
    out << ", ";
  }

  // member: f_mpc_fr_z
  {
    out << "f_mpc_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_z, out);
    out << ", ";
  }

  // member: f_mpc_rl_x
  {
    out << "f_mpc_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_x, out);
    out << ", ";
  }

  // member: f_mpc_rl_y
  {
    out << "f_mpc_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_y, out);
    out << ", ";
  }

  // member: f_mpc_rl_z
  {
    out << "f_mpc_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_z, out);
    out << ", ";
  }

  // member: f_mpc_rr_x
  {
    out << "f_mpc_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_x, out);
    out << ", ";
  }

  // member: f_mpc_rr_y
  {
    out << "f_mpc_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_y, out);
    out << ", ";
  }

  // member: f_mpc_rr_z
  {
    out << "f_mpc_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_z, out);
    out << ", ";
  }

  // member: f_wbc_fl_x
  {
    out << "f_wbc_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_x, out);
    out << ", ";
  }

  // member: f_wbc_fl_y
  {
    out << "f_wbc_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_y, out);
    out << ", ";
  }

  // member: f_wbc_fl_z
  {
    out << "f_wbc_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_z, out);
    out << ", ";
  }

  // member: f_wbc_fr_x
  {
    out << "f_wbc_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_x, out);
    out << ", ";
  }

  // member: f_wbc_fr_y
  {
    out << "f_wbc_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_y, out);
    out << ", ";
  }

  // member: f_wbc_fr_z
  {
    out << "f_wbc_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_z, out);
    out << ", ";
  }

  // member: f_wbc_rl_x
  {
    out << "f_wbc_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_x, out);
    out << ", ";
  }

  // member: f_wbc_rl_y
  {
    out << "f_wbc_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_y, out);
    out << ", ";
  }

  // member: f_wbc_rl_z
  {
    out << "f_wbc_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_z, out);
    out << ", ";
  }

  // member: f_wbc_rr_x
  {
    out << "f_wbc_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_x, out);
    out << ", ";
  }

  // member: f_wbc_rr_y
  {
    out << "f_wbc_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_y, out);
    out << ", ";
  }

  // member: f_wbc_rr_z
  {
    out << "f_wbc_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_z, out);
    out << ", ";
  }

  // member: contact_fl
  {
    out << "contact_fl: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_fl, out);
    out << ", ";
  }

  // member: contact_fr
  {
    out << "contact_fr: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_fr, out);
    out << ", ";
  }

  // member: contact_rl
  {
    out << "contact_rl: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_rl, out);
    out << ", ";
  }

  // member: contact_rr
  {
    out << "contact_rr: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_rr, out);
    out << ", ";
  }

  // member: body_x
  {
    out << "body_x: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x, out);
    out << ", ";
  }

  // member: body_z
  {
    out << "body_z: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z, out);
    out << ", ";
  }

  // member: body_x_v
  {
    out << "body_x_v: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x_v, out);
    out << ", ";
  }

  // member: body_z_v
  {
    out << "body_z_v: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z_v, out);
    out << ", ";
  }

  // member: body_x_v_d
  {
    out << "body_x_v_d: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x_v_d, out);
    out << ", ";
  }

  // member: body_z_v_d
  {
    out << "body_z_v_d: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z_v_d, out);
    out << ", ";
  }

  // member: q_des_lin_x
  {
    out << "q_des_lin_x: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_x, out);
    out << ", ";
  }

  // member: q_des_lin_y
  {
    out << "q_des_lin_y: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_y, out);
    out << ", ";
  }

  // member: q_des_lin_z
  {
    out << "q_des_lin_z: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_z, out);
    out << ", ";
  }

  // member: q_des_ang_x
  {
    out << "q_des_ang_x: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_x, out);
    out << ", ";
  }

  // member: q_des_ang_y
  {
    out << "q_des_ang_y: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_y, out);
    out << ", ";
  }

  // member: q_des_ang_z
  {
    out << "q_des_ang_z: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_z, out);
    out << ", ";
  }

  // member: q_des_joint_0
  {
    out << "q_des_joint_0: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_0, out);
    out << ", ";
  }

  // member: q_des_joint_1
  {
    out << "q_des_joint_1: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_1, out);
    out << ", ";
  }

  // member: q_des_joint_2
  {
    out << "q_des_joint_2: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_2, out);
    out << ", ";
  }

  // member: q_des_joint_3
  {
    out << "q_des_joint_3: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_3, out);
    out << ", ";
  }

  // member: q_des_joint_4
  {
    out << "q_des_joint_4: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_4, out);
    out << ", ";
  }

  // member: q_des_joint_5
  {
    out << "q_des_joint_5: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_5, out);
    out << ", ";
  }

  // member: q_des_joint_6
  {
    out << "q_des_joint_6: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_6, out);
    out << ", ";
  }

  // member: q_des_joint_7
  {
    out << "q_des_joint_7: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_7, out);
    out << ", ";
  }

  // member: q_des_joint_8
  {
    out << "q_des_joint_8: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_8, out);
    out << ", ";
  }

  // member: q_des_joint_9
  {
    out << "q_des_joint_9: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_9, out);
    out << ", ";
  }

  // member: q_des_joint_10
  {
    out << "q_des_joint_10: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_10, out);
    out << ", ";
  }

  // member: q_des_joint_11
  {
    out << "q_des_joint_11: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_11, out);
    out << ", ";
  }

  // member: tau_yaw_mpc
  {
    out << "tau_yaw_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_yaw_mpc, out);
    out << ", ";
  }

  // member: tau_yaw_wbc
  {
    out << "tau_yaw_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_yaw_wbc, out);
    out << ", ";
  }

  // member: f_cone_fl
  {
    out << "f_cone_fl: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_fl, out);
    out << ", ";
  }

  // member: f_cone_fr
  {
    out << "f_cone_fr: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_fr, out);
    out << ", ";
  }

  // member: f_cone_rl
  {
    out << "f_cone_rl: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_rl, out);
    out << ", ";
  }

  // member: f_cone_rr
  {
    out << "f_cone_rr: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_rr, out);
    out << ", ";
  }

  // member: tau_roll_mpc
  {
    out << "tau_roll_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_roll_mpc, out);
    out << ", ";
  }

  // member: tau_roll_wbc
  {
    out << "tau_roll_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_roll_wbc, out);
    out << ", ";
  }

  // member: tau_pitch_mpc
  {
    out << "tau_pitch_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_pitch_mpc, out);
    out << ", ";
  }

  // member: tau_pitch_wbc
  {
    out << "tau_pitch_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_pitch_wbc, out);
    out << ", ";
  }

  // member: a_wbc_ang_x
  {
    out << "a_wbc_ang_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_x, out);
    out << ", ";
  }

  // member: a_wbc_ang_y
  {
    out << "a_wbc_ang_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_y, out);
    out << ", ";
  }

  // member: a_wbc_ang_z
  {
    out << "a_wbc_ang_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_z, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Go2Telemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: p_ref_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_x, out);
    out << "\n";
  }

  // member: p_ref_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_y, out);
    out << "\n";
  }

  // member: p_ref_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fl_z, out);
    out << "\n";
  }

  // member: p_ref_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_x, out);
    out << "\n";
  }

  // member: p_ref_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_y, out);
    out << "\n";
  }

  // member: p_ref_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_fr_z, out);
    out << "\n";
  }

  // member: p_ref_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_x, out);
    out << "\n";
  }

  // member: p_ref_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_y, out);
    out << "\n";
  }

  // member: p_ref_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rl_z, out);
    out << "\n";
  }

  // member: p_ref_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_x, out);
    out << "\n";
  }

  // member: p_ref_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_y, out);
    out << "\n";
  }

  // member: p_ref_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_ref_rr_z, out);
    out << "\n";
  }

  // member: p_act_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_x, out);
    out << "\n";
  }

  // member: p_act_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_y, out);
    out << "\n";
  }

  // member: p_act_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fl_z, out);
    out << "\n";
  }

  // member: p_act_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_x, out);
    out << "\n";
  }

  // member: p_act_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_y, out);
    out << "\n";
  }

  // member: p_act_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_fr_z, out);
    out << "\n";
  }

  // member: p_act_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_x, out);
    out << "\n";
  }

  // member: p_act_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_y, out);
    out << "\n";
  }

  // member: p_act_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rl_z, out);
    out << "\n";
  }

  // member: p_act_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_x, out);
    out << "\n";
  }

  // member: p_act_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_y, out);
    out << "\n";
  }

  // member: p_act_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.p_act_rr_z, out);
    out << "\n";
  }

  // member: v_ref_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_x, out);
    out << "\n";
  }

  // member: v_ref_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_y, out);
    out << "\n";
  }

  // member: v_ref_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fl_z, out);
    out << "\n";
  }

  // member: v_ref_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_x, out);
    out << "\n";
  }

  // member: v_ref_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_y, out);
    out << "\n";
  }

  // member: v_ref_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_fr_z, out);
    out << "\n";
  }

  // member: v_ref_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_x, out);
    out << "\n";
  }

  // member: v_ref_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_y, out);
    out << "\n";
  }

  // member: v_ref_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rl_z, out);
    out << "\n";
  }

  // member: v_ref_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_x, out);
    out << "\n";
  }

  // member: v_ref_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_y, out);
    out << "\n";
  }

  // member: v_ref_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_ref_rr_z, out);
    out << "\n";
  }

  // member: v_act_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_x, out);
    out << "\n";
  }

  // member: v_act_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_y, out);
    out << "\n";
  }

  // member: v_act_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fl_z, out);
    out << "\n";
  }

  // member: v_act_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_x, out);
    out << "\n";
  }

  // member: v_act_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_y, out);
    out << "\n";
  }

  // member: v_act_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_fr_z, out);
    out << "\n";
  }

  // member: v_act_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_x, out);
    out << "\n";
  }

  // member: v_act_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_y, out);
    out << "\n";
  }

  // member: v_act_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rl_z, out);
    out << "\n";
  }

  // member: v_act_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_x, out);
    out << "\n";
  }

  // member: v_act_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_y, out);
    out << "\n";
  }

  // member: v_act_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "v_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.v_act_rr_z, out);
    out << "\n";
  }

  // member: a_ref_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_x, out);
    out << "\n";
  }

  // member: a_ref_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_y, out);
    out << "\n";
  }

  // member: a_ref_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fl_z, out);
    out << "\n";
  }

  // member: a_ref_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_x, out);
    out << "\n";
  }

  // member: a_ref_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_y, out);
    out << "\n";
  }

  // member: a_ref_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_fr_z, out);
    out << "\n";
  }

  // member: a_ref_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_x, out);
    out << "\n";
  }

  // member: a_ref_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_y, out);
    out << "\n";
  }

  // member: a_ref_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rl_z, out);
    out << "\n";
  }

  // member: a_ref_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_x, out);
    out << "\n";
  }

  // member: a_ref_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_y, out);
    out << "\n";
  }

  // member: a_ref_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_ref_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_ref_rr_z, out);
    out << "\n";
  }

  // member: a_act_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_x, out);
    out << "\n";
  }

  // member: a_act_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_y, out);
    out << "\n";
  }

  // member: a_act_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fl_z, out);
    out << "\n";
  }

  // member: a_act_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_x, out);
    out << "\n";
  }

  // member: a_act_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_y, out);
    out << "\n";
  }

  // member: a_act_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_fr_z, out);
    out << "\n";
  }

  // member: a_act_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_x, out);
    out << "\n";
  }

  // member: a_act_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_y, out);
    out << "\n";
  }

  // member: a_act_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rl_z, out);
    out << "\n";
  }

  // member: a_act_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_x, out);
    out << "\n";
  }

  // member: a_act_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_y, out);
    out << "\n";
  }

  // member: a_act_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_act_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_act_rr_z, out);
    out << "\n";
  }

  // member: f_mpc_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_x, out);
    out << "\n";
  }

  // member: f_mpc_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_y, out);
    out << "\n";
  }

  // member: f_mpc_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fl_z, out);
    out << "\n";
  }

  // member: f_mpc_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_x, out);
    out << "\n";
  }

  // member: f_mpc_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_y, out);
    out << "\n";
  }

  // member: f_mpc_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_fr_z, out);
    out << "\n";
  }

  // member: f_mpc_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_x, out);
    out << "\n";
  }

  // member: f_mpc_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_y, out);
    out << "\n";
  }

  // member: f_mpc_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rl_z, out);
    out << "\n";
  }

  // member: f_mpc_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_x, out);
    out << "\n";
  }

  // member: f_mpc_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_y, out);
    out << "\n";
  }

  // member: f_mpc_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_mpc_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_mpc_rr_z, out);
    out << "\n";
  }

  // member: f_wbc_fl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_x, out);
    out << "\n";
  }

  // member: f_wbc_fl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_y, out);
    out << "\n";
  }

  // member: f_wbc_fl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fl_z, out);
    out << "\n";
  }

  // member: f_wbc_fr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_x, out);
    out << "\n";
  }

  // member: f_wbc_fr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_y, out);
    out << "\n";
  }

  // member: f_wbc_fr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_fr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_fr_z, out);
    out << "\n";
  }

  // member: f_wbc_rl_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rl_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_x, out);
    out << "\n";
  }

  // member: f_wbc_rl_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rl_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_y, out);
    out << "\n";
  }

  // member: f_wbc_rl_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rl_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rl_z, out);
    out << "\n";
  }

  // member: f_wbc_rr_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rr_x: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_x, out);
    out << "\n";
  }

  // member: f_wbc_rr_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rr_y: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_y, out);
    out << "\n";
  }

  // member: f_wbc_rr_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_wbc_rr_z: ";
    rosidl_generator_traits::value_to_yaml(msg.f_wbc_rr_z, out);
    out << "\n";
  }

  // member: contact_fl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contact_fl: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_fl, out);
    out << "\n";
  }

  // member: contact_fr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contact_fr: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_fr, out);
    out << "\n";
  }

  // member: contact_rl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contact_rl: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_rl, out);
    out << "\n";
  }

  // member: contact_rr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "contact_rr: ";
    rosidl_generator_traits::value_to_yaml(msg.contact_rr, out);
    out << "\n";
  }

  // member: body_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_x: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x, out);
    out << "\n";
  }

  // member: body_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_z: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z, out);
    out << "\n";
  }

  // member: body_x_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_x_v: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x_v, out);
    out << "\n";
  }

  // member: body_z_v
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_z_v: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z_v, out);
    out << "\n";
  }

  // member: body_x_v_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_x_v_d: ";
    rosidl_generator_traits::value_to_yaml(msg.body_x_v_d, out);
    out << "\n";
  }

  // member: body_z_v_d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "body_z_v_d: ";
    rosidl_generator_traits::value_to_yaml(msg.body_z_v_d, out);
    out << "\n";
  }

  // member: q_des_lin_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_lin_x: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_x, out);
    out << "\n";
  }

  // member: q_des_lin_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_lin_y: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_y, out);
    out << "\n";
  }

  // member: q_des_lin_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_lin_z: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_lin_z, out);
    out << "\n";
  }

  // member: q_des_ang_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_ang_x: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_x, out);
    out << "\n";
  }

  // member: q_des_ang_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_ang_y: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_y, out);
    out << "\n";
  }

  // member: q_des_ang_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_ang_z: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_ang_z, out);
    out << "\n";
  }

  // member: q_des_joint_0
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_0: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_0, out);
    out << "\n";
  }

  // member: q_des_joint_1
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_1: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_1, out);
    out << "\n";
  }

  // member: q_des_joint_2
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_2: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_2, out);
    out << "\n";
  }

  // member: q_des_joint_3
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_3: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_3, out);
    out << "\n";
  }

  // member: q_des_joint_4
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_4: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_4, out);
    out << "\n";
  }

  // member: q_des_joint_5
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_5: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_5, out);
    out << "\n";
  }

  // member: q_des_joint_6
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_6: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_6, out);
    out << "\n";
  }

  // member: q_des_joint_7
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_7: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_7, out);
    out << "\n";
  }

  // member: q_des_joint_8
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_8: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_8, out);
    out << "\n";
  }

  // member: q_des_joint_9
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_9: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_9, out);
    out << "\n";
  }

  // member: q_des_joint_10
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_10: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_10, out);
    out << "\n";
  }

  // member: q_des_joint_11
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "q_des_joint_11: ";
    rosidl_generator_traits::value_to_yaml(msg.q_des_joint_11, out);
    out << "\n";
  }

  // member: tau_yaw_mpc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_yaw_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_yaw_mpc, out);
    out << "\n";
  }

  // member: tau_yaw_wbc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_yaw_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_yaw_wbc, out);
    out << "\n";
  }

  // member: f_cone_fl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_cone_fl: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_fl, out);
    out << "\n";
  }

  // member: f_cone_fr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_cone_fr: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_fr, out);
    out << "\n";
  }

  // member: f_cone_rl
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_cone_rl: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_rl, out);
    out << "\n";
  }

  // member: f_cone_rr
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "f_cone_rr: ";
    rosidl_generator_traits::value_to_yaml(msg.f_cone_rr, out);
    out << "\n";
  }

  // member: tau_roll_mpc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_roll_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_roll_mpc, out);
    out << "\n";
  }

  // member: tau_roll_wbc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_roll_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_roll_wbc, out);
    out << "\n";
  }

  // member: tau_pitch_mpc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_pitch_mpc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_pitch_mpc, out);
    out << "\n";
  }

  // member: tau_pitch_wbc
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "tau_pitch_wbc: ";
    rosidl_generator_traits::value_to_yaml(msg.tau_pitch_wbc, out);
    out << "\n";
  }

  // member: a_wbc_ang_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_wbc_ang_x: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_x, out);
    out << "\n";
  }

  // member: a_wbc_ang_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_wbc_ang_y: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_y, out);
    out << "\n";
  }

  // member: a_wbc_ang_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "a_wbc_ang_z: ";
    rosidl_generator_traits::value_to_yaml(msg.a_wbc_ang_z, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Go2Telemetry & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace go2_robot

namespace rosidl_generator_traits
{

[[deprecated("use go2_robot::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const go2_robot::msg::Go2Telemetry & msg,
  std::ostream & out, size_t indentation = 0)
{
  go2_robot::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use go2_robot::msg::to_yaml() instead")]]
inline std::string to_yaml(const go2_robot::msg::Go2Telemetry & msg)
{
  return go2_robot::msg::to_yaml(msg);
}

template<>
inline const char * data_type<go2_robot::msg::Go2Telemetry>()
{
  return "go2_robot::msg::Go2Telemetry";
}

template<>
inline const char * name<go2_robot::msg::Go2Telemetry>()
{
  return "go2_robot/msg/Go2Telemetry";
}

template<>
struct has_fixed_size<go2_robot::msg::Go2Telemetry>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<go2_robot::msg::Go2Telemetry>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<go2_robot::msg::Go2Telemetry>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__TRAITS_HPP_
