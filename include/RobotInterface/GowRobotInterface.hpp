#ifndef __GOW_ROBOT_INTERFACE_HPP
#define __GOW_ROBOT_INTERFACE_HPP

#include "RobotInterface/RobotInterface.hpp"

namespace RobotInterface
{


class GowRobotInterface : public RobotInterface
{
    public:
    explicit GowRobotInterface(const std::string& model_path, const std::string& urdf_path);

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


RobotInterfacePtr createGowRobotInterface(const std::string& model_path, const std::string& urdf_path);

}
#endif