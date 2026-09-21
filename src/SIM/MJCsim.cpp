#include "SIM/MJCsim.hpp"
#include <cmath>


void MJCSIM::SIM::InitMujoco(){
    char error[1000];
    m = mj_loadXML(pathxml.c_str(), nullptr, error, 1000);
    if (!m) {
        std::cout << "Load error: " << error << std::endl;
        return ;
    }
    d = mj_makeData(m);
    mj_resetDataKeyframe(m, d, 0);  // stand_pose
    // 仿真时间步长 (0.002s = 500步/秒)
    // 12kg 四足的接触动力学需要小步长, 0.01 会导致落地弹跳偏软
    // 调大提速: 0.005=200步/秒, 0.01=100步/秒 (main 的 sim_dt 会自动跟随)
    // 注意不能调到 0.0002 量级: 控制循环单拍要跑完 WBC QP + 渲染 (~1ms),
    // 步长 0.0002 时每拍预算只有 0.2ms, 仿真时间追不上墙钟 → 慢动作
    m->opt.timestep = 0.002;
    mj_forward(m, d);

    SimStart();
    InitViewer();
}

void MJCSIM::SIM::InitViewer(){

    // ===== 1. scene / camera / option =====
    mjv_defaultCamera(&cam);
    mjv_defaultOption(&opt);
    mjv_defaultScene(&scn);

    // ===== 2. 开启可视化选项 =====
    // opt.flags[mjVIS_CONTACTPOINT] = 1;
    // opt.flags[mjVIS_CONTACTFORCE] = 1;
    // opt.flags[mjVIS_COM] = 1;
    // opt.flags[mjVIS_JOINT] = 1;
    // opt.flags[mjVIS_ACTUATOR] = 1;
    // opt.flags[mjVIS_CONSTRAINT] = 1;
    // opt.flags[mjVIS_CONVEXHULL] = 0; // 关闭不必要的辅助线

    // ===== 3. 创建 scene =====
    mjv_makeScene(m, &scn, 2000);

    // ===== 4. 创建 OpenGL context =====
    mjr_defaultContext(con);
    mjr_makeContext(m, con, mjFONTSCALE_150);

    std::cout << "Viewer initialized" << std::endl;
}

void MJCSIM::SIM::Step(){
    mj_step(m, d);
};

void MJCSIM::SIM::Render(){
    // 渲染按墙钟节流到 ~60Hz: 控制循环 500Hz, 每拍都 updateScene+mjr_render+SwapBuffers
    // 会吃掉实时预算 (渲染路径 ~ms 级, 500 拍/秒远超显示需要)。窗口事件每拍照常
    // 轮询, 鼠标/键盘交互不受影响。
    auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(now - last_render_).count() < 1.0 / 60.0) {
        glfwPollEvents();
        return;
    }
    last_render_ = now;

    mjv_updateScene(m, d, &opt, NULL, &cam,mjCAT_ALL, &scn);
    mjrRect viewport = {0, 0, 1200, 900};
    mjr_render(viewport, &scn, con);

    glfwSwapBuffers(window);
    glfwPollEvents();
};

/**
 * 写入关节力矩到 MuJoCo ctrl
 * @param tau  关节力矩向量
 * @param hip_enabled  false=8 维 (仅 thigh+calf), true=12 维 (含 hip, 但 hip 力矩被忽略)
 *
 * Pinocchio 8 维顺序: FL_thigh, FL_calf, FR_thigh, FR_calf, RL_thigh, RL_calf, RR_thigh, RR_calf
 * Pinocchio 12 维顺序: FL_hip,FL_thigh,FL_calf, FR_hip,FR_thigh,FR_calf, RL_hip,RL_thigh,RL_calf, RR_hip,RR_thigh,RR_calf
 * MuJoCo actuator 顺序: FL_calf, FL_thigh, RR_calf, RR_thigh, RL_calf, RL_thigh, FR_calf, FR_thigh
 */
void MJCSIM::SIM::control(Eigen::VectorXd &tau, bool hip_enabled){

    double flh = 0, flt = 0, flc = 0,frh = 0, frt = 0, frc = 0;
    double rlh = 0, rlt = 0, rlc = 0,rrh = 0, rrt = 0, rrc = 0;

    flh = tau(0); flt = tau(1);  flc = tau(2);    // FL
    frh = tau(3); frt= tau(4);   frc= tau(5);    // FR
    rlh = tau(6); rlt= tau(7);   rlc= tau(8);    // RL
    rrh = tau(9); rrt= tau(10);  rrc= tau(11);   // RR
    d->ctrl[0] = flh;  d->ctrl[1] = flt;   d->ctrl[2] = flc;
    d->ctrl[3] = frh;  d->ctrl[4] = frt;   d->ctrl[5] = frc;
    d->ctrl[6] = rlh;  d->ctrl[7] = rlt;   d->ctrl[8] = rlc;
    d->ctrl[9] = rrh;  d->ctrl[10] = rrt;  d->ctrl[11] = rrc;


    //     flt = tau(0);  flc = tau(1);    // FL
    //     frt= tau(2);  frc= tau(3);    // FR
    //     rlt= tau(4);  rlc= tau(5);    // RL
    //     rrt= tau(6);  rrc= tau(7);    // RR
    //     d->ctrl[1] = flt;   d->ctrl[0] = flc;
    //     d->ctrl[7] = frt;  d->ctrl[6] = frc;
    //     d->ctrl[5] = rlt;  d->ctrl[4] = rlc;
    //     d->ctrl[3] = rrt;  d->ctrl[2] = rrc;
 

   
}



