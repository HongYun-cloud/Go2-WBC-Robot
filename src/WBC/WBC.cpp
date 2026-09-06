#include "WBC/WBC.hpp"

namespace WBC
{
    WBC::WBC(Estimator::PositionVelocityEstimator *extern_estimator)
    {
        _pin = nullptr;
        config = new WBCConfig();
        qpconstraint = new QPConstraint();
        task_vec.setZero();
        estimator = extern_estimator;
    }

    WBC::~WBC()
    {
    }

    void WBC::loadConfig(const std::string& yaml_path){
        YAML::Node yaml = YAML::LoadFile(yaml_path);
        auto wbc = yaml["wbc"];

        // 读取 W (18 维对角向量 → 18×18)
        if (wbc["W"] && wbc["W"].size() == 18) {
            config->W.setZero();
            for (int i = 0; i < 18; i++)
                config->W(i, i) = wbc["W"][i].as<double>();
        }

        // 读取 FI (12 维对角向量 → 12×12)
        if (wbc["FI"] && wbc["FI"].size() == 12) {
            config->FI.setZero();
            for (int i = 0; i < 12; i++)
                config->FI(i, i) = wbc["FI"][i].as<double>();
        }

        // 读取 C (30 维对角向量 → 30×30)
        if (wbc["C"] && wbc["C"].size() == 30) {
            config->C.setZero();
            for (int i = 0; i < 30; i++)
                config->C(i, i) = wbc["C"][i].as<double>();
        }

        std::cout << "[WBC] Config loaded from " << yaml_path << std::endl;
    }

    void WBC::init(){
        // 目标函数固定结构初始化
        config->A_q.block<18,18>(0,0).setIdentity();
        config->A_f.block<12,12>(0, 18).setIdentity();  // f 从第 18 列开始
    }

    // @note 每次都会计算Hg，同时更新约束矩阵
    // @warning 使用前要先调用一下init
    void WBC::update(Vec18d& q, Vec12d& f, Eigen::Matrix<double,12,1>& a, RobotState state){
        cmd.q_d = q;
        cmd.f_d = f;
        cmd.a_d = a;

        config->A_a.setZero();
        config->b_a.setZero();
        config->b_q = cmd.q_d;
        config->b_f = cmd.f_d;

        // 缓存全状态速度和接触状态
        v_full_ << state.linear_vel, state.angular_vel, _pin->getJointVelocity();
        contact_states_ = state.contact_states;

        // 设置基底姿态 (供动力学计算用)
        _pin->setBaseQuaternion(state.quat);

        // 计算浮动基座动力学 (M, h)
        _pin->computeFloatingBaseDynamics();

        // 遍历 4 条腿，摆动腿 (contact_states[leg]==0) 做足端轨迹跟踪
        int row = 0;
        for (int leg = 0; leg < 4; leg++) {
            if (state.contact_states[leg] == 1) continue;  // 支撑腿跳过

            // 浮动基座摆动腿雅可比 (3×18)
            Eigen::Matrix<double, 3, 18> J  = _pin->getFootJacobianFloatingBase(leg);
            Eigen::Matrix<double, 3, 18> dJ = _pin->getFootJacobianTimeVariationFloatingBase(leg);

            // A_a: 前18维的摆动腿J
            config->A_a.block<3, 18>(row * 3, 0) = J;
            // b_a: 摆动腿加速度跟踪 a_d - d（J*q）
            config->b_a.segment<3>(row * 3) = cmd.a_d.segment<3>(leg * 3) - dJ * v_full_;
            row++;
        }

        // ---- 动力学软约束 (行 12-29): M*a - J^T*f + h ≈ 0 ----
        auto M = _pin->getMassMatrix();       // 18×18
        auto h = _pin->getBiasForces();       // 18×1
        config->A_a.block<18, 18>(12, 0) = M;
        for (int leg = 0; leg < 4; leg++) {
            Eigen::Matrix<double, 3, 18> J = _pin->getFootJacobianFloatingBase(leg);
            config->A_a.block<18, 3>(12, 18 + leg * 3) = -J.transpose();
        }
        config->b_a.segment<18>(12) = -h;

        updateconstraint();
        compuseHg();
    }

