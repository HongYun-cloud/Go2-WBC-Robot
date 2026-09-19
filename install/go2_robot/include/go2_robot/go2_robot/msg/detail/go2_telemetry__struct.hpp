// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice

#ifndef GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_HPP_
#define GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__go2_robot__msg__Go2Telemetry __attribute__((deprecated))
#else
# define DEPRECATED__go2_robot__msg__Go2Telemetry __declspec(deprecated)
#endif

namespace go2_robot
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Go2Telemetry_
{
  using Type = Go2Telemetry_<ContainerAllocator>;

  explicit Go2Telemetry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p_ref_fl_x = 0.0;
      this->p_ref_fl_y = 0.0;
      this->p_ref_fl_z = 0.0;
      this->p_ref_fr_x = 0.0;
      this->p_ref_fr_y = 0.0;
      this->p_ref_fr_z = 0.0;
      this->p_ref_rl_x = 0.0;
      this->p_ref_rl_y = 0.0;
      this->p_ref_rl_z = 0.0;
      this->p_ref_rr_x = 0.0;
      this->p_ref_rr_y = 0.0;
      this->p_ref_rr_z = 0.0;
      this->p_act_fl_x = 0.0;
      this->p_act_fl_y = 0.0;
      this->p_act_fl_z = 0.0;
      this->p_act_fr_x = 0.0;
      this->p_act_fr_y = 0.0;
      this->p_act_fr_z = 0.0;
      this->p_act_rl_x = 0.0;
      this->p_act_rl_y = 0.0;
      this->p_act_rl_z = 0.0;
      this->p_act_rr_x = 0.0;
      this->p_act_rr_y = 0.0;
      this->p_act_rr_z = 0.0;
      this->v_ref_fl_x = 0.0;
      this->v_ref_fl_y = 0.0;
      this->v_ref_fl_z = 0.0;
      this->v_ref_fr_x = 0.0;
      this->v_ref_fr_y = 0.0;
      this->v_ref_fr_z = 0.0;
      this->v_ref_rl_x = 0.0;
      this->v_ref_rl_y = 0.0;
      this->v_ref_rl_z = 0.0;
      this->v_ref_rr_x = 0.0;
      this->v_ref_rr_y = 0.0;
      this->v_ref_rr_z = 0.0;
      this->v_act_fl_x = 0.0;
      this->v_act_fl_y = 0.0;
      this->v_act_fl_z = 0.0;
      this->v_act_fr_x = 0.0;
      this->v_act_fr_y = 0.0;
      this->v_act_fr_z = 0.0;
      this->v_act_rl_x = 0.0;
      this->v_act_rl_y = 0.0;
      this->v_act_rl_z = 0.0;
      this->v_act_rr_x = 0.0;
      this->v_act_rr_y = 0.0;
      this->v_act_rr_z = 0.0;
      this->a_ref_fl_x = 0.0;
      this->a_ref_fl_y = 0.0;
      this->a_ref_fl_z = 0.0;
      this->a_ref_fr_x = 0.0;
      this->a_ref_fr_y = 0.0;
      this->a_ref_fr_z = 0.0;
      this->a_ref_rl_x = 0.0;
      this->a_ref_rl_y = 0.0;
      this->a_ref_rl_z = 0.0;
      this->a_ref_rr_x = 0.0;
      this->a_ref_rr_y = 0.0;
      this->a_ref_rr_z = 0.0;
      this->a_act_fl_x = 0.0;
      this->a_act_fl_y = 0.0;
      this->a_act_fl_z = 0.0;
      this->a_act_fr_x = 0.0;
      this->a_act_fr_y = 0.0;
      this->a_act_fr_z = 0.0;
      this->a_act_rl_x = 0.0;
      this->a_act_rl_y = 0.0;
      this->a_act_rl_z = 0.0;
      this->a_act_rr_x = 0.0;
      this->a_act_rr_y = 0.0;
      this->a_act_rr_z = 0.0;
      this->f_mpc_fl_x = 0.0;
      this->f_mpc_fl_y = 0.0;
      this->f_mpc_fl_z = 0.0;
      this->f_mpc_fr_x = 0.0;
      this->f_mpc_fr_y = 0.0;
      this->f_mpc_fr_z = 0.0;
      this->f_mpc_rl_x = 0.0;
      this->f_mpc_rl_y = 0.0;
      this->f_mpc_rl_z = 0.0;
      this->f_mpc_rr_x = 0.0;
      this->f_mpc_rr_y = 0.0;
      this->f_mpc_rr_z = 0.0;
      this->f_wbc_fl_x = 0.0;
      this->f_wbc_fl_y = 0.0;
      this->f_wbc_fl_z = 0.0;
      this->f_wbc_fr_x = 0.0;
      this->f_wbc_fr_y = 0.0;
      this->f_wbc_fr_z = 0.0;
      this->f_wbc_rl_x = 0.0;
      this->f_wbc_rl_y = 0.0;
      this->f_wbc_rl_z = 0.0;
      this->f_wbc_rr_x = 0.0;
      this->f_wbc_rr_y = 0.0;
      this->f_wbc_rr_z = 0.0;
      this->contact_fl = 0.0;
      this->contact_fr = 0.0;
      this->contact_rl = 0.0;
      this->contact_rr = 0.0;
      this->body_x = 0.0;
      this->body_z = 0.0;
      this->body_x_v = 0.0;
      this->body_z_v = 0.0;
      this->body_x_v_d = 0.0;
      this->body_z_v_d = 0.0;
      this->q_des_lin_x = 0.0;
      this->q_des_lin_y = 0.0;
      this->q_des_lin_z = 0.0;
      this->q_des_ang_x = 0.0;
      this->q_des_ang_y = 0.0;
      this->q_des_ang_z = 0.0;
      this->q_des_joint_0 = 0.0;
      this->q_des_joint_1 = 0.0;
      this->q_des_joint_2 = 0.0;
      this->q_des_joint_3 = 0.0;
      this->q_des_joint_4 = 0.0;
      this->q_des_joint_5 = 0.0;
      this->q_des_joint_6 = 0.0;
      this->q_des_joint_7 = 0.0;
      this->q_des_joint_8 = 0.0;
      this->q_des_joint_9 = 0.0;
      this->q_des_joint_10 = 0.0;
      this->q_des_joint_11 = 0.0;
      this->tau_yaw_mpc = 0.0;
      this->tau_yaw_wbc = 0.0;
      this->f_cone_fl = 0.0;
      this->f_cone_fr = 0.0;
      this->f_cone_rl = 0.0;
      this->f_cone_rr = 0.0;
      this->tau_roll_mpc = 0.0;
      this->tau_roll_wbc = 0.0;
      this->tau_pitch_mpc = 0.0;
      this->tau_pitch_wbc = 0.0;
      this->a_wbc_ang_x = 0.0;
      this->a_wbc_ang_y = 0.0;
      this->a_wbc_ang_z = 0.0;
      this->tau_joint_0 = 0.0;
      this->tau_joint_1 = 0.0;
      this->tau_joint_2 = 0.0;
      this->tau_joint_3 = 0.0;
      this->tau_joint_4 = 0.0;
      this->tau_joint_5 = 0.0;
      this->tau_joint_6 = 0.0;
      this->tau_joint_7 = 0.0;
      this->tau_joint_8 = 0.0;
      this->tau_joint_9 = 0.0;
      this->tau_joint_10 = 0.0;
      this->tau_joint_11 = 0.0;
    }
  }

  explicit Go2Telemetry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->p_ref_fl_x = 0.0;
      this->p_ref_fl_y = 0.0;
      this->p_ref_fl_z = 0.0;
      this->p_ref_fr_x = 0.0;
      this->p_ref_fr_y = 0.0;
      this->p_ref_fr_z = 0.0;
      this->p_ref_rl_x = 0.0;
      this->p_ref_rl_y = 0.0;
      this->p_ref_rl_z = 0.0;
      this->p_ref_rr_x = 0.0;
      this->p_ref_rr_y = 0.0;
      this->p_ref_rr_z = 0.0;
      this->p_act_fl_x = 0.0;
      this->p_act_fl_y = 0.0;
      this->p_act_fl_z = 0.0;
      this->p_act_fr_x = 0.0;
      this->p_act_fr_y = 0.0;
      this->p_act_fr_z = 0.0;
      this->p_act_rl_x = 0.0;
      this->p_act_rl_y = 0.0;
      this->p_act_rl_z = 0.0;
      this->p_act_rr_x = 0.0;
      this->p_act_rr_y = 0.0;
      this->p_act_rr_z = 0.0;
      this->v_ref_fl_x = 0.0;
      this->v_ref_fl_y = 0.0;
      this->v_ref_fl_z = 0.0;
      this->v_ref_fr_x = 0.0;
      this->v_ref_fr_y = 0.0;
      this->v_ref_fr_z = 0.0;
      this->v_ref_rl_x = 0.0;
      this->v_ref_rl_y = 0.0;
      this->v_ref_rl_z = 0.0;
      this->v_ref_rr_x = 0.0;
      this->v_ref_rr_y = 0.0;
      this->v_ref_rr_z = 0.0;
      this->v_act_fl_x = 0.0;
      this->v_act_fl_y = 0.0;
      this->v_act_fl_z = 0.0;
      this->v_act_fr_x = 0.0;
      this->v_act_fr_y = 0.0;
      this->v_act_fr_z = 0.0;
      this->v_act_rl_x = 0.0;
      this->v_act_rl_y = 0.0;
      this->v_act_rl_z = 0.0;
      this->v_act_rr_x = 0.0;
      this->v_act_rr_y = 0.0;
      this->v_act_rr_z = 0.0;
      this->a_ref_fl_x = 0.0;
      this->a_ref_fl_y = 0.0;
      this->a_ref_fl_z = 0.0;
      this->a_ref_fr_x = 0.0;
      this->a_ref_fr_y = 0.0;
      this->a_ref_fr_z = 0.0;
      this->a_ref_rl_x = 0.0;
      this->a_ref_rl_y = 0.0;
      this->a_ref_rl_z = 0.0;
      this->a_ref_rr_x = 0.0;
      this->a_ref_rr_y = 0.0;
      this->a_ref_rr_z = 0.0;
      this->a_act_fl_x = 0.0;
      this->a_act_fl_y = 0.0;
      this->a_act_fl_z = 0.0;
      this->a_act_fr_x = 0.0;
      this->a_act_fr_y = 0.0;
      this->a_act_fr_z = 0.0;
      this->a_act_rl_x = 0.0;
      this->a_act_rl_y = 0.0;
      this->a_act_rl_z = 0.0;
      this->a_act_rr_x = 0.0;
      this->a_act_rr_y = 0.0;
      this->a_act_rr_z = 0.0;
      this->f_mpc_fl_x = 0.0;
      this->f_mpc_fl_y = 0.0;
      this->f_mpc_fl_z = 0.0;
      this->f_mpc_fr_x = 0.0;
      this->f_mpc_fr_y = 0.0;
      this->f_mpc_fr_z = 0.0;
      this->f_mpc_rl_x = 0.0;
      this->f_mpc_rl_y = 0.0;
      this->f_mpc_rl_z = 0.0;
      this->f_mpc_rr_x = 0.0;
      this->f_mpc_rr_y = 0.0;
      this->f_mpc_rr_z = 0.0;
      this->f_wbc_fl_x = 0.0;
      this->f_wbc_fl_y = 0.0;
      this->f_wbc_fl_z = 0.0;
      this->f_wbc_fr_x = 0.0;
      this->f_wbc_fr_y = 0.0;
      this->f_wbc_fr_z = 0.0;
      this->f_wbc_rl_x = 0.0;
      this->f_wbc_rl_y = 0.0;
      this->f_wbc_rl_z = 0.0;
      this->f_wbc_rr_x = 0.0;
      this->f_wbc_rr_y = 0.0;
      this->f_wbc_rr_z = 0.0;
      this->contact_fl = 0.0;
      this->contact_fr = 0.0;
      this->contact_rl = 0.0;
      this->contact_rr = 0.0;
      this->body_x = 0.0;
      this->body_z = 0.0;
      this->body_x_v = 0.0;
      this->body_z_v = 0.0;
      this->body_x_v_d = 0.0;
      this->body_z_v_d = 0.0;
      this->q_des_lin_x = 0.0;
      this->q_des_lin_y = 0.0;
      this->q_des_lin_z = 0.0;
      this->q_des_ang_x = 0.0;
      this->q_des_ang_y = 0.0;
      this->q_des_ang_z = 0.0;
      this->q_des_joint_0 = 0.0;
      this->q_des_joint_1 = 0.0;
      this->q_des_joint_2 = 0.0;
      this->q_des_joint_3 = 0.0;
      this->q_des_joint_4 = 0.0;
      this->q_des_joint_5 = 0.0;
      this->q_des_joint_6 = 0.0;
      this->q_des_joint_7 = 0.0;
      this->q_des_joint_8 = 0.0;
      this->q_des_joint_9 = 0.0;
      this->q_des_joint_10 = 0.0;
      this->q_des_joint_11 = 0.0;
      this->tau_yaw_mpc = 0.0;
      this->tau_yaw_wbc = 0.0;
      this->f_cone_fl = 0.0;
      this->f_cone_fr = 0.0;
      this->f_cone_rl = 0.0;
      this->f_cone_rr = 0.0;
      this->tau_roll_mpc = 0.0;
      this->tau_roll_wbc = 0.0;
      this->tau_pitch_mpc = 0.0;
      this->tau_pitch_wbc = 0.0;
      this->a_wbc_ang_x = 0.0;
      this->a_wbc_ang_y = 0.0;
      this->a_wbc_ang_z = 0.0;
      this->tau_joint_0 = 0.0;
      this->tau_joint_1 = 0.0;
      this->tau_joint_2 = 0.0;
      this->tau_joint_3 = 0.0;
      this->tau_joint_4 = 0.0;
      this->tau_joint_5 = 0.0;
      this->tau_joint_6 = 0.0;
      this->tau_joint_7 = 0.0;
      this->tau_joint_8 = 0.0;
      this->tau_joint_9 = 0.0;
      this->tau_joint_10 = 0.0;
      this->tau_joint_11 = 0.0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _p_ref_fl_x_type =
    double;
  _p_ref_fl_x_type p_ref_fl_x;
  using _p_ref_fl_y_type =
    double;
  _p_ref_fl_y_type p_ref_fl_y;
  using _p_ref_fl_z_type =
    double;
  _p_ref_fl_z_type p_ref_fl_z;
  using _p_ref_fr_x_type =
    double;
  _p_ref_fr_x_type p_ref_fr_x;
  using _p_ref_fr_y_type =
    double;
  _p_ref_fr_y_type p_ref_fr_y;
  using _p_ref_fr_z_type =
    double;
  _p_ref_fr_z_type p_ref_fr_z;
  using _p_ref_rl_x_type =
    double;
  _p_ref_rl_x_type p_ref_rl_x;
  using _p_ref_rl_y_type =
    double;
  _p_ref_rl_y_type p_ref_rl_y;
  using _p_ref_rl_z_type =
    double;
  _p_ref_rl_z_type p_ref_rl_z;
  using _p_ref_rr_x_type =
    double;
  _p_ref_rr_x_type p_ref_rr_x;
  using _p_ref_rr_y_type =
    double;
  _p_ref_rr_y_type p_ref_rr_y;
  using _p_ref_rr_z_type =
    double;
  _p_ref_rr_z_type p_ref_rr_z;
  using _p_act_fl_x_type =
    double;
  _p_act_fl_x_type p_act_fl_x;
  using _p_act_fl_y_type =
    double;
  _p_act_fl_y_type p_act_fl_y;
  using _p_act_fl_z_type =
    double;
  _p_act_fl_z_type p_act_fl_z;
  using _p_act_fr_x_type =
    double;
  _p_act_fr_x_type p_act_fr_x;
  using _p_act_fr_y_type =
    double;
  _p_act_fr_y_type p_act_fr_y;
  using _p_act_fr_z_type =
    double;
  _p_act_fr_z_type p_act_fr_z;
  using _p_act_rl_x_type =
    double;
  _p_act_rl_x_type p_act_rl_x;
  using _p_act_rl_y_type =
    double;
  _p_act_rl_y_type p_act_rl_y;
  using _p_act_rl_z_type =
    double;
  _p_act_rl_z_type p_act_rl_z;
  using _p_act_rr_x_type =
    double;
  _p_act_rr_x_type p_act_rr_x;
  using _p_act_rr_y_type =
    double;
  _p_act_rr_y_type p_act_rr_y;
  using _p_act_rr_z_type =
    double;
  _p_act_rr_z_type p_act_rr_z;
  using _v_ref_fl_x_type =
    double;
  _v_ref_fl_x_type v_ref_fl_x;
  using _v_ref_fl_y_type =
    double;
  _v_ref_fl_y_type v_ref_fl_y;
  using _v_ref_fl_z_type =
    double;
  _v_ref_fl_z_type v_ref_fl_z;
  using _v_ref_fr_x_type =
    double;
  _v_ref_fr_x_type v_ref_fr_x;
  using _v_ref_fr_y_type =
    double;
  _v_ref_fr_y_type v_ref_fr_y;
  using _v_ref_fr_z_type =
    double;
  _v_ref_fr_z_type v_ref_fr_z;
  using _v_ref_rl_x_type =
    double;
  _v_ref_rl_x_type v_ref_rl_x;
  using _v_ref_rl_y_type =
    double;
  _v_ref_rl_y_type v_ref_rl_y;
  using _v_ref_rl_z_type =
    double;
  _v_ref_rl_z_type v_ref_rl_z;
  using _v_ref_rr_x_type =
    double;
  _v_ref_rr_x_type v_ref_rr_x;
  using _v_ref_rr_y_type =
    double;
  _v_ref_rr_y_type v_ref_rr_y;
  using _v_ref_rr_z_type =
    double;
  _v_ref_rr_z_type v_ref_rr_z;
  using _v_act_fl_x_type =
    double;
  _v_act_fl_x_type v_act_fl_x;
  using _v_act_fl_y_type =
    double;
  _v_act_fl_y_type v_act_fl_y;
  using _v_act_fl_z_type =
    double;
  _v_act_fl_z_type v_act_fl_z;
  using _v_act_fr_x_type =
    double;
  _v_act_fr_x_type v_act_fr_x;
  using _v_act_fr_y_type =
    double;
  _v_act_fr_y_type v_act_fr_y;
  using _v_act_fr_z_type =
    double;
  _v_act_fr_z_type v_act_fr_z;
  using _v_act_rl_x_type =
    double;
  _v_act_rl_x_type v_act_rl_x;
  using _v_act_rl_y_type =
    double;
  _v_act_rl_y_type v_act_rl_y;
  using _v_act_rl_z_type =
    double;
  _v_act_rl_z_type v_act_rl_z;
  using _v_act_rr_x_type =
    double;
  _v_act_rr_x_type v_act_rr_x;
  using _v_act_rr_y_type =
    double;
  _v_act_rr_y_type v_act_rr_y;
  using _v_act_rr_z_type =
    double;
  _v_act_rr_z_type v_act_rr_z;
  using _a_ref_fl_x_type =
    double;
  _a_ref_fl_x_type a_ref_fl_x;
  using _a_ref_fl_y_type =
    double;
  _a_ref_fl_y_type a_ref_fl_y;
  using _a_ref_fl_z_type =
    double;
  _a_ref_fl_z_type a_ref_fl_z;
  using _a_ref_fr_x_type =
    double;
  _a_ref_fr_x_type a_ref_fr_x;
  using _a_ref_fr_y_type =
    double;
  _a_ref_fr_y_type a_ref_fr_y;
  using _a_ref_fr_z_type =
    double;
  _a_ref_fr_z_type a_ref_fr_z;
  using _a_ref_rl_x_type =
    double;
  _a_ref_rl_x_type a_ref_rl_x;
  using _a_ref_rl_y_type =
    double;
  _a_ref_rl_y_type a_ref_rl_y;
  using _a_ref_rl_z_type =
    double;
  _a_ref_rl_z_type a_ref_rl_z;
  using _a_ref_rr_x_type =
    double;
  _a_ref_rr_x_type a_ref_rr_x;
  using _a_ref_rr_y_type =
    double;
  _a_ref_rr_y_type a_ref_rr_y;
  using _a_ref_rr_z_type =
    double;
  _a_ref_rr_z_type a_ref_rr_z;
  using _a_act_fl_x_type =
    double;
  _a_act_fl_x_type a_act_fl_x;
  using _a_act_fl_y_type =
    double;
  _a_act_fl_y_type a_act_fl_y;
  using _a_act_fl_z_type =
    double;
  _a_act_fl_z_type a_act_fl_z;
  using _a_act_fr_x_type =
    double;
  _a_act_fr_x_type a_act_fr_x;
  using _a_act_fr_y_type =
    double;
  _a_act_fr_y_type a_act_fr_y;
  using _a_act_fr_z_type =
    double;
  _a_act_fr_z_type a_act_fr_z;
  using _a_act_rl_x_type =
    double;
  _a_act_rl_x_type a_act_rl_x;
  using _a_act_rl_y_type =
    double;
  _a_act_rl_y_type a_act_rl_y;
  using _a_act_rl_z_type =
    double;
  _a_act_rl_z_type a_act_rl_z;
  using _a_act_rr_x_type =
    double;
  _a_act_rr_x_type a_act_rr_x;
  using _a_act_rr_y_type =
    double;
  _a_act_rr_y_type a_act_rr_y;
  using _a_act_rr_z_type =
    double;
  _a_act_rr_z_type a_act_rr_z;
  using _f_mpc_fl_x_type =
    double;
  _f_mpc_fl_x_type f_mpc_fl_x;
  using _f_mpc_fl_y_type =
    double;
  _f_mpc_fl_y_type f_mpc_fl_y;
  using _f_mpc_fl_z_type =
    double;
  _f_mpc_fl_z_type f_mpc_fl_z;
  using _f_mpc_fr_x_type =
    double;
  _f_mpc_fr_x_type f_mpc_fr_x;
  using _f_mpc_fr_y_type =
    double;
  _f_mpc_fr_y_type f_mpc_fr_y;
  using _f_mpc_fr_z_type =
    double;
  _f_mpc_fr_z_type f_mpc_fr_z;
  using _f_mpc_rl_x_type =
    double;
  _f_mpc_rl_x_type f_mpc_rl_x;
  using _f_mpc_rl_y_type =
    double;
  _f_mpc_rl_y_type f_mpc_rl_y;
  using _f_mpc_rl_z_type =
    double;
  _f_mpc_rl_z_type f_mpc_rl_z;
  using _f_mpc_rr_x_type =
    double;
  _f_mpc_rr_x_type f_mpc_rr_x;
  using _f_mpc_rr_y_type =
    double;
  _f_mpc_rr_y_type f_mpc_rr_y;
  using _f_mpc_rr_z_type =
    double;
  _f_mpc_rr_z_type f_mpc_rr_z;
  using _f_wbc_fl_x_type =
    double;
  _f_wbc_fl_x_type f_wbc_fl_x;
  using _f_wbc_fl_y_type =
    double;
  _f_wbc_fl_y_type f_wbc_fl_y;
  using _f_wbc_fl_z_type =
    double;
  _f_wbc_fl_z_type f_wbc_fl_z;
  using _f_wbc_fr_x_type =
    double;
  _f_wbc_fr_x_type f_wbc_fr_x;
  using _f_wbc_fr_y_type =
    double;
  _f_wbc_fr_y_type f_wbc_fr_y;
  using _f_wbc_fr_z_type =
    double;
  _f_wbc_fr_z_type f_wbc_fr_z;
  using _f_wbc_rl_x_type =
    double;
  _f_wbc_rl_x_type f_wbc_rl_x;
  using _f_wbc_rl_y_type =
    double;
  _f_wbc_rl_y_type f_wbc_rl_y;
  using _f_wbc_rl_z_type =
    double;
  _f_wbc_rl_z_type f_wbc_rl_z;
  using _f_wbc_rr_x_type =
    double;
  _f_wbc_rr_x_type f_wbc_rr_x;
  using _f_wbc_rr_y_type =
    double;
  _f_wbc_rr_y_type f_wbc_rr_y;
  using _f_wbc_rr_z_type =
    double;
  _f_wbc_rr_z_type f_wbc_rr_z;
  using _contact_fl_type =
    double;
  _contact_fl_type contact_fl;
  using _contact_fr_type =
    double;
  _contact_fr_type contact_fr;
  using _contact_rl_type =
    double;
  _contact_rl_type contact_rl;
  using _contact_rr_type =
    double;
  _contact_rr_type contact_rr;
  using _body_x_type =
    double;
  _body_x_type body_x;
  using _body_z_type =
    double;
  _body_z_type body_z;
  using _body_x_v_type =
    double;
  _body_x_v_type body_x_v;
  using _body_z_v_type =
    double;
  _body_z_v_type body_z_v;
  using _body_x_v_d_type =
    double;
  _body_x_v_d_type body_x_v_d;
  using _body_z_v_d_type =
    double;
  _body_z_v_d_type body_z_v_d;
  using _q_des_lin_x_type =
    double;
  _q_des_lin_x_type q_des_lin_x;
  using _q_des_lin_y_type =
    double;
  _q_des_lin_y_type q_des_lin_y;
  using _q_des_lin_z_type =
    double;
  _q_des_lin_z_type q_des_lin_z;
  using _q_des_ang_x_type =
    double;
  _q_des_ang_x_type q_des_ang_x;
  using _q_des_ang_y_type =
    double;
  _q_des_ang_y_type q_des_ang_y;
  using _q_des_ang_z_type =
    double;
  _q_des_ang_z_type q_des_ang_z;
  using _q_des_joint_0_type =
    double;
  _q_des_joint_0_type q_des_joint_0;
  using _q_des_joint_1_type =
    double;
  _q_des_joint_1_type q_des_joint_1;
  using _q_des_joint_2_type =
    double;
  _q_des_joint_2_type q_des_joint_2;
  using _q_des_joint_3_type =
    double;
  _q_des_joint_3_type q_des_joint_3;
  using _q_des_joint_4_type =
    double;
  _q_des_joint_4_type q_des_joint_4;
  using _q_des_joint_5_type =
    double;
  _q_des_joint_5_type q_des_joint_5;
  using _q_des_joint_6_type =
    double;
  _q_des_joint_6_type q_des_joint_6;
  using _q_des_joint_7_type =
    double;
  _q_des_joint_7_type q_des_joint_7;
  using _q_des_joint_8_type =
    double;
  _q_des_joint_8_type q_des_joint_8;
  using _q_des_joint_9_type =
    double;
  _q_des_joint_9_type q_des_joint_9;
  using _q_des_joint_10_type =
    double;
  _q_des_joint_10_type q_des_joint_10;
  using _q_des_joint_11_type =
    double;
  _q_des_joint_11_type q_des_joint_11;
  using _tau_yaw_mpc_type =
    double;
  _tau_yaw_mpc_type tau_yaw_mpc;
  using _tau_yaw_wbc_type =
    double;
  _tau_yaw_wbc_type tau_yaw_wbc;
  using _f_cone_fl_type =
    double;
  _f_cone_fl_type f_cone_fl;
  using _f_cone_fr_type =
    double;
  _f_cone_fr_type f_cone_fr;
  using _f_cone_rl_type =
    double;
  _f_cone_rl_type f_cone_rl;
  using _f_cone_rr_type =
    double;
  _f_cone_rr_type f_cone_rr;
  using _tau_roll_mpc_type =
    double;
  _tau_roll_mpc_type tau_roll_mpc;
  using _tau_roll_wbc_type =
    double;
  _tau_roll_wbc_type tau_roll_wbc;
  using _tau_pitch_mpc_type =
    double;
  _tau_pitch_mpc_type tau_pitch_mpc;
  using _tau_pitch_wbc_type =
    double;
  _tau_pitch_wbc_type tau_pitch_wbc;
  using _a_wbc_ang_x_type =
    double;
  _a_wbc_ang_x_type a_wbc_ang_x;
  using _a_wbc_ang_y_type =
    double;
  _a_wbc_ang_y_type a_wbc_ang_y;
  using _a_wbc_ang_z_type =
    double;
  _a_wbc_ang_z_type a_wbc_ang_z;
  using _tau_joint_0_type =
    double;
  _tau_joint_0_type tau_joint_0;
  using _tau_joint_1_type =
    double;
  _tau_joint_1_type tau_joint_1;
  using _tau_joint_2_type =
    double;
  _tau_joint_2_type tau_joint_2;
  using _tau_joint_3_type =
    double;
  _tau_joint_3_type tau_joint_3;
  using _tau_joint_4_type =
    double;
  _tau_joint_4_type tau_joint_4;
  using _tau_joint_5_type =
    double;
  _tau_joint_5_type tau_joint_5;
  using _tau_joint_6_type =
    double;
  _tau_joint_6_type tau_joint_6;
  using _tau_joint_7_type =
    double;
  _tau_joint_7_type tau_joint_7;
  using _tau_joint_8_type =
    double;
  _tau_joint_8_type tau_joint_8;
  using _tau_joint_9_type =
    double;
  _tau_joint_9_type tau_joint_9;
  using _tau_joint_10_type =
    double;
  _tau_joint_10_type tau_joint_10;
  using _tau_joint_11_type =
    double;
  _tau_joint_11_type tau_joint_11;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__p_ref_fl_x(
    const double & _arg)
  {
    this->p_ref_fl_x = _arg;
    return *this;
  }
  Type & set__p_ref_fl_y(
    const double & _arg)
  {
    this->p_ref_fl_y = _arg;
    return *this;
  }
  Type & set__p_ref_fl_z(
    const double & _arg)
  {
    this->p_ref_fl_z = _arg;
    return *this;
  }
  Type & set__p_ref_fr_x(
    const double & _arg)
  {
    this->p_ref_fr_x = _arg;
    return *this;
  }
  Type & set__p_ref_fr_y(
    const double & _arg)
  {
    this->p_ref_fr_y = _arg;
    return *this;
  }
  Type & set__p_ref_fr_z(
    const double & _arg)
  {
    this->p_ref_fr_z = _arg;
    return *this;
  }
  Type & set__p_ref_rl_x(
    const double & _arg)
  {
    this->p_ref_rl_x = _arg;
    return *this;
  }
  Type & set__p_ref_rl_y(
    const double & _arg)
  {
    this->p_ref_rl_y = _arg;
    return *this;
  }
  Type & set__p_ref_rl_z(
    const double & _arg)
  {
    this->p_ref_rl_z = _arg;
    return *this;
  }
  Type & set__p_ref_rr_x(
    const double & _arg)
  {
    this->p_ref_rr_x = _arg;
    return *this;
  }
  Type & set__p_ref_rr_y(
    const double & _arg)
  {
    this->p_ref_rr_y = _arg;
    return *this;
  }
  Type & set__p_ref_rr_z(
    const double & _arg)
  {
    this->p_ref_rr_z = _arg;
    return *this;
  }
  Type & set__p_act_fl_x(
    const double & _arg)
  {
    this->p_act_fl_x = _arg;
    return *this;
  }
  Type & set__p_act_fl_y(
    const double & _arg)
  {
    this->p_act_fl_y = _arg;
    return *this;
  }
  Type & set__p_act_fl_z(
    const double & _arg)
  {
    this->p_act_fl_z = _arg;
    return *this;
  }
  Type & set__p_act_fr_x(
    const double & _arg)
  {
    this->p_act_fr_x = _arg;
    return *this;
  }
  Type & set__p_act_fr_y(
    const double & _arg)
  {
    this->p_act_fr_y = _arg;
    return *this;
  }
  Type & set__p_act_fr_z(
    const double & _arg)
  {
    this->p_act_fr_z = _arg;
    return *this;
  }
  Type & set__p_act_rl_x(
    const double & _arg)
  {
    this->p_act_rl_x = _arg;
    return *this;
  }
  Type & set__p_act_rl_y(
    const double & _arg)
  {
    this->p_act_rl_y = _arg;
    return *this;
  }
  Type & set__p_act_rl_z(
    const double & _arg)
  {
    this->p_act_rl_z = _arg;
    return *this;
  }
  Type & set__p_act_rr_x(
    const double & _arg)
  {
    this->p_act_rr_x = _arg;
    return *this;
  }
  Type & set__p_act_rr_y(
    const double & _arg)
  {
    this->p_act_rr_y = _arg;
    return *this;
  }
  Type & set__p_act_rr_z(
    const double & _arg)
  {
    this->p_act_rr_z = _arg;
    return *this;
  }
  Type & set__v_ref_fl_x(
    const double & _arg)
  {
    this->v_ref_fl_x = _arg;
    return *this;
  }
  Type & set__v_ref_fl_y(
    const double & _arg)
  {
    this->v_ref_fl_y = _arg;
    return *this;
  }
  Type & set__v_ref_fl_z(
    const double & _arg)
  {
    this->v_ref_fl_z = _arg;
    return *this;
  }
  Type & set__v_ref_fr_x(
    const double & _arg)
  {
    this->v_ref_fr_x = _arg;
    return *this;
  }
  Type & set__v_ref_fr_y(
    const double & _arg)
  {
    this->v_ref_fr_y = _arg;
    return *this;
  }
  Type & set__v_ref_fr_z(
    const double & _arg)
  {
    this->v_ref_fr_z = _arg;
    return *this;
  }
  Type & set__v_ref_rl_x(
    const double & _arg)
  {
    this->v_ref_rl_x = _arg;
    return *this;
  }
  Type & set__v_ref_rl_y(
    const double & _arg)
  {
    this->v_ref_rl_y = _arg;
    return *this;
  }
  Type & set__v_ref_rl_z(
    const double & _arg)
  {
    this->v_ref_rl_z = _arg;
    return *this;
  }
  Type & set__v_ref_rr_x(
    const double & _arg)
  {
    this->v_ref_rr_x = _arg;
    return *this;
  }
  Type & set__v_ref_rr_y(
    const double & _arg)
  {
    this->v_ref_rr_y = _arg;
    return *this;
  }
  Type & set__v_ref_rr_z(
    const double & _arg)
  {
    this->v_ref_rr_z = _arg;
    return *this;
  }
  Type & set__v_act_fl_x(
    const double & _arg)
  {
    this->v_act_fl_x = _arg;
    return *this;
  }
  Type & set__v_act_fl_y(
    const double & _arg)
  {
    this->v_act_fl_y = _arg;
    return *this;
  }
  Type & set__v_act_fl_z(
    const double & _arg)
  {
    this->v_act_fl_z = _arg;
    return *this;
  }
  Type & set__v_act_fr_x(
    const double & _arg)
  {
    this->v_act_fr_x = _arg;
    return *this;
  }
  Type & set__v_act_fr_y(
    const double & _arg)
  {
    this->v_act_fr_y = _arg;
    return *this;
  }
  Type & set__v_act_fr_z(
    const double & _arg)
  {
    this->v_act_fr_z = _arg;
    return *this;
  }
  Type & set__v_act_rl_x(
    const double & _arg)
  {
    this->v_act_rl_x = _arg;
    return *this;
  }
  Type & set__v_act_rl_y(
    const double & _arg)
  {
    this->v_act_rl_y = _arg;
    return *this;
  }
  Type & set__v_act_rl_z(
    const double & _arg)
  {
    this->v_act_rl_z = _arg;
    return *this;
  }
  Type & set__v_act_rr_x(
    const double & _arg)
  {
    this->v_act_rr_x = _arg;
    return *this;
  }
  Type & set__v_act_rr_y(
    const double & _arg)
  {
    this->v_act_rr_y = _arg;
    return *this;
  }
  Type & set__v_act_rr_z(
    const double & _arg)
  {
    this->v_act_rr_z = _arg;
    return *this;
  }
  Type & set__a_ref_fl_x(
    const double & _arg)
  {
    this->a_ref_fl_x = _arg;
    return *this;
  }
  Type & set__a_ref_fl_y(
    const double & _arg)
  {
    this->a_ref_fl_y = _arg;
    return *this;
  }
  Type & set__a_ref_fl_z(
    const double & _arg)
  {
    this->a_ref_fl_z = _arg;
    return *this;
  }
  Type & set__a_ref_fr_x(
    const double & _arg)
  {
    this->a_ref_fr_x = _arg;
    return *this;
  }
  Type & set__a_ref_fr_y(
    const double & _arg)
  {
    this->a_ref_fr_y = _arg;
    return *this;
  }
  Type & set__a_ref_fr_z(
    const double & _arg)
  {
    this->a_ref_fr_z = _arg;
    return *this;
  }
  Type & set__a_ref_rl_x(
    const double & _arg)
  {
    this->a_ref_rl_x = _arg;
    return *this;
  }
  Type & set__a_ref_rl_y(
    const double & _arg)
  {
    this->a_ref_rl_y = _arg;
    return *this;
  }
  Type & set__a_ref_rl_z(
    const double & _arg)
  {
    this->a_ref_rl_z = _arg;
    return *this;
  }
  Type & set__a_ref_rr_x(
    const double & _arg)
  {
    this->a_ref_rr_x = _arg;
    return *this;
  }
  Type & set__a_ref_rr_y(
    const double & _arg)
  {
    this->a_ref_rr_y = _arg;
    return *this;
  }
  Type & set__a_ref_rr_z(
    const double & _arg)
  {
    this->a_ref_rr_z = _arg;
    return *this;
  }
  Type & set__a_act_fl_x(
    const double & _arg)
  {
    this->a_act_fl_x = _arg;
    return *this;
  }
  Type & set__a_act_fl_y(
    const double & _arg)
  {
    this->a_act_fl_y = _arg;
    return *this;
  }
  Type & set__a_act_fl_z(
    const double & _arg)
  {
    this->a_act_fl_z = _arg;
    return *this;
  }
  Type & set__a_act_fr_x(
    const double & _arg)
  {
    this->a_act_fr_x = _arg;
    return *this;
  }
  Type & set__a_act_fr_y(
    const double & _arg)
  {
    this->a_act_fr_y = _arg;
    return *this;
  }
  Type & set__a_act_fr_z(
    const double & _arg)
  {
    this->a_act_fr_z = _arg;
    return *this;
  }
  Type & set__a_act_rl_x(
    const double & _arg)
  {
    this->a_act_rl_x = _arg;
    return *this;
  }
  Type & set__a_act_rl_y(
    const double & _arg)
  {
    this->a_act_rl_y = _arg;
    return *this;
  }
  Type & set__a_act_rl_z(
    const double & _arg)
  {
    this->a_act_rl_z = _arg;
    return *this;
  }
  Type & set__a_act_rr_x(
    const double & _arg)
  {
    this->a_act_rr_x = _arg;
    return *this;
  }
  Type & set__a_act_rr_y(
    const double & _arg)
  {
    this->a_act_rr_y = _arg;
    return *this;
  }
  Type & set__a_act_rr_z(
    const double & _arg)
  {
    this->a_act_rr_z = _arg;
    return *this;
  }
  Type & set__f_mpc_fl_x(
    const double & _arg)
  {
    this->f_mpc_fl_x = _arg;
    return *this;
  }
  Type & set__f_mpc_fl_y(
    const double & _arg)
  {
    this->f_mpc_fl_y = _arg;
    return *this;
  }
  Type & set__f_mpc_fl_z(
    const double & _arg)
  {
    this->f_mpc_fl_z = _arg;
    return *this;
  }
  Type & set__f_mpc_fr_x(
    const double & _arg)
  {
    this->f_mpc_fr_x = _arg;
    return *this;
  }
  Type & set__f_mpc_fr_y(
    const double & _arg)
  {
    this->f_mpc_fr_y = _arg;
    return *this;
  }
  Type & set__f_mpc_fr_z(
    const double & _arg)
  {
    this->f_mpc_fr_z = _arg;
    return *this;
  }
  Type & set__f_mpc_rl_x(
    const double & _arg)
  {
    this->f_mpc_rl_x = _arg;
    return *this;
  }
  Type & set__f_mpc_rl_y(
    const double & _arg)
  {
    this->f_mpc_rl_y = _arg;
    return *this;
  }
  Type & set__f_mpc_rl_z(
    const double & _arg)
  {
    this->f_mpc_rl_z = _arg;
    return *this;
  }
  Type & set__f_mpc_rr_x(
    const double & _arg)
  {
    this->f_mpc_rr_x = _arg;
    return *this;
  }
  Type & set__f_mpc_rr_y(
    const double & _arg)
  {
    this->f_mpc_rr_y = _arg;
    return *this;
  }
  Type & set__f_mpc_rr_z(
    const double & _arg)
  {
    this->f_mpc_rr_z = _arg;
    return *this;
  }
  Type & set__f_wbc_fl_x(
    const double & _arg)
  {
    this->f_wbc_fl_x = _arg;
    return *this;
  }
  Type & set__f_wbc_fl_y(
    const double & _arg)
  {
    this->f_wbc_fl_y = _arg;
    return *this;
  }
  Type & set__f_wbc_fl_z(
    const double & _arg)
  {
    this->f_wbc_fl_z = _arg;
    return *this;
  }
  Type & set__f_wbc_fr_x(
    const double & _arg)
  {
    this->f_wbc_fr_x = _arg;
    return *this;
  }
  Type & set__f_wbc_fr_y(
    const double & _arg)
  {
    this->f_wbc_fr_y = _arg;
    return *this;
  }
  Type & set__f_wbc_fr_z(
    const double & _arg)
  {
    this->f_wbc_fr_z = _arg;
    return *this;
  }
  Type & set__f_wbc_rl_x(
    const double & _arg)
  {
    this->f_wbc_rl_x = _arg;
    return *this;
  }
  Type & set__f_wbc_rl_y(
    const double & _arg)
  {
    this->f_wbc_rl_y = _arg;
    return *this;
  }
  Type & set__f_wbc_rl_z(
    const double & _arg)
  {
    this->f_wbc_rl_z = _arg;
    return *this;
  }
  Type & set__f_wbc_rr_x(
    const double & _arg)
  {
    this->f_wbc_rr_x = _arg;
    return *this;
  }
  Type & set__f_wbc_rr_y(
    const double & _arg)
  {
    this->f_wbc_rr_y = _arg;
    return *this;
  }
  Type & set__f_wbc_rr_z(
    const double & _arg)
  {
    this->f_wbc_rr_z = _arg;
    return *this;
  }
  Type & set__contact_fl(
    const double & _arg)
  {
    this->contact_fl = _arg;
    return *this;
  }
  Type & set__contact_fr(
    const double & _arg)
  {
    this->contact_fr = _arg;
    return *this;
  }
  Type & set__contact_rl(
    const double & _arg)
  {
    this->contact_rl = _arg;
    return *this;
  }
  Type & set__contact_rr(
    const double & _arg)
  {
    this->contact_rr = _arg;
    return *this;
  }
  Type & set__body_x(
    const double & _arg)
  {
    this->body_x = _arg;
    return *this;
  }
  Type & set__body_z(
    const double & _arg)
  {
    this->body_z = _arg;
    return *this;
  }
  Type & set__body_x_v(
    const double & _arg)
  {
    this->body_x_v = _arg;
    return *this;
  }
  Type & set__body_z_v(
    const double & _arg)
  {
    this->body_z_v = _arg;
    return *this;
  }
  Type & set__body_x_v_d(
    const double & _arg)
  {
    this->body_x_v_d = _arg;
    return *this;
  }
  Type & set__body_z_v_d(
    const double & _arg)
  {
    this->body_z_v_d = _arg;
    return *this;
  }
  Type & set__q_des_lin_x(
    const double & _arg)
  {
    this->q_des_lin_x = _arg;
    return *this;
  }
  Type & set__q_des_lin_y(
    const double & _arg)
  {
    this->q_des_lin_y = _arg;
    return *this;
  }
  Type & set__q_des_lin_z(
    const double & _arg)
  {
    this->q_des_lin_z = _arg;
    return *this;
  }
  Type & set__q_des_ang_x(
    const double & _arg)
  {
    this->q_des_ang_x = _arg;
    return *this;
  }
  Type & set__q_des_ang_y(
    const double & _arg)
  {
    this->q_des_ang_y = _arg;
    return *this;
  }
  Type & set__q_des_ang_z(
    const double & _arg)
  {
    this->q_des_ang_z = _arg;
    return *this;
  }
  Type & set__q_des_joint_0(
    const double & _arg)
  {
    this->q_des_joint_0 = _arg;
    return *this;
  }
  Type & set__q_des_joint_1(
    const double & _arg)
  {
    this->q_des_joint_1 = _arg;
    return *this;
  }
  Type & set__q_des_joint_2(
    const double & _arg)
  {
    this->q_des_joint_2 = _arg;
    return *this;
  }
  Type & set__q_des_joint_3(
    const double & _arg)
  {
    this->q_des_joint_3 = _arg;
    return *this;
  }
  Type & set__q_des_joint_4(
    const double & _arg)
  {
    this->q_des_joint_4 = _arg;
    return *this;
  }
  Type & set__q_des_joint_5(
    const double & _arg)
  {
    this->q_des_joint_5 = _arg;
    return *this;
  }
  Type & set__q_des_joint_6(
    const double & _arg)
  {
    this->q_des_joint_6 = _arg;
    return *this;
  }
  Type & set__q_des_joint_7(
    const double & _arg)
  {
    this->q_des_joint_7 = _arg;
    return *this;
  }
  Type & set__q_des_joint_8(
    const double & _arg)
  {
    this->q_des_joint_8 = _arg;
    return *this;
  }
  Type & set__q_des_joint_9(
    const double & _arg)
  {
    this->q_des_joint_9 = _arg;
    return *this;
  }
  Type & set__q_des_joint_10(
    const double & _arg)
  {
    this->q_des_joint_10 = _arg;
    return *this;
  }
  Type & set__q_des_joint_11(
    const double & _arg)
  {
    this->q_des_joint_11 = _arg;
    return *this;
  }
  Type & set__tau_yaw_mpc(
    const double & _arg)
  {
    this->tau_yaw_mpc = _arg;
    return *this;
  }
  Type & set__tau_yaw_wbc(
    const double & _arg)
  {
    this->tau_yaw_wbc = _arg;
    return *this;
  }
  Type & set__f_cone_fl(
    const double & _arg)
  {
    this->f_cone_fl = _arg;
    return *this;
  }
  Type & set__f_cone_fr(
    const double & _arg)
  {
    this->f_cone_fr = _arg;
    return *this;
  }
  Type & set__f_cone_rl(
    const double & _arg)
  {
    this->f_cone_rl = _arg;
    return *this;
  }
  Type & set__f_cone_rr(
    const double & _arg)
  {
    this->f_cone_rr = _arg;
    return *this;
  }
  Type & set__tau_roll_mpc(
    const double & _arg)
  {
    this->tau_roll_mpc = _arg;
    return *this;
  }
  Type & set__tau_roll_wbc(
    const double & _arg)
  {
    this->tau_roll_wbc = _arg;
    return *this;
  }
  Type & set__tau_pitch_mpc(
    const double & _arg)
  {
    this->tau_pitch_mpc = _arg;
    return *this;
  }
  Type & set__tau_pitch_wbc(
    const double & _arg)
  {
    this->tau_pitch_wbc = _arg;
    return *this;
  }
  Type & set__a_wbc_ang_x(
    const double & _arg)
  {
    this->a_wbc_ang_x = _arg;
    return *this;
  }
  Type & set__a_wbc_ang_y(
    const double & _arg)
  {
    this->a_wbc_ang_y = _arg;
    return *this;
  }
  Type & set__a_wbc_ang_z(
    const double & _arg)
  {
    this->a_wbc_ang_z = _arg;
    return *this;
  }
  Type & set__tau_joint_0(
    const double & _arg)
  {
    this->tau_joint_0 = _arg;
    return *this;
  }
  Type & set__tau_joint_1(
    const double & _arg)
  {
    this->tau_joint_1 = _arg;
    return *this;
  }
  Type & set__tau_joint_2(
    const double & _arg)
  {
    this->tau_joint_2 = _arg;
    return *this;
  }
  Type & set__tau_joint_3(
    const double & _arg)
  {
    this->tau_joint_3 = _arg;
    return *this;
  }
  Type & set__tau_joint_4(
    const double & _arg)
  {
    this->tau_joint_4 = _arg;
    return *this;
  }
  Type & set__tau_joint_5(
    const double & _arg)
  {
    this->tau_joint_5 = _arg;
    return *this;
  }
  Type & set__tau_joint_6(
    const double & _arg)
  {
    this->tau_joint_6 = _arg;
    return *this;
  }
  Type & set__tau_joint_7(
    const double & _arg)
  {
    this->tau_joint_7 = _arg;
    return *this;
  }
  Type & set__tau_joint_8(
    const double & _arg)
  {
    this->tau_joint_8 = _arg;
    return *this;
  }
  Type & set__tau_joint_9(
    const double & _arg)
  {
    this->tau_joint_9 = _arg;
    return *this;
  }
  Type & set__tau_joint_10(
    const double & _arg)
  {
    this->tau_joint_10 = _arg;
    return *this;
  }
  Type & set__tau_joint_11(
    const double & _arg)
  {
    this->tau_joint_11 = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    go2_robot::msg::Go2Telemetry_<ContainerAllocator> *;
  using ConstRawPtr =
    const go2_robot::msg::Go2Telemetry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      go2_robot::msg::Go2Telemetry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      go2_robot::msg::Go2Telemetry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__go2_robot__msg__Go2Telemetry
    std::shared_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__go2_robot__msg__Go2Telemetry
    std::shared_ptr<go2_robot::msg::Go2Telemetry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Go2Telemetry_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->p_ref_fl_x != other.p_ref_fl_x) {
      return false;
    }
    if (this->p_ref_fl_y != other.p_ref_fl_y) {
      return false;
    }
    if (this->p_ref_fl_z != other.p_ref_fl_z) {
      return false;
    }
    if (this->p_ref_fr_x != other.p_ref_fr_x) {
      return false;
    }
    if (this->p_ref_fr_y != other.p_ref_fr_y) {
      return false;
    }
    if (this->p_ref_fr_z != other.p_ref_fr_z) {
      return false;
    }
    if (this->p_ref_rl_x != other.p_ref_rl_x) {
      return false;
    }
    if (this->p_ref_rl_y != other.p_ref_rl_y) {
      return false;
    }
    if (this->p_ref_rl_z != other.p_ref_rl_z) {
      return false;
    }
    if (this->p_ref_rr_x != other.p_ref_rr_x) {
      return false;
    }
    if (this->p_ref_rr_y != other.p_ref_rr_y) {
      return false;
    }
    if (this->p_ref_rr_z != other.p_ref_rr_z) {
      return false;
    }
    if (this->p_act_fl_x != other.p_act_fl_x) {
      return false;
    }
    if (this->p_act_fl_y != other.p_act_fl_y) {
      return false;
    }
    if (this->p_act_fl_z != other.p_act_fl_z) {
      return false;
    }
    if (this->p_act_fr_x != other.p_act_fr_x) {
      return false;
    }
    if (this->p_act_fr_y != other.p_act_fr_y) {
      return false;
    }
    if (this->p_act_fr_z != other.p_act_fr_z) {
      return false;
    }
    if (this->p_act_rl_x != other.p_act_rl_x) {
      return false;
    }
    if (this->p_act_rl_y != other.p_act_rl_y) {
      return false;
    }
    if (this->p_act_rl_z != other.p_act_rl_z) {
      return false;
    }
    if (this->p_act_rr_x != other.p_act_rr_x) {
      return false;
    }
    if (this->p_act_rr_y != other.p_act_rr_y) {
      return false;
    }
    if (this->p_act_rr_z != other.p_act_rr_z) {
      return false;
    }
    if (this->v_ref_fl_x != other.v_ref_fl_x) {
      return false;
    }
    if (this->v_ref_fl_y != other.v_ref_fl_y) {
      return false;
    }
    if (this->v_ref_fl_z != other.v_ref_fl_z) {
      return false;
    }
    if (this->v_ref_fr_x != other.v_ref_fr_x) {
      return false;
    }
    if (this->v_ref_fr_y != other.v_ref_fr_y) {
      return false;
    }
    if (this->v_ref_fr_z != other.v_ref_fr_z) {
      return false;
    }
    if (this->v_ref_rl_x != other.v_ref_rl_x) {
      return false;
    }
    if (this->v_ref_rl_y != other.v_ref_rl_y) {
      return false;
    }
    if (this->v_ref_rl_z != other.v_ref_rl_z) {
      return false;
    }
    if (this->v_ref_rr_x != other.v_ref_rr_x) {
      return false;
    }
    if (this->v_ref_rr_y != other.v_ref_rr_y) {
      return false;
    }
    if (this->v_ref_rr_z != other.v_ref_rr_z) {
      return false;
    }
    if (this->v_act_fl_x != other.v_act_fl_x) {
      return false;
    }
    if (this->v_act_fl_y != other.v_act_fl_y) {
      return false;
    }
    if (this->v_act_fl_z != other.v_act_fl_z) {
      return false;
    }
    if (this->v_act_fr_x != other.v_act_fr_x) {
      return false;
    }
    if (this->v_act_fr_y != other.v_act_fr_y) {
      return false;
    }
    if (this->v_act_fr_z != other.v_act_fr_z) {
      return false;
    }
    if (this->v_act_rl_x != other.v_act_rl_x) {
      return false;
    }
    if (this->v_act_rl_y != other.v_act_rl_y) {
      return false;
    }
    if (this->v_act_rl_z != other.v_act_rl_z) {
      return false;
    }
    if (this->v_act_rr_x != other.v_act_rr_x) {
      return false;
    }
    if (this->v_act_rr_y != other.v_act_rr_y) {
      return false;
    }
    if (this->v_act_rr_z != other.v_act_rr_z) {
      return false;
    }
    if (this->a_ref_fl_x != other.a_ref_fl_x) {
      return false;
    }
    if (this->a_ref_fl_y != other.a_ref_fl_y) {
      return false;
    }
    if (this->a_ref_fl_z != other.a_ref_fl_z) {
      return false;
    }
    if (this->a_ref_fr_x != other.a_ref_fr_x) {
      return false;
    }
    if (this->a_ref_fr_y != other.a_ref_fr_y) {
      return false;
    }
    if (this->a_ref_fr_z != other.a_ref_fr_z) {
      return false;
    }
    if (this->a_ref_rl_x != other.a_ref_rl_x) {
      return false;
    }
    if (this->a_ref_rl_y != other.a_ref_rl_y) {
      return false;
    }
    if (this->a_ref_rl_z != other.a_ref_rl_z) {
      return false;
    }
    if (this->a_ref_rr_x != other.a_ref_rr_x) {
      return false;
    }
    if (this->a_ref_rr_y != other.a_ref_rr_y) {
      return false;
    }
    if (this->a_ref_rr_z != other.a_ref_rr_z) {
      return false;
    }
    if (this->a_act_fl_x != other.a_act_fl_x) {
      return false;
    }
    if (this->a_act_fl_y != other.a_act_fl_y) {
      return false;
    }
    if (this->a_act_fl_z != other.a_act_fl_z) {
      return false;
    }
    if (this->a_act_fr_x != other.a_act_fr_x) {
      return false;
    }
    if (this->a_act_fr_y != other.a_act_fr_y) {
      return false;
    }
    if (this->a_act_fr_z != other.a_act_fr_z) {
      return false;
    }
    if (this->a_act_rl_x != other.a_act_rl_x) {
      return false;
    }
    if (this->a_act_rl_y != other.a_act_rl_y) {
      return false;
    }
    if (this->a_act_rl_z != other.a_act_rl_z) {
      return false;
    }
    if (this->a_act_rr_x != other.a_act_rr_x) {
      return false;
    }
    if (this->a_act_rr_y != other.a_act_rr_y) {
      return false;
    }
    if (this->a_act_rr_z != other.a_act_rr_z) {
      return false;
    }
    if (this->f_mpc_fl_x != other.f_mpc_fl_x) {
      return false;
    }
    if (this->f_mpc_fl_y != other.f_mpc_fl_y) {
      return false;
    }
    if (this->f_mpc_fl_z != other.f_mpc_fl_z) {
      return false;
    }
    if (this->f_mpc_fr_x != other.f_mpc_fr_x) {
      return false;
    }
    if (this->f_mpc_fr_y != other.f_mpc_fr_y) {
      return false;
    }
    if (this->f_mpc_fr_z != other.f_mpc_fr_z) {
      return false;
    }
    if (this->f_mpc_rl_x != other.f_mpc_rl_x) {
      return false;
    }
    if (this->f_mpc_rl_y != other.f_mpc_rl_y) {
      return false;
    }
    if (this->f_mpc_rl_z != other.f_mpc_rl_z) {
      return false;
    }
    if (this->f_mpc_rr_x != other.f_mpc_rr_x) {
      return false;
    }
    if (this->f_mpc_rr_y != other.f_mpc_rr_y) {
      return false;
    }
    if (this->f_mpc_rr_z != other.f_mpc_rr_z) {
      return false;
    }
    if (this->f_wbc_fl_x != other.f_wbc_fl_x) {
      return false;
    }
    if (this->f_wbc_fl_y != other.f_wbc_fl_y) {
      return false;
    }
    if (this->f_wbc_fl_z != other.f_wbc_fl_z) {
      return false;
    }
    if (this->f_wbc_fr_x != other.f_wbc_fr_x) {
      return false;
    }
    if (this->f_wbc_fr_y != other.f_wbc_fr_y) {
      return false;
    }
    if (this->f_wbc_fr_z != other.f_wbc_fr_z) {
      return false;
    }
    if (this->f_wbc_rl_x != other.f_wbc_rl_x) {
      return false;
    }
    if (this->f_wbc_rl_y != other.f_wbc_rl_y) {
      return false;
    }
    if (this->f_wbc_rl_z != other.f_wbc_rl_z) {
      return false;
    }
    if (this->f_wbc_rr_x != other.f_wbc_rr_x) {
      return false;
    }
    if (this->f_wbc_rr_y != other.f_wbc_rr_y) {
      return false;
    }
    if (this->f_wbc_rr_z != other.f_wbc_rr_z) {
      return false;
    }
    if (this->contact_fl != other.contact_fl) {
      return false;
    }
    if (this->contact_fr != other.contact_fr) {
      return false;
    }
    if (this->contact_rl != other.contact_rl) {
      return false;
    }
    if (this->contact_rr != other.contact_rr) {
      return false;
    }
    if (this->body_x != other.body_x) {
      return false;
    }
    if (this->body_z != other.body_z) {
      return false;
    }
    if (this->body_x_v != other.body_x_v) {
      return false;
    }
    if (this->body_z_v != other.body_z_v) {
      return false;
    }
    if (this->body_x_v_d != other.body_x_v_d) {
      return false;
    }
    if (this->body_z_v_d != other.body_z_v_d) {
      return false;
    }
    if (this->q_des_lin_x != other.q_des_lin_x) {
      return false;
    }
    if (this->q_des_lin_y != other.q_des_lin_y) {
      return false;
    }
    if (this->q_des_lin_z != other.q_des_lin_z) {
      return false;
    }
    if (this->q_des_ang_x != other.q_des_ang_x) {
      return false;
    }
    if (this->q_des_ang_y != other.q_des_ang_y) {
      return false;
    }
    if (this->q_des_ang_z != other.q_des_ang_z) {
      return false;
    }
    if (this->q_des_joint_0 != other.q_des_joint_0) {
      return false;
    }
    if (this->q_des_joint_1 != other.q_des_joint_1) {
      return false;
    }
    if (this->q_des_joint_2 != other.q_des_joint_2) {
      return false;
    }
    if (this->q_des_joint_3 != other.q_des_joint_3) {
      return false;
    }
    if (this->q_des_joint_4 != other.q_des_joint_4) {
      return false;
    }
    if (this->q_des_joint_5 != other.q_des_joint_5) {
      return false;
    }
    if (this->q_des_joint_6 != other.q_des_joint_6) {
      return false;
    }
    if (this->q_des_joint_7 != other.q_des_joint_7) {
      return false;
    }
    if (this->q_des_joint_8 != other.q_des_joint_8) {
      return false;
    }
    if (this->q_des_joint_9 != other.q_des_joint_9) {
      return false;
    }
    if (this->q_des_joint_10 != other.q_des_joint_10) {
      return false;
    }
    if (this->q_des_joint_11 != other.q_des_joint_11) {
      return false;
    }
    if (this->tau_yaw_mpc != other.tau_yaw_mpc) {
      return false;
    }
    if (this->tau_yaw_wbc != other.tau_yaw_wbc) {
      return false;
    }
    if (this->f_cone_fl != other.f_cone_fl) {
      return false;
    }
    if (this->f_cone_fr != other.f_cone_fr) {
      return false;
    }
    if (this->f_cone_rl != other.f_cone_rl) {
      return false;
    }
    if (this->f_cone_rr != other.f_cone_rr) {
      return false;
    }
    if (this->tau_roll_mpc != other.tau_roll_mpc) {
      return false;
    }
    if (this->tau_roll_wbc != other.tau_roll_wbc) {
      return false;
    }
    if (this->tau_pitch_mpc != other.tau_pitch_mpc) {
      return false;
    }
    if (this->tau_pitch_wbc != other.tau_pitch_wbc) {
      return false;
    }
    if (this->a_wbc_ang_x != other.a_wbc_ang_x) {
      return false;
    }
    if (this->a_wbc_ang_y != other.a_wbc_ang_y) {
      return false;
    }
    if (this->a_wbc_ang_z != other.a_wbc_ang_z) {
      return false;
    }
    if (this->tau_joint_0 != other.tau_joint_0) {
      return false;
    }
    if (this->tau_joint_1 != other.tau_joint_1) {
      return false;
    }
    if (this->tau_joint_2 != other.tau_joint_2) {
      return false;
    }
    if (this->tau_joint_3 != other.tau_joint_3) {
      return false;
    }
    if (this->tau_joint_4 != other.tau_joint_4) {
      return false;
    }
    if (this->tau_joint_5 != other.tau_joint_5) {
      return false;
    }
    if (this->tau_joint_6 != other.tau_joint_6) {
      return false;
    }
    if (this->tau_joint_7 != other.tau_joint_7) {
      return false;
    }
    if (this->tau_joint_8 != other.tau_joint_8) {
      return false;
    }
    if (this->tau_joint_9 != other.tau_joint_9) {
      return false;
    }
    if (this->tau_joint_10 != other.tau_joint_10) {
      return false;
    }
    if (this->tau_joint_11 != other.tau_joint_11) {
      return false;
    }
    return true;
  }
  bool operator!=(const Go2Telemetry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Go2Telemetry_

// alias to use template instance with default allocator
using Go2Telemetry =
  go2_robot::msg::Go2Telemetry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace go2_robot

#endif  // GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__STRUCT_HPP_
