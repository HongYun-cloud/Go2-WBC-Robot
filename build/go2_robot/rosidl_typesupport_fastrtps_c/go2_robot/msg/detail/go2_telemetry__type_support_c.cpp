// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice
#include "go2_robot/msg/detail/go2_telemetry__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "go2_robot/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "go2_robot/msg/detail/go2_telemetry__struct.h"
#include "go2_robot/msg/detail/go2_telemetry__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "std_msgs/msg/detail/header__functions.h"  // header

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_robot
size_t get_serialized_size_std_msgs__msg__Header(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_robot
size_t max_serialized_size_std_msgs__msg__Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_go2_robot
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, std_msgs, msg, Header)();


using _Go2Telemetry__ros_msg_type = go2_robot__msg__Go2Telemetry;

static bool _Go2Telemetry__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _Go2Telemetry__ros_msg_type * ros_message = static_cast<const _Go2Telemetry__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->header, cdr))
    {
      return false;
    }
  }

  // Field name: p_ref_fl_x
  {
    cdr << ros_message->p_ref_fl_x;
  }

  // Field name: p_ref_fl_y
  {
    cdr << ros_message->p_ref_fl_y;
  }

  // Field name: p_ref_fl_z
  {
    cdr << ros_message->p_ref_fl_z;
  }

  // Field name: p_ref_fr_x
  {
    cdr << ros_message->p_ref_fr_x;
  }

  // Field name: p_ref_fr_y
  {
    cdr << ros_message->p_ref_fr_y;
  }

  // Field name: p_ref_fr_z
  {
    cdr << ros_message->p_ref_fr_z;
  }

  // Field name: p_ref_rl_x
  {
    cdr << ros_message->p_ref_rl_x;
  }

  // Field name: p_ref_rl_y
  {
    cdr << ros_message->p_ref_rl_y;
  }

  // Field name: p_ref_rl_z
  {
    cdr << ros_message->p_ref_rl_z;
  }

  // Field name: p_ref_rr_x
  {
    cdr << ros_message->p_ref_rr_x;
  }

  // Field name: p_ref_rr_y
  {
    cdr << ros_message->p_ref_rr_y;
  }

  // Field name: p_ref_rr_z
  {
    cdr << ros_message->p_ref_rr_z;
  }

  // Field name: p_act_fl_x
  {
    cdr << ros_message->p_act_fl_x;
  }

  // Field name: p_act_fl_y
  {
    cdr << ros_message->p_act_fl_y;
  }

  // Field name: p_act_fl_z
  {
    cdr << ros_message->p_act_fl_z;
  }

  // Field name: p_act_fr_x
  {
    cdr << ros_message->p_act_fr_x;
  }

  // Field name: p_act_fr_y
  {
    cdr << ros_message->p_act_fr_y;
  }

  // Field name: p_act_fr_z
  {
    cdr << ros_message->p_act_fr_z;
  }

  // Field name: p_act_rl_x
  {
    cdr << ros_message->p_act_rl_x;
  }

  // Field name: p_act_rl_y
  {
    cdr << ros_message->p_act_rl_y;
  }

  // Field name: p_act_rl_z
  {
    cdr << ros_message->p_act_rl_z;
  }

  // Field name: p_act_rr_x
  {
    cdr << ros_message->p_act_rr_x;
  }

  // Field name: p_act_rr_y
  {
    cdr << ros_message->p_act_rr_y;
  }

  // Field name: p_act_rr_z
  {
    cdr << ros_message->p_act_rr_z;
  }

  // Field name: v_ref_fl_x
  {
    cdr << ros_message->v_ref_fl_x;
  }

  // Field name: v_ref_fl_y
  {
    cdr << ros_message->v_ref_fl_y;
  }

  // Field name: v_ref_fl_z
  {
    cdr << ros_message->v_ref_fl_z;
  }

  // Field name: v_ref_fr_x
  {
    cdr << ros_message->v_ref_fr_x;
  }

  // Field name: v_ref_fr_y
  {
    cdr << ros_message->v_ref_fr_y;
  }

  // Field name: v_ref_fr_z
  {
    cdr << ros_message->v_ref_fr_z;
  }

  // Field name: v_ref_rl_x
  {
    cdr << ros_message->v_ref_rl_x;
  }

  // Field name: v_ref_rl_y
  {
    cdr << ros_message->v_ref_rl_y;
  }

  // Field name: v_ref_rl_z
  {
    cdr << ros_message->v_ref_rl_z;
  }

  // Field name: v_ref_rr_x
  {
    cdr << ros_message->v_ref_rr_x;
  }

  // Field name: v_ref_rr_y
  {
    cdr << ros_message->v_ref_rr_y;
  }

  // Field name: v_ref_rr_z
  {
    cdr << ros_message->v_ref_rr_z;
  }

  // Field name: v_act_fl_x
  {
    cdr << ros_message->v_act_fl_x;
  }

  // Field name: v_act_fl_y
  {
    cdr << ros_message->v_act_fl_y;
  }

  // Field name: v_act_fl_z
  {
    cdr << ros_message->v_act_fl_z;
  }

  // Field name: v_act_fr_x
  {
    cdr << ros_message->v_act_fr_x;
  }

  // Field name: v_act_fr_y
  {
    cdr << ros_message->v_act_fr_y;
  }

  // Field name: v_act_fr_z
  {
    cdr << ros_message->v_act_fr_z;
  }

  // Field name: v_act_rl_x
  {
    cdr << ros_message->v_act_rl_x;
  }

  // Field name: v_act_rl_y
  {
    cdr << ros_message->v_act_rl_y;
  }

  // Field name: v_act_rl_z
  {
    cdr << ros_message->v_act_rl_z;
  }

  // Field name: v_act_rr_x
  {
    cdr << ros_message->v_act_rr_x;
  }

  // Field name: v_act_rr_y
  {
    cdr << ros_message->v_act_rr_y;
  }

  // Field name: v_act_rr_z
  {
    cdr << ros_message->v_act_rr_z;
  }

  // Field name: a_ref_fl_x
  {
    cdr << ros_message->a_ref_fl_x;
  }

  // Field name: a_ref_fl_y
  {
    cdr << ros_message->a_ref_fl_y;
  }

  // Field name: a_ref_fl_z
  {
    cdr << ros_message->a_ref_fl_z;
  }

  // Field name: a_ref_fr_x
  {
    cdr << ros_message->a_ref_fr_x;
  }

  // Field name: a_ref_fr_y
  {
    cdr << ros_message->a_ref_fr_y;
  }

  // Field name: a_ref_fr_z
  {
    cdr << ros_message->a_ref_fr_z;
  }

  // Field name: a_ref_rl_x
  {
    cdr << ros_message->a_ref_rl_x;
  }

  // Field name: a_ref_rl_y
  {
    cdr << ros_message->a_ref_rl_y;
  }

  // Field name: a_ref_rl_z
  {
    cdr << ros_message->a_ref_rl_z;
  }

  // Field name: a_ref_rr_x
  {
    cdr << ros_message->a_ref_rr_x;
  }

  // Field name: a_ref_rr_y
  {
    cdr << ros_message->a_ref_rr_y;
  }

  // Field name: a_ref_rr_z
  {
    cdr << ros_message->a_ref_rr_z;
  }

  // Field name: a_act_fl_x
  {
    cdr << ros_message->a_act_fl_x;
  }

  // Field name: a_act_fl_y
  {
    cdr << ros_message->a_act_fl_y;
  }

  // Field name: a_act_fl_z
  {
    cdr << ros_message->a_act_fl_z;
  }

  // Field name: a_act_fr_x
  {
    cdr << ros_message->a_act_fr_x;
  }

  // Field name: a_act_fr_y
  {
    cdr << ros_message->a_act_fr_y;
  }

  // Field name: a_act_fr_z
  {
    cdr << ros_message->a_act_fr_z;
  }

  // Field name: a_act_rl_x
  {
    cdr << ros_message->a_act_rl_x;
  }

  // Field name: a_act_rl_y
  {
    cdr << ros_message->a_act_rl_y;
  }

  // Field name: a_act_rl_z
  {
    cdr << ros_message->a_act_rl_z;
  }

  // Field name: a_act_rr_x
  {
    cdr << ros_message->a_act_rr_x;
  }

  // Field name: a_act_rr_y
  {
    cdr << ros_message->a_act_rr_y;
  }

  // Field name: a_act_rr_z
  {
    cdr << ros_message->a_act_rr_z;
  }

  // Field name: f_mpc_fl_x
  {
    cdr << ros_message->f_mpc_fl_x;
  }

  // Field name: f_mpc_fl_y
  {
    cdr << ros_message->f_mpc_fl_y;
  }

  // Field name: f_mpc_fl_z
  {
    cdr << ros_message->f_mpc_fl_z;
  }

  // Field name: f_mpc_fr_x
  {
    cdr << ros_message->f_mpc_fr_x;
  }

  // Field name: f_mpc_fr_y
  {
    cdr << ros_message->f_mpc_fr_y;
  }

  // Field name: f_mpc_fr_z
  {
    cdr << ros_message->f_mpc_fr_z;
  }

  // Field name: f_mpc_rl_x
  {
    cdr << ros_message->f_mpc_rl_x;
  }

  // Field name: f_mpc_rl_y
  {
    cdr << ros_message->f_mpc_rl_y;
  }

  // Field name: f_mpc_rl_z
  {
    cdr << ros_message->f_mpc_rl_z;
  }

  // Field name: f_mpc_rr_x
  {
    cdr << ros_message->f_mpc_rr_x;
  }

  // Field name: f_mpc_rr_y
  {
    cdr << ros_message->f_mpc_rr_y;
  }

  // Field name: f_mpc_rr_z
  {
    cdr << ros_message->f_mpc_rr_z;
  }

  // Field name: f_wbc_fl_x
  {
    cdr << ros_message->f_wbc_fl_x;
  }

  // Field name: f_wbc_fl_y
  {
    cdr << ros_message->f_wbc_fl_y;
  }

  // Field name: f_wbc_fl_z
  {
    cdr << ros_message->f_wbc_fl_z;
  }

  // Field name: f_wbc_fr_x
  {
    cdr << ros_message->f_wbc_fr_x;
  }

  // Field name: f_wbc_fr_y
  {
    cdr << ros_message->f_wbc_fr_y;
  }

  // Field name: f_wbc_fr_z
  {
    cdr << ros_message->f_wbc_fr_z;
  }

  // Field name: f_wbc_rl_x
  {
    cdr << ros_message->f_wbc_rl_x;
  }

  // Field name: f_wbc_rl_y
  {
    cdr << ros_message->f_wbc_rl_y;
  }

  // Field name: f_wbc_rl_z
  {
    cdr << ros_message->f_wbc_rl_z;
  }

  // Field name: f_wbc_rr_x
  {
    cdr << ros_message->f_wbc_rr_x;
  }

  // Field name: f_wbc_rr_y
  {
    cdr << ros_message->f_wbc_rr_y;
  }

  // Field name: f_wbc_rr_z
  {
    cdr << ros_message->f_wbc_rr_z;
  }

  // Field name: contact_fl
  {
    cdr << ros_message->contact_fl;
  }

  // Field name: contact_fr
  {
    cdr << ros_message->contact_fr;
  }

  // Field name: contact_rl
  {
    cdr << ros_message->contact_rl;
  }

  // Field name: contact_rr
  {
    cdr << ros_message->contact_rr;
  }

  // Field name: body_x
  {
    cdr << ros_message->body_x;
  }

  // Field name: body_z
  {
    cdr << ros_message->body_z;
  }

  // Field name: body_x_v
  {
    cdr << ros_message->body_x_v;
  }

  // Field name: body_z_v
  {
    cdr << ros_message->body_z_v;
  }

  // Field name: body_x_v_d
  {
    cdr << ros_message->body_x_v_d;
  }

  // Field name: body_z_v_d
  {
    cdr << ros_message->body_z_v_d;
  }

  // Field name: q_des_lin_x
  {
    cdr << ros_message->q_des_lin_x;
  }

  // Field name: q_des_lin_y
  {
    cdr << ros_message->q_des_lin_y;
  }

  // Field name: q_des_lin_z
  {
    cdr << ros_message->q_des_lin_z;
  }

  // Field name: q_des_ang_x
  {
    cdr << ros_message->q_des_ang_x;
  }

  // Field name: q_des_ang_y
  {
    cdr << ros_message->q_des_ang_y;
  }

  // Field name: q_des_ang_z
  {
    cdr << ros_message->q_des_ang_z;
  }

  // Field name: q_des_joint_0
  {
    cdr << ros_message->q_des_joint_0;
  }

  // Field name: q_des_joint_1
  {
    cdr << ros_message->q_des_joint_1;
  }

  // Field name: q_des_joint_2
  {
    cdr << ros_message->q_des_joint_2;
  }

  // Field name: q_des_joint_3
  {
    cdr << ros_message->q_des_joint_3;
  }

  // Field name: q_des_joint_4
  {
    cdr << ros_message->q_des_joint_4;
  }

  // Field name: q_des_joint_5
  {
    cdr << ros_message->q_des_joint_5;
  }

  // Field name: q_des_joint_6
  {
    cdr << ros_message->q_des_joint_6;
  }

  // Field name: q_des_joint_7
  {
    cdr << ros_message->q_des_joint_7;
  }

  // Field name: q_des_joint_8
  {
    cdr << ros_message->q_des_joint_8;
  }

  // Field name: q_des_joint_9
  {
    cdr << ros_message->q_des_joint_9;
  }

  // Field name: q_des_joint_10
  {
    cdr << ros_message->q_des_joint_10;
  }

  // Field name: q_des_joint_11
  {
    cdr << ros_message->q_des_joint_11;
  }

  // Field name: tau_yaw_mpc
  {
    cdr << ros_message->tau_yaw_mpc;
  }

  // Field name: tau_yaw_wbc
  {
    cdr << ros_message->tau_yaw_wbc;
  }

  // Field name: f_cone_fl
  {
    cdr << ros_message->f_cone_fl;
  }

  // Field name: f_cone_fr
  {
    cdr << ros_message->f_cone_fr;
  }

  // Field name: f_cone_rl
  {
    cdr << ros_message->f_cone_rl;
  }

  // Field name: f_cone_rr
  {
    cdr << ros_message->f_cone_rr;
  }

  // Field name: tau_roll_mpc
  {
    cdr << ros_message->tau_roll_mpc;
  }

  // Field name: tau_roll_wbc
  {
    cdr << ros_message->tau_roll_wbc;
  }

  // Field name: tau_pitch_mpc
  {
    cdr << ros_message->tau_pitch_mpc;
  }

  // Field name: tau_pitch_wbc
  {
    cdr << ros_message->tau_pitch_wbc;
  }

  // Field name: a_wbc_ang_x
  {
    cdr << ros_message->a_wbc_ang_x;
  }

  // Field name: a_wbc_ang_y
  {
    cdr << ros_message->a_wbc_ang_y;
  }

  // Field name: a_wbc_ang_z
  {
    cdr << ros_message->a_wbc_ang_z;
  }

  // Field name: tau_joint_0
  {
    cdr << ros_message->tau_joint_0;
  }

  // Field name: tau_joint_1
  {
    cdr << ros_message->tau_joint_1;
  }

  // Field name: tau_joint_2
  {
    cdr << ros_message->tau_joint_2;
  }

  // Field name: tau_joint_3
  {
    cdr << ros_message->tau_joint_3;
  }

  // Field name: tau_joint_4
  {
    cdr << ros_message->tau_joint_4;
  }

  // Field name: tau_joint_5
  {
    cdr << ros_message->tau_joint_5;
  }

  // Field name: tau_joint_6
  {
    cdr << ros_message->tau_joint_6;
  }

  // Field name: tau_joint_7
  {
    cdr << ros_message->tau_joint_7;
  }

  // Field name: tau_joint_8
  {
    cdr << ros_message->tau_joint_8;
  }

  // Field name: tau_joint_9
  {
    cdr << ros_message->tau_joint_9;
  }

  // Field name: tau_joint_10
  {
    cdr << ros_message->tau_joint_10;
  }

  // Field name: tau_joint_11
  {
    cdr << ros_message->tau_joint_11;
  }

  return true;
}