    void WBC::updateconstraint(){
        // 腿级硬约束: 支撑腿接触 / 摆动腿力为零
        // 决策变量 x = [a(18); f(12)] (30维)

        qpconstraint->A.setZero();
        qpconstraint->lower.setZero();
        qpconstraint->upper.setZero();

        // ---- 腿级约束 (行 18-29): 支撑腿接触 / 摆动腿力为零 ----
        for (int leg = 0; leg < 4; leg++) {
            int row = 18 + leg * 3;
            int col_f = 18 + leg * 3;

            if (contact_states_[leg] == 1) {
                // 支撑腿: J_leg * a = -dJ_leg * v  (足端无滑动)
                Eigen::Matrix<double, 3, 18> J  = _pin->getFootJacobianFloatingBase(leg);
                Eigen::Matrix<double, 3, 18> dJ = _pin->getFootJacobianTimeVariationFloatingBase(leg);
                qpconstraint->A.block<3, 18>(row, 0) = J;
                Eigen::Vector3d rhs = -dJ * v_full_;
                qpconstraint->lower.segment<3>(row) = rhs;
                qpconstraint->upper.segment<3>(row) = rhs;
            } else {
                // 摆动腿: f_leg = 0  (无地面接触力)
                qpconstraint->A.block<3, 3>(row, col_f).setIdentity();
                qpconstraint->lower.segment<3>(row).setZero();
                qpconstraint->upper.segment<3>(row).setZero();
            }
        }

        // ---- 摩擦锥约束 (行 30-49, 4腿×5行): 支撑腿 |fx|,|fy| ≤ μ·fz 且 fz ∈ [0, fz_max] ----
        // 原本 WBC 的 QP 没有摩擦锥, 为了满足动力学项会编造物理上实现不了的接触力
        // (切向力超出 μ·fz 或 fz<0), MuJoCo 里脚打滑/无法吸附 → QP 解出的基座加速度落不了地
        // 系数每帧都写 (稀疏模式稳定), 只按接触状态改上下界
        for (int leg = 0; leg < 4; leg++) {
            int col = 18 + leg * 3;
            int row = 30 + leg * 5;
            double mu = qpconstraint->mu;

            // |fx| ≤ μ·fz
            qpconstraint->A(row,     col)     =  1.0;  qpconstraint->A(row,     col + 2) = -mu;
            qpconstraint->A(row + 1, col)     = -1.0;  qpconstraint->A(row + 1, col + 2) = -mu;
            // |fy| ≤ μ·fz
            qpconstraint->A(row + 2, col + 1) =  1.0;  qpconstraint->A(row + 2, col + 2) = -mu;
            qpconstraint->A(row + 3, col + 1) = -1.0;  qpconstraint->A(row + 3, col + 2) = -mu;
            // fz
            qpconstraint->A(row + 4, col + 2) =  1.0;

            if (contact_states_[leg] == 1) {
                qpconstraint->lower.segment<5>(row).setConstant(-1e10);
                qpconstraint->lower(row + 4) = 0.0;
                qpconstraint->upper.segment<5>(row).setZero();
                qpconstraint->upper(row + 4) = qpconstraint->fz_max;
            } else {
                // 摆动腿 f 已被腿级等式约束钉在 0, 锥约束放开避免冲突
                qpconstraint->lower.segment<5>(row).setConstant(-1e10);
                qpconstraint->upper.segment<5>(row).setConstant(1e10);
            }
        }
    }
    
