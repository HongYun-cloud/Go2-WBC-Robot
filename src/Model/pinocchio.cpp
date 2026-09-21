#include "Model/pinocchio.hpp"
#include <fstream>
#include <sstream>
#include <regex>
#include <pinocchio/algorithm/center-of-mass.hpp>

namespace Pinocchio
{

// ========== 构造 / 析构 ==========

PinocchioKinematics::PinocchioKinematics()
{
}

PinocchioKinematics::PinocchioKinematics(const std::string& urdf_path)
{
    loadModel(urdf_path);
}

PinocchioKinematics::~PinocchioKinematics() = default;

// ========== stripPackageTags ==========
// 去除 <visual> 和 <collision> 标签（含内部的 package:// mesh 引用）
// 只保留 kinematics 需要的 link/joint 结构

std::string PinocchioKinematics::stripPackageTags(const std::string& urdf_path) const
{
    std::ifstream file(urdf_path);
    if (!file.is_open()) {
        std::cerr << "[Pinocchio] Cannot open URDF: " << urdf_path << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string xml = buffer.str();
    file.close();

    // 去除 <visual> ... </visual>
    {
        std::regex visual_regex(R"(<visual[\s\S]*?<\/visual>)");
        xml = std::regex_replace(xml, visual_regex, "");
    }

    // 去除 <collision> ... </collision>
    {
        std::regex collision_regex(R"(<collision[\s\S]*?<\/collision>)");
        xml = std::regex_replace(xml, collision_regex, "");
    }

    // 去除 <material> ... </material> (可能残留)
    {
        std::regex material_regex(R"(<material[^>]*\/>)");
        xml = std::regex_replace(xml, material_regex, "");
    }

    return xml;
}

// ========== 模型加载 ==========

bool PinocchioKinematics::loadModel(const std::string& urdf_path)
{
    try {
        // 预处理 URDF：去除 visual/collision 避免 package:// 路径解析失败
        std::string stripped_xml = stripPackageTags(urdf_path);
        if (stripped_xml.empty())
            return false;

        model_ = std::make_shared<pinocchio::Model>();
        pinocchio::urdf::buildModelFromXML(stripped_xml, *model_);
        data_ = std::make_shared<pinocchio::Data>(*model_);

        // 构建带自由飞轮的浮动基座模型 (用于动力学: nq=19, nv=18)
        model_fb_ = std::make_shared<pinocchio::Model>();
        pinocchio::urdf::buildModelFromXML(stripped_xml,
                                            pinocchio::JointModelFreeFlyer(),
                                            *model_fb_);
        data_fb_ = std::make_shared<pinocchio::Data>(*model_fb_);
        M_fb_.setZero(18, 18);
        h_fb_.setZero(18);

        nq_ = model_->nq;
        nv_ = model_->nv;

        // 缓存足端 frame ID
        foot_names_ = {"FL_foot", "FR_foot", "RL_foot", "RR_foot"};
        foot_frame_ids_.resize(4, -1);
        for (int i = 0; i < 4; i++) {
            if (model_->existFrame(foot_names_[i])) {
                foot_frame_ids_[i] = model_->getFrameId(foot_names_[i]);
            } else {
                std::cerr << "[Pinocchio] Warning: frame '" << foot_names_[i]
                          << "' not found in model" << std::endl;
            }
        }

        q_.resize(nq_);
        q_.setZero();
        v_.resize(nv_);
        v_.setZero();

        std::cout << "[Pinocchio] Model loaded: " << model_->name << std::endl;
        std::cout << "  nq=" << nq_ << ", nv=" << nv_ << std::endl;
        std::cout << "  Foot frames: ";
        for (int i = 0; i < 4; i++)
            std::cout << foot_names_[i] << "(id=" << foot_frame_ids_[i] << ") ";
        std::cout << std::endl;

        return true;

    } catch (const std::exception& e) {
        std::cerr << "[Pinocchio] Failed to load URDF: " << e.what() << std::endl;
        return false;
    }
}

// ========== 正运动学 ==========

void PinocchioKinematics::forwardKinematics(const Eigen::VectorXd& q)
{
    q_ = q;
    pinocchio::forwardKinematics(*model_, *data_, q_);
    pinocchio::updateFramePlacements(*model_, *data_);
    pinocchio::computeJointJacobians(*model_, *data_, q_);
    pinocchio::computeJointJacobiansTimeVariation(*model_, *data_, q_, v_);
    _syncLegData();
}

void PinocchioKinematics::forwardKinematics(const Eigen::VectorXd& q,
                                             const Eigen::Vector3d& base_pos,
                                             const Eigen::Vector4d& base_quat)
{
    q_ = q;
    base_pos_ = base_pos;
    base_quat_ = base_quat;
    // 固定基座模型只传 12 维关节角，基底位姿单独存储
    // (浮动基座雅可比 getFootJacobianFloatingBase 会手动拼基底贡献)
    pinocchio::forwardKinematics(*model_, *data_, q_);
    pinocchio::updateFramePlacements(*model_, *data_);
    pinocchio::computeJointJacobians(*model_, *data_, q_);
    pinocchio::computeJointJacobiansTimeVariation(*model_, *data_, q_, v_);
    _syncLegData();
}

Regulator::legData* PinocchioKinematics::getLegData()
{
    return &leg_data_;
}

void PinocchioKinematics::_syncLegData()
{
    // 将 Pinocchio FK 结果同步到 leg_data_
    // p: 世界系 质心→足端 向量
    // (MPC 的 B 矩阵用它算力矩 τ = Σ r×f, r 必须与力 f 同在世界系、且相对质心;
    //  之前用机身系向量 + 世界系力混系, 且参考点是 base 原点不是质心)
    pinocchio::centerOfMass(*model_, *data_, q_);
    Eigen::Quaterniond qb(base_quat_(3), base_quat_(0), base_quat_(1), base_quat_(2));
    Eigen::Vector3d com_world = base_pos_ + qb.toRotationMatrix() * data_->com[0];
    for (int i = 0; i < 4; i++) {
        leg_data_.p[i] = getFootPosition(i) - com_world;
    }
    // w 需要在外部用 setFootVelocities 或 IK 更新
}

void PinocchioKinematics::getTotalMassInertia(double& mass, Eigen::Matrix3d& I_com) const
{
    // 整机质心惯量: 逐连杆累加 (不依赖 crba/oYcrb —— pinocchio 2.x 的 crba 不填充 oYcrb,
    // 之前直接读 oYcrb[0] 拿到全 0 → MPC mass=0 → B 矩阵除零 Inf → 求解被跳过、力冻结 → 不支撑)
    // 每个连杆: I_origin += R_i·I_i·R_iᵀ + m_i·(rᵢᵀrᵢ·I − rᵢrᵢᵀ), rᵢ = 连杆质心 (基座系)
    mass = 0.0;
    Eigen::Matrix3d I_origin = Eigen::Matrix3d::Zero();
    Eigen::Vector3d com = Eigen::Vector3d::Zero();

    // std::cout << "njoints = " << model_->njoints << std::endl;
    // std::cout << "nbodies = " << model_->nbodies << std::endl;

    // for (size_t i = 0; i < model_->njoints; ++i) {
    //     std::cout << i
    //             << "  "
    //             << model_->names[i]
    //             << "  mass="
    //             << model_->inertias[i].mass()
    //             << std::endl;
    // }

    

    // i 从 0 起: universe 槽位装的不是"世界", 而是整个机身组 —— 固定基座模型下 pinocchio
    // 把 root link 及其所有 fixed-joint 子树合并进该 body (base 6.921 + 4×hip_rotor 0.089 + head 0.002 = 7.279)
    for (size_t i = 1; i < (size_t)model_->njoints; i++) {
        const pinocchio::Inertia& Y = model_->inertias[i];
        double m = Y.mass();
        if (m <= 0.0) continue;
        Eigen::Matrix3d R = data_->oMi[i].rotation();        // 连杆系 → 基座系
        Eigen::Vector3d r = data_->oMi[i].act(Y.lever());    // 连杆质心在基座系的位置
        mass += m;
        com  += m * r;
        I_origin += R * Y.inertia().matrix() * R.transpose()
                  + m * (r.dot(r) * Eigen::Matrix3d::Identity() - r * r.transpose());
    }
    mass += 1.0;
    com /= mass;

    // I_origin = I_com + m·(cᵀc·I − c·cᵀ)  ⇒  I_com = I_origin − m·(cᵀc·I − c·cᵀ)
    I_com = I_origin - mass * (com.dot(com) * Eigen::Matrix3d::Identity() - com * com.transpose());
}

// ========== 正解结果查询 ==========

Eigen::Vector3d PinocchioKinematics::getFootPosition(int leg) const
{
    // 机身系 → 世界系: p_world = base_pos + R_base * p_body
    // (固定基座模型基座在原点, oMf 直接是机身系坐标)
    Eigen::Vector3d p_body = data_->oMf[foot_frame_ids_.at(leg)].translation();
    Eigen::Quaterniond qb(base_quat_(3), base_quat_(0), base_quat_(1), base_quat_(2));  // (w,x,y,z)
    return base_pos_ + qb.toRotationMatrix() * p_body;
}

Eigen::Vector3d PinocchioKinematics::getFootPositionInBase(int leg) const
{
    int fid = foot_frame_ids_.at(leg);
    const auto& oMfoot = data_->oMf[fid];
    return oMfoot.translation();  // base 在原点，无需 actInv
}


Eigen::Matrix<double, 4, 3> PinocchioKinematics::getAllFootPositions() const
{
    Eigen::Matrix<double, 4, 3> feet;
    for (int i = 0; i < 4; i++)
        feet.row(i) = getFootPosition(i);

    return feet;
}

Eigen::Matrix<double, 4, 3> PinocchioKinematics::getAllFootPositionsInBase() const
{
    Eigen::Matrix<double, 4, 3> feet;
    for (int i = 0; i < 4; i++)
        feet.row(i) = getFootPositionInBase(i);
    return feet;
}

// ========== 雅可比 ==========

Eigen::MatrixXd PinocchioKinematics::getFootJacobian(int leg) const
{
    int fid = foot_frame_ids_.at(leg);
    Eigen::MatrixXd J = Eigen::MatrixXd::Zero(6, nv_);
    pinocchio::getFrameJacobian(*model_, *data_, fid,
                                 pinocchio::LOCAL_WORLD_ALIGNED, J);
    return J.topRows(3);
}

Eigen::MatrixXd PinocchioKinematics::getFootJacobianFull(int leg) const
{
    int fid = foot_frame_ids_.at(leg);
    Eigen::MatrixXd J = Eigen::MatrixXd::Zero(6, nv_);
    pinocchio::getFrameJacobian(*model_, *data_, fid,
                                 pinocchio::LOCAL_WORLD_ALIGNED, J);
    return J;
}

Eigen::MatrixXd PinocchioKinematics::getFootJacobianTimeVariation(int leg) const
{
    int fid = foot_frame_ids_.at(leg);
    Eigen::MatrixXd dJ = Eigen::MatrixXd::Zero(6, nv_);
    pinocchio::getFrameJacobianTimeVariation(*model_, *data_, fid,
                                             pinocchio::LOCAL_WORLD_ALIGNED, dJ);
    return dJ.topRows(3);  // 仅返回平动部分 (3×nv)
}

// ========== 浮动基座雅可比 ==========

Eigen::Matrix<double, 3, 18> PinocchioKinematics::getFootJacobianFloatingBase(int leg) const
{
    int fid = foot_frame_ids_.at(leg);

    // 关节部分: 3×12
    Eigen::MatrixXd J_joint = Eigen::MatrixXd::Zero(6, nv_);
    pinocchio::getFrameJacobian(*model_, *data_, fid,
                                 pinocchio::LOCAL_WORLD_ALIGNED, J_joint);

    // 基底部分: I₃ 和 -skew(p_foot - p_base)
    Eigen::Vector3d p_foot = getFootPosition(leg);
    Eigen::Vector3d r = p_foot - base_pos_;

    Eigen::Matrix<double, 3, 18> J;
    J.setZero();
    J.block<3, 3>(0, 0) = Eigen::Matrix3d::Identity();   // ∂v_foot/∂v_base
    // -skew(r): ∂(ω×r)/∂ω = -skew(r), 之前写成 +skew(r) 整块取反 ——
    // 站立时 ω≈0 不显形, 一摆动腿就把 2·|r|·a_ang 的假项注进无滑动约束
    J(0, 4) =  r(2);   J(0, 5) = -r(1);
    J(1, 3) = -r(2);   J(1, 5) =  r(0);
    J(2, 3) =  r(1);   J(2, 4) = -r(0);
    J.block<3, 12>(0, 6) = J_joint.topRows(3);           // ∂v_foot/∂q̇_joint

    return J;
}

Eigen::Matrix<double, 3, 18> PinocchioKinematics::getFootJacobianTimeVariationFloatingBase(int leg) const
{
    int fid = foot_frame_ids_.at(leg);

    // 关节部分 dJ/dt: 3×12
    Eigen::MatrixXd dJ_joint = Eigen::MatrixXd::Zero(6, nv_);
    pinocchio::getFrameJacobianTimeVariation(*model_, *data_, fid,
                                              pinocchio::LOCAL_WORLD_ALIGNED, dJ_joint);

    // 足端速度: v_foot = v_base + ω_base × r + J_joint * q̇_joint
    Eigen::Vector3d p_foot = getFootPosition(leg);
    Eigen::Vector3d r = p_foot - base_pos_;
    Eigen::VectorXd v_joint = getJointVelocity();
    Eigen::Vector3d v_foot = base_vel_
                           + base_ang_.cross(r)
                           + getFootJacobian(leg) * v_joint;

    // ṙ = v_foot - v_base
    Eigen::Vector3d r_dot = v_foot - base_vel_;

    Eigen::Matrix<double, 3, 18> dJ;
    dJ.setZero();
    // dJ_base_linear = 0₃ (I 是常量)
    // dJ_base_angular = -skew(ṙ) (与上面 J 的角速度块同步取反)
    dJ(0, 4) =  r_dot(2);   dJ(0, 5) = -r_dot(1);
    dJ(1, 3) = -r_dot(2);   dJ(1, 5) =  r_dot(0);
    dJ(2, 3) =  r_dot(1);   dJ(2, 4) = -r_dot(0);
    dJ.block<3, 12>(0, 6) = dJ_joint.topRows(3);

    return dJ;
}

Eigen::VectorXd PinocchioKinematics::getJointTorques(const Eigen::Matrix<double, 12, 1>& foot_forces,
                                                      bool hip_enabled) const
{
    // 组装 12×12 足端力雅可比 (4 腿 × 3 轴力)
    Eigen::MatrixXd J_full(12, nv_);
    for (int leg = 0; leg < 4; leg++) {
        J_full.block<3, 12>(leg * 3, 0) = getFootJacobian(leg);
    }

    // DEBUG: 打印雅可比信息
    // static int j_dbg = 0;
    // if (j_dbg++ % 100 == 0) {
    //     std::cout << "[IK J_full] nnz=" << J_full.norm()
    //               << " fid=[";
    //     for (int l = 0; l < 4; l++)
    //         std::cout << foot_frame_ids_[l] << " ";
    //     std::cout << "] nv=" << nv_ << std::endl;
    //     std::cout << "[IK] J(0:3,0:3):\n" << J_full.block<3,3>(0,0) << std::endl;
    //     std::cout << "[IK] foot_forces head(6): " << foot_forces.head(6).transpose() << std::endl;
    // }

    // τ = J^T · f  (12 维关节力矩)
    Eigen::VectorXd tau_full = -J_full.transpose() * foot_forces;

    if (hip_enabled) {
        return tau_full;  // 12 维, 含 hip
    }

    // 转换为 MuJoCo 8 维 (跳过 hip 关节: 索引 0,3,6,9)
    // Pinocchio 关节顺序: FL_hip,FL_thigh,FL_calf, FR_hip,FR_thigh,FR_calf,
    //                       RL_hip,RL_thigh,RL_calf, RR_hip,RR_thigh,RR_calf
    // MuJoCo 关节顺序:    FL_thigh,FL_calf, FR_thigh,FR_calf,
    //                       RL_thigh,RL_calf, RR_thigh,RR_calf
    Eigen::VectorXd tau_8(nv_ - 4);  // 8 维 (12 - 4 hip)
    int idx = 0;
    for (int i = 0; i < nv_; i++) {
        if (i % 3 != 0) {  // 跳过 hip (每 3 个关节的第 1 个)
            tau_8(idx++) = tau_full(i);
        }
    }
    return tau_8;
}

Eigen::VectorXd PinocchioKinematics::getJointTorquesFromSolution(const Eigen::Matrix<double, 18, 1>& a,
                                                                  const Eigen::Matrix<double, 12, 1>& f) const
{
    // 浮动基座逆动力学: τ = (M·a + h - J^T·f) 的关节行
    Eigen::Matrix<double, 18, 1> gen = M_fb_ * a + h_fb_;
    for (int leg = 0; leg < 4; leg++) {
        Eigen::Matrix<double, 3, 18> J = getFootJacobianFloatingBase(leg);
        gen -= J.transpose() * f.segment<3>(leg * 3);
    }
    Eigen::VectorXd tau_full = gen.tail(12);  // Pinocchio 顺序: FL_hip,FL_thigh,FL_calf, FR_hip,...

    // // 转换为 MuJoCo 8 维 (跳过 hip 关节: 索引 0,3,6,9), 与 getJointTorques 一致
    // Eigen::VectorXd tau_8(nv_ - 4);
    // int idx = 0;
    // for (int i = 0; i < nv_; i++) {
    //     if (i % 3 != 0) {  // 跳过 hip (每 3 个关节的第 1 个)
    //         tau_8(idx++) = tau_full(i);
    //     }
    // }
    return tau_full;
}

// ========== 逆运动学 (阻尼最小二乘) ==========

bool PinocchioKinematics::inverseKinematics(int leg,
                                             const Eigen::Vector3d& target_pos,
                                             const Eigen::VectorXd& q_init,
                                             Eigen::VectorXd& q_out,
                                             int max_iter,
                                             double tol)
{
    q_out = q_init;
    double lambda = 0.1;

    for (int iter = 0; iter < max_iter; iter++) {
        forwardKinematics(q_out);
        Eigen::Vector3d current = getFootPosition(leg);
        Eigen::Vector3d error = target_pos - current;

        if (error.norm() < tol)
            return true;

        Eigen::MatrixXd J = getFootJacobian(leg);
        Eigen::Matrix3d JJt = J * J.transpose();
        JJt.diagonal() += Eigen::Vector3d::Constant(lambda);

        Eigen::Vector3d delta = JJt.ldlt().solve(error);
        q_out += J.transpose() * delta;

        lambda *= 0.9;
    }

    forwardKinematics(q_out);
    return (target_pos - getFootPosition(leg)).norm() < tol * 10.0;
}

bool PinocchioKinematics::inverseKinematicsFull(const Eigen::Matrix<double, 4, 3>& targets,
                                                 const Eigen::VectorXd& q_init,
                                                 Eigen::VectorXd& q_out,
                                                 int max_iter,
                                                 double tol)
{
    q_out = q_init;
    double lambda = 0.1;

    for (int iter = 0; iter < max_iter; iter++) {
        forwardKinematics(q_out);

        Eigen::VectorXd error(12);
        Eigen::MatrixXd J_full(12, nq_);

        for (int leg = 0; leg < 4; leg++) {
            error.segment<3>(leg * 3) = targets.row(leg).transpose() - getFootPosition(leg);
            J_full.block<3, 12>(leg * 3, 0) = getFootJacobian(leg);
        }

        if (error.norm() < tol)
            return true;

        Eigen::MatrixXd JJt = J_full * J_full.transpose();
        JJt.diagonal() += Eigen::VectorXd::Constant(12, lambda);

        Eigen::VectorXd delta = JJt.ldlt().solve(error);
        q_out += J_full.transpose() * delta;

        lambda *= 0.95;
    }

    forwardKinematics(q_out);
    double final_err = 0;
    for (int leg = 0; leg < 4; leg++)
        final_err += (targets.row(leg).transpose() - getFootPosition(leg)).norm();
    return final_err / 4.0 < tol * 10.0;
}

bool PinocchioKinematics::inverseKinematicsFullWorld(const Eigen::Matrix<double, 4, 3>& targets,
                                                     const Eigen::VectorXd& q_init,
                                                     Eigen::VectorXd& q_out,
                                                     int max_iter,
                                                     double tol)
{
    q_out = q_init;
    double lambda = 0.1;

    // 世界系: 基底位姿取上次 forwardKinematics 存储的 base_pos_/base_quat_
    Eigen::Matrix3d R_base = Eigen::Quaterniond(base_quat_(3), base_quat_(0), base_quat_(1), base_quat_(2)).toRotationMatrix();

    // 局部数据缓存: 迭代只写局部 data, 不污染成员 data_/q_, 调用方无需恢复
    pinocchio::Data data_local(*model_);

    for (int iter = 0; iter < max_iter; iter++) {
        pinocchio::forwardKinematics(*model_, data_local, q_out);
        pinocchio::updateFramePlacements(*model_, data_local);
        pinocchio::computeJointJacobians(*model_, data_local, q_out);

        Eigen::VectorXd error(12);
        Eigen::MatrixXd J_world(12, nq_);

        for (int leg = 0; leg < 4; leg++) {
            // 足端世界系位置: 机身系坐标旋转后叠加基底位置
            Eigen::Vector3d p_world = base_pos_ + R_base * data_local.oMf[foot_frame_ids_.at(leg)].translation();
            error.segment<3>(leg * 3) = targets.row(leg).transpose() - p_world;

            Eigen::MatrixXd J = Eigen::MatrixXd::Zero(6, nv_);
            pinocchio::getFrameJacobian(*model_, data_local, foot_frame_ids_.at(leg),
                                        pinocchio::LOCAL_WORLD_ALIGNED, J);
            J_world.block<3, 12>(leg * 3, 0) = R_base * J.topRows(3);  // 机身系对齐雅可比转世界系
        }

        if (error.norm() < tol)
            return true;

        Eigen::MatrixXd JJt = J_world * J_world.transpose();
        JJt.diagonal() += Eigen::VectorXd::Constant(12, lambda);

        Eigen::VectorXd delta = JJt.ldlt().solve(error);
        q_out += J_world.transpose() * delta;

        lambda *= 0.95;
    }

    // 最终误差检查 (局部 data 上)
    pinocchio::forwardKinematics(*model_, data_local, q_out);
    pinocchio::updateFramePlacements(*model_, data_local);
    double final_err = 0;
    for (int leg = 0; leg < 4; leg++) {
        Eigen::Vector3d p_world = base_pos_ + R_base * data_local.oMf[foot_frame_ids_.at(leg)].translation();
        final_err += (targets.row(leg).transpose() - p_world).norm();
    }
    return final_err / 4.0 < tol * 10.0;
}

bool PinocchioKinematics::footAccelerationToJointAcceleration(const Eigen::Vector<double, 12>& foot_acc_world,
                                                              Eigen::VectorXd& qdd_out) const
{
    // 操作空间加速度: ẍ = J·q̈ + dJ·v, 基座加速度视为 0, 只解 12 维关节加速度
    Eigen::MatrixXd J12(12, 12);
    Eigen::VectorXd bias(12);

    Eigen::VectorXd v_full(18);
    v_full << base_vel_, base_ang_, v_;

    for (int leg = 0; leg < 4; leg++) {
        Eigen::Matrix<double, 3, 18> J  = getFootJacobianFloatingBase(leg);
        Eigen::Matrix<double, 3, 18> dJ = getFootJacobianTimeVariationFloatingBase(leg);
        J12.block<3, 12>(leg * 3, 0) = J.block<3, 12>(0, 6);  // 关节列 (6..17)
        bias.segment<3>(leg * 3) = dJ * v_full;               // J̇·q̇ 偏置项
    }

    Eigen::FullPivLU<Eigen::MatrixXd> lu(J12);
    if (!lu.isInvertible()) {
        qdd_out.setZero();
        return false;
    }
    qdd_out = lu.solve(foot_acc_world - bias);
    return true;
}

// ========== 查询接口 ==========

int PinocchioKinematics::getNq() const { return nq_; }
int PinocchioKinematics::getNv() const { return nv_; }
const Eigen::VectorXd& PinocchioKinematics::getJointConfig() const { return q_; }

void PinocchioKinematics::setJointVelocity(const Eigen::VectorXd& v)
{
    v_ = v;
}

const Eigen::VectorXd& PinocchioKinematics::getJointVelocity() const
{
    return v_;
}

void PinocchioKinematics::setBaseVelocity(const Eigen::Vector3d& base_vel,
                                           const Eigen::Vector3d& base_ang)
{
    base_vel_ = base_vel;
    base_ang_ = base_ang;
}

void PinocchioKinematics::setBaseQuaternion(const Eigen::Quaterniond& quat)
{
    // coeffs() 返回 (x, y, z, w)，与 Pinocchio 约定一致
    base_quat_ = quat.coeffs();
}

// ========== 浮动基座动力学 ==========

void PinocchioKinematics::computeFloatingBaseDynamics()
{
    // 用已建好的自由飞轮模型算真实 18×18 浮动基座动力学。
    // 之前是手拼 blkdiag(m·I₃, I₃, M_joint) 并"耦合项暂置零", 有两个后果:
    //   1) 基座转动块写死 I₃ (真实 ≈ diag(0.24, 0.55, 0.54)) → WBC 的角加速度行变成
    //      a_ang = Σ(r×f) 而不是 Σ(r×f) = I·a_ang, 姿态环实际增益差 1/I (roll 4.2 倍)
    //   2) h 里缺重力对基座原点的力矩 c×(m·g) → 恒定 pitch 偏置
    // pinocchio 的自由飞轮把基座速度表达在机体系, WBC/MPC 用世界系对齐
    // → 前 6 行/列左右各乘一次 T = blockdiag(R, R, I₁₂) (T 正交)。

    Eigen::VectorXd q_fb(model_fb_->nq), v_fb(model_fb_->nv);
    q_fb.setZero();
    q_fb.segment<4>(3) = base_quat_;      // pinocchio 约定 (x,y,z,w); 基座平移不影响 M/h
    q_fb.tail(nv_)     = q_;
    v_fb.setZero();
    v_fb.head<3>()     = base_vel_;
    v_fb.segment<3>(3) = base_ang_;
    v_fb.tail(nv_)     = v_;

    pinocchio::crba(*model_fb_, *data_fb_, q_fb);
    data_fb_->M.triangularView<Eigen::StrictlyLower>() =
        data_fb_->M.transpose().triangularView<Eigen::StrictlyLower>();
    // 非线性格包括科氏/离心/重力 (之前传零速度只算了重力)
    pinocchio::nonLinearEffects(*model_fb_, *data_fb_, q_fb, v_fb);

    Eigen::Quaterniond qb(base_quat_(3), base_quat_(0), base_quat_(1), base_quat_(2));  // (w,x,y,z)
    Eigen::Matrix<double, 18, 18> T = Eigen::Matrix<double, 18, 18>::Identity();
    T.block<3, 3>(0, 0) = qb.toRotationMatrix();
    T.block<3, 3>(3, 3) = T.block<3, 3>(0, 0);

    // x_world = T·x_local ⇒ M_world = T·M_local·Tᵀ, h_world = T·h_local
    M_fb_ = T * data_fb_->M * T.transpose();
    h_fb_ = T * data_fb_->nle;
}

Eigen::Matrix<double, 18, 18> PinocchioKinematics::getMassMatrix() const
{
    return M_fb_;
}

Eigen::Matrix<double, 18, 1> PinocchioKinematics::getBiasForces() const
{
    return h_fb_;
}

std::vector<std::string> PinocchioKinematics::getJointNames() const
{
    std::vector<std::string> names;
    for (int i = 1; i < model_->njoints; i++) {
        if (model_->nvs[i] > 0)
            names.push_back(model_->names[i]);
    }
    return names;
}

void PinocchioKinematics::printJointInfo() const
{
    std::cout << "\n===== Pinocchio Joint Info =====" << std::endl;
    std::cout << "Total joints: " << model_->njoints - 1 << std::endl;
    std::cout << "Config dim (nq): " << nq_ << std::endl;
    std::cout << "Velocity dim (nv): " << nv_ << std::endl;
    std::cout << "\nRevolute joints:" << std::endl;

    int idx = 0;
    for (int i = 1; i < model_->njoints; i++) {
        if (model_->nvs[i] > 0) {
            std::cout << "  [" << idx << "] " << model_->names[i]
                      << "  (nq=" << model_->nqs[i]
                      << ", nv=" << model_->nvs[i]
                      << ", parent=" << model_->parents[i] << ")"
                      << std::endl;
            idx++;
        }
    }

    std::cout << "\nFoot frames:" << std::endl;
    for (int i = 0; i < 4; i++) {
        std::cout << "  " << foot_names_[i]
                  << "  frame_id=" << foot_frame_ids_[i] << std::endl;
    }
    std::cout << "================================\n" << std::endl;
}

} // namespace Pinocchio
