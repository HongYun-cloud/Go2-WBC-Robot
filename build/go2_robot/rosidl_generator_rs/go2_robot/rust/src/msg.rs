#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to go2_robot__msg__Go2Telemetry
/// Go2 控制遥测: 供 PlotJuggler (ROS2 Topic Subscriber) 绘图
/// 字段名与原 PlotSend UDP JSON key 一一对应 (contract_* 笔误已改为 contact_*)
/// 足端字段顺序均为 FL, FR, RL, RR × x, y, z (世界系)

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Go2Telemetry {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Go2Telemetry::default())
  }
}

impl rosidl_runtime_rs::Message for Go2Telemetry {
  type RmwMsg = super::msg::rmw::Go2Telemetry;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        p_ref_fl_x: msg.p_ref_fl_x,
        p_ref_fl_y: msg.p_ref_fl_y,
        p_ref_fl_z: msg.p_ref_fl_z,
        p_ref_fr_x: msg.p_ref_fr_x,
        p_ref_fr_y: msg.p_ref_fr_y,
        p_ref_fr_z: msg.p_ref_fr_z,
        p_ref_rl_x: msg.p_ref_rl_x,
        p_ref_rl_y: msg.p_ref_rl_y,
        p_ref_rl_z: msg.p_ref_rl_z,
        p_ref_rr_x: msg.p_ref_rr_x,
        p_ref_rr_y: msg.p_ref_rr_y,
        p_ref_rr_z: msg.p_ref_rr_z,
        p_act_fl_x: msg.p_act_fl_x,
        p_act_fl_y: msg.p_act_fl_y,
        p_act_fl_z: msg.p_act_fl_z,
        p_act_fr_x: msg.p_act_fr_x,
        p_act_fr_y: msg.p_act_fr_y,
        p_act_fr_z: msg.p_act_fr_z,
        p_act_rl_x: msg.p_act_rl_x,
        p_act_rl_y: msg.p_act_rl_y,
        p_act_rl_z: msg.p_act_rl_z,
        p_act_rr_x: msg.p_act_rr_x,
        p_act_rr_y: msg.p_act_rr_y,
        p_act_rr_z: msg.p_act_rr_z,
        v_ref_fl_x: msg.v_ref_fl_x,
        v_ref_fl_y: msg.v_ref_fl_y,
        v_ref_fl_z: msg.v_ref_fl_z,
        v_ref_fr_x: msg.v_ref_fr_x,
        v_ref_fr_y: msg.v_ref_fr_y,
        v_ref_fr_z: msg.v_ref_fr_z,
        v_ref_rl_x: msg.v_ref_rl_x,
        v_ref_rl_y: msg.v_ref_rl_y,
        v_ref_rl_z: msg.v_ref_rl_z,
        v_ref_rr_x: msg.v_ref_rr_x,
        v_ref_rr_y: msg.v_ref_rr_y,
        v_ref_rr_z: msg.v_ref_rr_z,
        v_act_fl_x: msg.v_act_fl_x,
        v_act_fl_y: msg.v_act_fl_y,
        v_act_fl_z: msg.v_act_fl_z,
        v_act_fr_x: msg.v_act_fr_x,
        v_act_fr_y: msg.v_act_fr_y,
        v_act_fr_z: msg.v_act_fr_z,
        v_act_rl_x: msg.v_act_rl_x,
        v_act_rl_y: msg.v_act_rl_y,
        v_act_rl_z: msg.v_act_rl_z,
        v_act_rr_x: msg.v_act_rr_x,
        v_act_rr_y: msg.v_act_rr_y,
        v_act_rr_z: msg.v_act_rr_z,
        a_ref_fl_x: msg.a_ref_fl_x,
        a_ref_fl_y: msg.a_ref_fl_y,
        a_ref_fl_z: msg.a_ref_fl_z,
        a_ref_fr_x: msg.a_ref_fr_x,
        a_ref_fr_y: msg.a_ref_fr_y,
        a_ref_fr_z: msg.a_ref_fr_z,
        a_ref_rl_x: msg.a_ref_rl_x,
        a_ref_rl_y: msg.a_ref_rl_y,
        a_ref_rl_z: msg.a_ref_rl_z,
        a_ref_rr_x: msg.a_ref_rr_x,
        a_ref_rr_y: msg.a_ref_rr_y,
        a_ref_rr_z: msg.a_ref_rr_z,
        a_act_fl_x: msg.a_act_fl_x,
        a_act_fl_y: msg.a_act_fl_y,
        a_act_fl_z: msg.a_act_fl_z,
        a_act_fr_x: msg.a_act_fr_x,
        a_act_fr_y: msg.a_act_fr_y,
        a_act_fr_z: msg.a_act_fr_z,
        a_act_rl_x: msg.a_act_rl_x,
        a_act_rl_y: msg.a_act_rl_y,
        a_act_rl_z: msg.a_act_rl_z,
        a_act_rr_x: msg.a_act_rr_x,
        a_act_rr_y: msg.a_act_rr_y,
        a_act_rr_z: msg.a_act_rr_z,
        f_mpc_fl_x: msg.f_mpc_fl_x,
        f_mpc_fl_y: msg.f_mpc_fl_y,
        f_mpc_fl_z: msg.f_mpc_fl_z,
        f_mpc_fr_x: msg.f_mpc_fr_x,
        f_mpc_fr_y: msg.f_mpc_fr_y,
        f_mpc_fr_z: msg.f_mpc_fr_z,
        f_mpc_rl_x: msg.f_mpc_rl_x,
        f_mpc_rl_y: msg.f_mpc_rl_y,
        f_mpc_rl_z: msg.f_mpc_rl_z,
        f_mpc_rr_x: msg.f_mpc_rr_x,
        f_mpc_rr_y: msg.f_mpc_rr_y,
        f_mpc_rr_z: msg.f_mpc_rr_z,
        f_wbc_fl_x: msg.f_wbc_fl_x,
        f_wbc_fl_y: msg.f_wbc_fl_y,
        f_wbc_fl_z: msg.f_wbc_fl_z,
        f_wbc_fr_x: msg.f_wbc_fr_x,
        f_wbc_fr_y: msg.f_wbc_fr_y,
        f_wbc_fr_z: msg.f_wbc_fr_z,
        f_wbc_rl_x: msg.f_wbc_rl_x,
        f_wbc_rl_y: msg.f_wbc_rl_y,
        f_wbc_rl_z: msg.f_wbc_rl_z,
        f_wbc_rr_x: msg.f_wbc_rr_x,
        f_wbc_rr_y: msg.f_wbc_rr_y,
        f_wbc_rr_z: msg.f_wbc_rr_z,
        contact_fl: msg.contact_fl,
        contact_fr: msg.contact_fr,
        contact_rl: msg.contact_rl,
        contact_rr: msg.contact_rr,
        body_x: msg.body_x,
        body_z: msg.body_z,
        body_x_v: msg.body_x_v,
        body_z_v: msg.body_z_v,
        body_x_v_d: msg.body_x_v_d,
        body_z_v_d: msg.body_z_v_d,
        q_des_lin_x: msg.q_des_lin_x,
        q_des_lin_y: msg.q_des_lin_y,
        q_des_lin_z: msg.q_des_lin_z,
        q_des_ang_x: msg.q_des_ang_x,
        q_des_ang_y: msg.q_des_ang_y,
        q_des_ang_z: msg.q_des_ang_z,
        q_des_joint_0: msg.q_des_joint_0,
        q_des_joint_1: msg.q_des_joint_1,
        q_des_joint_2: msg.q_des_joint_2,
        q_des_joint_3: msg.q_des_joint_3,
        q_des_joint_4: msg.q_des_joint_4,
        q_des_joint_5: msg.q_des_joint_5,
        q_des_joint_6: msg.q_des_joint_6,
        q_des_joint_7: msg.q_des_joint_7,
        q_des_joint_8: msg.q_des_joint_8,
        q_des_joint_9: msg.q_des_joint_9,
        q_des_joint_10: msg.q_des_joint_10,
        q_des_joint_11: msg.q_des_joint_11,
        tau_yaw_mpc: msg.tau_yaw_mpc,
        tau_yaw_wbc: msg.tau_yaw_wbc,
        f_cone_fl: msg.f_cone_fl,
        f_cone_fr: msg.f_cone_fr,
        f_cone_rl: msg.f_cone_rl,
        f_cone_rr: msg.f_cone_rr,
        tau_roll_mpc: msg.tau_roll_mpc,
        tau_roll_wbc: msg.tau_roll_wbc,
        tau_pitch_mpc: msg.tau_pitch_mpc,
        tau_pitch_wbc: msg.tau_pitch_wbc,
        a_wbc_ang_x: msg.a_wbc_ang_x,
        a_wbc_ang_y: msg.a_wbc_ang_y,
        a_wbc_ang_z: msg.a_wbc_ang_z,
        tau_joint_0: msg.tau_joint_0,
        tau_joint_1: msg.tau_joint_1,
        tau_joint_2: msg.tau_joint_2,
        tau_joint_3: msg.tau_joint_3,
        tau_joint_4: msg.tau_joint_4,
        tau_joint_5: msg.tau_joint_5,
        tau_joint_6: msg.tau_joint_6,
        tau_joint_7: msg.tau_joint_7,
        tau_joint_8: msg.tau_joint_8,
        tau_joint_9: msg.tau_joint_9,
        tau_joint_10: msg.tau_joint_10,
        tau_joint_11: msg.tau_joint_11,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      p_ref_fl_x: msg.p_ref_fl_x,
      p_ref_fl_y: msg.p_ref_fl_y,
      p_ref_fl_z: msg.p_ref_fl_z,
      p_ref_fr_x: msg.p_ref_fr_x,
      p_ref_fr_y: msg.p_ref_fr_y,
      p_ref_fr_z: msg.p_ref_fr_z,
      p_ref_rl_x: msg.p_ref_rl_x,
      p_ref_rl_y: msg.p_ref_rl_y,
      p_ref_rl_z: msg.p_ref_rl_z,
      p_ref_rr_x: msg.p_ref_rr_x,
      p_ref_rr_y: msg.p_ref_rr_y,
      p_ref_rr_z: msg.p_ref_rr_z,
      p_act_fl_x: msg.p_act_fl_x,
      p_act_fl_y: msg.p_act_fl_y,
      p_act_fl_z: msg.p_act_fl_z,
      p_act_fr_x: msg.p_act_fr_x,
      p_act_fr_y: msg.p_act_fr_y,
      p_act_fr_z: msg.p_act_fr_z,
      p_act_rl_x: msg.p_act_rl_x,
      p_act_rl_y: msg.p_act_rl_y,
      p_act_rl_z: msg.p_act_rl_z,
      p_act_rr_x: msg.p_act_rr_x,
      p_act_rr_y: msg.p_act_rr_y,
      p_act_rr_z: msg.p_act_rr_z,
      v_ref_fl_x: msg.v_ref_fl_x,
      v_ref_fl_y: msg.v_ref_fl_y,
      v_ref_fl_z: msg.v_ref_fl_z,
      v_ref_fr_x: msg.v_ref_fr_x,
      v_ref_fr_y: msg.v_ref_fr_y,
      v_ref_fr_z: msg.v_ref_fr_z,
      v_ref_rl_x: msg.v_ref_rl_x,
      v_ref_rl_y: msg.v_ref_rl_y,
      v_ref_rl_z: msg.v_ref_rl_z,
      v_ref_rr_x: msg.v_ref_rr_x,
      v_ref_rr_y: msg.v_ref_rr_y,
      v_ref_rr_z: msg.v_ref_rr_z,
      v_act_fl_x: msg.v_act_fl_x,
      v_act_fl_y: msg.v_act_fl_y,
      v_act_fl_z: msg.v_act_fl_z,
      v_act_fr_x: msg.v_act_fr_x,
      v_act_fr_y: msg.v_act_fr_y,
      v_act_fr_z: msg.v_act_fr_z,
      v_act_rl_x: msg.v_act_rl_x,
      v_act_rl_y: msg.v_act_rl_y,
      v_act_rl_z: msg.v_act_rl_z,
      v_act_rr_x: msg.v_act_rr_x,
      v_act_rr_y: msg.v_act_rr_y,
      v_act_rr_z: msg.v_act_rr_z,
      a_ref_fl_x: msg.a_ref_fl_x,
      a_ref_fl_y: msg.a_ref_fl_y,
      a_ref_fl_z: msg.a_ref_fl_z,
      a_ref_fr_x: msg.a_ref_fr_x,
      a_ref_fr_y: msg.a_ref_fr_y,
      a_ref_fr_z: msg.a_ref_fr_z,
      a_ref_rl_x: msg.a_ref_rl_x,
      a_ref_rl_y: msg.a_ref_rl_y,
      a_ref_rl_z: msg.a_ref_rl_z,
      a_ref_rr_x: msg.a_ref_rr_x,
      a_ref_rr_y: msg.a_ref_rr_y,
      a_ref_rr_z: msg.a_ref_rr_z,
      a_act_fl_x: msg.a_act_fl_x,
      a_act_fl_y: msg.a_act_fl_y,
      a_act_fl_z: msg.a_act_fl_z,
      a_act_fr_x: msg.a_act_fr_x,
      a_act_fr_y: msg.a_act_fr_y,
      a_act_fr_z: msg.a_act_fr_z,
      a_act_rl_x: msg.a_act_rl_x,
      a_act_rl_y: msg.a_act_rl_y,
      a_act_rl_z: msg.a_act_rl_z,
      a_act_rr_x: msg.a_act_rr_x,
      a_act_rr_y: msg.a_act_rr_y,
      a_act_rr_z: msg.a_act_rr_z,
      f_mpc_fl_x: msg.f_mpc_fl_x,
      f_mpc_fl_y: msg.f_mpc_fl_y,
      f_mpc_fl_z: msg.f_mpc_fl_z,
      f_mpc_fr_x: msg.f_mpc_fr_x,
      f_mpc_fr_y: msg.f_mpc_fr_y,
      f_mpc_fr_z: msg.f_mpc_fr_z,
      f_mpc_rl_x: msg.f_mpc_rl_x,
      f_mpc_rl_y: msg.f_mpc_rl_y,
      f_mpc_rl_z: msg.f_mpc_rl_z,
      f_mpc_rr_x: msg.f_mpc_rr_x,
      f_mpc_rr_y: msg.f_mpc_rr_y,
      f_mpc_rr_z: msg.f_mpc_rr_z,
      f_wbc_fl_x: msg.f_wbc_fl_x,
      f_wbc_fl_y: msg.f_wbc_fl_y,
      f_wbc_fl_z: msg.f_wbc_fl_z,
      f_wbc_fr_x: msg.f_wbc_fr_x,
      f_wbc_fr_y: msg.f_wbc_fr_y,
      f_wbc_fr_z: msg.f_wbc_fr_z,
      f_wbc_rl_x: msg.f_wbc_rl_x,
      f_wbc_rl_y: msg.f_wbc_rl_y,
      f_wbc_rl_z: msg.f_wbc_rl_z,
      f_wbc_rr_x: msg.f_wbc_rr_x,
      f_wbc_rr_y: msg.f_wbc_rr_y,
      f_wbc_rr_z: msg.f_wbc_rr_z,
      contact_fl: msg.contact_fl,
      contact_fr: msg.contact_fr,
      contact_rl: msg.contact_rl,
      contact_rr: msg.contact_rr,
      body_x: msg.body_x,
      body_z: msg.body_z,
      body_x_v: msg.body_x_v,
      body_z_v: msg.body_z_v,
      body_x_v_d: msg.body_x_v_d,
      body_z_v_d: msg.body_z_v_d,
      q_des_lin_x: msg.q_des_lin_x,
      q_des_lin_y: msg.q_des_lin_y,
      q_des_lin_z: msg.q_des_lin_z,
      q_des_ang_x: msg.q_des_ang_x,
      q_des_ang_y: msg.q_des_ang_y,
      q_des_ang_z: msg.q_des_ang_z,
      q_des_joint_0: msg.q_des_joint_0,
      q_des_joint_1: msg.q_des_joint_1,
      q_des_joint_2: msg.q_des_joint_2,
      q_des_joint_3: msg.q_des_joint_3,
      q_des_joint_4: msg.q_des_joint_4,
      q_des_joint_5: msg.q_des_joint_5,
      q_des_joint_6: msg.q_des_joint_6,
      q_des_joint_7: msg.q_des_joint_7,
      q_des_joint_8: msg.q_des_joint_8,
      q_des_joint_9: msg.q_des_joint_9,
      q_des_joint_10: msg.q_des_joint_10,
      q_des_joint_11: msg.q_des_joint_11,
      tau_yaw_mpc: msg.tau_yaw_mpc,
      tau_yaw_wbc: msg.tau_yaw_wbc,
      f_cone_fl: msg.f_cone_fl,
      f_cone_fr: msg.f_cone_fr,
      f_cone_rl: msg.f_cone_rl,
      f_cone_rr: msg.f_cone_rr,
      tau_roll_mpc: msg.tau_roll_mpc,
      tau_roll_wbc: msg.tau_roll_wbc,
      tau_pitch_mpc: msg.tau_pitch_mpc,
      tau_pitch_wbc: msg.tau_pitch_wbc,
      a_wbc_ang_x: msg.a_wbc_ang_x,
      a_wbc_ang_y: msg.a_wbc_ang_y,
      a_wbc_ang_z: msg.a_wbc_ang_z,
      tau_joint_0: msg.tau_joint_0,
      tau_joint_1: msg.tau_joint_1,
      tau_joint_2: msg.tau_joint_2,
      tau_joint_3: msg.tau_joint_3,
      tau_joint_4: msg.tau_joint_4,
      tau_joint_5: msg.tau_joint_5,
      tau_joint_6: msg.tau_joint_6,
      tau_joint_7: msg.tau_joint_7,
      tau_joint_8: msg.tau_joint_8,
      tau_joint_9: msg.tau_joint_9,
      tau_joint_10: msg.tau_joint_10,
      tau_joint_11: msg.tau_joint_11,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      p_ref_fl_x: msg.p_ref_fl_x,
      p_ref_fl_y: msg.p_ref_fl_y,
      p_ref_fl_z: msg.p_ref_fl_z,
      p_ref_fr_x: msg.p_ref_fr_x,
      p_ref_fr_y: msg.p_ref_fr_y,
      p_ref_fr_z: msg.p_ref_fr_z,
      p_ref_rl_x: msg.p_ref_rl_x,
      p_ref_rl_y: msg.p_ref_rl_y,
      p_ref_rl_z: msg.p_ref_rl_z,
      p_ref_rr_x: msg.p_ref_rr_x,
      p_ref_rr_y: msg.p_ref_rr_y,
      p_ref_rr_z: msg.p_ref_rr_z,
      p_act_fl_x: msg.p_act_fl_x,
      p_act_fl_y: msg.p_act_fl_y,
      p_act_fl_z: msg.p_act_fl_z,
      p_act_fr_x: msg.p_act_fr_x,
      p_act_fr_y: msg.p_act_fr_y,
      p_act_fr_z: msg.p_act_fr_z,
      p_act_rl_x: msg.p_act_rl_x,
      p_act_rl_y: msg.p_act_rl_y,
      p_act_rl_z: msg.p_act_rl_z,
      p_act_rr_x: msg.p_act_rr_x,
      p_act_rr_y: msg.p_act_rr_y,
      p_act_rr_z: msg.p_act_rr_z,
      v_ref_fl_x: msg.v_ref_fl_x,
      v_ref_fl_y: msg.v_ref_fl_y,
      v_ref_fl_z: msg.v_ref_fl_z,
      v_ref_fr_x: msg.v_ref_fr_x,
      v_ref_fr_y: msg.v_ref_fr_y,
      v_ref_fr_z: msg.v_ref_fr_z,
      v_ref_rl_x: msg.v_ref_rl_x,
      v_ref_rl_y: msg.v_ref_rl_y,
      v_ref_rl_z: msg.v_ref_rl_z,
      v_ref_rr_x: msg.v_ref_rr_x,
      v_ref_rr_y: msg.v_ref_rr_y,
      v_ref_rr_z: msg.v_ref_rr_z,
      v_act_fl_x: msg.v_act_fl_x,
      v_act_fl_y: msg.v_act_fl_y,
      v_act_fl_z: msg.v_act_fl_z,
      v_act_fr_x: msg.v_act_fr_x,
      v_act_fr_y: msg.v_act_fr_y,
      v_act_fr_z: msg.v_act_fr_z,
      v_act_rl_x: msg.v_act_rl_x,
      v_act_rl_y: msg.v_act_rl_y,
      v_act_rl_z: msg.v_act_rl_z,
      v_act_rr_x: msg.v_act_rr_x,
      v_act_rr_y: msg.v_act_rr_y,
      v_act_rr_z: msg.v_act_rr_z,
      a_ref_fl_x: msg.a_ref_fl_x,
      a_ref_fl_y: msg.a_ref_fl_y,
      a_ref_fl_z: msg.a_ref_fl_z,
      a_ref_fr_x: msg.a_ref_fr_x,
      a_ref_fr_y: msg.a_ref_fr_y,
      a_ref_fr_z: msg.a_ref_fr_z,
      a_ref_rl_x: msg.a_ref_rl_x,
      a_ref_rl_y: msg.a_ref_rl_y,
      a_ref_rl_z: msg.a_ref_rl_z,
      a_ref_rr_x: msg.a_ref_rr_x,
      a_ref_rr_y: msg.a_ref_rr_y,
      a_ref_rr_z: msg.a_ref_rr_z,
      a_act_fl_x: msg.a_act_fl_x,
      a_act_fl_y: msg.a_act_fl_y,
      a_act_fl_z: msg.a_act_fl_z,
      a_act_fr_x: msg.a_act_fr_x,
      a_act_fr_y: msg.a_act_fr_y,
      a_act_fr_z: msg.a_act_fr_z,
      a_act_rl_x: msg.a_act_rl_x,
      a_act_rl_y: msg.a_act_rl_y,
      a_act_rl_z: msg.a_act_rl_z,
      a_act_rr_x: msg.a_act_rr_x,
      a_act_rr_y: msg.a_act_rr_y,
      a_act_rr_z: msg.a_act_rr_z,
      f_mpc_fl_x: msg.f_mpc_fl_x,
      f_mpc_fl_y: msg.f_mpc_fl_y,
      f_mpc_fl_z: msg.f_mpc_fl_z,
      f_mpc_fr_x: msg.f_mpc_fr_x,
      f_mpc_fr_y: msg.f_mpc_fr_y,
      f_mpc_fr_z: msg.f_mpc_fr_z,
      f_mpc_rl_x: msg.f_mpc_rl_x,
      f_mpc_rl_y: msg.f_mpc_rl_y,
      f_mpc_rl_z: msg.f_mpc_rl_z,
      f_mpc_rr_x: msg.f_mpc_rr_x,
      f_mpc_rr_y: msg.f_mpc_rr_y,
      f_mpc_rr_z: msg.f_mpc_rr_z,
      f_wbc_fl_x: msg.f_wbc_fl_x,
      f_wbc_fl_y: msg.f_wbc_fl_y,
      f_wbc_fl_z: msg.f_wbc_fl_z,
      f_wbc_fr_x: msg.f_wbc_fr_x,
      f_wbc_fr_y: msg.f_wbc_fr_y,
      f_wbc_fr_z: msg.f_wbc_fr_z,
      f_wbc_rl_x: msg.f_wbc_rl_x,
      f_wbc_rl_y: msg.f_wbc_rl_y,
      f_wbc_rl_z: msg.f_wbc_rl_z,
      f_wbc_rr_x: msg.f_wbc_rr_x,
      f_wbc_rr_y: msg.f_wbc_rr_y,
      f_wbc_rr_z: msg.f_wbc_rr_z,
      contact_fl: msg.contact_fl,
      contact_fr: msg.contact_fr,
      contact_rl: msg.contact_rl,
      contact_rr: msg.contact_rr,
      body_x: msg.body_x,
      body_z: msg.body_z,
      body_x_v: msg.body_x_v,
      body_z_v: msg.body_z_v,
      body_x_v_d: msg.body_x_v_d,
      body_z_v_d: msg.body_z_v_d,
      q_des_lin_x: msg.q_des_lin_x,
      q_des_lin_y: msg.q_des_lin_y,
      q_des_lin_z: msg.q_des_lin_z,
      q_des_ang_x: msg.q_des_ang_x,
      q_des_ang_y: msg.q_des_ang_y,
      q_des_ang_z: msg.q_des_ang_z,
      q_des_joint_0: msg.q_des_joint_0,
      q_des_joint_1: msg.q_des_joint_1,
      q_des_joint_2: msg.q_des_joint_2,
      q_des_joint_3: msg.q_des_joint_3,
      q_des_joint_4: msg.q_des_joint_4,
      q_des_joint_5: msg.q_des_joint_5,
      q_des_joint_6: msg.q_des_joint_6,
      q_des_joint_7: msg.q_des_joint_7,
      q_des_joint_8: msg.q_des_joint_8,
      q_des_joint_9: msg.q_des_joint_9,
      q_des_joint_10: msg.q_des_joint_10,
      q_des_joint_11: msg.q_des_joint_11,
      tau_yaw_mpc: msg.tau_yaw_mpc,
      tau_yaw_wbc: msg.tau_yaw_wbc,
      f_cone_fl: msg.f_cone_fl,
      f_cone_fr: msg.f_cone_fr,
      f_cone_rl: msg.f_cone_rl,
      f_cone_rr: msg.f_cone_rr,
      tau_roll_mpc: msg.tau_roll_mpc,
      tau_roll_wbc: msg.tau_roll_wbc,
      tau_pitch_mpc: msg.tau_pitch_mpc,
      tau_pitch_wbc: msg.tau_pitch_wbc,
      a_wbc_ang_x: msg.a_wbc_ang_x,
      a_wbc_ang_y: msg.a_wbc_ang_y,
      a_wbc_ang_z: msg.a_wbc_ang_z,
      tau_joint_0: msg.tau_joint_0,
      tau_joint_1: msg.tau_joint_1,
      tau_joint_2: msg.tau_joint_2,
      tau_joint_3: msg.tau_joint_3,
      tau_joint_4: msg.tau_joint_4,
      tau_joint_5: msg.tau_joint_5,
      tau_joint_6: msg.tau_joint_6,
      tau_joint_7: msg.tau_joint_7,
      tau_joint_8: msg.tau_joint_8,
      tau_joint_9: msg.tau_joint_9,
      tau_joint_10: msg.tau_joint_10,
      tau_joint_11: msg.tau_joint_11,
    }
  }
}


