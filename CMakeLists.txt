cmake_minimum_required(VERSION 3.10)
project(go2_robot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================
# 1. ROS 2 (ament_cmake)
# =========================
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
# =========================
# 2. MuJoCo 路径
# =========================
set(MUJOCO_PATH $ENV{HOME}/.mujoco/mujoco-3.9.0)

# =========================
# 3. GLFW / GLEW / OpenGL
# =========================
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

# =========================
# 4. Threads / OsqpEigen(源码编译) / yaml-cpp
# =========================
find_package(Threads REQUIRED)
find_package(yaml-cpp REQUIRED)
add_subdirectory(third_party/osqp-eigen)

# =========================
# 5. Pinocchio (ROS Humble)
# =========================
find_package(pinocchio REQUIRED
    PATHS /opt/ros/humble/lib/x86_64-linux-gnu/cmake/pinocchio
)

# =========================
# 6. 核心算法库 (原有源码, 原样编译, 不含 ROS)
# =========================
add_library(go2_core STATIC
    src/SIM/MJCsim.cpp
    src/MPC/MPC.cpp
    src/Model/pinocchio.cpp
    src/WBC/WBC.cpp
    src/Planner/GaitScheduler.cpp
    src/Planner/SwingLegPlanner.cpp
    src/fsm/ControlFSM.cpp
    src/Estimator/PositionVelocityEstimator.cpp
)
target_include_directories(go2_core PUBLIC
    ${CMAKE_SOURCE_DIR}/include
    ${MUJOCO_PATH}/include
    /usr/include/eigen3
)
target_link_libraries(go2_core PUBLIC
    pinocchio::pinocchio
    OsqpEigen::OsqpEigen
    yaml-cpp
    ${MUJOCO_PATH}/lib/libmujoco.so
    glfw
    OpenGL::GL
    ${CMAKE_DL_LIBS}
    GLEW
    Threads::Threads
)

# =========================
# 7. ROS 2 节点 (原 main.cpp 逻辑封装)
# =========================
add_executable(go2_control_node
    src/ros2/go2_control_node.cpp
    src/ros2/main.cpp
)

# 使用 ament_target_dependencies 自动处理所有 ROS 依赖
# 注意这里加入了 nav_msgs
ament_target_dependencies(go2_control_node
    rclcpp
    geometry_msgs
    nav_msgs
    sensor_msgs
    std_msgs
)

# 链接你自己的库（去掉 PRIVATE 关键字，避免之前的冲突报错）
target_link_libraries(go2_control_node
    go2_core
)

target_include_directories(go2_control_node PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)


# =========================
# 8. 安装
# =========================
install(TARGETS go2_control_node
    DESTINATION lib/${PROJECT_NAME}
)
install(DIRECTORY config/
    DESTINATION share/${PROJECT_NAME}/config
)
install(DIRECTORY launch/
    DESTINATION share/${PROJECT_NAME}/launch
)
# MuJoCo 模型目录整体安装, 保持内部相对引用 (scene.xml → go2.xml → assets/) 不变;
# 排除误生成的 dump 与嵌套工作区
install(DIRECTORY go2/
    DESTINATION share/${PROJECT_NAME}/go2
    PATTERN "build" EXCLUDE
    PATTERN "install" EXCLUDE
    PATTERN "log" EXCLUDE
    PATTERN "*.TXT" EXCLUDE
    PATTERN "*.mjb" EXCLUDE
)

ament_package()
