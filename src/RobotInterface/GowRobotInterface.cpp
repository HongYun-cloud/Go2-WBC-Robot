#include "RobotInterface/GowRobotInterface.hpp"
#include "Hardware/GowManager.hpp"
#include "SIM/MJCsim.hpp"
#include <memory>


namespace RobotInterface
{

class GowRobotInterface::Impl
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
    std::unique_ptr<Hardware::Manager> manager;   
    std::unique_ptr<MJCSIM::SIM> sim_; 
    std::string urdf_path_;
    std::string model_path_;
};

void GowRobotInterface::init() { impl_->init(); }
double GowRobotInterface::getTimestep() const { return impl_->getTimestep(); }
RobotState GowRobotInterface::getState() { return impl_->getState(); }
void GowRobotInterface::setCommand(const Eigen::VectorXd& tau) { impl_->setCommand(tau); }
void GowRobotInterface::step() { impl_->step(); }
void GowRobotInterface::render() { impl_->render(); }
void GowRobotInterface::reset() { impl_->reset(); }
bool GowRobotInterface::isRunning() const { return impl_->isRunning(); }
std::string GowRobotInterface::getUrdfPath() const { return impl_->getUrdfPath(); }
std::string GowRobotInterface::getModelPath() const { return impl_->getModelPath(); }














} // namespce RobotInterface