// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice
#include "go2_robot/msg/detail/go2_telemetry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
go2_robot__msg__Go2Telemetry__init(go2_robot__msg__Go2Telemetry * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    go2_robot__msg__Go2Telemetry__fini(msg);
    return false;
  }
  // p_ref_fl_x
  // p_ref_fl_y
  // p_ref_fl_z
  // p_ref_fr_x
  // p_ref_fr_y
  // p_ref_fr_z
  // p_ref_rl_x
  // p_ref_rl_y
  // p_ref_rl_z
  // p_ref_rr_x
  // p_ref_rr_y
  // p_ref_rr_z
  // p_act_fl_x
  // p_act_fl_y
  // p_act_fl_z
  // p_act_fr_x
  // p_act_fr_y
  // p_act_fr_z
  // p_act_rl_x
  // p_act_rl_y
  // p_act_rl_z
  // p_act_rr_x
  // p_act_rr_y
  // p_act_rr_z
  // v_ref_fl_x
  // v_ref_fl_y
  // v_ref_fl_z
  // v_ref_fr_x
  // v_ref_fr_y
  // v_ref_fr_z
  // v_ref_rl_x
  // v_ref_rl_y
  // v_ref_rl_z
  // v_ref_rr_x
  // v_ref_rr_y
  // v_ref_rr_z
  // v_act_fl_x
  // v_act_fl_y
  // v_act_fl_z
  // v_act_fr_x
  // v_act_fr_y
  // v_act_fr_z
  // v_act_rl_x
  // v_act_rl_y
  // v_act_rl_z
  // v_act_rr_x
  // v_act_rr_y
  // v_act_rr_z
  // a_ref_fl_x
  // a_ref_fl_y
  // a_ref_fl_z
  // a_ref_fr_x
  // a_ref_fr_y
  // a_ref_fr_z
  // a_ref_rl_x
  // a_ref_rl_y
  // a_ref_rl_z
  // a_ref_rr_x
  // a_ref_rr_y
  // a_ref_rr_z
  // a_act_fl_x
  // a_act_fl_y
  // a_act_fl_z
  // a_act_fr_x
  // a_act_fr_y
  // a_act_fr_z
  // a_act_rl_x
  // a_act_rl_y
  // a_act_rl_z
  // a_act_rr_x
  // a_act_rr_y
  // a_act_rr_z
  // f_mpc_fl_x
  // f_mpc_fl_y
  // f_mpc_fl_z
  // f_mpc_fr_x
  // f_mpc_fr_y
  // f_mpc_fr_z
  // f_mpc_rl_x
  // f_mpc_rl_y
  // f_mpc_rl_z
  // f_mpc_rr_x
  // f_mpc_rr_y
  // f_mpc_rr_z
  // f_wbc_fl_x
  // f_wbc_fl_y
  // f_wbc_fl_z
  // f_wbc_fr_x
  // f_wbc_fr_y
  // f_wbc_fr_z
  // f_wbc_rl_x
  // f_wbc_rl_y
  // f_wbc_rl_z
  // f_wbc_rr_x
  // f_wbc_rr_y
  // f_wbc_rr_z
  // contact_fl
  // contact_fr
  // contact_rl
  // contact_rr
  // body_x
  // body_z
  // body_x_v
  // body_z_v
  // body_x_v_d
  // body_z_v_d
  return true;
}

