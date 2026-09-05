#include "MPC/MPC.hpp"
#include <algorithm>

namespace DEBUG{
    void ErrorInfo(Regulator::Vec13d e){
        std::cout << "error of current and desire" ;
        std::cout << "\n Eular: " << e.segment(0,3).transpose()
                  << "\n Pos: " << e.segment(3,3).transpose() 
                  << "\n Angular: " << e.segment(6,3).transpose()
                  << "\n Velocity: "  << e.segment(9,3).transpose() << std::endl;

    }

    
}


namespace Regulator{
    
    void MPC::ConfigUpdata(){
        auto A = &controller->config->A;
        auto B = &controller->config->B;
        auto s = controller->data->leg;

        // 欧拉角速率: ė = T(φ,θ)·ω (ZYX 顺序, 状态 0..2 = roll, pitch, yaw)
        // 之前用 Eular2Rotation(q(2)) 拿 yaw 角构造 Rx —— 姿态通道被污染:
        // yaw 一旦漂移, roll/pitch 纠偏方向在模型里跟着旋转 → 倒向固定一侧
        // 截断 ±60°: T 含 tanθ, 倾倒到 90° 时 tan 爆炸 → 矩阵指数溢出 → H 含 Inf
        // (OSQP 报 "KKT matrix is not quasidefinite"); 超过 60° 机器人已倒, 截断不影响有效工作区
        double phi   = std::clamp(controller->data->est_state.q(0), -1.0472, 1.0472);
        double theta = std::clamp(controller->data->est_state.q(1), -1.0472, 1.0472);
        double cth = std::cos(theta);
        Mat3d T;
        T << 1.0, std::sin(phi) * std::tan(theta), std::cos(phi) * std::tan(theta),
             0.0, std::cos(phi),                  -std::sin(phi),
             0.0, std::sin(phi) / cth,             std::cos(phi) / cth;
        A->block<3,3>(0,6) = T;
        A->block<3,3>(3,9) = Mat3d::Identity();
        A->block<3,1>(9,12) = Vec3d{0,0,1};

        for (int i = 0; i < 4 ;i++){

            B->block<3,3>(6,i*3) = (params->I).inverse() * SkewSymmetric(s->p[i]);
            B->block<3,3>(9,i*3) = Mat3d::Identity() / params->mass;
        }


    }

    void MPC::loadConfig(const std::string& yaml_path){
        YAML::Node config = YAML::LoadFile(yaml_path);
        auto mpc = config["mpc"];

        // 读取标量参数
        if (mpc["N"])
            controller->config->N = mpc["N"].as<int>();
        if (mpc["dt"])
            controller->config->dt = mpc["dt"].as<double>();

        // 读取 Q (13 维对角向量, Mat13d)
        if (mpc["Q"] && mpc["Q"].size() == 13){
            controller->config->Q.setZero();
            for (int i = 0; i < 13; i++)
                controller->config->Q(i,i) = mpc["Q"][i].as<double>();
        }

        // 读取 R (12 维对角向量, Mat12d)
        if (mpc["R"] && mpc["R"].size() == 12){
            controller->config->R.setZero();
            for (int i = 0; i < 12; i++)
                controller->config->R(i,i) = mpc["R"][i].as<double>();
        }

        // 读取 P (13 维对角向量, Mat13d)
        if (mpc["P"] && mpc["P"].size() == 13){
            controller->config->P.setZero();
            for (int i = 0; i < 13; i++)
                controller->config->P(i,i) = mpc["P"][i].as<double>();
        }

        // std::cout << "R:" << controller->config->R << std::endl;
    }

