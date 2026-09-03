// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice
#include "go2_robot/msg/detail/go2_telemetry__rosidl_typesupport_fastrtps_cpp.hpp"
#include "go2_robot/msg/detail/go2_telemetry__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace go2_robot
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_go2_robot
cdr_serialize(
  const go2_robot::msg::Go2Telemetry & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: p_ref_fl_x
  cdr << ros_message.p_ref_fl_x;
  // Member: p_ref_fl_y
  cdr << ros_message.p_ref_fl_y;
  // Member: p_ref_fl_z
  cdr << ros_message.p_ref_fl_z;
  // Member: p_ref_fr_x
  cdr << ros_message.p_ref_fr_x;
  // Member: p_ref_fr_y
  cdr << ros_message.p_ref_fr_y;
  // Member: p_ref_fr_z
  cdr << ros_message.p_ref_fr_z;
  // Member: p_ref_rl_x
  cdr << ros_message.p_ref_rl_x;
  // Member: p_ref_rl_y
  cdr << ros_message.p_ref_rl_y;
  // Member: p_ref_rl_z
  cdr << ros_message.p_ref_rl_z;
  // Member: p_ref_rr_x
  cdr << ros_message.p_ref_rr_x;
  // Member: p_ref_rr_y
  cdr << ros_message.p_ref_rr_y;
  // Member: p_ref_rr_z
  cdr << ros_message.p_ref_rr_z;
  // Member: p_act_fl_x
  cdr << ros_message.p_act_fl_x;
  // Member: p_act_fl_y
  cdr << ros_message.p_act_fl_y;
  // Member: p_act_fl_z
  cdr << ros_message.p_act_fl_z;
  // Member: p_act_fr_x
  cdr << ros_message.p_act_fr_x;
  // Member: p_act_fr_y
  cdr << ros_message.p_act_fr_y;
  // Member: p_act_fr_z
  cdr << ros_message.p_act_fr_z;
  // Member: p_act_rl_x
  cdr << ros_message.p_act_rl_x;
  // Member: p_act_rl_y
  cdr << ros_message.p_act_rl_y;
  // Member: p_act_rl_z
  cdr << ros_message.p_act_rl_z;
  // Member: p_act_rr_x
  cdr << ros_message.p_act_rr_x;
  // Member: p_act_rr_y
  cdr << ros_message.p_act_rr_y;
  // Member: p_act_rr_z
  cdr << ros_message.p_act_rr_z;
  // Member: v_ref_fl_x
  cdr << ros_message.v_ref_fl_x;
  // Member: v_ref_fl_y
  cdr << ros_message.v_ref_fl_y;
  // Member: v_ref_fl_z
  cdr << ros_message.v_ref_fl_z;
  // Member: v_ref_fr_x
  cdr << ros_message.v_ref_fr_x;
  // Member: v_ref_fr_y
  cdr << ros_message.v_ref_fr_y;
  // Member: v_ref_fr_z
  cdr << ros_message.v_ref_fr_z;
  // Member: v_ref_rl_x
  cdr << ros_message.v_ref_rl_x;
  // Member: v_ref_rl_y
  cdr << ros_message.v_ref_rl_y;
  // Member: v_ref_rl_z
  cdr << ros_message.v_ref_rl_z;
  // Member: v_ref_rr_x
  cdr << ros_message.v_ref_rr_x;
  // Member: v_ref_rr_y
  cdr << ros_message.v_ref_rr_y;
  // Member: v_ref_rr_z
  cdr << ros_message.v_ref_rr_z;
  // Member: v_act_fl_x
  cdr << ros_message.v_act_fl_x;
  // Member: v_act_fl_y
  cdr << ros_message.v_act_fl_y;
  // Member: v_act_fl_z
  cdr << ros_message.v_act_fl_z;
  // Member: v_act_fr_x
  cdr << ros_message.v_act_fr_x;
  // Member: v_act_fr_y
  cdr << ros_message.v_act_fr_y;
  // Member: v_act_fr_z
  cdr << ros_message.v_act_fr_z;
  // Member: v_act_rl_x
  cdr << ros_message.v_act_rl_x;
  // Member: v_act_rl_y
  cdr << ros_message.v_act_rl_y;
  // Member: v_act_rl_z
  cdr << ros_message.v_act_rl_z;
  // Member: v_act_rr_x
  cdr << ros_message.v_act_rr_x;
  // Member: v_act_rr_y
  cdr << ros_message.v_act_rr_y;
  // Member: v_act_rr_z
  cdr << ros_message.v_act_rr_z;
  // Member: a_ref_fl_x
  cdr << ros_message.a_ref_fl_x;
  // Member: a_ref_fl_y
  cdr << ros_message.a_ref_fl_y;
  // Member: a_ref_fl_z
  cdr << ros_message.a_ref_fl_z;
  // Member: a_ref_fr_x
  cdr << ros_message.a_ref_fr_x;
  // Member: a_ref_fr_y
  cdr << ros_message.a_ref_fr_y;
  // Member: a_ref_fr_z
  cdr << ros_message.a_ref_fr_z;
  // Member: a_ref_rl_x
  cdr << ros_message.a_ref_rl_x;
  // Member: a_ref_rl_y
  cdr << ros_message.a_ref_rl_y;
  // Member: a_ref_rl_z
  cdr << ros_message.a_ref_rl_z;
  // Member: a_ref_rr_x
  cdr << ros_message.a_ref_rr_x;
  // Member: a_ref_rr_y
  cdr << ros_message.a_ref_rr_y;
  // Member: a_ref_rr_z
  cdr << ros_message.a_ref_rr_z;
  // Member: a_act_fl_x
  cdr << ros_message.a_act_fl_x;
  // Member: a_act_fl_y
  cdr << ros_message.a_act_fl_y;
  // Member: a_act_fl_z
  cdr << ros_message.a_act_fl_z;
  // Member: a_act_fr_x
  cdr << ros_message.a_act_fr_x;
  // Member: a_act_fr_y
  cdr << ros_message.a_act_fr_y;
  // Member: a_act_fr_z
  cdr << ros_message.a_act_fr_z;
  // Member: a_act_rl_x
  cdr << ros_message.a_act_rl_x;
  // Member: a_act_rl_y
  cdr << ros_message.a_act_rl_y;
  // Member: a_act_rl_z
  cdr << ros_message.a_act_rl_z;
  // Member: a_act_rr_x
  cdr << ros_message.a_act_rr_x;
  // Member: a_act_rr_y
  cdr << ros_message.a_act_rr_y;
  // Member: a_act_rr_z
  cdr << ros_message.a_act_rr_z;
  // Member: f_mpc_fl_x
  cdr << ros_message.f_mpc_fl_x;
  // Member: f_mpc_fl_y
  cdr << ros_message.f_mpc_fl_y;
  // Member: f_mpc_fl_z
  cdr << ros_message.f_mpc_fl_z;
  // Member: f_mpc_fr_x
  cdr << ros_message.f_mpc_fr_x;
  // Member: f_mpc_fr_y
  cdr << ros_message.f_mpc_fr_y;
  // Member: f_mpc_fr_z
  cdr << ros_message.f_mpc_fr_z;
  // Member: f_mpc_rl_x
  cdr << ros_message.f_mpc_rl_x;
  // Member: f_mpc_rl_y
  cdr << ros_message.f_mpc_rl_y;
  // Member: f_mpc_rl_z
  cdr << ros_message.f_mpc_rl_z;
  // Member: f_mpc_rr_x
  cdr << ros_message.f_mpc_rr_x;
  // Member: f_mpc_rr_y
  cdr << ros_message.f_mpc_rr_y;
  // Member: f_mpc_rr_z
  cdr << ros_message.f_mpc_rr_z;
  // Member: f_wbc_fl_x
  cdr << ros_message.f_wbc_fl_x;
  // Member: f_wbc_fl_y
  cdr << ros_message.f_wbc_fl_y;
  // Member: f_wbc_fl_z
  cdr << ros_message.f_wbc_fl_z;
  // Member: f_wbc_fr_x
  cdr << ros_message.f_wbc_fr_x;
  // Member: f_wbc_fr_y
  cdr << ros_message.f_wbc_fr_y;
  // Member: f_wbc_fr_z
  cdr << ros_message.f_wbc_fr_z;
  // Member: f_wbc_rl_x
  cdr << ros_message.f_wbc_rl_x;
  // Member: f_wbc_rl_y
  cdr << ros_message.f_wbc_rl_y;
  // Member: f_wbc_rl_z
  cdr << ros_message.f_wbc_rl_z;
  // Member: f_wbc_rr_x
  cdr << ros_message.f_wbc_rr_x;
  // Member: f_wbc_rr_y
  cdr << ros_message.f_wbc_rr_y;
  // Member: f_wbc_rr_z
  cdr << ros_message.f_wbc_rr_z;
  // Member: contact_fl
  cdr << ros_message.contact_fl;
  // Member: contact_fr
  cdr << ros_message.contact_fr;
  // Member: contact_rl
  cdr << ros_message.contact_rl;
  // Member: contact_rr
  cdr << ros_message.contact_rr;
  // Member: body_x
  cdr << ros_message.body_x;
  // Member: body_z
  cdr << ros_message.body_z;
  // Member: body_x_v
  cdr << ros_message.body_x_v;
  // Member: body_z_v
  cdr << ros_message.body_z_v;
  // Member: body_x_v_d
  cdr << ros_message.body_x_v_d;
  // Member: body_z_v_d
  cdr << ros_message.body_z_v_d;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_go2_robot
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  go2_robot::msg::Go2Telemetry & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: p_ref_fl_x
  cdr >> ros_message.p_ref_fl_x;

  // Member: p_ref_fl_y
  cdr >> ros_message.p_ref_fl_y;

  // Member: p_ref_fl_z
  cdr >> ros_message.p_ref_fl_z;

  // Member: p_ref_fr_x
  cdr >> ros_message.p_ref_fr_x;

  // Member: p_ref_fr_y
  cdr >> ros_message.p_ref_fr_y;

  // Member: p_ref_fr_z
  cdr >> ros_message.p_ref_fr_z;

  // Member: p_ref_rl_x
  cdr >> ros_message.p_ref_rl_x;

  // Member: p_ref_rl_y
  cdr >> ros_message.p_ref_rl_y;

  // Member: p_ref_rl_z
  cdr >> ros_message.p_ref_rl_z;

  // Member: p_ref_rr_x
  cdr >> ros_message.p_ref_rr_x;

  // Member: p_ref_rr_y
  cdr >> ros_message.p_ref_rr_y;

  // Member: p_ref_rr_z
  cdr >> ros_message.p_ref_rr_z;

  // Member: p_act_fl_x
  cdr >> ros_message.p_act_fl_x;

  // Member: p_act_fl_y
  cdr >> ros_message.p_act_fl_y;

  // Member: p_act_fl_z
  cdr >> ros_message.p_act_fl_z;

  // Member: p_act_fr_x
  cdr >> ros_message.p_act_fr_x;

  // Member: p_act_fr_y
  cdr >> ros_message.p_act_fr_y;

  // Member: p_act_fr_z
  cdr >> ros_message.p_act_fr_z;

  // Member: p_act_rl_x
  cdr >> ros_message.p_act_rl_x;

  // Member: p_act_rl_y
  cdr >> ros_message.p_act_rl_y;

  // Member: p_act_rl_z
  cdr >> ros_message.p_act_rl_z;

  // Member: p_act_rr_x
  cdr >> ros_message.p_act_rr_x;

  // Member: p_act_rr_y
  cdr >> ros_message.p_act_rr_y;

  // Member: p_act_rr_z
  cdr >> ros_message.p_act_rr_z;

  // Member: v_ref_fl_x
  cdr >> ros_message.v_ref_fl_x;

  // Member: v_ref_fl_y
  cdr >> ros_message.v_ref_fl_y;

  // Member: v_ref_fl_z
  cdr >> ros_message.v_ref_fl_z;

  // Member: v_ref_fr_x
  cdr >> ros_message.v_ref_fr_x;

  // Member: v_ref_fr_y
  cdr >> ros_message.v_ref_fr_y;

  // Member: v_ref_fr_z
  cdr >> ros_message.v_ref_fr_z;

  // Member: v_ref_rl_x
  cdr >> ros_message.v_ref_rl_x;

  // Member: v_ref_rl_y
  cdr >> ros_message.v_ref_rl_y;

  // Member: v_ref_rl_z
  cdr >> ros_message.v_ref_rl_z;

  // Member: v_ref_rr_x
  cdr >> ros_message.v_ref_rr_x;

  // Member: v_ref_rr_y
  cdr >> ros_message.v_ref_rr_y;

  // Member: v_ref_rr_z
  cdr >> ros_message.v_ref_rr_z;

  // Member: v_act_fl_x
  cdr >> ros_message.v_act_fl_x;

  // Member: v_act_fl_y
  cdr >> ros_message.v_act_fl_y;

  // Member: v_act_fl_z
  cdr >> ros_message.v_act_fl_z;

  // Member: v_act_fr_x
  cdr >> ros_message.v_act_fr_x;

  // Member: v_act_fr_y
  cdr >> ros_message.v_act_fr_y;

  // Member: v_act_fr_z
  cdr >> ros_message.v_act_fr_z;

  // Member: v_act_rl_x
  cdr >> ros_message.v_act_rl_x;

  // Member: v_act_rl_y
  cdr >> ros_message.v_act_rl_y;

  // Member: v_act_rl_z
  cdr >> ros_message.v_act_rl_z;

  // Member: v_act_rr_x
  cdr >> ros_message.v_act_rr_x;

  // Member: v_act_rr_y
  cdr >> ros_message.v_act_rr_y;

  // Member: v_act_rr_z
  cdr >> ros_message.v_act_rr_z;

  // Member: a_ref_fl_x
  cdr >> ros_message.a_ref_fl_x;

  // Member: a_ref_fl_y
  cdr >> ros_message.a_ref_fl_y;

  // Member: a_ref_fl_z
  cdr >> ros_message.a_ref_fl_z;

  // Member: a_ref_fr_x
  cdr >> ros_message.a_ref_fr_x;

  // Member: a_ref_fr_y
  cdr >> ros_message.a_ref_fr_y;

  // Member: a_ref_fr_z
  cdr >> ros_message.a_ref_fr_z;

  // Member: a_ref_rl_x
  cdr >> ros_message.a_ref_rl_x;

  // Member: a_ref_rl_y
  cdr >> ros_message.a_ref_rl_y;

  // Member: a_ref_rl_z
  cdr >> ros_message.a_ref_rl_z;

  // Member: a_ref_rr_x
  cdr >> ros_message.a_ref_rr_x;

  // Member: a_ref_rr_y
  cdr >> ros_message.a_ref_rr_y;

  // Member: a_ref_rr_z
  cdr >> ros_message.a_ref_rr_z;

  // Member: a_act_fl_x
  cdr >> ros_message.a_act_fl_x;

  // Member: a_act_fl_y
  cdr >> ros_message.a_act_fl_y;

  // Member: a_act_fl_z
  cdr >> ros_message.a_act_fl_z;

  // Member: a_act_fr_x
  cdr >> ros_message.a_act_fr_x;

  // Member: a_act_fr_y
  cdr >> ros_message.a_act_fr_y;

  // Member: a_act_fr_z
  cdr >> ros_message.a_act_fr_z;

  // Member: a_act_rl_x
  cdr >> ros_message.a_act_rl_x;

  // Member: a_act_rl_y
  cdr >> ros_message.a_act_rl_y;

  // Member: a_act_rl_z
  cdr >> ros_message.a_act_rl_z;

  // Member: a_act_rr_x
  cdr >> ros_message.a_act_rr_x;

  // Member: a_act_rr_y
  cdr >> ros_message.a_act_rr_y;

  // Member: a_act_rr_z
  cdr >> ros_message.a_act_rr_z;

  // Member: f_mpc_fl_x
  cdr >> ros_message.f_mpc_fl_x;

  // Member: f_mpc_fl_y
  cdr >> ros_message.f_mpc_fl_y;

  // Member: f_mpc_fl_z
  cdr >> ros_message.f_mpc_fl_z;

  // Member: f_mpc_fr_x
  cdr >> ros_message.f_mpc_fr_x;

  // Member: f_mpc_fr_y
  cdr >> ros_message.f_mpc_fr_y;

  // Member: f_mpc_fr_z
  cdr >> ros_message.f_mpc_fr_z;

  // Member: f_mpc_rl_x
  cdr >> ros_message.f_mpc_rl_x;

  // Member: f_mpc_rl_y
  cdr >> ros_message.f_mpc_rl_y;

  // Member: f_mpc_rl_z
  cdr >> ros_message.f_mpc_rl_z;

  // Member: f_mpc_rr_x
  cdr >> ros_message.f_mpc_rr_x;

  // Member: f_mpc_rr_y
  cdr >> ros_message.f_mpc_rr_y;

  // Member: f_mpc_rr_z
  cdr >> ros_message.f_mpc_rr_z;

  // Member: f_wbc_fl_x
  cdr >> ros_message.f_wbc_fl_x;

  // Member: f_wbc_fl_y
  cdr >> ros_message.f_wbc_fl_y;

  // Member: f_wbc_fl_z
  cdr >> ros_message.f_wbc_fl_z;

  // Member: f_wbc_fr_x
  cdr >> ros_message.f_wbc_fr_x;

  // Member: f_wbc_fr_y
  cdr >> ros_message.f_wbc_fr_y;

  // Member: f_wbc_fr_z
  cdr >> ros_message.f_wbc_fr_z;

  // Member: f_wbc_rl_x
  cdr >> ros_message.f_wbc_rl_x;

  // Member: f_wbc_rl_y
  cdr >> ros_message.f_wbc_rl_y;

  // Member: f_wbc_rl_z
  cdr >> ros_message.f_wbc_rl_z;

  // Member: f_wbc_rr_x
  cdr >> ros_message.f_wbc_rr_x;

  // Member: f_wbc_rr_y
  cdr >> ros_message.f_wbc_rr_y;

  // Member: f_wbc_rr_z
  cdr >> ros_message.f_wbc_rr_z;

  // Member: contact_fl
  cdr >> ros_message.contact_fl;

  // Member: contact_fr
  cdr >> ros_message.contact_fr;

  // Member: contact_rl
  cdr >> ros_message.contact_rl;

  // Member: contact_rr
  cdr >> ros_message.contact_rr;

  // Member: body_x
  cdr >> ros_message.body_x;

  // Member: body_z
  cdr >> ros_message.body_z;

  // Member: body_x_v
  cdr >> ros_message.body_x_v;

  // Member: body_z_v
  cdr >> ros_message.body_z_v;

  // Member: body_x_v_d
  cdr >> ros_message.body_x_v_d;

  // Member: body_z_v_d
  cdr >> ros_message.body_z_v_d;

  return true;
}  // NOLINT(readability/fn_size)

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_go2_robot
get_serialized_size(
  const go2_robot::msg::Go2Telemetry & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: p_ref_fl_x
  {
    size_t item_size = sizeof(ros_message.p_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_fl_y
  {
    size_t item_size = sizeof(ros_message.p_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_fl_z
  {
    size_t item_size = sizeof(ros_message.p_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_fr_x
  {
    size_t item_size = sizeof(ros_message.p_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_fr_y
  {
    size_t item_size = sizeof(ros_message.p_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_fr_z
  {
    size_t item_size = sizeof(ros_message.p_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rl_x
  {
    size_t item_size = sizeof(ros_message.p_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rl_y
  {
    size_t item_size = sizeof(ros_message.p_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rl_z
  {
    size_t item_size = sizeof(ros_message.p_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rr_x
  {
    size_t item_size = sizeof(ros_message.p_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rr_y
  {
    size_t item_size = sizeof(ros_message.p_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_ref_rr_z
  {
    size_t item_size = sizeof(ros_message.p_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fl_x
  {
    size_t item_size = sizeof(ros_message.p_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fl_y
  {
    size_t item_size = sizeof(ros_message.p_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fl_z
  {
    size_t item_size = sizeof(ros_message.p_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fr_x
  {
    size_t item_size = sizeof(ros_message.p_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fr_y
  {
    size_t item_size = sizeof(ros_message.p_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_fr_z
  {
    size_t item_size = sizeof(ros_message.p_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rl_x
  {
    size_t item_size = sizeof(ros_message.p_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rl_y
  {
    size_t item_size = sizeof(ros_message.p_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rl_z
  {
    size_t item_size = sizeof(ros_message.p_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rr_x
  {
    size_t item_size = sizeof(ros_message.p_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rr_y
  {
    size_t item_size = sizeof(ros_message.p_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: p_act_rr_z
  {
    size_t item_size = sizeof(ros_message.p_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fl_x
  {
    size_t item_size = sizeof(ros_message.v_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fl_y
  {
    size_t item_size = sizeof(ros_message.v_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fl_z
  {
    size_t item_size = sizeof(ros_message.v_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fr_x
  {
    size_t item_size = sizeof(ros_message.v_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fr_y
  {
    size_t item_size = sizeof(ros_message.v_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_fr_z
  {
    size_t item_size = sizeof(ros_message.v_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rl_x
  {
    size_t item_size = sizeof(ros_message.v_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rl_y
  {
    size_t item_size = sizeof(ros_message.v_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rl_z
  {
    size_t item_size = sizeof(ros_message.v_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rr_x
  {
    size_t item_size = sizeof(ros_message.v_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rr_y
  {
    size_t item_size = sizeof(ros_message.v_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_ref_rr_z
  {
    size_t item_size = sizeof(ros_message.v_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fl_x
  {
    size_t item_size = sizeof(ros_message.v_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fl_y
  {
    size_t item_size = sizeof(ros_message.v_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fl_z
  {
    size_t item_size = sizeof(ros_message.v_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fr_x
  {
    size_t item_size = sizeof(ros_message.v_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fr_y
  {
    size_t item_size = sizeof(ros_message.v_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_fr_z
  {
    size_t item_size = sizeof(ros_message.v_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rl_x
  {
    size_t item_size = sizeof(ros_message.v_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rl_y
  {
    size_t item_size = sizeof(ros_message.v_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rl_z
  {
    size_t item_size = sizeof(ros_message.v_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rr_x
  {
    size_t item_size = sizeof(ros_message.v_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rr_y
  {
    size_t item_size = sizeof(ros_message.v_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: v_act_rr_z
  {
    size_t item_size = sizeof(ros_message.v_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fl_x
  {
    size_t item_size = sizeof(ros_message.a_ref_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fl_y
  {
    size_t item_size = sizeof(ros_message.a_ref_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fl_z
  {
    size_t item_size = sizeof(ros_message.a_ref_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fr_x
  {
    size_t item_size = sizeof(ros_message.a_ref_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fr_y
  {
    size_t item_size = sizeof(ros_message.a_ref_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_fr_z
  {
    size_t item_size = sizeof(ros_message.a_ref_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rl_x
  {
    size_t item_size = sizeof(ros_message.a_ref_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rl_y
  {
    size_t item_size = sizeof(ros_message.a_ref_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rl_z
  {
    size_t item_size = sizeof(ros_message.a_ref_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rr_x
  {
    size_t item_size = sizeof(ros_message.a_ref_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rr_y
  {
    size_t item_size = sizeof(ros_message.a_ref_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_ref_rr_z
  {
    size_t item_size = sizeof(ros_message.a_ref_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fl_x
  {
    size_t item_size = sizeof(ros_message.a_act_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fl_y
  {
    size_t item_size = sizeof(ros_message.a_act_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fl_z
  {
    size_t item_size = sizeof(ros_message.a_act_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fr_x
  {
    size_t item_size = sizeof(ros_message.a_act_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fr_y
  {
    size_t item_size = sizeof(ros_message.a_act_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_fr_z
  {
    size_t item_size = sizeof(ros_message.a_act_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rl_x
  {
    size_t item_size = sizeof(ros_message.a_act_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rl_y
  {
    size_t item_size = sizeof(ros_message.a_act_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rl_z
  {
    size_t item_size = sizeof(ros_message.a_act_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rr_x
  {
    size_t item_size = sizeof(ros_message.a_act_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rr_y
  {
    size_t item_size = sizeof(ros_message.a_act_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: a_act_rr_z
  {
    size_t item_size = sizeof(ros_message.a_act_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fl_x
  {
    size_t item_size = sizeof(ros_message.f_mpc_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fl_y
  {
    size_t item_size = sizeof(ros_message.f_mpc_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fl_z
  {
    size_t item_size = sizeof(ros_message.f_mpc_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fr_x
  {
    size_t item_size = sizeof(ros_message.f_mpc_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fr_y
  {
    size_t item_size = sizeof(ros_message.f_mpc_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_fr_z
  {
    size_t item_size = sizeof(ros_message.f_mpc_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rl_x
  {
    size_t item_size = sizeof(ros_message.f_mpc_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rl_y
  {
    size_t item_size = sizeof(ros_message.f_mpc_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rl_z
  {
    size_t item_size = sizeof(ros_message.f_mpc_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rr_x
  {
    size_t item_size = sizeof(ros_message.f_mpc_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rr_y
  {
    size_t item_size = sizeof(ros_message.f_mpc_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_mpc_rr_z
  {
    size_t item_size = sizeof(ros_message.f_mpc_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fl_x
  {
    size_t item_size = sizeof(ros_message.f_wbc_fl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fl_y
  {
    size_t item_size = sizeof(ros_message.f_wbc_fl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fl_z
  {
    size_t item_size = sizeof(ros_message.f_wbc_fl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fr_x
  {
    size_t item_size = sizeof(ros_message.f_wbc_fr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fr_y
  {
    size_t item_size = sizeof(ros_message.f_wbc_fr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_fr_z
  {
    size_t item_size = sizeof(ros_message.f_wbc_fr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rl_x
  {
    size_t item_size = sizeof(ros_message.f_wbc_rl_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rl_y
  {
    size_t item_size = sizeof(ros_message.f_wbc_rl_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rl_z
  {
    size_t item_size = sizeof(ros_message.f_wbc_rl_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rr_x
  {
    size_t item_size = sizeof(ros_message.f_wbc_rr_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rr_y
  {
    size_t item_size = sizeof(ros_message.f_wbc_rr_y);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: f_wbc_rr_z
  {
    size_t item_size = sizeof(ros_message.f_wbc_rr_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: contact_fl
  {
    size_t item_size = sizeof(ros_message.contact_fl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: contact_fr
  {
    size_t item_size = sizeof(ros_message.contact_fr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: contact_rl
  {
    size_t item_size = sizeof(ros_message.contact_rl);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: contact_rr
  {
    size_t item_size = sizeof(ros_message.contact_rr);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_x
  {
    size_t item_size = sizeof(ros_message.body_x);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_z
  {
    size_t item_size = sizeof(ros_message.body_z);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_x_v
  {
    size_t item_size = sizeof(ros_message.body_x_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_z_v
  {
    size_t item_size = sizeof(ros_message.body_z_v);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_x_v_d
  {
    size_t item_size = sizeof(ros_message.body_x_v_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: body_z_v_d
  {
    size_t item_size = sizeof(ros_message.body_z_v_d);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_go2_robot
max_serialized_size_Go2Telemetry(
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


  // Member: header
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: p_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: p_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: v_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_ref_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: a_act_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_mpc_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_fr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rl_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rl_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rl_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rr_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rr_y
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: f_wbc_rr_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: contact_fl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: contact_fr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: contact_rl
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: contact_rr
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_x
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_z
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_x_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_z_v
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_x_v_d
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: body_z_v_d
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
    using DataType = go2_robot::msg::Go2Telemetry;
    is_plain =
      (
      offsetof(DataType, body_z_v_d) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _Go2Telemetry__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const go2_robot::msg::Go2Telemetry *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _Go2Telemetry__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<go2_robot::msg::Go2Telemetry *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _Go2Telemetry__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const go2_robot::msg::Go2Telemetry *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _Go2Telemetry__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_Go2Telemetry(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _Go2Telemetry__callbacks = {
  "go2_robot::msg",
  "Go2Telemetry",
  _Go2Telemetry__cdr_serialize,
  _Go2Telemetry__cdr_deserialize,
  _Go2Telemetry__get_serialized_size,
  _Go2Telemetry__max_serialized_size
};

static rosidl_message_type_support_t _Go2Telemetry__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_Go2Telemetry__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace go2_robot

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_go2_robot
const rosidl_message_type_support_t *
get_message_type_support_handle<go2_robot::msg::Go2Telemetry>()
{
  return &go2_robot::msg::typesupport_fastrtps_cpp::_Go2Telemetry__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, go2_robot, msg, Go2Telemetry)() {
  return &go2_robot::msg::typesupport_fastrtps_cpp::_Go2Telemetry__handle;
}

#ifdef __cplusplus
}
#endif