void
go2_robot__msg__Go2Telemetry__fini(go2_robot__msg__Go2Telemetry * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // p_ref_fl_x
  // p_ref_fl_y
  // p_ref_fl_z
  // p_ref_fr_x
  // p_ref_fr_y
  // p_ref_fr_z
  // p_ref_rl_x
  // p_ref_rl_y
  // p_ref_rl_z
  // p_ref_rr_x
  // p_ref_rr_y
  // p_ref_rr_z
  // p_act_fl_x
  // p_act_fl_y
  // p_act_fl_z
  // p_act_fr_x
  // p_act_fr_y
  // p_act_fr_z
  // p_act_rl_x
  // p_act_rl_y
  // p_act_rl_z
  // p_act_rr_x
  // p_act_rr_y
  // p_act_rr_z
  // v_ref_fl_x
  // v_ref_fl_y
  // v_ref_fl_z
  // v_ref_fr_x
  // v_ref_fr_y
  // v_ref_fr_z
  // v_ref_rl_x
  // v_ref_rl_y
  // v_ref_rl_z
  // v_ref_rr_x
  // v_ref_rr_y
  // v_ref_rr_z
  // v_act_fl_x
  // v_act_fl_y
  // v_act_fl_z
  // v_act_fr_x
  // v_act_fr_y
  // v_act_fr_z
  // v_act_rl_x
  // v_act_rl_y
  // v_act_rl_z
  // v_act_rr_x
  // v_act_rr_y
  // v_act_rr_z
  // a_ref_fl_x
  // a_ref_fl_y
  // a_ref_fl_z
  // a_ref_fr_x
  // a_ref_fr_y
  // a_ref_fr_z
  // a_ref_rl_x
  // a_ref_rl_y
  // a_ref_rl_z
  // a_ref_rr_x
  // a_ref_rr_y
  // a_ref_rr_z
  // a_act_fl_x
  // a_act_fl_y
  // a_act_fl_z
  // a_act_fr_x
  // a_act_fr_y
  // a_act_fr_z
  // a_act_rl_x
  // a_act_rl_y
  // a_act_rl_z
  // a_act_rr_x
  // a_act_rr_y
  // a_act_rr_z
  // f_mpc_fl_x
  // f_mpc_fl_y
  // f_mpc_fl_z
  // f_mpc_fr_x
  // f_mpc_fr_y
  // f_mpc_fr_z
  // f_mpc_rl_x
  // f_mpc_rl_y
  // f_mpc_rl_z
  // f_mpc_rr_x
  // f_mpc_rr_y
  // f_mpc_rr_z
  // f_wbc_fl_x
  // f_wbc_fl_y
  // f_wbc_fl_z
  // f_wbc_fr_x
  // f_wbc_fr_y
  // f_wbc_fr_z
  // f_wbc_rl_x
  // f_wbc_rl_y
  // f_wbc_rl_z
  // f_wbc_rr_x
  // f_wbc_rr_y
  // f_wbc_rr_z
  // contact_fl
  // contact_fr
  // contact_rl
  // contact_rr
  // body_x
  // body_z
  // body_x_v
  // body_z_v
  // body_x_v_d
  // body_z_v_d
}

