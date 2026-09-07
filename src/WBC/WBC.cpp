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

        // 读取 C (12 维对角向量 → 12×12)
        if (wbc["C"] && wbc["C"].size() == 12) {
            config->C.setZero();
            for (int i = 0; i < 12; i++)
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
        contact_num = 0;
        
        for (int leg = 0; leg < 4; leg++) {
            if (state.contact_states[leg] == 1) continue;  // 支撑腿跳过

            // 浮动基座摆动腿雅可比 (3×18)
            Eigen::Matrix<double, 3, 18> J  = _pin->getFootJacobianFloatingBase(leg);
            Eigen::Matrix<double, 3, 18> dJ = _pin->getFootJacobianTimeVariationFloatingBase(leg);

            // A_a: 前18维的摆动腿J
            config->A_a.block<3, 18>(contact_num * 3, 0) = J;
            // b_a: 摆动腿加速度跟踪 a_d - d（J*q）
            config->b_a.segment<3>(contact_num * 3) = cmd.a_d.segment<3>(leg * 3) - dJ * v_full_;
            contact_num++;
        }

        updateconstraint();
        compuseHg();
    }

    void WBC::updateconstraint(){
        // 腿级硬约束: 支撑腿接触 / 摆动腿力为零
        // 决策变量 x = [a(18); f(12)] (30维)

        qpconstraint->A.setZero();
        qpconstraint->lower.setZero();
        qpconstraint->upper.setZero();
        _pin->computeFloatingBaseDynamics();
        Mat18d M = _pin->getMassMatrix();
        auto h = _pin->getBiasForces(); 
        Eigen::Matrix<double, 12, 18> Jc;
        
        for (int leg = 0; leg < 4; leg++) {
            Eigen::Matrix<double, 3, 18> J  = _pin->getFootJacobianFloatingBase(leg);
            Jc.block<3,18>(leg * 3,0) = J;
        }
        // 第一个 等式约束 动力学方程
        {
        Eigen::Matrix<double, 6, 30> A_dyn;
        Eigen::Matrix<double, 6, 1> b_dyn;
        A_dyn.block<6, 18>(0, 0)  = M.topRows<6>();               // 前 18 列
        A_dyn.block<6, 12>(0, 18) = -Jc.leftCols<6>().transpose();    // Jc的前6列
        b_dyn = -h.head(6);
        qpconstraint->A.block<6, 30>(0, 0) = A_dyn;
        qpconstraint->lower.segment<6>(0) = b_dyn;
        qpconstraint->upper.segment<6>(0) = b_dyn;
        }
        
        
        for (int leg = 0; leg < 4; leg++) {
            int row = 18 + leg * 3;
            int col_f = 18 + leg * 3;
            // 第二个 等式约束 接触足端无滑动
            if (contact_states_[leg] == 1) {
                // 支撑腿: J_leg * a = -dJ_leg * v  (足端无滑动)
                Eigen::Matrix<double, 3, 18> J  = _pin->getFootJacobianFloatingBase(leg);
                Eigen::Matrix<double, 3, 18> dJ = _pin->getFootJacobianTimeVariationFloatingBase(leg);
                qpconstraint->A.block<3, 18>(row, 0) = J;
                Eigen::Vector3d rhs = -dJ * v_full_;
                qpconstraint->lower.segment<3>(row) = rhs;
                qpconstraint->upper.segment<3>(row) = rhs;
            } else {
                // 第三个 等式约束 摆动腿: f_leg = 0  (无地面接触力)
                qpconstraint->A.block<3, 3>(row, col_f).setIdentity();
                qpconstraint->lower.segment<3>(row).setZero();
                qpconstraint->upper.segment<3>(row).setZero();
            }  
        }

        // 第四个 不等式约束 摩擦锥约束 (行 30-49, 4腿×5行): 支撑腿 |fx|,|fy| ≤ μ·fz 且 fz ∈ [0, fz_max] ----
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

        // 第五个 不等式约束 力上限约束


        
    }
    
    void WBC::compuseHg(){
        Mat30d H;
        Vec30d g;

        Mat30d H1 = config->A_q.transpose() * config->W  * config->A_q;
        Mat30d H2 = config->A_f.transpose() * config->FI * config->A_f;
        Mat30d H3 = config->A_a.transpose() * config->C  * config->A_a;

        Vec30d g1 = config->A_q.transpose() * config->W  * config->b_q;
        Vec30d g2 = config->A_f.transpose() * config->FI * config->b_f;
        Vec30d g3 = config->A_a.transpose() * config->C  * config->b_a;

        // if (contact_num > 0) {
        //     auto A_valid = config->A_a.topRows(row * 3); // 比如只有 2 条腿摆动，只取前 6 行
        //     auto b_valid = config->b_a.head(row * 3);
        //     auto C_valid = config->C.block(0, 0, row * 3, row * 3);

        //     H3 = A_valid.transpose() * C_valid * A_valid;
        //     g3 = A_valid.transpose() * C_valid * b_valid;
        // } else {
        //     // 4 条腿全站立，没有摆动腿任务
        //     H3.setZero();
        //     g3.setZero();
        // }
        

        H = H1 + H2 + H3;
        g = g1 + g2 + g3;
        // double lambda = 1e-6;
        // H.diagonal().array() += lambda;


        // H = H1;
        // g = g1;
        H.diagonal().segment<6>(0).array()   += 1e-4; // Base 加速度
        H.diagonal().segment<12>(6).array()  += 1e-4; // 12 关节加速度 (防止关节狂甩)
        H.diagonal().segment<12>(18).array() += 1e-3; // 12 接触力 (防止足端内力对抗)
        

        config->H= 2 * H;
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
            // solver.setVariableBounds(x_min, x_max);
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
