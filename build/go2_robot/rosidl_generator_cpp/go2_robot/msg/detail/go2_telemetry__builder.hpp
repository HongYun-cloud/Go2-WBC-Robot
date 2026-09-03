// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice

#ifndef GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__BUILDER_HPP_
#define GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "go2_robot/msg/detail/go2_telemetry__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace go2_robot
{

namespace msg
{

namespace builder
{

class Init_Go2Telemetry_body_z_v_d
{
public:
  explicit Init_Go2Telemetry_body_z_v_d(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  ::go2_robot::msg::Go2Telemetry body_z_v_d(::go2_robot::msg::Go2Telemetry::_body_z_v_d_type arg)
  {
    msg_.body_z_v_d = std::move(arg);
    return std::move(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_body_x_v_d
{
public:
  explicit Init_Go2Telemetry_body_x_v_d(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_z_v_d body_x_v_d(::go2_robot::msg::Go2Telemetry::_body_x_v_d_type arg)
  {
    msg_.body_x_v_d = std::move(arg);
    return Init_Go2Telemetry_body_z_v_d(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_body_z_v
{
public:
  explicit Init_Go2Telemetry_body_z_v(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_x_v_d body_z_v(::go2_robot::msg::Go2Telemetry::_body_z_v_type arg)
  {
    msg_.body_z_v = std::move(arg);
    return Init_Go2Telemetry_body_x_v_d(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_body_x_v
{
public:
  explicit Init_Go2Telemetry_body_x_v(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_z_v body_x_v(::go2_robot::msg::Go2Telemetry::_body_x_v_type arg)
  {
    msg_.body_x_v = std::move(arg);
    return Init_Go2Telemetry_body_z_v(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_body_z
{
public:
  explicit Init_Go2Telemetry_body_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_x_v body_z(::go2_robot::msg::Go2Telemetry::_body_z_type arg)
  {
    msg_.body_z = std::move(arg);
    return Init_Go2Telemetry_body_x_v(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_body_x
{
public:
  explicit Init_Go2Telemetry_body_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_z body_x(::go2_robot::msg::Go2Telemetry::_body_x_type arg)
  {
    msg_.body_x = std::move(arg);
    return Init_Go2Telemetry_body_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_contact_rr
{
public:
  explicit Init_Go2Telemetry_contact_rr(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_body_x contact_rr(::go2_robot::msg::Go2Telemetry::_contact_rr_type arg)
  {
    msg_.contact_rr = std::move(arg);
    return Init_Go2Telemetry_body_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_contact_rl
{
public:
  explicit Init_Go2Telemetry_contact_rl(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_contact_rr contact_rl(::go2_robot::msg::Go2Telemetry::_contact_rl_type arg)
  {
    msg_.contact_rl = std::move(arg);
    return Init_Go2Telemetry_contact_rr(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_contact_fr
{
public:
  explicit Init_Go2Telemetry_contact_fr(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_contact_rl contact_fr(::go2_robot::msg::Go2Telemetry::_contact_fr_type arg)
  {
    msg_.contact_fr = std::move(arg);
    return Init_Go2Telemetry_contact_rl(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_contact_fl
{
public:
  explicit Init_Go2Telemetry_contact_fl(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_contact_fr contact_fl(::go2_robot::msg::Go2Telemetry::_contact_fl_type arg)
  {
    msg_.contact_fl = std::move(arg);
    return Init_Go2Telemetry_contact_fr(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rr_z
{
public:
  explicit Init_Go2Telemetry_f_wbc_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_contact_fl f_wbc_rr_z(::go2_robot::msg::Go2Telemetry::_f_wbc_rr_z_type arg)
  {
    msg_.f_wbc_rr_z = std::move(arg);
    return Init_Go2Telemetry_contact_fl(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rr_y
{
public:
  explicit Init_Go2Telemetry_f_wbc_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rr_z f_wbc_rr_y(::go2_robot::msg::Go2Telemetry::_f_wbc_rr_y_type arg)
  {
    msg_.f_wbc_rr_y = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rr_x
{
public:
  explicit Init_Go2Telemetry_f_wbc_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rr_y f_wbc_rr_x(::go2_robot::msg::Go2Telemetry::_f_wbc_rr_x_type arg)
  {
    msg_.f_wbc_rr_x = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rl_z
{
public:
  explicit Init_Go2Telemetry_f_wbc_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rr_x f_wbc_rl_z(::go2_robot::msg::Go2Telemetry::_f_wbc_rl_z_type arg)
  {
    msg_.f_wbc_rl_z = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rl_y
{
public:
  explicit Init_Go2Telemetry_f_wbc_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rl_z f_wbc_rl_y(::go2_robot::msg::Go2Telemetry::_f_wbc_rl_y_type arg)
  {
    msg_.f_wbc_rl_y = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_rl_x
{
public:
  explicit Init_Go2Telemetry_f_wbc_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rl_y f_wbc_rl_x(::go2_robot::msg::Go2Telemetry::_f_wbc_rl_x_type arg)
  {
    msg_.f_wbc_rl_x = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fr_z
{
public:
  explicit Init_Go2Telemetry_f_wbc_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_rl_x f_wbc_fr_z(::go2_robot::msg::Go2Telemetry::_f_wbc_fr_z_type arg)
  {
    msg_.f_wbc_fr_z = std::move(arg);
    return Init_Go2Telemetry_f_wbc_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fr_y
{
public:
  explicit Init_Go2Telemetry_f_wbc_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fr_z f_wbc_fr_y(::go2_robot::msg::Go2Telemetry::_f_wbc_fr_y_type arg)
  {
    msg_.f_wbc_fr_y = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fr_x
{
public:
  explicit Init_Go2Telemetry_f_wbc_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fr_y f_wbc_fr_x(::go2_robot::msg::Go2Telemetry::_f_wbc_fr_x_type arg)
  {
    msg_.f_wbc_fr_x = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fl_z
{
public:
  explicit Init_Go2Telemetry_f_wbc_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fr_x f_wbc_fl_z(::go2_robot::msg::Go2Telemetry::_f_wbc_fl_z_type arg)
  {
    msg_.f_wbc_fl_z = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fl_y
{
public:
  explicit Init_Go2Telemetry_f_wbc_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fl_z f_wbc_fl_y(::go2_robot::msg::Go2Telemetry::_f_wbc_fl_y_type arg)
  {
    msg_.f_wbc_fl_y = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_wbc_fl_x
{
public:
  explicit Init_Go2Telemetry_f_wbc_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fl_y f_wbc_fl_x(::go2_robot::msg::Go2Telemetry::_f_wbc_fl_x_type arg)
  {
    msg_.f_wbc_fl_x = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rr_z
{
public:
  explicit Init_Go2Telemetry_f_mpc_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_wbc_fl_x f_mpc_rr_z(::go2_robot::msg::Go2Telemetry::_f_mpc_rr_z_type arg)
  {
    msg_.f_mpc_rr_z = std::move(arg);
    return Init_Go2Telemetry_f_wbc_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rr_y
{
public:
  explicit Init_Go2Telemetry_f_mpc_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rr_z f_mpc_rr_y(::go2_robot::msg::Go2Telemetry::_f_mpc_rr_y_type arg)
  {
    msg_.f_mpc_rr_y = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rr_x
{
public:
  explicit Init_Go2Telemetry_f_mpc_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rr_y f_mpc_rr_x(::go2_robot::msg::Go2Telemetry::_f_mpc_rr_x_type arg)
  {
    msg_.f_mpc_rr_x = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rl_z
{
public:
  explicit Init_Go2Telemetry_f_mpc_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rr_x f_mpc_rl_z(::go2_robot::msg::Go2Telemetry::_f_mpc_rl_z_type arg)
  {
    msg_.f_mpc_rl_z = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rl_y
{
public:
  explicit Init_Go2Telemetry_f_mpc_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rl_z f_mpc_rl_y(::go2_robot::msg::Go2Telemetry::_f_mpc_rl_y_type arg)
  {
    msg_.f_mpc_rl_y = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_rl_x
{
public:
  explicit Init_Go2Telemetry_f_mpc_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rl_y f_mpc_rl_x(::go2_robot::msg::Go2Telemetry::_f_mpc_rl_x_type arg)
  {
    msg_.f_mpc_rl_x = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fr_z
{
public:
  explicit Init_Go2Telemetry_f_mpc_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_rl_x f_mpc_fr_z(::go2_robot::msg::Go2Telemetry::_f_mpc_fr_z_type arg)
  {
    msg_.f_mpc_fr_z = std::move(arg);
    return Init_Go2Telemetry_f_mpc_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fr_y
{
public:
  explicit Init_Go2Telemetry_f_mpc_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fr_z f_mpc_fr_y(::go2_robot::msg::Go2Telemetry::_f_mpc_fr_y_type arg)
  {
    msg_.f_mpc_fr_y = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fr_x
{
public:
  explicit Init_Go2Telemetry_f_mpc_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fr_y f_mpc_fr_x(::go2_robot::msg::Go2Telemetry::_f_mpc_fr_x_type arg)
  {
    msg_.f_mpc_fr_x = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fl_z
{
public:
  explicit Init_Go2Telemetry_f_mpc_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fr_x f_mpc_fl_z(::go2_robot::msg::Go2Telemetry::_f_mpc_fl_z_type arg)
  {
    msg_.f_mpc_fl_z = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fl_y
{
public:
  explicit Init_Go2Telemetry_f_mpc_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fl_z f_mpc_fl_y(::go2_robot::msg::Go2Telemetry::_f_mpc_fl_y_type arg)
  {
    msg_.f_mpc_fl_y = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_f_mpc_fl_x
{
public:
  explicit Init_Go2Telemetry_f_mpc_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fl_y f_mpc_fl_x(::go2_robot::msg::Go2Telemetry::_f_mpc_fl_x_type arg)
  {
    msg_.f_mpc_fl_x = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rr_z
{
public:
  explicit Init_Go2Telemetry_a_act_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_f_mpc_fl_x a_act_rr_z(::go2_robot::msg::Go2Telemetry::_a_act_rr_z_type arg)
  {
    msg_.a_act_rr_z = std::move(arg);
    return Init_Go2Telemetry_f_mpc_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rr_y
{
public:
  explicit Init_Go2Telemetry_a_act_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rr_z a_act_rr_y(::go2_robot::msg::Go2Telemetry::_a_act_rr_y_type arg)
  {
    msg_.a_act_rr_y = std::move(arg);
    return Init_Go2Telemetry_a_act_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rr_x
{
public:
  explicit Init_Go2Telemetry_a_act_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rr_y a_act_rr_x(::go2_robot::msg::Go2Telemetry::_a_act_rr_x_type arg)
  {
    msg_.a_act_rr_x = std::move(arg);
    return Init_Go2Telemetry_a_act_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rl_z
{
public:
  explicit Init_Go2Telemetry_a_act_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rr_x a_act_rl_z(::go2_robot::msg::Go2Telemetry::_a_act_rl_z_type arg)
  {
    msg_.a_act_rl_z = std::move(arg);
    return Init_Go2Telemetry_a_act_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rl_y
{
public:
  explicit Init_Go2Telemetry_a_act_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rl_z a_act_rl_y(::go2_robot::msg::Go2Telemetry::_a_act_rl_y_type arg)
  {
    msg_.a_act_rl_y = std::move(arg);
    return Init_Go2Telemetry_a_act_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_rl_x
{
public:
  explicit Init_Go2Telemetry_a_act_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rl_y a_act_rl_x(::go2_robot::msg::Go2Telemetry::_a_act_rl_x_type arg)
  {
    msg_.a_act_rl_x = std::move(arg);
    return Init_Go2Telemetry_a_act_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fr_z
{
public:
  explicit Init_Go2Telemetry_a_act_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_rl_x a_act_fr_z(::go2_robot::msg::Go2Telemetry::_a_act_fr_z_type arg)
  {
    msg_.a_act_fr_z = std::move(arg);
    return Init_Go2Telemetry_a_act_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fr_y
{
public:
  explicit Init_Go2Telemetry_a_act_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fr_z a_act_fr_y(::go2_robot::msg::Go2Telemetry::_a_act_fr_y_type arg)
  {
    msg_.a_act_fr_y = std::move(arg);
    return Init_Go2Telemetry_a_act_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fr_x
{
public:
  explicit Init_Go2Telemetry_a_act_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fr_y a_act_fr_x(::go2_robot::msg::Go2Telemetry::_a_act_fr_x_type arg)
  {
    msg_.a_act_fr_x = std::move(arg);
    return Init_Go2Telemetry_a_act_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fl_z
{
public:
  explicit Init_Go2Telemetry_a_act_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fr_x a_act_fl_z(::go2_robot::msg::Go2Telemetry::_a_act_fl_z_type arg)
  {
    msg_.a_act_fl_z = std::move(arg);
    return Init_Go2Telemetry_a_act_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fl_y
{
public:
  explicit Init_Go2Telemetry_a_act_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fl_z a_act_fl_y(::go2_robot::msg::Go2Telemetry::_a_act_fl_y_type arg)
  {
    msg_.a_act_fl_y = std::move(arg);
    return Init_Go2Telemetry_a_act_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_act_fl_x
{
public:
  explicit Init_Go2Telemetry_a_act_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fl_y a_act_fl_x(::go2_robot::msg::Go2Telemetry::_a_act_fl_x_type arg)
  {
    msg_.a_act_fl_x = std::move(arg);
    return Init_Go2Telemetry_a_act_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rr_z
{
public:
  explicit Init_Go2Telemetry_a_ref_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_act_fl_x a_ref_rr_z(::go2_robot::msg::Go2Telemetry::_a_ref_rr_z_type arg)
  {
    msg_.a_ref_rr_z = std::move(arg);
    return Init_Go2Telemetry_a_act_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rr_y
{
public:
  explicit Init_Go2Telemetry_a_ref_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rr_z a_ref_rr_y(::go2_robot::msg::Go2Telemetry::_a_ref_rr_y_type arg)
  {
    msg_.a_ref_rr_y = std::move(arg);
    return Init_Go2Telemetry_a_ref_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rr_x
{
public:
  explicit Init_Go2Telemetry_a_ref_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rr_y a_ref_rr_x(::go2_robot::msg::Go2Telemetry::_a_ref_rr_x_type arg)
  {
    msg_.a_ref_rr_x = std::move(arg);
    return Init_Go2Telemetry_a_ref_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rl_z
{
public:
  explicit Init_Go2Telemetry_a_ref_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rr_x a_ref_rl_z(::go2_robot::msg::Go2Telemetry::_a_ref_rl_z_type arg)
  {
    msg_.a_ref_rl_z = std::move(arg);
    return Init_Go2Telemetry_a_ref_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rl_y
{
public:
  explicit Init_Go2Telemetry_a_ref_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rl_z a_ref_rl_y(::go2_robot::msg::Go2Telemetry::_a_ref_rl_y_type arg)
  {
    msg_.a_ref_rl_y = std::move(arg);
    return Init_Go2Telemetry_a_ref_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_rl_x
{
public:
  explicit Init_Go2Telemetry_a_ref_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rl_y a_ref_rl_x(::go2_robot::msg::Go2Telemetry::_a_ref_rl_x_type arg)
  {
    msg_.a_ref_rl_x = std::move(arg);
    return Init_Go2Telemetry_a_ref_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fr_z
{
public:
  explicit Init_Go2Telemetry_a_ref_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_rl_x a_ref_fr_z(::go2_robot::msg::Go2Telemetry::_a_ref_fr_z_type arg)
  {
    msg_.a_ref_fr_z = std::move(arg);
    return Init_Go2Telemetry_a_ref_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fr_y
{
public:
  explicit Init_Go2Telemetry_a_ref_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fr_z a_ref_fr_y(::go2_robot::msg::Go2Telemetry::_a_ref_fr_y_type arg)
  {
    msg_.a_ref_fr_y = std::move(arg);
    return Init_Go2Telemetry_a_ref_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fr_x
{
public:
  explicit Init_Go2Telemetry_a_ref_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fr_y a_ref_fr_x(::go2_robot::msg::Go2Telemetry::_a_ref_fr_x_type arg)
  {
    msg_.a_ref_fr_x = std::move(arg);
    return Init_Go2Telemetry_a_ref_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fl_z
{
public:
  explicit Init_Go2Telemetry_a_ref_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fr_x a_ref_fl_z(::go2_robot::msg::Go2Telemetry::_a_ref_fl_z_type arg)
  {
    msg_.a_ref_fl_z = std::move(arg);
    return Init_Go2Telemetry_a_ref_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fl_y
{
public:
  explicit Init_Go2Telemetry_a_ref_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fl_z a_ref_fl_y(::go2_robot::msg::Go2Telemetry::_a_ref_fl_y_type arg)
  {
    msg_.a_ref_fl_y = std::move(arg);
    return Init_Go2Telemetry_a_ref_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_a_ref_fl_x
{
public:
  explicit Init_Go2Telemetry_a_ref_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fl_y a_ref_fl_x(::go2_robot::msg::Go2Telemetry::_a_ref_fl_x_type arg)
  {
    msg_.a_ref_fl_x = std::move(arg);
    return Init_Go2Telemetry_a_ref_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rr_z
{
public:
  explicit Init_Go2Telemetry_v_act_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_a_ref_fl_x v_act_rr_z(::go2_robot::msg::Go2Telemetry::_v_act_rr_z_type arg)
  {
    msg_.v_act_rr_z = std::move(arg);
    return Init_Go2Telemetry_a_ref_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rr_y
{
public:
  explicit Init_Go2Telemetry_v_act_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rr_z v_act_rr_y(::go2_robot::msg::Go2Telemetry::_v_act_rr_y_type arg)
  {
    msg_.v_act_rr_y = std::move(arg);
    return Init_Go2Telemetry_v_act_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rr_x
{
public:
  explicit Init_Go2Telemetry_v_act_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rr_y v_act_rr_x(::go2_robot::msg::Go2Telemetry::_v_act_rr_x_type arg)
  {
    msg_.v_act_rr_x = std::move(arg);
    return Init_Go2Telemetry_v_act_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rl_z
{
public:
  explicit Init_Go2Telemetry_v_act_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rr_x v_act_rl_z(::go2_robot::msg::Go2Telemetry::_v_act_rl_z_type arg)
  {
    msg_.v_act_rl_z = std::move(arg);
    return Init_Go2Telemetry_v_act_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rl_y
{
public:
  explicit Init_Go2Telemetry_v_act_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rl_z v_act_rl_y(::go2_robot::msg::Go2Telemetry::_v_act_rl_y_type arg)
  {
    msg_.v_act_rl_y = std::move(arg);
    return Init_Go2Telemetry_v_act_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_rl_x
{
public:
  explicit Init_Go2Telemetry_v_act_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rl_y v_act_rl_x(::go2_robot::msg::Go2Telemetry::_v_act_rl_x_type arg)
  {
    msg_.v_act_rl_x = std::move(arg);
    return Init_Go2Telemetry_v_act_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fr_z
{
public:
  explicit Init_Go2Telemetry_v_act_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_rl_x v_act_fr_z(::go2_robot::msg::Go2Telemetry::_v_act_fr_z_type arg)
  {
    msg_.v_act_fr_z = std::move(arg);
    return Init_Go2Telemetry_v_act_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fr_y
{
public:
  explicit Init_Go2Telemetry_v_act_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fr_z v_act_fr_y(::go2_robot::msg::Go2Telemetry::_v_act_fr_y_type arg)
  {
    msg_.v_act_fr_y = std::move(arg);
    return Init_Go2Telemetry_v_act_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fr_x
{
public:
  explicit Init_Go2Telemetry_v_act_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fr_y v_act_fr_x(::go2_robot::msg::Go2Telemetry::_v_act_fr_x_type arg)
  {
    msg_.v_act_fr_x = std::move(arg);
    return Init_Go2Telemetry_v_act_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fl_z
{
public:
  explicit Init_Go2Telemetry_v_act_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fr_x v_act_fl_z(::go2_robot::msg::Go2Telemetry::_v_act_fl_z_type arg)
  {
    msg_.v_act_fl_z = std::move(arg);
    return Init_Go2Telemetry_v_act_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fl_y
{
public:
  explicit Init_Go2Telemetry_v_act_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fl_z v_act_fl_y(::go2_robot::msg::Go2Telemetry::_v_act_fl_y_type arg)
  {
    msg_.v_act_fl_y = std::move(arg);
    return Init_Go2Telemetry_v_act_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_act_fl_x
{
public:
  explicit Init_Go2Telemetry_v_act_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fl_y v_act_fl_x(::go2_robot::msg::Go2Telemetry::_v_act_fl_x_type arg)
  {
    msg_.v_act_fl_x = std::move(arg);
    return Init_Go2Telemetry_v_act_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rr_z
{
public:
  explicit Init_Go2Telemetry_v_ref_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_act_fl_x v_ref_rr_z(::go2_robot::msg::Go2Telemetry::_v_ref_rr_z_type arg)
  {
    msg_.v_ref_rr_z = std::move(arg);
    return Init_Go2Telemetry_v_act_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rr_y
{
public:
  explicit Init_Go2Telemetry_v_ref_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rr_z v_ref_rr_y(::go2_robot::msg::Go2Telemetry::_v_ref_rr_y_type arg)
  {
    msg_.v_ref_rr_y = std::move(arg);
    return Init_Go2Telemetry_v_ref_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rr_x
{
public:
  explicit Init_Go2Telemetry_v_ref_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rr_y v_ref_rr_x(::go2_robot::msg::Go2Telemetry::_v_ref_rr_x_type arg)
  {
    msg_.v_ref_rr_x = std::move(arg);
    return Init_Go2Telemetry_v_ref_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rl_z
{
public:
  explicit Init_Go2Telemetry_v_ref_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rr_x v_ref_rl_z(::go2_robot::msg::Go2Telemetry::_v_ref_rl_z_type arg)
  {
    msg_.v_ref_rl_z = std::move(arg);
    return Init_Go2Telemetry_v_ref_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rl_y
{
public:
  explicit Init_Go2Telemetry_v_ref_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rl_z v_ref_rl_y(::go2_robot::msg::Go2Telemetry::_v_ref_rl_y_type arg)
  {
    msg_.v_ref_rl_y = std::move(arg);
    return Init_Go2Telemetry_v_ref_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_rl_x
{
public:
  explicit Init_Go2Telemetry_v_ref_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rl_y v_ref_rl_x(::go2_robot::msg::Go2Telemetry::_v_ref_rl_x_type arg)
  {
    msg_.v_ref_rl_x = std::move(arg);
    return Init_Go2Telemetry_v_ref_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fr_z
{
public:
  explicit Init_Go2Telemetry_v_ref_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_rl_x v_ref_fr_z(::go2_robot::msg::Go2Telemetry::_v_ref_fr_z_type arg)
  {
    msg_.v_ref_fr_z = std::move(arg);
    return Init_Go2Telemetry_v_ref_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fr_y
{
public:
  explicit Init_Go2Telemetry_v_ref_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fr_z v_ref_fr_y(::go2_robot::msg::Go2Telemetry::_v_ref_fr_y_type arg)
  {
    msg_.v_ref_fr_y = std::move(arg);
    return Init_Go2Telemetry_v_ref_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fr_x
{
public:
  explicit Init_Go2Telemetry_v_ref_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fr_y v_ref_fr_x(::go2_robot::msg::Go2Telemetry::_v_ref_fr_x_type arg)
  {
    msg_.v_ref_fr_x = std::move(arg);
    return Init_Go2Telemetry_v_ref_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fl_z
{
public:
  explicit Init_Go2Telemetry_v_ref_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fr_x v_ref_fl_z(::go2_robot::msg::Go2Telemetry::_v_ref_fl_z_type arg)
  {
    msg_.v_ref_fl_z = std::move(arg);
    return Init_Go2Telemetry_v_ref_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fl_y
{
public:
  explicit Init_Go2Telemetry_v_ref_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fl_z v_ref_fl_y(::go2_robot::msg::Go2Telemetry::_v_ref_fl_y_type arg)
  {
    msg_.v_ref_fl_y = std::move(arg);
    return Init_Go2Telemetry_v_ref_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_v_ref_fl_x
{
public:
  explicit Init_Go2Telemetry_v_ref_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fl_y v_ref_fl_x(::go2_robot::msg::Go2Telemetry::_v_ref_fl_x_type arg)
  {
    msg_.v_ref_fl_x = std::move(arg);
    return Init_Go2Telemetry_v_ref_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rr_z
{
public:
  explicit Init_Go2Telemetry_p_act_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_v_ref_fl_x p_act_rr_z(::go2_robot::msg::Go2Telemetry::_p_act_rr_z_type arg)
  {
    msg_.p_act_rr_z = std::move(arg);
    return Init_Go2Telemetry_v_ref_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rr_y
{
public:
  explicit Init_Go2Telemetry_p_act_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rr_z p_act_rr_y(::go2_robot::msg::Go2Telemetry::_p_act_rr_y_type arg)
  {
    msg_.p_act_rr_y = std::move(arg);
    return Init_Go2Telemetry_p_act_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rr_x
{
public:
  explicit Init_Go2Telemetry_p_act_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rr_y p_act_rr_x(::go2_robot::msg::Go2Telemetry::_p_act_rr_x_type arg)
  {
    msg_.p_act_rr_x = std::move(arg);
    return Init_Go2Telemetry_p_act_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rl_z
{
public:
  explicit Init_Go2Telemetry_p_act_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rr_x p_act_rl_z(::go2_robot::msg::Go2Telemetry::_p_act_rl_z_type arg)
  {
    msg_.p_act_rl_z = std::move(arg);
    return Init_Go2Telemetry_p_act_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rl_y
{
public:
  explicit Init_Go2Telemetry_p_act_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rl_z p_act_rl_y(::go2_robot::msg::Go2Telemetry::_p_act_rl_y_type arg)
  {
    msg_.p_act_rl_y = std::move(arg);
    return Init_Go2Telemetry_p_act_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_rl_x
{
public:
  explicit Init_Go2Telemetry_p_act_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rl_y p_act_rl_x(::go2_robot::msg::Go2Telemetry::_p_act_rl_x_type arg)
  {
    msg_.p_act_rl_x = std::move(arg);
    return Init_Go2Telemetry_p_act_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fr_z
{
public:
  explicit Init_Go2Telemetry_p_act_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_rl_x p_act_fr_z(::go2_robot::msg::Go2Telemetry::_p_act_fr_z_type arg)
  {
    msg_.p_act_fr_z = std::move(arg);
    return Init_Go2Telemetry_p_act_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fr_y
{
public:
  explicit Init_Go2Telemetry_p_act_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fr_z p_act_fr_y(::go2_robot::msg::Go2Telemetry::_p_act_fr_y_type arg)
  {
    msg_.p_act_fr_y = std::move(arg);
    return Init_Go2Telemetry_p_act_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fr_x
{
public:
  explicit Init_Go2Telemetry_p_act_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fr_y p_act_fr_x(::go2_robot::msg::Go2Telemetry::_p_act_fr_x_type arg)
  {
    msg_.p_act_fr_x = std::move(arg);
    return Init_Go2Telemetry_p_act_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fl_z
{
public:
  explicit Init_Go2Telemetry_p_act_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fr_x p_act_fl_z(::go2_robot::msg::Go2Telemetry::_p_act_fl_z_type arg)
  {
    msg_.p_act_fl_z = std::move(arg);
    return Init_Go2Telemetry_p_act_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fl_y
{
public:
  explicit Init_Go2Telemetry_p_act_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fl_z p_act_fl_y(::go2_robot::msg::Go2Telemetry::_p_act_fl_y_type arg)
  {
    msg_.p_act_fl_y = std::move(arg);
    return Init_Go2Telemetry_p_act_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_act_fl_x
{
public:
  explicit Init_Go2Telemetry_p_act_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fl_y p_act_fl_x(::go2_robot::msg::Go2Telemetry::_p_act_fl_x_type arg)
  {
    msg_.p_act_fl_x = std::move(arg);
    return Init_Go2Telemetry_p_act_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rr_z
{
public:
  explicit Init_Go2Telemetry_p_ref_rr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_act_fl_x p_ref_rr_z(::go2_robot::msg::Go2Telemetry::_p_ref_rr_z_type arg)
  {
    msg_.p_ref_rr_z = std::move(arg);
    return Init_Go2Telemetry_p_act_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rr_y
{
public:
  explicit Init_Go2Telemetry_p_ref_rr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rr_z p_ref_rr_y(::go2_robot::msg::Go2Telemetry::_p_ref_rr_y_type arg)
  {
    msg_.p_ref_rr_y = std::move(arg);
    return Init_Go2Telemetry_p_ref_rr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rr_x
{
public:
  explicit Init_Go2Telemetry_p_ref_rr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rr_y p_ref_rr_x(::go2_robot::msg::Go2Telemetry::_p_ref_rr_x_type arg)
  {
    msg_.p_ref_rr_x = std::move(arg);
    return Init_Go2Telemetry_p_ref_rr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rl_z
{
public:
  explicit Init_Go2Telemetry_p_ref_rl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rr_x p_ref_rl_z(::go2_robot::msg::Go2Telemetry::_p_ref_rl_z_type arg)
  {
    msg_.p_ref_rl_z = std::move(arg);
    return Init_Go2Telemetry_p_ref_rr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rl_y
{
public:
  explicit Init_Go2Telemetry_p_ref_rl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rl_z p_ref_rl_y(::go2_robot::msg::Go2Telemetry::_p_ref_rl_y_type arg)
  {
    msg_.p_ref_rl_y = std::move(arg);
    return Init_Go2Telemetry_p_ref_rl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_rl_x
{
public:
  explicit Init_Go2Telemetry_p_ref_rl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rl_y p_ref_rl_x(::go2_robot::msg::Go2Telemetry::_p_ref_rl_x_type arg)
  {
    msg_.p_ref_rl_x = std::move(arg);
    return Init_Go2Telemetry_p_ref_rl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fr_z
{
public:
  explicit Init_Go2Telemetry_p_ref_fr_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_rl_x p_ref_fr_z(::go2_robot::msg::Go2Telemetry::_p_ref_fr_z_type arg)
  {
    msg_.p_ref_fr_z = std::move(arg);
    return Init_Go2Telemetry_p_ref_rl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fr_y
{
public:
  explicit Init_Go2Telemetry_p_ref_fr_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_fr_z p_ref_fr_y(::go2_robot::msg::Go2Telemetry::_p_ref_fr_y_type arg)
  {
    msg_.p_ref_fr_y = std::move(arg);
    return Init_Go2Telemetry_p_ref_fr_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fr_x
{
public:
  explicit Init_Go2Telemetry_p_ref_fr_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_fr_y p_ref_fr_x(::go2_robot::msg::Go2Telemetry::_p_ref_fr_x_type arg)
  {
    msg_.p_ref_fr_x = std::move(arg);
    return Init_Go2Telemetry_p_ref_fr_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fl_z
{
public:
  explicit Init_Go2Telemetry_p_ref_fl_z(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_fr_x p_ref_fl_z(::go2_robot::msg::Go2Telemetry::_p_ref_fl_z_type arg)
  {
    msg_.p_ref_fl_z = std::move(arg);
    return Init_Go2Telemetry_p_ref_fr_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fl_y
{
public:
  explicit Init_Go2Telemetry_p_ref_fl_y(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_fl_z p_ref_fl_y(::go2_robot::msg::Go2Telemetry::_p_ref_fl_y_type arg)
  {
    msg_.p_ref_fl_y = std::move(arg);
    return Init_Go2Telemetry_p_ref_fl_z(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_p_ref_fl_x
{
public:
  explicit Init_Go2Telemetry_p_ref_fl_x(::go2_robot::msg::Go2Telemetry & msg)
  : msg_(msg)
  {}
  Init_Go2Telemetry_p_ref_fl_y p_ref_fl_x(::go2_robot::msg::Go2Telemetry::_p_ref_fl_x_type arg)
  {
    msg_.p_ref_fl_x = std::move(arg);
    return Init_Go2Telemetry_p_ref_fl_y(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

class Init_Go2Telemetry_header
{
public:
  Init_Go2Telemetry_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Go2Telemetry_p_ref_fl_x header(::go2_robot::msg::Go2Telemetry::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_Go2Telemetry_p_ref_fl_x(msg_);
  }

private:
  ::go2_robot::msg::Go2Telemetry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::go2_robot::msg::Go2Telemetry>()
{
  return go2_robot::msg::builder::Init_Go2Telemetry_header();
}

}  // namespace go2_robot

#endif  // GO2_ROBOT__MSG__DETAIL__GO2_TELEMETRY__BUILDER_HPP_
