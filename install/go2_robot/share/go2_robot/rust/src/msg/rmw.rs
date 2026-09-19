#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "go2_robot__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__go2_robot__msg__Go2Telemetry() -> *const std::ffi::c_void;
}

#[link(name = "go2_robot__rosidl_generator_c")]
extern "C" {
    fn go2_robot__msg__Go2Telemetry__init(msg: *mut Go2Telemetry) -> bool;
    fn go2_robot__msg__Go2Telemetry__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Go2Telemetry>, size: usize) -> bool;
    fn go2_robot__msg__Go2Telemetry__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Go2Telemetry>);
    fn go2_robot__msg__Go2Telemetry__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Go2Telemetry>, out_seq: *mut rosidl_runtime_rs::Sequence<Go2Telemetry>) -> bool;
}

// Corresponds to go2_robot__msg__Go2Telemetry
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Go2 控制遥测: 供 PlotJuggler (ROS2 Topic Subscriber) 绘图
/// 字段名与原 PlotSend UDP JSON key 一一对应 (contract_* 笔误已改为 contact_*)
/// 足端字段顺序均为 FL, FR, RL, RR × x, y, z (世界系)

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Go2Telemetry {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// 摆动轨迹参考/实际足端位置
    pub p_ref_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_ref_rr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub p_act_rr_z: f64,

    /// 摆动轨迹参考/实际足端速度
    pub v_ref_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_ref_rr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub v_act_rr_z: f64,

    /// a_ref = a_des (摆动前馈加速度 + 阻抗修正), a_act = v_act 数值微分
    pub a_ref_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_ref_rr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_act_rr_z: f64,

    /// MPC / WBC 足端接触力
    pub f_mpc_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_mpc_rr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_fr_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rl_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rl_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rl_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rr_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rr_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_wbc_rr_z: f64,

    /// 计划接触状态 (1=支撑, 0=摆动)
    pub contact_fl: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub contact_fr: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub contact_rl: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub contact_rr: f64,

    /// 机身位置/速度 (x, z) 与期望速度 (body_x_v_d = v[0], body_z_v_d = v[2])
    pub body_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub body_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub body_x_v: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub body_z_v: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub body_x_v_d: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub body_z_v_d: f64,

    /// WBC 期望加速度 q_des (computePoseAccDes 输出: 基座线3 + 角3 + 关节12)
    pub q_des_lin_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_lin_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_lin_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_ang_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_ang_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_ang_z: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_0: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_2: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_3: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_4: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_5: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_6: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_7: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_8: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_9: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_10: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub q_des_joint_11: f64,

    /// 诊断: 偏航力矩 Σ(x·fy − y·fx) (世界系, 足端相对机身) 与摩擦锥利用率 |ft|/(μ·fz), μ=0.5
    pub tau_yaw_mpc: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_yaw_wbc: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_cone_fl: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_cone_fr: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_cone_rl: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub f_cone_rr: f64,

    /// 诊断: roll/pitch 力矩 Σ(r × f) (世界系, 足端相对机身), 与 tau_yaw 配套
    pub tau_roll_mpc: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_roll_wbc: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_pitch_mpc: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_pitch_wbc: f64,

    /// 诊断: WBC QP 解出的基座角加速度 (机体系, sol.head(18) 第3~5维), 与 q_des_ang 对比用
    pub a_wbc_ang_x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_wbc_ang_y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub a_wbc_ang_z: f64,

    /// 关节力矩 τ = M·a + h − Jᵀf (WBC 逆动力学, 即 mj->control(tau) 的输入)
    /// 顺序: FL_hip,FL_thigh,FL_calf, FR_hip,FR_thigh,FR_calf, RL_*, RR_* (12 维, 与 q_des_joint_* 同序)
    pub tau_joint_0: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_1: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_2: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_3: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_4: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_5: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_6: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_7: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_8: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_9: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_10: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub tau_joint_11: f64,

}



impl Default for Go2Telemetry {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !go2_robot__msg__Go2Telemetry__init(&mut msg as *mut _) {
        panic!("Call to go2_robot__msg__Go2Telemetry__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Go2Telemetry {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { go2_robot__msg__Go2Telemetry__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { go2_robot__msg__Go2Telemetry__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { go2_robot__msg__Go2Telemetry__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Go2Telemetry {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Go2Telemetry where Self: Sized {
  const TYPE_NAME: &'static str = "go2_robot/msg/Go2Telemetry";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__go2_robot__msg__Go2Telemetry() }
  }
}


