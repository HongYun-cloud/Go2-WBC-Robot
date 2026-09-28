#include "RobotInterface/MujocoRobotInterface.hpp"
#include "Hardware/GowManager.hpp"
#include "SIM/MJCsim.hpp"
#include <memory>


namespace RobotInterface
{

class GowRobotInterface::Impl
{
    explicit Impl(const std::string& model_path, const std::string& urdf_path)
            : sim_(std::make_unique<MJCSIM::SIM>(model_path)),
                urdf_path_(urdf_path),
                model_path_(model_path)
        {}


    private: 
    std::unique_ptr<Hardware::Manager> manager;   
    std::unique_ptr<MJCSIM::SIM> sim_; 
    std::string urdf_path_;
    std::string model_path_;
};














} // namespce RobotInterface