static bool _Go2Telemetry__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _Go2Telemetry__ros_msg_type * ros_message = static_cast<_Go2Telemetry__ros_msg_type *>(untyped_ros_message);
  // Field name: header
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, std_msgs, msg, Header
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->header))
    {
      return false;
    }
  }

  // Field name: p_ref_fl_x
  {
    cdr >> ros_message->p_ref_fl_x;
  }

  // Field name: p_ref_fl_y
  {
    cdr >> ros_message->p_ref_fl_y;
  }

  // Field name: p_ref_fl_z
  {
    cdr >> ros_message->p_ref_fl_z;
  }

  // Field name: p_ref_fr_x
  {
    cdr >> ros_message->p_ref_fr_x;
  }

  // Field name: p_ref_fr_y
  {
    cdr >> ros_message->p_ref_fr_y;
  }

  // Field name: p_ref_fr_z
  {
    cdr >> ros_message->p_ref_fr_z;
  }

  // Field name: p_ref_rl_x
  {
    cdr >> ros_message->p_ref_rl_x;
  }

  // Field name: p_ref_rl_y
  {
    cdr >> ros_message->p_ref_rl_y;
  }

  // Field name: p_ref_rl_z
  {
    cdr >> ros_message->p_ref_rl_z;
  }

  // Field name: p_ref_rr_x
  {
    cdr >> ros_message->p_ref_rr_x;
  }

  // Field name: p_ref_rr_y
  {
    cdr >> ros_message->p_ref_rr_y;
  }

  // Field name: p_ref_rr_z
  {
    cdr >> ros_message->p_ref_rr_z;
  }

  // Field name: p_act_fl_x
  {
    cdr >> ros_message->p_act_fl_x;
  }

  // Field name: p_act_fl_y
  {
    cdr >> ros_message->p_act_fl_y;
  }

  // Field name: p_act_fl_z
  {
    cdr >> ros_message->p_act_fl_z;
  }

  // Field name: p_act_fr_x
  {
    cdr >> ros_message->p_act_fr_x;
  }

  // Field name: p_act_fr_y
  {
    cdr >> ros_message->p_act_fr_y;
  }

  // Field name: p_act_fr_z
  {
    cdr >> ros_message->p_act_fr_z;
  }

  // Field name: p_act_rl_x
  {
    cdr >> ros_message->p_act_rl_x;
  }

  // Field name: p_act_rl_y
  {
    cdr >> ros_message->p_act_rl_y;
  }

  // Field name: p_act_rl_z
  {
    cdr >> ros_message->p_act_rl_z;
  }

  // Field name: p_act_rr_x
  {
    cdr >> ros_message->p_act_rr_x;
  }

  // Field name: p_act_rr_y
  {
    cdr >> ros_message->p_act_rr_y;
  }

  // Field name: p_act_rr_z
  {
    cdr >> ros_message->p_act_rr_z;
  }

  // Field name: v_ref_fl_x
  {
    cdr >> ros_message->v_ref_fl_x;
  }

  // Field name: v_ref_fl_y
  {
    cdr >> ros_message->v_ref_fl_y;
  }

  // Field name: v_ref_fl_z
  {
    cdr >> ros_message->v_ref_fl_z;
  }

  // Field name: v_ref_fr_x
  {
    cdr >> ros_message->v_ref_fr_x;
  }

  // Field name: v_ref_fr_y
  {
    cdr >> ros_message->v_ref_fr_y;
  }

  // Field name: v_ref_fr_z
  {
    cdr >> ros_message->v_ref_fr_z;
  }

  // Field name: v_ref_rl_x
  {
    cdr >> ros_message->v_ref_rl_x;
  }

  // Field name: v_ref_rl_y
  {
    cdr >> ros_message->v_ref_rl_y;
  }

  // Field name: v_ref_rl_z
  {
    cdr >> ros_message->v_ref_rl_z;
  }

  // Field name: v_ref_rr_x
  {
    cdr >> ros_message->v_ref_rr_x;
  }

  // Field name: v_ref_rr_y
  {
    cdr >> ros_message->v_ref_rr_y;
  }

  // Field name: v_ref_rr_z
  {
    cdr >> ros_message->v_ref_rr_z;
  }

  // Field name: v_act_fl_x
  {
    cdr >> ros_message->v_act_fl_x;
  }

  // Field name: v_act_fl_y
  {
    cdr >> ros_message->v_act_fl_y;
  }

  // Field name: v_act_fl_z
  {
    cdr >> ros_message->v_act_fl_z;
  }

  // Field name: v_act_fr_x
  {
    cdr >> ros_message->v_act_fr_x;
  }

  // Field name: v_act_fr_y
  {
    cdr >> ros_message->v_act_fr_y;
  }

  // Field name: v_act_fr_z
  {
    cdr >> ros_message->v_act_fr_z;
  }

  // Field name: v_act_rl_x
  {
    cdr >> ros_message->v_act_rl_x;
  }

  // Field name: v_act_rl_y
  {
    cdr >> ros_message->v_act_rl_y;
  }

  // Field name: v_act_rl_z
  {
    cdr >> ros_message->v_act_rl_z;
  }

  // Field name: v_act_rr_x
  {
    cdr >> ros_message->v_act_rr_x;
  }

  // Field name: v_act_rr_y
  {
    cdr >> ros_message->v_act_rr_y;
  }

  // Field name: v_act_rr_z
  {
    cdr >> ros_message->v_act_rr_z;
  }

  // Field name: a_ref_fl_x
  {
    cdr >> ros_message->a_ref_fl_x;
  }

  // Field name: a_ref_fl_y
  {
    cdr >> ros_message->a_ref_fl_y;
  }

  // Field name: a_ref_fl_z
  {
    cdr >> ros_message->a_ref_fl_z;
  }

  // Field name: a_ref_fr_x
  {
    cdr >> ros_message->a_ref_fr_x;
  }

  // Field name: a_ref_fr_y
  {
    cdr >> ros_message->a_ref_fr_y;
  }

  // Field name: a_ref_fr_z
  {
    cdr >> ros_message->a_ref_fr_z;
  }

  // Field name: a_ref_rl_x
  {
    cdr >> ros_message->a_ref_rl_x;
  }

  // Field name: a_ref_rl_y
  {
    cdr >> ros_message->a_ref_rl_y;
  }

  // Field name: a_ref_rl_z
  {
    cdr >> ros_message->a_ref_rl_z;
  }

  // Field name: a_ref_rr_x
  {
    cdr >> ros_message->a_ref_rr_x;
  }

  // Field name: a_ref_rr_y
  {
    cdr >> ros_message->a_ref_rr_y;
  }

  // Field name: a_ref_rr_z
  {
    cdr >> ros_message->a_ref_rr_z;
  }

  // Field name: a_act_fl_x
  {
    cdr >> ros_message->a_act_fl_x;
  }

  // Field name: a_act_fl_y
  {
    cdr >> ros_message->a_act_fl_y;
  }

  // Field name: a_act_fl_z
  {
    cdr >> ros_message->a_act_fl_z;
  }

  // Field name: a_act_fr_x
  {
    cdr >> ros_message->a_act_fr_x;
  }

  // Field name: a_act_fr_y
  {
    cdr >> ros_message->a_act_fr_y;
  }

  // Field name: a_act_fr_z
  {
    cdr >> ros_message->a_act_fr_z;
  }

  // Field name: a_act_rl_x
  {
    cdr >> ros_message->a_act_rl_x;
  }

  // Field name: a_act_rl_y
  {
    cdr >> ros_message->a_act_rl_y;
  }

  // Field name: a_act_rl_z
  {
    cdr >> ros_message->a_act_rl_z;
  }

  // Field name: a_act_rr_x
  {
    cdr >> ros_message->a_act_rr_x;
  }

  // Field name: a_act_rr_y
  {
    cdr >> ros_message->a_act_rr_y;
  }

  // Field name: a_act_rr_z
  {
    cdr >> ros_message->a_act_rr_z;
  }

  // Field name: f_mpc_fl_x
  {
    cdr >> ros_message->f_mpc_fl_x;
  }

  // Field name: f_mpc_fl_y
  {
    cdr >> ros_message->f_mpc_fl_y;
  }

  // Field name: f_mpc_fl_z
  {
    cdr >> ros_message->f_mpc_fl_z;
  }

  // Field name: f_mpc_fr_x
  {
    cdr >> ros_message->f_mpc_fr_x;
  }

  // Field name: f_mpc_fr_y
  {
    cdr >> ros_message->f_mpc_fr_y;
  }

  // Field name: f_mpc_fr_z
  {
    cdr >> ros_message->f_mpc_fr_z;
  }

  // Field name: f_mpc_rl_x
  {
    cdr >> ros_message->f_mpc_rl_x;
  }

  // Field name: f_mpc_rl_y
  {
    cdr >> ros_message->f_mpc_rl_y;
  }

  // Field name: f_mpc_rl_z
  {
    cdr >> ros_message->f_mpc_rl_z;
  }

  // Field name: f_mpc_rr_x
  {
    cdr >> ros_message->f_mpc_rr_x;
  }

  // Field name: f_mpc_rr_y
  {
    cdr >> ros_message->f_mpc_rr_y;
  }

  // Field name: f_mpc_rr_z
  {
    cdr >> ros_message->f_mpc_rr_z;
  }

  // Field name: f_wbc_fl_x
  {
    cdr >> ros_message->f_wbc_fl_x;
  }

  // Field name: f_wbc_fl_y
  {
    cdr >> ros_message->f_wbc_fl_y;
  }

  // Field name: f_wbc_fl_z
  {
    cdr >> ros_message->f_wbc_fl_z;
  }

  // Field name: f_wbc_fr_x
  {
    cdr >> ros_message->f_wbc_fr_x;
  }

  // Field name: f_wbc_fr_y
  {
    cdr >> ros_message->f_wbc_fr_y;
  }

  // Field name: f_wbc_fr_z
  {
    cdr >> ros_message->f_wbc_fr_z;
  }

  // Field name: f_wbc_rl_x
  {
    cdr >> ros_message->f_wbc_rl_x;
  }

  // Field name: f_wbc_rl_y
  {
    cdr >> ros_message->f_wbc_rl_y;
  }

  // Field name: f_wbc_rl_z
  {
    cdr >> ros_message->f_wbc_rl_z;
  }

  // Field name: f_wbc_rr_x
  {
    cdr >> ros_message->f_wbc_rr_x;
  }

  // Field name: f_wbc_rr_y
  {
    cdr >> ros_message->f_wbc_rr_y;
  }

  // Field name: f_wbc_rr_z
  {
    cdr >> ros_message->f_wbc_rr_z;
  }

  // Field name: contact_fl
  {
    cdr >> ros_message->contact_fl;
  }

  // Field name: contact_fr
  {
    cdr >> ros_message->contact_fr;
  }

  // Field name: contact_rl
  {
    cdr >> ros_message->contact_rl;
  }

  // Field name: contact_rr
  {
    cdr >> ros_message->contact_rr;
  }

  // Field name: body_x
  {
    cdr >> ros_message->body_x;
  }

  // Field name: body_z
  {
    cdr >> ros_message->body_z;
  }

  // Field name: body_x_v
  {
    cdr >> ros_message->body_x_v;
  }

  // Field name: body_z_v
  {
    cdr >> ros_message->body_z_v;
  }

  // Field name: body_x_v_d
  {
    cdr >> ros_message->body_x_v_d;
  }

  // Field name: body_z_v_d
  {
    cdr >> ros_message->body_z_v_d;
  }

  // Field name: q_des_lin_x
  {
    cdr >> ros_message->q_des_lin_x;
  }

  // Field name: q_des_lin_y
  {
    cdr >> ros_message->q_des_lin_y;
  }

  // Field name: q_des_lin_z
  {
    cdr >> ros_message->q_des_lin_z;
  }

  // Field name: q_des_ang_x
  {
    cdr >> ros_message->q_des_ang_x;
  }

  // Field name: q_des_ang_y
  {
    cdr >> ros_message->q_des_ang_y;
  }

  // Field name: q_des_ang_z
  {
    cdr >> ros_message->q_des_ang_z;
  }

  // Field name: q_des_joint_0
  {
    cdr >> ros_message->q_des_joint_0;
  }

  // Field name: q_des_joint_1
  {
    cdr >> ros_message->q_des_joint_1;
  }

  // Field name: q_des_joint_2
  {
    cdr >> ros_message->q_des_joint_2;
  }

  // Field name: q_des_joint_3
  {
    cdr >> ros_message->q_des_joint_3;
  }

  // Field name: q_des_joint_4
  {
    cdr >> ros_message->q_des_joint_4;
  }

  // Field name: q_des_joint_5
  {
    cdr >> ros_message->q_des_joint_5;
  }

  // Field name: q_des_joint_6
  {
    cdr >> ros_message->q_des_joint_6;
  }

  // Field name: q_des_joint_7
  {
    cdr >> ros_message->q_des_joint_7;
  }

  // Field name: q_des_joint_8
  {
    cdr >> ros_message->q_des_joint_8;
  }

  // Field name: q_des_joint_9
  {
    cdr >> ros_message->q_des_joint_9;
  }

  // Field name: q_des_joint_10
  {
    cdr >> ros_message->q_des_joint_10;
  }

  // Field name: q_des_joint_11
  {
    cdr >> ros_message->q_des_joint_11;
  }

  // Field name: tau_yaw_mpc
  {
    cdr >> ros_message->tau_yaw_mpc;
  }

  // Field name: tau_yaw_wbc
  {
    cdr >> ros_message->tau_yaw_wbc;
  }

  // Field name: f_cone_fl
  {
    cdr >> ros_message->f_cone_fl;
  }

  // Field name: f_cone_fr
  {
    cdr >> ros_message->f_cone_fr;
  }

  // Field name: f_cone_rl
  {
    cdr >> ros_message->f_cone_rl;
  }

  // Field name: f_cone_rr
  {
    cdr >> ros_message->f_cone_rr;
  }

  // Field name: tau_roll_mpc
  {
    cdr >> ros_message->tau_roll_mpc;
  }

  // Field name: tau_roll_wbc
  {
    cdr >> ros_message->tau_roll_wbc;
  }

  // Field name: tau_pitch_mpc
  {
    cdr >> ros_message->tau_pitch_mpc;
  }

  // Field name: tau_pitch_wbc
  {
    cdr >> ros_message->tau_pitch_wbc;
  }

  // Field name: a_wbc_ang_x
  {
    cdr >> ros_message->a_wbc_ang_x;
  }

  // Field name: a_wbc_ang_y
  {
    cdr >> ros_message->a_wbc_ang_y;
  }

  // Field name: a_wbc_ang_z
  {
    cdr >> ros_message->a_wbc_ang_z;
  }

  // Field name: tau_joint_0
  {
    cdr >> ros_message->tau_joint_0;
  }

  // Field name: tau_joint_1
  {
    cdr >> ros_message->tau_joint_1;
  }

  // Field name: tau_joint_2
  {
    cdr >> ros_message->tau_joint_2;
  }

  // Field name: tau_joint_3
  {
    cdr >> ros_message->tau_joint_3;
  }

  // Field name: tau_joint_4
  {
    cdr >> ros_message->tau_joint_4;
  }

  // Field name: tau_joint_5
  {
    cdr >> ros_message->tau_joint_5;
  }

  // Field name: tau_joint_6
  {
    cdr >> ros_message->tau_joint_6;
  }

  // Field name: tau_joint_7
  {
    cdr >> ros_message->tau_joint_7;
  }

  // Field name: tau_joint_8
  {
    cdr >> ros_message->tau_joint_8;
  }

  // Field name: tau_joint_9
  {
    cdr >> ros_message->tau_joint_9;
  }

  // Field name: tau_joint_10
  {
    cdr >> ros_message->tau_joint_10;
  }

  // Field name: tau_joint_11
  {
    cdr >> ros_message->tau_joint_11;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_robot
size_t get_serialized_size_go2_robot__msg__Go2Telemetry(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _Go2Telemetry__ros_msg_type * ros_message = static_cast<const _Go2Telemetry__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name header

  current_alignment += get_serialized_size_std_msgs__msg__Header(
    &(ros_message->header), current_alignment);
  // field.name p_ref_fl_x
  {
    size_t item_size = sizeof(ros_message->p_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_fl_y
  {
    size_t item_size = sizeof(ros_message->p_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_fl_z
  {
    size_t item_size = sizeof(ros_message->p_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_fr_x
  {
    size_t item_size = sizeof(ros_message->p_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_fr_y
  {
    size_t item_size = sizeof(ros_message->p_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_fr_z
  {
    size_t item_size = sizeof(ros_message->p_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rl_x
  {
    size_t item_size = sizeof(ros_message->p_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rl_y
  {
    size_t item_size = sizeof(ros_message->p_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rl_z
  {
    size_t item_size = sizeof(ros_message->p_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rr_x
  {
    size_t item_size = sizeof(ros_message->p_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rr_y
  {
    size_t item_size = sizeof(ros_message->p_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_ref_rr_z
  {
    size_t item_size = sizeof(ros_message->p_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fl_x
  {
    size_t item_size = sizeof(ros_message->p_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fl_y
  {
    size_t item_size = sizeof(ros_message->p_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fl_z
  {
    size_t item_size = sizeof(ros_message->p_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fr_x
  {
    size_t item_size = sizeof(ros_message->p_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fr_y
  {
    size_t item_size = sizeof(ros_message->p_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_fr_z
  {
    size_t item_size = sizeof(ros_message->p_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rl_x
  {
    size_t item_size = sizeof(ros_message->p_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rl_y
  {
    size_t item_size = sizeof(ros_message->p_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rl_z
  {
    size_t item_size = sizeof(ros_message->p_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rr_x
  {
    size_t item_size = sizeof(ros_message->p_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rr_y
  {
    size_t item_size = sizeof(ros_message->p_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name p_act_rr_z
  {
    size_t item_size = sizeof(ros_message->p_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fl_x
  {
    size_t item_size = sizeof(ros_message->v_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fl_y
  {
    size_t item_size = sizeof(ros_message->v_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fl_z
  {
    size_t item_size = sizeof(ros_message->v_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fr_x
  {
    size_t item_size = sizeof(ros_message->v_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fr_y
  {
    size_t item_size = sizeof(ros_message->v_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_fr_z
  {
    size_t item_size = sizeof(ros_message->v_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rl_x
  {
    size_t item_size = sizeof(ros_message->v_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rl_y
  {
    size_t item_size = sizeof(ros_message->v_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rl_z
  {
    size_t item_size = sizeof(ros_message->v_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rr_x
  {
    size_t item_size = sizeof(ros_message->v_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rr_y
  {
    size_t item_size = sizeof(ros_message->v_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_ref_rr_z
  {
    size_t item_size = sizeof(ros_message->v_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fl_x
  {
    size_t item_size = sizeof(ros_message->v_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fl_y
  {
    size_t item_size = sizeof(ros_message->v_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fl_z
  {
    size_t item_size = sizeof(ros_message->v_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fr_x
  {
    size_t item_size = sizeof(ros_message->v_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fr_y
  {
    size_t item_size = sizeof(ros_message->v_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_fr_z
  {
    size_t item_size = sizeof(ros_message->v_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rl_x
  {
    size_t item_size = sizeof(ros_message->v_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rl_y
  {
    size_t item_size = sizeof(ros_message->v_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rl_z
  {
    size_t item_size = sizeof(ros_message->v_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rr_x
  {
    size_t item_size = sizeof(ros_message->v_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rr_y
  {
    size_t item_size = sizeof(ros_message->v_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name v_act_rr_z
  {
    size_t item_size = sizeof(ros_message->v_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fl_x
  {
    size_t item_size = sizeof(ros_message->a_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fl_y
  {
    size_t item_size = sizeof(ros_message->a_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fl_z
  {
    size_t item_size = sizeof(ros_message->a_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fr_x
  {
    size_t item_size = sizeof(ros_message->a_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fr_y
  {
    size_t item_size = sizeof(ros_message->a_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_fr_z
  {
    size_t item_size = sizeof(ros_message->a_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rl_x
  {
    size_t item_size = sizeof(ros_message->a_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rl_y
  {
    size_t item_size = sizeof(ros_message->a_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rl_z
  {
    size_t item_size = sizeof(ros_message->a_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rr_x
  {
    size_t item_size = sizeof(ros_message->a_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rr_y
  {
    size_t item_size = sizeof(ros_message->a_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_ref_rr_z
  {
    size_t item_size = sizeof(ros_message->a_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fl_x
  {
    size_t item_size = sizeof(ros_message->a_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fl_y
  {
    size_t item_size = sizeof(ros_message->a_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fl_z
  {
    size_t item_size = sizeof(ros_message->a_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fr_x
  {
    size_t item_size = sizeof(ros_message->a_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fr_y
  {
    size_t item_size = sizeof(ros_message->a_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_fr_z
  {
    size_t item_size = sizeof(ros_message->a_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rl_x
  {
    size_t item_size = sizeof(ros_message->a_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rl_y
  {
    size_t item_size = sizeof(ros_message->a_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rl_z
  {
    size_t item_size = sizeof(ros_message->a_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rr_x
  {
    size_t item_size = sizeof(ros_message->a_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rr_y
  {
    size_t item_size = sizeof(ros_message->a_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_act_rr_z
  {
    size_t item_size = sizeof(ros_message->a_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fl_x
  {
    size_t item_size = sizeof(ros_message->f_mpc_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fl_y
  {
    size_t item_size = sizeof(ros_message->f_mpc_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fl_z
  {
    size_t item_size = sizeof(ros_message->f_mpc_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fr_x
  {
    size_t item_size = sizeof(ros_message->f_mpc_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fr_y
  {
    size_t item_size = sizeof(ros_message->f_mpc_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_fr_z
  {
    size_t item_size = sizeof(ros_message->f_mpc_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rl_x
  {
    size_t item_size = sizeof(ros_message->f_mpc_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rl_y
  {
    size_t item_size = sizeof(ros_message->f_mpc_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rl_z
  {
    size_t item_size = sizeof(ros_message->f_mpc_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rr_x
  {
    size_t item_size = sizeof(ros_message->f_mpc_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rr_y
  {
    size_t item_size = sizeof(ros_message->f_mpc_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_mpc_rr_z
  {
    size_t item_size = sizeof(ros_message->f_mpc_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fl_x
  {
    size_t item_size = sizeof(ros_message->f_wbc_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fl_y
  {
    size_t item_size = sizeof(ros_message->f_wbc_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fl_z
  {
    size_t item_size = sizeof(ros_message->f_wbc_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fr_x
  {
    size_t item_size = sizeof(ros_message->f_wbc_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fr_y
  {
    size_t item_size = sizeof(ros_message->f_wbc_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_fr_z
  {
    size_t item_size = sizeof(ros_message->f_wbc_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rl_x
  {
    size_t item_size = sizeof(ros_message->f_wbc_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rl_y
  {
    size_t item_size = sizeof(ros_message->f_wbc_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rl_z
  {
    size_t item_size = sizeof(ros_message->f_wbc_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rr_x
  {
    size_t item_size = sizeof(ros_message->f_wbc_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rr_y
  {
    size_t item_size = sizeof(ros_message->f_wbc_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_wbc_rr_z
  {
    size_t item_size = sizeof(ros_message->f_wbc_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name contact_fl
  {
    size_t item_size = sizeof(ros_message->contact_fl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name contact_fr
  {
    size_t item_size = sizeof(ros_message->contact_fr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name contact_rl
  {
    size_t item_size = sizeof(ros_message->contact_rl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name contact_rr
  {
    size_t item_size = sizeof(ros_message->contact_rr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_x
  {
    size_t item_size = sizeof(ros_message->body_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_z
  {
    size_t item_size = sizeof(ros_message->body_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_x_v
  {
    size_t item_size = sizeof(ros_message->body_x_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_z_v
  {
    size_t item_size = sizeof(ros_message->body_z_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_x_v_d
  {
    size_t item_size = sizeof(ros_message->body_x_v_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name body_z_v_d
  {
    size_t item_size = sizeof(ros_message->body_z_v_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_lin_x
  {
    size_t item_size = sizeof(ros_message->q_des_lin_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_lin_y
  {
    size_t item_size = sizeof(ros_message->q_des_lin_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_lin_z
  {
    size_t item_size = sizeof(ros_message->q_des_lin_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_ang_x
  {
    size_t item_size = sizeof(ros_message->q_des_ang_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_ang_y
  {
    size_t item_size = sizeof(ros_message->q_des_ang_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_ang_z
  {
    size_t item_size = sizeof(ros_message->q_des_ang_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_0
  {
    size_t item_size = sizeof(ros_message->q_des_joint_0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_1
  {
    size_t item_size = sizeof(ros_message->q_des_joint_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_2
  {
    size_t item_size = sizeof(ros_message->q_des_joint_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_3
  {
    size_t item_size = sizeof(ros_message->q_des_joint_3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_4
  {
    size_t item_size = sizeof(ros_message->q_des_joint_4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_5
  {
    size_t item_size = sizeof(ros_message->q_des_joint_5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_6
  {
    size_t item_size = sizeof(ros_message->q_des_joint_6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_7
  {
    size_t item_size = sizeof(ros_message->q_des_joint_7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_8
  {
    size_t item_size = sizeof(ros_message->q_des_joint_8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_9
  {
    size_t item_size = sizeof(ros_message->q_des_joint_9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_10
  {
    size_t item_size = sizeof(ros_message->q_des_joint_10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name q_des_joint_11
  {
    size_t item_size = sizeof(ros_message->q_des_joint_11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_yaw_mpc
  {
    size_t item_size = sizeof(ros_message->tau_yaw_mpc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_yaw_wbc
  {
    size_t item_size = sizeof(ros_message->tau_yaw_wbc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_cone_fl
  {
    size_t item_size = sizeof(ros_message->f_cone_fl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_cone_fr
  {
    size_t item_size = sizeof(ros_message->f_cone_fr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_cone_rl
  {
    size_t item_size = sizeof(ros_message->f_cone_rl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name f_cone_rr
  {
    size_t item_size = sizeof(ros_message->f_cone_rr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_roll_mpc
  {
    size_t item_size = sizeof(ros_message->tau_roll_mpc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_roll_wbc
  {
    size_t item_size = sizeof(ros_message->tau_roll_wbc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_pitch_mpc
  {
    size_t item_size = sizeof(ros_message->tau_pitch_mpc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_pitch_wbc
  {
    size_t item_size = sizeof(ros_message->tau_pitch_wbc);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_wbc_ang_x
  {
    size_t item_size = sizeof(ros_message->a_wbc_ang_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_wbc_ang_y
  {
    size_t item_size = sizeof(ros_message->a_wbc_ang_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name a_wbc_ang_z
  {
    size_t item_size = sizeof(ros_message->a_wbc_ang_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_0
  {
    size_t item_size = sizeof(ros_message->tau_joint_0);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_1
  {
    size_t item_size = sizeof(ros_message->tau_joint_1);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_2
  {
    size_t item_size = sizeof(ros_message->tau_joint_2);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_3
  {
    size_t item_size = sizeof(ros_message->tau_joint_3);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_4
  {
    size_t item_size = sizeof(ros_message->tau_joint_4);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_5
  {
    size_t item_size = sizeof(ros_message->tau_joint_5);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_6
  {
    size_t item_size = sizeof(ros_message->tau_joint_6);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_7
  {
    size_t item_size = sizeof(ros_message->tau_joint_7);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_8
  {
    size_t item_size = sizeof(ros_message->tau_joint_8);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_9
  {
    size_t item_size = sizeof(ros_message->tau_joint_9);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_10
  {
    size_t item_size = sizeof(ros_message->tau_joint_10);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name tau_joint_11
  {
    size_t item_size = sizeof(ros_message->tau_joint_11);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _Go2Telemetry__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_go2_robot__msg__Go2Telemetry(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_go2_robot
size_t max_serialized_size_go2_robot__msg__Go2Telemetry(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_std_msgs__msg__Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }
  // member: p_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: p_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: v_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_mpc_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_wbc_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: contact_fl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: contact_fr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: contact_rl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: contact_rr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_x_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_z_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_x_v_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: body_z_v_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_lin_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_lin_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_lin_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_ang_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_ang_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_ang_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: q_des_joint_11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_yaw_mpc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_yaw_wbc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_cone_fl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_cone_fr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_cone_rl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: f_cone_rr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_roll_mpc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_roll_wbc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_pitch_mpc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_pitch_wbc
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_wbc_ang_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_wbc_ang_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: a_wbc_ang_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_0
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_1
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_2
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_3
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_4
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_5
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_6
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_7
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_8
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_9
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_10
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: tau_joint_11
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = go2_robot__msg__Go2Telemetry;
    is_plain =
      (
      offsetof(DataType, tau_joint_11) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _Go2Telemetry__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_go2_robot__msg__Go2Telemetry(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_Go2Telemetry = {
  "go2_robot::msg",
  "Go2Telemetry",
  _Go2Telemetry__cdr_serialize,
  _Go2Telemetry__cdr_deserialize,
  _Go2Telemetry__get_serialized_size,
  _Go2Telemetry__max_serialized_size
};

static rosidl_message_type_support_t _Go2Telemetry__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_Go2Telemetry,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, go2_robot, msg, Go2Telemetry)() {
  return &_Go2Telemetry__type_support;
}

#if defined(__cplusplus)
}
#endif