void MJCSIM::SIM::SimStart(){

    // ===== GLFW  =====
    if (!window) {
        glfwInit();
        window = glfwCreateWindow(1200, 900, "MuJoCo", NULL, NULL);
        glfwMakeContextCurrent(window);
        // 关闭垂直同步: GLX 默认 swap interval=1, 每次 SwapBuffers 阻塞等 vblank
        // (~16.7ms @60Hz), 500Hz 控制循环会被压到 60Hz → 仿真慢动作 (实测 RTF≈0.12)
        glfwSwapInterval(0);

        // Register mouse + scroll + keyboard callbacks
        glfwSetWindowUserPointer(window, this);
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSetCursorPosCallback(window, cursorPosCallback);
        glfwSetScrollCallback(window, scrollCallback);
        glfwSetKeyCallback(window, keyCallback);

    }
}

// ====================== Mouse / Camera Callbacks ======================


void MJCSIM::SIM::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods){
    SIM* sim = static_cast<SIM*>(glfwGetWindowUserPointer(window));
    if (!sim) return;

    bool pressed = (action == GLFW_PRESS);

    if (button == GLFW_MOUSE_BUTTON_LEFT)
        sim->mouse_left   = pressed;
    else if (button == GLFW_MOUSE_BUTTON_RIGHT)
        sim->mouse_right  = pressed;
    else if (button == GLFW_MOUSE_BUTTON_MIDDLE)
        sim->mouse_middle = pressed;


    if (pressed) {
        glfwGetCursorPos(window, &sim->last_mouse_x, &sim->last_mouse_y);
    }
}


void MJCSIM::SIM::cursorPosCallback(GLFWwindow* window, double xpos, double ypos){
    SIM* sim = static_cast<SIM*>(glfwGetWindowUserPointer(window));
    if (!sim) return;

    double dx = xpos - sim->last_mouse_x;
    double dy = ypos - sim->last_mouse_y;


    if (sim->mouse_left) {
        sim->cam.azimuth   -= dx * 0.3;
        sim->cam.elevation -= dy * 0.3;

        if (sim->cam.elevation >  89.0) sim->cam.elevation =  89.0;
        if (sim->cam.elevation < -89.0) sim->cam.elevation = -89.0;
    }


    if (sim->mouse_right) {
        double az = sim->cam.azimuth   * M_PI / 180.0;
        double el = sim->cam.elevation * M_PI / 180.0;


        double rx =  std::sin(az);                  
        double ry = -std::cos(az);
        double rz =  0.0;

        double ux = -std::sin(el) * std::cos(az);    
        double uy = -std::sin(el) * std::sin(az);
        double uz =  std::cos(el);

        double pan_scale = sim->cam.distance * 0.0006;

        sim->cam.lookat[0] += (-rx * dx + ux * dy) * pan_scale;
        sim->cam.lookat[1] += (-ry * dx + uy * dy) * pan_scale;
        sim->cam.lookat[2] += (-rz * dx + uz * dy) * pan_scale;
    }

    sim->last_mouse_x = xpos;
    sim->last_mouse_y = ypos;
}

void MJCSIM::SIM::scrollCallback(GLFWwindow* window, double xoffset, double yoffset){
    SIM* sim = static_cast<SIM*>(glfwGetWindowUserPointer(window));
    if (!sim) return;

    // yoffset > 0 → scroll up → zoom in (shorter distance)
    sim->cam.distance *= (1.0 - yoffset * 0.08);
    // Clamp to reasonable range
    if (sim->cam.distance <  0.05) sim->cam.distance =  0.05;
    if (sim->cam.distance > 50.0)  sim->cam.distance = 50.0;
}

void MJCSIM::SIM::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods){
    SIM* sim = static_cast<SIM*>(glfwGetWindowUserPointer(window));
    if (!sim) return;

    if (action == GLFW_PRESS && key == GLFW_KEY_R) {
        mj_resetDataKeyframe(sim->m, sim->d, 0);
        std::cout << "[Sim] Reset to keyframe 0 (stand_pose)" << std::endl;
    }
}

double MJCSIM::SIM::getMouseTargetPosition() const {
    double normalized = last_mouse_x / 1200.0;
    return (1.0 - normalized) * 2.0 - 1.0;
}

