#ifndef _MUJOCOSIM_HPP
#define _MUJOCOSIM_HPP

#include "mujoco/mujoco.h"
#include <GLFW/glfw3.h>
#include <string.h>
#include <iostream>
#include <Eigen/Dense>
#include "common.h"

namespace MJCSIM{


class SIM{
    public:
        SIM(std::string path): pathxml(path){}

        void InitMujoco();
        void InitViewer();
        void SimStart();
        void SimStop();
        void Step();
        void Render();
        void control(Eigen::VectorXd &tau, bool hip_enabled = false);
        void getModel(double &box_mass,double &stick_mass,double &stick_length);
        RobotState getState();

        // 物理步长: 控制循环的 dt 必须与之一致, 否则步态时钟与物理时间失配
        double getTimestep() const { return m->opt.timestep; }
        
        bool isMouseControlActive() const { return mouse_left || mouse_right; }
        double getMouseTargetPosition() const;

    private:
        mjModel* m;
        mjData* d;
        mjrContext* con = new mjrContext;
        GLFWwindow* window = nullptr;
        mjvOption opt;
        mjvScene scn;
        mjvCamera cam;
        std::string pathxml;

        double last_mouse_x = 0.0;
        double last_mouse_y = 0.0;
        bool mouse_left   = false;
        bool mouse_right  = false;
        bool mouse_middle = false;

        // 缓存 touch sensor ID，避免每帧 mj_name2id 字符串查找
        int  touch_id_[4] = {-1, -1, -1, -1};
        bool touch_id_cached_ = false;

        // Quaternion to Euler (roll, pitch, yaw) — ZYX intrinsic convention
        static Eigen::Vector3d quatToEuler(float qw, float qx, float qy, float qz);

        // GLFW callbacks
        static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
        static void cursorPosCallback(GLFWwindow* window, double xpos, double ypos);
        static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);
        static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
};

};





#endif