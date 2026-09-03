#include <rclcpp/rclcpp.hpp>
#include "ros2/go2_control_node.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    // 单线程 executor: 定时器回调 (WBC 500Hz 主控循环) 全部在主线程,
    // 与 GLFW 窗口创建线程一致 (mj->Render 必须在窗口线程调用)
    rclcpp::executors::SingleThreadedExecutor executor;

    auto node = std::make_shared<go2::Go2ControlNode>();
    executor.add_node(node);

    // Ctrl+C / ros2 lifecycle shutdown → rclcpp::ok() 为 false →
    // MPC 线程退出循环, 节点析构 join 线程后销毁控制栈
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