    void MPC::solve(){
        int nu = 12;
        int N  = controller->config->N;
        int n_var = nu * N;
        int n_con = 5 * 4 * N;

        Eigen::SparseMatrix<double> H_sparse = controller->config->H.sparseView();
        Eigen::VectorXd gradient = 2 * (controller->config->E.transpose() * controller->data->state).cast<double>();

        // 姿态角过大时矩阵指数可能溢出 (H/gradient 含 Inf) → 跳过本帧求解, 沿用上一帧控制
        // (机器人已倾倒, MPC 输出无意义; OSQP 对非有限数据会拒绝更新并报错刷屏)
        if (!controller->config->H.allFinite() || !gradient.allFinite())
            return;

        // 展开 contact_states: 4 -> 4*N
        // 优先用外部滚动预测 (按步态相位, 接触切换点可被预测到);
        // 未设置时回退到旧行为: 当前接触复制到所有预测步 (切换点附近模型错误)
        std::vector<int> contact_expanded(N * 4, 1);
        
        if (contact_sched_.size() == (size_t)(N * 4)) {
            contact_expanded = contact_sched_;
        } else {
            auto& cs = controller->data->est_state.contact_states;
            if (cs.size() >= 4) {
                for (int j = 0; j < N; j++)
                    for (int i = 0; i < 4; i++)
                        contact_expanded[j * 4 + i] = cs[i];
            }
        }
        // DEBUG 全接触查看期望位置加速度波形
        // std::fill(contact_expanded.begin(), contact_expanded.end(), 1);
        
        _qpconstraint->updateConstraints(contact_expanded);
        Eigen::SparseMatrix<double> A_sparse = _qpconstraint->A_constraint.sparseView();
        // 注意: OsqpEigen 存裸指针, 必须用持久对象而非局部变量
        Eigen::VectorXd& boundL = _qpconstraint->L_constraint;
        Eigen::VectorXd& boundU = _qpconstraint->U_constraint;

        A_sparse.makeCompressed();
        H_sparse.makeCompressed();

        // // ===== DEBUG: 打印OSQP输入参数 =====
        // std::cout << "\n========== OSQP SOLVE ==========" << std::endl;
        // std::cout << "[Gradient q] first 12 (head): " << gradient.head(12).transpose() << std::endl;
        // std::cout << "[Gradient q] max_abs: " << gradient.lpNorm<Eigen::Infinity>() << std::endl;
        // std::cout << "[State error] " << controller->data->state.transpose() << std::endl;
        // std::cout << "[H diag] first 12: ";
        // for (int i = 0; i < 12; i++)
        //     std::cout << controller->config->H(i,i) << " ";
        // std::cout << std::endl;
        // std::cout << "[Constraint L] first 5: " << boundL.head(5).transpose() << std::endl;
        // std::cout << "[Constraint U] first 5: " << boundU.head(5).transpose() << std::endl;
        // std::cout << "[contact_states] size=" << controller->data->est_state.contact_states.size() << ": ";
        // for (auto c : controller->data->est_state.contact_states) std::cout << c << " ";
        // std::cout << std::endl;

        if (!_solver_initialized) {
            _solver.settings()->setVerbosity(false);
            _solver.data()->setNumberOfVariables(n_var);
            _solver.data()->setNumberOfConstraints(n_con);
            _solver.data()->setHessianMatrix(H_sparse);
            _solver.data()->setGradient(gradient);
            _solver.data()->setLinearConstraintsMatrix(A_sparse);
            _solver.data()->setLowerBound(boundL);
            _solver.data()->setUpperBound(boundU);
            _solver.initSolver();
            _solver_initialized = true;
            std::cout << "[OSQP] Initialized (n_var=" << n_var << ", n_con=" << n_con << ")" << std::endl;
        } else {
            _solver.updateHessianMatrix(H_sparse);
            _solver.updateGradient(gradient);
            _solver.updateLinearConstraintsMatrix(A_sparse);
            _solver.updateBounds(boundL, boundU);
        }

        _solver.solveProblem();
        Eigen::VectorXd optimalU = _solver.getSolution();
        controller->data->control = optimalU.head(12).cast<double>();
        // std::cout << "[OSQP] optimalU head(12): " << controller->data->control.transpose() << std::endl;
        // std::cout << "================================\n" << std::endl;
    }

    void MPC::update_DesireStateCommand(Vec3d q,Vec3d p,Vec3d v,Vec3d w){
        controller->data->state_Cmd.q = q;
        controller->data->state_Cmd.p = p;
        controller->data->state_Cmd.v = v;
        controller->data->state_Cmd.w = w;
        
    }

    void MPC::update_reference_trajectory(){
        Vec13d d; // 期望状态
        auto c = controller->data->state_Cmd; // 命令
        auto e = controller->data->est_state; 
        double dt = controller->config->dt;
        
        d.setZero();

        // d(0) = e.q(0);
        // d(1) = e.q(1);
        // d(2) = e.q(2);

        // d(3) = e.p(0) + c.v(0) * dt;
        // d(4) = e.p(1) + c.v(0) * dt;
        // d(5) = 0.25 + c.v(0) * dt;

        // d(6) = c.w(0);
        // d(7) = c.w(1);
        // d(8) = c.w(2);

        // d(9)  = c.v(0);
        // d(10) = c.v(1);
        // d(11) = c.v(2);
        d(12) = 9.81;

        d(0) = c.q(0);
        d(1) = c.q(1);
        d(2) = c.q(2);

        // 期望位置: x/y 锚定当前估计位置 (MIT 式), 不积分奔跑参考
        // 若参考位置按 v 积分无脑前进, 机器人起步慢 → 位置误差累积 → MPC 猛推 →
        // 追过头 → 反向急刹 → 前后振荡摔倒。让前进只由速度误差驱动即可避免。
        d(3) = e.p(0);
        d(4) = e.p(1);
        d(5) = c.p(2);  // 高度保持命令值

        d(6) = c.w(0);
        d(7) = c.w(1);
        d(8) = c.w(2);

        d(9)  = c.v(0);
        d(10) = c.v(1);
        d(11) = c.v(2);
        controller->data->desireState = d;
    }   