bool
go2_robot__msg__Go2Telemetry__are_equal(const go2_robot__msg__Go2Telemetry * lhs, const go2_robot__msg__Go2Telemetry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // p_ref_fl_x
  if (lhs->p_ref_fl_x != rhs->p_ref_fl_x) {
    return false;
  }
  // p_ref_fl_y
  if (lhs->p_ref_fl_y != rhs->p_ref_fl_y) {
    return false;
  }
  // p_ref_fl_z
  if (lhs->p_ref_fl_z != rhs->p_ref_fl_z) {
    return false;
  }
  // p_ref_fr_x
  if (lhs->p_ref_fr_x != rhs->p_ref_fr_x) {
    return false;
  }
  // p_ref_fr_y
  if (lhs->p_ref_fr_y != rhs->p_ref_fr_y) {
    return false;
  }
  // p_ref_fr_z
  if (lhs->p_ref_fr_z != rhs->p_ref_fr_z) {
    return false;
  }
  // p_ref_rl_x
  if (lhs->p_ref_rl_x != rhs->p_ref_rl_x) {
    return false;
  }
  // p_ref_rl_y
  if (lhs->p_ref_rl_y != rhs->p_ref_rl_y) {
    return false;
  }
  // p_ref_rl_z
  if (lhs->p_ref_rl_z != rhs->p_ref_rl_z) {
    return false;
  }
  // p_ref_rr_x
  if (lhs->p_ref_rr_x != rhs->p_ref_rr_x) {
    return false;
  }
  // p_ref_rr_y
  if (lhs->p_ref_rr_y != rhs->p_ref_rr_y) {
    return false;
  }
  // p_ref_rr_z
  if (lhs->p_ref_rr_z != rhs->p_ref_rr_z) {
    return false;
  }
  // p_act_fl_x
  if (lhs->p_act_fl_x != rhs->p_act_fl_x) {
    return false;
  }
  // p_act_fl_y
  if (lhs->p_act_fl_y != rhs->p_act_fl_y) {
    return false;
  }
  // p_act_fl_z
  if (lhs->p_act_fl_z != rhs->p_act_fl_z) {
    return false;
  }
  // p_act_fr_x
  if (lhs->p_act_fr_x != rhs->p_act_fr_x) {
    return false;
  }
  // p_act_fr_y
  if (lhs->p_act_fr_y != rhs->p_act_fr_y) {
    return false;
  }
  // p_act_fr_z
  if (lhs->p_act_fr_z != rhs->p_act_fr_z) {
    return false;
  }
  // p_act_rl_x
  if (lhs->p_act_rl_x != rhs->p_act_rl_x) {
    return false;
  }
  // p_act_rl_y
  if (lhs->p_act_rl_y != rhs->p_act_rl_y) {
    return false;
  }
  // p_act_rl_z
  if (lhs->p_act_rl_z != rhs->p_act_rl_z) {
    return false;
  }
  // p_act_rr_x
  if (lhs->p_act_rr_x != rhs->p_act_rr_x) {
    return false;
  }
  // p_act_rr_y
  if (lhs->p_act_rr_y != rhs->p_act_rr_y) {
    return false;
  }
  // p_act_rr_z
  if (lhs->p_act_rr_z != rhs->p_act_rr_z) {
    return false;
  }
  // v_ref_fl_x
  if (lhs->v_ref_fl_x != rhs->v_ref_fl_x) {
    return false;
  }
  // v_ref_fl_y
  if (lhs->v_ref_fl_y != rhs->v_ref_fl_y) {
    return false;
  }
  // v_ref_fl_z
  if (lhs->v_ref_fl_z != rhs->v_ref_fl_z) {
    return false;
  }
  // v_ref_fr_x
  if (lhs->v_ref_fr_x != rhs->v_ref_fr_x) {
    return false;
  }
  // v_ref_fr_y
  if (lhs->v_ref_fr_y != rhs->v_ref_fr_y) {
    return false;
  }
  // v_ref_fr_z
  if (lhs->v_ref_fr_z != rhs->v_ref_fr_z) {
    return false;
  }
  // v_ref_rl_x
  if (lhs->v_ref_rl_x != rhs->v_ref_rl_x) {
    return false;
  }
  // v_ref_rl_y
  if (lhs->v_ref_rl_y != rhs->v_ref_rl_y) {
    return false;
  }
  // v_ref_rl_z
  if (lhs->v_ref_rl_z != rhs->v_ref_rl_z) {
    return false;
  }
  // v_ref_rr_x
  if (lhs->v_ref_rr_x != rhs->v_ref_rr_x) {
    return false;
  }
  // v_ref_rr_y
  if (lhs->v_ref_rr_y != rhs->v_ref_rr_y) {
    return false;
  }
  // v_ref_rr_z
  if (lhs->v_ref_rr_z != rhs->v_ref_rr_z) {
    return false;
  }
  // v_act_fl_x
  if (lhs->v_act_fl_x != rhs->v_act_fl_x) {
    return false;
  }
  // v_act_fl_y
  if (lhs->v_act_fl_y != rhs->v_act_fl_y) {
    return false;
  }
  // v_act_fl_z
  if (lhs->v_act_fl_z != rhs->v_act_fl_z) {
    return false;
  }
  // v_act_fr_x
  if (lhs->v_act_fr_x != rhs->v_act_fr_x) {
    return false;
  }
  // v_act_fr_y
  if (lhs->v_act_fr_y != rhs->v_act_fr_y) {
    return false;
  }
  // v_act_fr_z
  if (lhs->v_act_fr_z != rhs->v_act_fr_z) {
    return false;
  }
  // v_act_rl_x
  if (lhs->v_act_rl_x != rhs->v_act_rl_x) {
    return false;
  }
  // v_act_rl_y
  if (lhs->v_act_rl_y != rhs->v_act_rl_y) {
    return false;
  }
  // v_act_rl_z
  if (lhs->v_act_rl_z != rhs->v_act_rl_z) {
    return false;
  }
  // v_act_rr_x
  if (lhs->v_act_rr_x != rhs->v_act_rr_x) {
    return false;
  }
  // v_act_rr_y
  if (lhs->v_act_rr_y != rhs->v_act_rr_y) {
    return false;
  }
  // v_act_rr_z
  if (lhs->v_act_rr_z != rhs->v_act_rr_z) {
    return false;
  }
  // a_ref_fl_x
  if (lhs->a_ref_fl_x != rhs->a_ref_fl_x) {
    return false;
  }
  // a_ref_fl_y
  if (lhs->a_ref_fl_y != rhs->a_ref_fl_y) {
    return false;
  }
  // a_ref_fl_z
  if (lhs->a_ref_fl_z != rhs->a_ref_fl_z) {
    return false;
  }
  // a_ref_fr_x
  if (lhs->a_ref_fr_x != rhs->a_ref_fr_x) {
    return false;
  }
  // a_ref_fr_y
  if (lhs->a_ref_fr_y != rhs->a_ref_fr_y) {
    return false;
  }
  // a_ref_fr_z
  if (lhs->a_ref_fr_z != rhs->a_ref_fr_z) {
    return false;
  }
  // a_ref_rl_x
  if (lhs->a_ref_rl_x != rhs->a_ref_rl_x) {
    return false;
  }
  // a_ref_rl_y
  if (lhs->a_ref_rl_y != rhs->a_ref_rl_y) {
    return false;
  }
  // a_ref_rl_z
  if (lhs->a_ref_rl_z != rhs->a_ref_rl_z) {
    return false;
  }
  // a_ref_rr_x
  if (lhs->a_ref_rr_x != rhs->a_ref_rr_x) {
    return false;
  }
  // a_ref_rr_y
  if (lhs->a_ref_rr_y != rhs->a_ref_rr_y) {
    return false;
  }
  // a_ref_rr_z
  if (lhs->a_ref_rr_z != rhs->a_ref_rr_z) {
    return false;
  }
  // a_act_fl_x
  if (lhs->a_act_fl_x != rhs->a_act_fl_x) {
    return false;
  }
  // a_act_fl_y
  if (lhs->a_act_fl_y != rhs->a_act_fl_y) {
    return false;
  }
  // a_act_fl_z
  if (lhs->a_act_fl_z != rhs->a_act_fl_z) {
    return false;
  }
  // a_act_fr_x
  if (lhs->a_act_fr_x != rhs->a_act_fr_x) {
    return false;
  }
  // a_act_fr_y
  if (lhs->a_act_fr_y != rhs->a_act_fr_y) {
    return false;
  }
  // a_act_fr_z
  if (lhs->a_act_fr_z != rhs->a_act_fr_z) {
    return false;
  }
  // a_act_rl_x
  if (lhs->a_act_rl_x != rhs->a_act_rl_x) {
    return false;
  }
  // a_act_rl_y
  if (lhs->a_act_rl_y != rhs->a_act_rl_y) {
    return false;
  }
  // a_act_rl_z
  if (lhs->a_act_rl_z != rhs->a_act_rl_z) {
    return false;
  }
  // a_act_rr_x
  if (lhs->a_act_rr_x != rhs->a_act_rr_x) {
    return false;
  }
  // a_act_rr_y
  if (lhs->a_act_rr_y != rhs->a_act_rr_y) {
    return false;
  }
  // a_act_rr_z
  if (lhs->a_act_rr_z != rhs->a_act_rr_z) {
    return false;
  }
  // f_mpc_fl_x
  if (lhs->f_mpc_fl_x != rhs->f_mpc_fl_x) {
    return false;
  }
  // f_mpc_fl_y
  if (lhs->f_mpc_fl_y != rhs->f_mpc_fl_y) {
    return false;
  }
  // f_mpc_fl_z
  if (lhs->f_mpc_fl_z != rhs->f_mpc_fl_z) {
    return false;
  }
  // f_mpc_fr_x
  if (lhs->f_mpc_fr_x != rhs->f_mpc_fr_x) {
    return false;
  }
  // f_mpc_fr_y
  if (lhs->f_mpc_fr_y != rhs->f_mpc_fr_y) {
    return false;
  }
  // f_mpc_fr_z
  if (lhs->f_mpc_fr_z != rhs->f_mpc_fr_z) {
    return false;
  }
  // f_mpc_rl_x
  if (lhs->f_mpc_rl_x != rhs->f_mpc_rl_x) {
    return false;
  }
  // f_mpc_rl_y
  if (lhs->f_mpc_rl_y != rhs->f_mpc_rl_y) {
    return false;
  }
  // f_mpc_rl_z
  if (lhs->f_mpc_rl_z != rhs->f_mpc_rl_z) {
    return false;
  }
  // f_mpc_rr_x
  if (lhs->f_mpc_rr_x != rhs->f_mpc_rr_x) {
    return false;
  }
  // f_mpc_rr_y
  if (lhs->f_mpc_rr_y != rhs->f_mpc_rr_y) {
    return false;
  }
  // f_mpc_rr_z
  if (lhs->f_mpc_rr_z != rhs->f_mpc_rr_z) {
    return false;
  }
  // f_wbc_fl_x
  if (lhs->f_wbc_fl_x != rhs->f_wbc_fl_x) {
    return false;
  }
  // f_wbc_fl_y
  if (lhs->f_wbc_fl_y != rhs->f_wbc_fl_y) {
    return false;
  }
  // f_wbc_fl_z
  if (lhs->f_wbc_fl_z != rhs->f_wbc_fl_z) {
    return false;
  }
  // f_wbc_fr_x
  if (lhs->f_wbc_fr_x != rhs->f_wbc_fr_x) {
    return false;
  }
  // f_wbc_fr_y
  if (lhs->f_wbc_fr_y != rhs->f_wbc_fr_y) {
    return false;
  }
  // f_wbc_fr_z
  if (lhs->f_wbc_fr_z != rhs->f_wbc_fr_z) {
    return false;
  }
  // f_wbc_rl_x
  if (lhs->f_wbc_rl_x != rhs->f_wbc_rl_x) {
    return false;
  }
  // f_wbc_rl_y
  if (lhs->f_wbc_rl_y != rhs->f_wbc_rl_y) {
    return false;
  }
  // f_wbc_rl_z
  if (lhs->f_wbc_rl_z != rhs->f_wbc_rl_z) {
    return false;
  }
  // f_wbc_rr_x
  if (lhs->f_wbc_rr_x != rhs->f_wbc_rr_x) {
    return false;
  }
  // f_wbc_rr_y
  if (lhs->f_wbc_rr_y != rhs->f_wbc_rr_y) {
    return false;
  }
  // f_wbc_rr_z
  if (lhs->f_wbc_rr_z != rhs->f_wbc_rr_z) {
    return false;
  }
  // contact_fl
  if (lhs->contact_fl != rhs->contact_fl) {
    return false;
  }
  // contact_fr
  if (lhs->contact_fr != rhs->contact_fr) {
    return false;
  }
  // contact_rl
  if (lhs->contact_rl != rhs->contact_rl) {
    return false;
  }
  // contact_rr
  if (lhs->contact_rr != rhs->contact_rr) {
    return false;
  }
  // body_x
  if (lhs->body_x != rhs->body_x) {
    return false;
  }
  // body_z
  if (lhs->body_z != rhs->body_z) {
    return false;
  }
  // body_x_v
  if (lhs->body_x_v != rhs->body_x_v) {
    return false;
  }
  // body_z_v
  if (lhs->body_z_v != rhs->body_z_v) {
    return false;
  }
  // body_x_v_d
  if (lhs->body_x_v_d != rhs->body_x_v_d) {
    return false;
  }
  // body_z_v_d
  if (lhs->body_z_v_d != rhs->body_z_v_d) {
    return false;
  }
  return true;
}