void MJCSIM::SIM::SimStop(){
    mj_deleteData(d);
    mj_deleteModel(m);
    glfwDestroyWindow(window);
    glfwTerminate();
    mjr_freeContext(con);
    delete con;
}

void MJCSIM::SIM::getModel(double &box_mass,double &stick_mass,double &stick_length){
    int box_id = mj_name2id(m, mjOBJ_BODY, "cart");
    int stcik_id = mj_name2id(m,mjOBJ_BODY, "pole");

    box_mass = m->body_mass[box_id];
    stick_mass = m->body_mass[stcik_id];
    stick_length = 0.3;

}

RobotState MJCSIM::SIM::getState(){
    RobotState s;

    // MuJoCo free joint qpos: [x, y, z, qw, qx, qy, qz]
    // 机身位置
    s.position = Eigen::Vector3d(d->qpos[0], d->qpos[1], d->qpos[2]);

    // 机身姿态: 四元数 → 欧拉角 (roll, pitch, yaw)
    s.euler = quatToEuler(d->qpos[3], d->qpos[4], d->qpos[5], d->qpos[6]);
    s.quat  = Eigen::Quaterniond{d->qpos[3], d->qpos[4], d->qpos[5], d->qpos[6]};
    // MuJoCo free joint qvel: [vx, vy, vz, wx, wy, wz]
    s.linear_vel  = Eigen::Vector3d(d->qvel[0], d->qvel[1], d->qvel[2]);
    s.angular_vel = Eigen::Vector3d(d->qvel[3], d->qvel[4], d->qvel[5]);

    // 关节角度和速度 (12 个关节, qpos[7..14], qvel[6..13])
    // 顺序: FL_thigh, FL_calf, FR_thigh, FR_calf, RL_thigh, RL_calf, RR_thigh, RR_calf
    for (int i = 0; i < 12; i++) {
        s.joint_positions(i) = d->qpos[7 + i];
        s.joint_velocities(i) = d->qvel[6 + i];
    }

    // 足端接触力 (4 条腿: FL, FR, RL, RR)
    // 不用 MuJoCo 的 <touch> sensor: 3.9.0 里 mjSENS_TOUCH 是空壳 —— XML 能解析、
    // sensor dim 也是 1, 但读数恒为 0 (实测: 盒子的 site 就压在接触点上依然读到 0,
    // 同一时刻 mj_contactForce 给出 19.6 N)。所以直接从 d->contact 取足端碰撞球的法向力。
    if (!foot_geom_id_cached_) {
        const char* names[4] = {"FL", "FR", "RL", "RR"};
        for (int i = 0; i < 4; i++) {
            foot_geom_id_[i] = mj_name2id(m, mjOBJ_GEOM, names[i]);
            if (foot_geom_id_[i] < 0)
                std::cout << "[MJCsim] 警告: 模型里没有 geom \"" << names[i]
                          << "\", 该腿触地检测失效 (按悬空处理)" << std::endl;
        }
        foot_geom_id_cached_ = true;
    }

    s.foot_forces.setZero();
    for (int ci = 0; ci < (int)d->ncon; ci++) {
        const mjContact& con = d->contact[ci];
        for (int leg = 0; leg < 4; leg++) {
            if (foot_geom_id_[leg] < 0) continue;
            if (con.geom1 != foot_geom_id_[leg] && con.geom2 != foot_geom_id_[leg])
                continue;
            double f[6];                       // 接触系 6 维力: f[0]=法向, f[1..5]=切向/扭矩
            mj_contactForce(m, d, ci, f);
            if (f[0] > 0.0) s.foot_forces(leg) += f[0];   // 负值=吸附, 不计入触地
        }
    }

    // 接触状态只表示"几何上有接触"(力 > 0); 真正的触地判定在 FSM 里按阈值做,
    // 阈值属于控制策略, 不该埋在仿真里
    s.contact_states.resize(4);
    for (int i = 0; i < 4; i++)
        s.contact_states[i] = (s.foot_forces(i) > 0.0) ? 1 : 0;
    // s.angular_vel.setZero(); 
    return s;
}

// 四元数 → 欧拉角 (ZYX 内旋 = yaw-pitch-roll)
// q = [qw, qx, qy, qz] — MuJoCo 标准格式
Eigen::Vector3d MJCSIM::SIM::quatToEuler(float qw, float qx, float qy, float qz){
    Eigen::Vector3d euler;

    // roll  = atan2( 2*(qw*qx + qy*qz), 1 - 2*(qx² + qy²) )
    euler(0) = std::atan2(2.0 * (qw * qx + qy * qz),
                          1.0f - 2.0f * (qx * qx + qy * qy));

    // pitch = asin( 2*(qw*qy - qz*qx) )
    euler(1) = std::asin(2.0f * (qw * qy - qz * qx));

    // yaw   = atan2( 2*(qw*qz + qx*qy), 1 - 2*(qy² + qz²) )
    euler(2) = std::atan2(2.0f * (qw * qz + qx * qy),
                          1.0f - 2.0f * (qy * qy + qz * qz));

    return euler;
}