    void MPC::update(){
        controller->data->est_state = estimator->get_estresult();

        update_reference_trajectory();
        auto s = controller->data->est_state;

        Vec13d cur_state;
        cur_state << s.q, s.p, s.w, s.v, 0;
        // 当前和目标的误差
        controller->data->state =  (cur_state - controller->data->desireState);
        // ErrorInfo(controller->data->state);
        // DEBUG::ErrorInfo(cur_state);
        // ErrorInfo(controller->data->desireState);
        // std::cout << "error_state " << controller->data->state << std::endl;

        ConfigUpdata();
        compuseEGH();



    }

    void MPC::run(){
        solve();

    }

    Vec12d MPC::getControl(){
        return controller->data->control;
    }

    void MPC::setModelParams(double mass, const Eigen::Matrix3d& I_com){
        params->mass = mass;
        params->I = I_com;
    }

    void MPC::setContactSchedule(const std::vector<int>& sched){
        contact_sched_ = sched;
    }

    void MPC::compuseEGH(){
        double dt = controller->config->dt;
        Mat13d A = controller->config->A;
        Mat132d B = controller->config->B;
        Mat13d Ad;
        Mat132d Bd;
        int N = controller->config->N;
        int nx = A.rows();
        int nu = B.cols();

        Eigen::MatrixXd K =
        Eigen::MatrixXd::Zero(
            nx+nu,
            nx+nu);

        K.block(0,0,nx,nx) = A;
        K.block(0,nx,nx,nu) = B;

        
        Eigen::MatrixXd Md =(K * dt).exp();
        Ad = Md.block(
                0,0,
                nx,nx);

        Bd = Md.block(
                0,nx,
                nx,nu);
        const int r = nx * (N+1);
        const int c = nu * N;

        Eigen::MatrixXd M(r,nx);
        Eigen::MatrixXd C(r,c);
        M.block(0,0,nx,nx) = Eigen::MatrixXd::Identity(nx,nx);
        Eigen::MatrixXd powA = Ad;
        for (int i = 1;i <= N;i++){
            M.block(nx*i,0,nx,nx) = powA;
            powA = powA * Ad;
        }
        

        C.setZero();
        for(int row = 1; row <= N; row++)           
        {
            for(int col = 0; col < row; col++)    
            {
                Eigen::MatrixXd Apow =
                    Eigen::MatrixXd::Identity(nx, nx);

                for(int k = 0; k < row - 1 - col; k++) 
                    Apow = Apow * Ad;

                C.block(row*nx, col*nu, nx, nu) = Apow * Bd;
            }
        }

        // Q_hat: 块对角 — 中间阶段用 Q, 终端用 P
        Eigen::MatrixXd Q_hat = Eigen::MatrixXd::Zero(r, r);
        for (int i = 0; i < N; i++)
            Q_hat.block(i*nx, i*nx, nx, nx) = controller->config->Q;
        Q_hat.block(N*nx, N*nx, nx, nx) = controller->config->P;
        
        Eigen::MatrixXd R_hat = Eigen::MatrixXd::Zero(nu*N, nu*N);
        for(int i=0; i<N; i++)
        {
            R_hat.block(
                i*nu,
                i*nu,
                nu,
                nu
            ) = controller->config->R;
        }

        Eigen::MatrixXd G(r,nx);
        Eigen::MatrixXd E(r,c);
        Eigen::MatrixXd H(nu*N,nu*N);

        G = M.transpose() * Q_hat * M;
        E = M.transpose() * Q_hat * C;
        H = C.transpose() * Q_hat * C + R_hat;
        H = 0.5 * (H + H.transpose());  // 强制对称，消除数值误差


        controller->config->E = E;
        controller->config->G = G;
        controller->config->H = H;
    }

    
};  // namespace Regulator