    void WBC::compuseHg(){
        Mat30d H;
        Vec30d g;

        auto H1 = config->A_q.transpose() * config->W  * config->A_q;
        auto H2 = config->A_f.transpose() * config->FI * config->A_f;
        auto H3 = config->A_a.transpose() * config->C  * config->A_a;

        auto g1 = config->A_q.transpose() * config->W  * config->b_q;
        auto g2 = config->A_f.transpose() * config->FI * config->b_f;
        auto g3 = config->A_a.transpose() * config->C  * config->b_a;

        H = H1 + H2 + H3;
        g = g1 + g2 + g3;

        double lambda = 1e-6;
        H.diagonal().array() += lambda;
        
        config->H=  2 * H;
        config->g= -2 * g;

    }

    void WBC::solve(){
        auto H = config->H;
        Eigen::SparseMatrix<double> H_sparse = H.sparseView();
        Eigen::SparseMatrix<double> A_sparse = qpconstraint->A.sparseView();
        // OSQP 对 q/l/u 存裸指针 (c_float = double), 必须用持久成员缓冲,
        // 局部变量会在函数返回后失效, 导致 update 时读到垃圾数据
        osqp_gradient_ = config->g;
        osqp_lower_ = qpconstraint->lower;
        osqp_upper_ = qpconstraint->upper;
        int n_con = 50;  // 18 保留 + 12 腿级 + 20 摩擦锥
        int n_var = 30;
        if (!_solver_initialized) {
            _solver.settings()->setVerbosity(false);
            _solver.data()->setNumberOfVariables(n_var);
            _solver.data()->setNumberOfConstraints(n_con);
            _solver.data()->setHessianMatrix(H_sparse);
            _solver.data()->setGradient(osqp_gradient_);
            _solver.data()->setLinearConstraintsMatrix(A_sparse);
            _solver.data()->setLowerBound(osqp_lower_);
            _solver.data()->setUpperBound(osqp_upper_);
            if (!_solver.initSolver()) {
                std::cerr << "[WBC] OSQP 初始化失败 (H 非正定/KKT 非凸?), 本帧不求解" << std::endl;
                _solver_initialized = false;
                return;
            }
            _solver_initialized = true;
            std::cout << "[OSQP] Initialized (n_var=" << n_var << ", n_con=" << n_con << ")" << std::endl;
        } else {
            _solver.updateHessianMatrix(H_sparse);
            _solver.updateGradient(osqp_gradient_);
            _solver.updateLinearConstraintsMatrix(A_sparse);
            _solver.updateBounds(osqp_lower_, osqp_upper_);
        }

        // 平动3+转动3+关节12+力矩12
        auto flag = _solver.solveProblem();
        Eigen::VectorXd solution = _solver.getSolution();
        task_vec = solution.head(30).cast<double>();

        // static int dbg = 0;
        // if (dbg++ % 100 == 0) {
        //     std::cout << "[WBC] contact: ";
        //     for (int c : contact_states_) std::cout << c << " ";
        //     std::cout << "| status=" << static_cast<int>(flag)
        //               << " | f_wbc Z: " << task_vec.segment<3>(18+2).transpose()  // FR z
        //               << " " << task_vec.segment<3>(18+5).transpose()             // RL z? no, FR is leg 1
        //               << std::endl;
        //     // FL_z=18+2=20? Let me fix: FL index 0 → col 18+0*3=18, f_z is col 20
        //     std::cout << "  FL f_z=" << task_vec(20)
        //               << " FR f_z=" << task_vec(23)
        //               << " RL f_z=" << task_vec(26)
        //               << " RR f_z=" << task_vec(29) << std::endl;
        // }

    }

    void WBC::GetSolution(SolutionVector& result){
        result = task_vec;
    }

    void WBC::GetForce(SolForce& f){
        f = task_vec.tail(12);
    }

    void WBC::GetAcc(SolAcc& a){
        a = task_vec.head(18);
        // a[3] = -a[3];
    }
} // namespace WBC