bool
go2_robot__msg__Go2Telemetry__copy(
  const go2_robot__msg__Go2Telemetry * input,
  go2_robot__msg__Go2Telemetry * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // p_ref_fl_x
  output->p_ref_fl_x = input->p_ref_fl_x;
  // p_ref_fl_y
  output->p_ref_fl_y = input->p_ref_fl_y;
  // p_ref_fl_z
  output->p_ref_fl_z = input->p_ref_fl_z;
  // p_ref_fr_x
  output->p_ref_fr_x = input->p_ref_fr_x;
  // p_ref_fr_y
  output->p_ref_fr_y = input->p_ref_fr_y;
  // p_ref_fr_z
  output->p_ref_fr_z = input->p_ref_fr_z;
  // p_ref_rl_x
  output->p_ref_rl_x = input->p_ref_rl_x;
  // p_ref_rl_y
  output->p_ref_rl_y = input->p_ref_rl_y;
  // p_ref_rl_z
  output->p_ref_rl_z = input->p_ref_rl_z;
  // p_ref_rr_x
  output->p_ref_rr_x = input->p_ref_rr_x;
  // p_ref_rr_y
  output->p_ref_rr_y = input->p_ref_rr_y;
  // p_ref_rr_z
  output->p_ref_rr_z = input->p_ref_rr_z;
  // p_act_fl_x
  output->p_act_fl_x = input->p_act_fl_x;
  // p_act_fl_y
  output->p_act_fl_y = input->p_act_fl_y;
  // p_act_fl_z
  output->p_act_fl_z = input->p_act_fl_z;
  // p_act_fr_x
  output->p_act_fr_x = input->p_act_fr_x;
  // p_act_fr_y
  output->p_act_fr_y = input->p_act_fr_y;
  // p_act_fr_z
  output->p_act_fr_z = input->p_act_fr_z;
  // p_act_rl_x
  output->p_act_rl_x = input->p_act_rl_x;
  // p_act_rl_y
  output->p_act_rl_y = input->p_act_rl_y;
  // p_act_rl_z
  output->p_act_rl_z = input->p_act_rl_z;
  // p_act_rr_x
  output->p_act_rr_x = input->p_act_rr_x;
  // p_act_rr_y
  output->p_act_rr_y = input->p_act_rr_y;
  // p_act_rr_z
  output->p_act_rr_z = input->p_act_rr_z;
  // v_ref_fl_x
  output->v_ref_fl_x = input->v_ref_fl_x;
  // v_ref_fl_y
  output->v_ref_fl_y = input->v_ref_fl_y;
  // v_ref_fl_z
  output->v_ref_fl_z = input->v_ref_fl_z;
  // v_ref_fr_x
  output->v_ref_fr_x = input->v_ref_fr_x;
  // v_ref_fr_y
  output->v_ref_fr_y = input->v_ref_fr_y;
  // v_ref_fr_z
  output->v_ref_fr_z = input->v_ref_fr_z;
  // v_ref_rl_x
  output->v_ref_rl_x = input->v_ref_rl_x;
  // v_ref_rl_y
  output->v_ref_rl_y = input->v_ref_rl_y;
  // v_ref_rl_z
  output->v_ref_rl_z = input->v_ref_rl_z;
  // v_ref_rr_x
  output->v_ref_rr_x = input->v_ref_rr_x;
  // v_ref_rr_y
  output->v_ref_rr_y = input->v_ref_rr_y;
  // v_ref_rr_z
  output->v_ref_rr_z = input->v_ref_rr_z;
  // v_act_fl_x
  output->v_act_fl_x = input->v_act_fl_x;
  // v_act_fl_y
  output->v_act_fl_y = input->v_act_fl_y;
  // v_act_fl_z
  output->v_act_fl_z = input->v_act_fl_z;
  // v_act_fr_x
  output->v_act_fr_x = input->v_act_fr_x;
  // v_act_fr_y
  output->v_act_fr_y = input->v_act_fr_y;
  // v_act_fr_z
  output->v_act_fr_z = input->v_act_fr_z;
  // v_act_rl_x
  output->v_act_rl_x = input->v_act_rl_x;
  // v_act_rl_y
  output->v_act_rl_y = input->v_act_rl_y;
  // v_act_rl_z
  output->v_act_rl_z = input->v_act_rl_z;
  // v_act_rr_x
  output->v_act_rr_x = input->v_act_rr_x;
  // v_act_rr_y
  output->v_act_rr_y = input->v_act_rr_y;
  // v_act_rr_z
  output->v_act_rr_z = input->v_act_rr_z;
  // a_ref_fl_x
  output->a_ref_fl_x = input->a_ref_fl_x;
  // a_ref_fl_y
  output->a_ref_fl_y = input->a_ref_fl_y;
  // a_ref_fl_z
  output->a_ref_fl_z = input->a_ref_fl_z;
  // a_ref_fr_x
  output->a_ref_fr_x = input->a_ref_fr_x;
  // a_ref_fr_y
  output->a_ref_fr_y = input->a_ref_fr_y;
  // a_ref_fr_z
  output->a_ref_fr_z = input->a_ref_fr_z;
  // a_ref_rl_x
  output->a_ref_rl_x = input->a_ref_rl_x;
  // a_ref_rl_y
  output->a_ref_rl_y = input->a_ref_rl_y;
  // a_ref_rl_z
  output->a_ref_rl_z = input->a_ref_rl_z;
  // a_ref_rr_x
  output->a_ref_rr_x = input->a_ref_rr_x;
  // a_ref_rr_y
  output->a_ref_rr_y = input->a_ref_rr_y;
  // a_ref_rr_z
  output->a_ref_rr_z = input->a_ref_rr_z;
  // a_act_fl_x
  output->a_act_fl_x = input->a_act_fl_x;
  // a_act_fl_y
  output->a_act_fl_y = input->a_act_fl_y;
  // a_act_fl_z
  output->a_act_fl_z = input->a_act_fl_z;
  // a_act_fr_x
  output->a_act_fr_x = input->a_act_fr_x;
  // a_act_fr_y
  output->a_act_fr_y = input->a_act_fr_y;
  // a_act_fr_z
  output->a_act_fr_z = input->a_act_fr_z;
  // a_act_rl_x
  output->a_act_rl_x = input->a_act_rl_x;
  // a_act_rl_y
  output->a_act_rl_y = input->a_act_rl_y;
  // a_act_rl_z
  output->a_act_rl_z = input->a_act_rl_z;
  // a_act_rr_x
  output->a_act_rr_x = input->a_act_rr_x;
  // a_act_rr_y
  output->a_act_rr_y = input->a_act_rr_y;
  // a_act_rr_z
  output->a_act_rr_z = input->a_act_rr_z;
  // f_mpc_fl_x
  output->f_mpc_fl_x = input->f_mpc_fl_x;
  // f_mpc_fl_y
  output->f_mpc_fl_y = input->f_mpc_fl_y;
  // f_mpc_fl_z
  output->f_mpc_fl_z = input->f_mpc_fl_z;
  // f_mpc_fr_x
  output->f_mpc_fr_x = input->f_mpc_fr_x;
  // f_mpc_fr_y
  output->f_mpc_fr_y = input->f_mpc_fr_y;
  // f_mpc_fr_z
  output->f_mpc_fr_z = input->f_mpc_fr_z;
  // f_mpc_rl_x
  output->f_mpc_rl_x = input->f_mpc_rl_x;
  // f_mpc_rl_y
  output->f_mpc_rl_y = input->f_mpc_rl_y;
  // f_mpc_rl_z
  output->f_mpc_rl_z = input->f_mpc_rl_z;
  // f_mpc_rr_x
  output->f_mpc_rr_x = input->f_mpc_rr_x;
  // f_mpc_rr_y
  output->f_mpc_rr_y = input->f_mpc_rr_y;
  // f_mpc_rr_z
  output->f_mpc_rr_z = input->f_mpc_rr_z;
  // f_wbc_fl_x
  output->f_wbc_fl_x = input->f_wbc_fl_x;
  // f_wbc_fl_y
  output->f_wbc_fl_y = input->f_wbc_fl_y;
  // f_wbc_fl_z
  output->f_wbc_fl_z = input->f_wbc_fl_z;
  // f_wbc_fr_x
  output->f_wbc_fr_x = input->f_wbc_fr_x;
  // f_wbc_fr_y
  output->f_wbc_fr_y = input->f_wbc_fr_y;
  // f_wbc_fr_z
  output->f_wbc_fr_z = input->f_wbc_fr_z;
  // f_wbc_rl_x
  output->f_wbc_rl_x = input->f_wbc_rl_x;
  // f_wbc_rl_y
  output->f_wbc_rl_y = input->f_wbc_rl_y;
  // f_wbc_rl_z
  output->f_wbc_rl_z = input->f_wbc_rl_z;
  // f_wbc_rr_x
  output->f_wbc_rr_x = input->f_wbc_rr_x;
  // f_wbc_rr_y
  output->f_wbc_rr_y = input->f_wbc_rr_y;
  // f_wbc_rr_z
  output->f_wbc_rr_z = input->f_wbc_rr_z;
  // contact_fl
  output->contact_fl = input->contact_fl;
  // contact_fr
  output->contact_fr = input->contact_fr;
  // contact_rl
  output->contact_rl = input->contact_rl;
  // contact_rr
  output->contact_rr = input->contact_rr;
  // body_x
  output->body_x = input->body_x;
  // body_z
  output->body_z = input->body_z;
  // body_x_v
  output->body_x_v = input->body_x_v;
  // body_z_v
  output->body_z_v = input->body_z_v;
  // body_x_v_d
  output->body_x_v_d = input->body_x_v_d;
  // body_z_v_d
  output->body_z_v_d = input->body_z_v_d;
  return true;
}

