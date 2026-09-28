#ifndef __CONTROLLER_BASE_HPP
#define __CONTROLLER_BASE_HPP

#include "common.h"
#include "RobotInterface/RobotInterface.hpp"
#include <memory>
#include <string>

namespace Controller
{

struct ControllerConfig
{
    std::string control_config_path;  // Path to control.yaml
    std::string urdf_path;            // Path to URDF for Pinocchio
    double control_frequency = 500.0;
    double desired_height = 0.25;
    std::string initial_gait = "TROT";
    double touchdown_force = 5.0;
    double airborne_hold_ratio = 0.5;
    double max_cmd_vel = 0.05;
};

/**
 * Abstract interface for locomotion controllers.
 * 
 * Concrete implementations:
 *   - TraditionalController: MPC + WBC (current implementation)
 *   - RLController: ONNX policy inference
 * 
 * The controller receives:
 *   - Robot state from RobotInterface
 *   - Velocity commands from /cmd_vel
 *   - Configuration parameters
 * 
 * The controller produces:
 *   - Joint torques to send to RobotInterface
 *   - Optional telemetry/debug data
 */
class ControllerBase
{
public:
    virtual ~ControllerBase() = default;

    /**
     * Initialize the controller with configuration.
     * Must be called before first update().
     */
    virtual void init(const ControllerConfig& config, RobotInterface::RobotInterfacePtr robot) = 0;

    /**
     * Main control update loop.
     * Called at control_frequency (e.g., 500Hz).
     * 
     * @param state Current robot state from RobotInterface
     * @param cmd_vel Desired velocity command (vx, vy, wz)
     * @return Joint torques (12-DOF) to apply
     */
    virtual Eigen::VectorXd update(const RobotState& state, const Eigen::Vector3d& cmd_vel) = 0;

    /**
     * Reset the controller to initial state.
     */
    virtual void reset() = 0;

    /**
     * Set velocity command (called from /cmd_vel callback).
     */
    virtual void setCmdVel(const Eigen::Vector3d& cmd_vel) = 0;

    /**
     * Get controller name for logging/telemetry.
     */
    virtual std::string getName() const = 0;

    /**
     * Check if controller is initialized and ready.
     */
    virtual bool isReady() const = 0;
};

using ControllerPtr = std::shared_ptr<ControllerBase>;

} // namespace Controller

#endif // __CONTROLLER_BASE_HPP