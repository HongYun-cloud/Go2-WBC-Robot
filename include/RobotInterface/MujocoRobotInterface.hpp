#ifndef __MUJOCO_ROBOT_INTERFACE_HPP
#define __MUJOCO_ROBOT_INTERFACE_HPP

#include "RobotInterface/RobotInterface.hpp"

namespace RobotInterface
{

/**
 * MuJoCo simulation backend implementation.
 * Wraps MJCSIM::SIM for simulation.
 */
class MujocoRobotInterface : public RobotInterface
{
public:
    explicit MujocoRobotInterface(const std::string& model_path, const std::string& urdf_path);

    void init() override;
    double getTimestep() const override;
    RobotState getState() override;
    void setCommand(const Eigen::VectorXd& tau) override;
    void step() override;
    void render() override;
    void reset() override;
    bool isRunning() const override;
    std::string getUrdfPath() const override;
    std::string getModelPath() const override;

private:
    class Impl;
    std::unique_ptr<Impl> impl_;
};




/**
 * Factory function to create a MuJoCo robot interface.
 */
RobotInterfacePtr createMujocoRobotInterface(const std::string& model_path, const std::string& urdf_path);

} // namespace RobotInterface

#endif // __MUJOCO_ROBOT_INTERFACE_HPP