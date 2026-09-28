#ifndef __ROBOT_INTERFACE_HPP
#define __ROBOT_INTERFACE_HPP

#include "common.h"
#include <memory>
#include <string>

namespace RobotInterface
{

/**
 * Abstract interface for robot hardware / simulation backends.
 * 
 * Concrete implementations:
 *   - MujocoRobotInterface: wraps MJCSIM::SIM (current sim)
 *   - UnitreeRobotInterface: wraps Unitree Go2 SDK (real hardware)
 * 
 * The control node uses this interface to:
 *   - Initialize the backend
 *   - Get robot state (position, velocity, joint states, contact forces)
 *   - Send joint torque commands
 *   - Step simulation (for sim) or communicate with hardware
 *   - Render (for sim with viewer)
 */
class RobotInterface
{
public:
    virtual ~RobotInterface() = default;

    /**
     * Initialize the robot backend.
     * For sim: loads MuJoCo model, creates viewer.
     * For hardware: connects to Unitree SDK, calibrates.
     */
    virtual void init() = 0;

    /**
     * Get the control timestep (simulation step or hardware control cycle).
     * The main control loop must run at this frequency.
     */
    virtual double getTimestep() const = 0;

    /**
     * Get current robot state from sim/hardware.
     * Populates all fields of RobotState.
     */
    virtual RobotState getState() = 0;

    /**
     * Send joint torques to the robot.
     * @param tau 12-DOF joint torques in order: FL_hip, FL_thigh, FL_calf, FR_hip, FR_thigh, FR_calf, RL_hip, RL_thigh, RL_calf, RR_hip, RR_thigh, RR_calf
     */
    virtual void setCommand(const Eigen::VectorXd& tau) = 0;

    /**
     * Step the simulation forward by one timestep.
     * For hardware: sends commands and waits for next cycle.
     * For sim: calls mj_step.
     */
    virtual void step() = 0;

    /**
     * Render the simulation (if applicable).
     * For hardware: no-op or update visualization.
     */
    virtual void render() = 0;

    /**
     * Reset the robot to initial state.
     */
    virtual void reset() = 0;

    /**
     * Check if the backend is running/connected.
     */
    virtual bool isRunning() const = 0;

    /**
     * Get the path to the URDF/model file for Pinocchio.
     */
    virtual std::string getUrdfPath() const = 0;

    /**
     * Get the path to the MuJoCo XML (for sim) or config (for hardware).
     */
    virtual std::string getModelPath() const = 0;
};

using RobotInterfacePtr = std::shared_ptr<RobotInterface>;

} // namespace RobotInterface

#endif // __ROBOT_INTERFACE_HPP