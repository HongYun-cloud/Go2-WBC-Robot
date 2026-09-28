#include <rclcpp/rclcpp.hpp>
#include "ros2/go2_control_node.hpp"

// 单线程 executor: 定时器回调 (控制循环 500Hz) 全部在主线程,
// 与 GLFW 窗口创建线程一致 (MuJoCo Render 必须在窗口线程调用)
int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    rclcpp::executors::SingleThreadedExecutor executor;

    auto node = std::make_shared<go2::Go2ControlNode>();
    executor.add_node(node);

    // Ctrl+C / ros2 lifecycle shutdown → rclcpp::ok() 为 false
    executor.spin();

    rclcpp::shutdown();
    return 0;
}