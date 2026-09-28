#include "RobotInterface/MujocoRobotInterface.hpp"
#include "SIM/MJCsim.hpp"
#include <memory>

namespace RobotInterface
{

class MujocoRobotInterface::Impl
{
public:
    explicit Impl(const std::string& model_path, const std::string& urdf_path)
        : sim_(std::make_unique<MJCSIM::SIM>(model_path)),
          urdf_path_(urdf_path),
          model_path_(model_path)
    {}

    void init() { sim_->InitMujoco(); }
    double getTimestep() const { return sim_->getTimestep(); }
    RobotState getState() { return sim_->getState(); }
    void setCommand(const Eigen::VectorXd& tau) { sim_->control(tau); }
    void step() { sim_->Step(); }
    void render() { sim_->Render(); }
    void reset() { sim_->SimStop(); sim_->InitMujoco(); }
    bool isRunning() const { return true; }
    std::string getUrdfPath() const { return urdf_path_; }
    std::string getModelPath() const { return model_path_; }

private:
    std::unique_ptr<MJCSIM::SIM> sim_;
    std::string urdf_path_;
    std::string model_path_;
};

MujocoRobotInterface::MujocoRobotInterface(const std::string& model_path, const std::string& urdf_path)
    : impl_(std::make_unique<Impl>(model_path, urdf_path))
{}

void MujocoRobotInterface::init() { impl_->init(); }
double MujocoRobotInterface::getTimestep() const { return impl_->getTimestep(); }
RobotState MujocoRobotInterface::getState() { return impl_->getState(); }
void MujocoRobotInterface::setCommand(const Eigen::VectorXd& tau) { impl_->setCommand(tau); }
void MujocoRobotInterface::step() { impl_->step(); }
void MujocoRobotInterface::render() { impl_->render(); }
void MujocoRobotInterface::reset() { impl_->reset(); }
bool MujocoRobotInterface::isRunning() const { return impl_->isRunning(); }
std::string MujocoRobotInterface::getUrdfPath() const { return impl_->getUrdfPath(); }
std::string MujocoRobotInterface::getModelPath() const { return impl_->getModelPath(); }

RobotInterfacePtr createMujocoRobotInterface(const std::string& model_path, const std::string& urdf_path)
{
    return std::make_shared<MujocoRobotInterface>(model_path, urdf_path);
}

} // namespace RobotInterface