go2_robot__msg__Go2Telemetry *
go2_robot__msg__Go2Telemetry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_robot__msg__Go2Telemetry * msg = (go2_robot__msg__Go2Telemetry *)allocator.allocate(sizeof(go2_robot__msg__Go2Telemetry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(go2_robot__msg__Go2Telemetry));
  bool success = go2_robot__msg__Go2Telemetry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
go2_robot__msg__Go2Telemetry__destroy(go2_robot__msg__Go2Telemetry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    go2_robot__msg__Go2Telemetry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
go2_robot__msg__Go2Telemetry__Sequence__init(go2_robot__msg__Go2Telemetry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_robot__msg__Go2Telemetry * data = NULL;

  if (size) {
    data = (go2_robot__msg__Go2Telemetry *)allocator.zero_allocate(size, sizeof(go2_robot__msg__Go2Telemetry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = go2_robot__msg__Go2Telemetry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        go2_robot__msg__Go2Telemetry__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
go2_robot__msg__Go2Telemetry__Sequence__fini(go2_robot__msg__Go2Telemetry__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      go2_robot__msg__Go2Telemetry__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

go2_robot__msg__Go2Telemetry__Sequence *
go2_robot__msg__Go2Telemetry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  go2_robot__msg__Go2Telemetry__Sequence * array = (go2_robot__msg__Go2Telemetry__Sequence *)allocator.allocate(sizeof(go2_robot__msg__Go2Telemetry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = go2_robot__msg__Go2Telemetry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
go2_robot__msg__Go2Telemetry__Sequence__destroy(go2_robot__msg__Go2Telemetry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    go2_robot__msg__Go2Telemetry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
go2_robot__msg__Go2Telemetry__Sequence__are_equal(const go2_robot__msg__Go2Telemetry__Sequence * lhs, const go2_robot__msg__Go2Telemetry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!go2_robot__msg__Go2Telemetry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
go2_robot__msg__Go2Telemetry__Sequence__copy(
  const go2_robot__msg__Go2Telemetry__Sequence * input,
  go2_robot__msg__Go2Telemetry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(go2_robot__msg__Go2Telemetry);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    go2_robot__msg__Go2Telemetry * data =
      (go2_robot__msg__Go2Telemetry *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!go2_robot__msg__Go2Telemetry__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          go2_robot__msg__Go2Telemetry__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!go2_robot__msg__Go2Telemetry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
