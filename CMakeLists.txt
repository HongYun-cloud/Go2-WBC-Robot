cmake_minimum_required(VERSION 3.10)
project(Go2Robot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# =========================
# 1. MuJoCo 路径
# =========================
set(MUJOCO_PATH $ENV{HOME}/.mujoco/mujoco-3.9.0)

# =========================
# 2. GLFW / GLEW
# =========================
find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)

# =========================
# 3. OpenGL
# =========================
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
# 6. 你的源码
# =========================
add_executable(Go2Robot
    src/main.cpp
    src/SIM/MJCsim.cpp
    src/MPC/MPC.cpp
    src/Model/pinocchio.cpp
    src/WBC/WBC.cpp
    src/Planner/GaitScheduler.cpp
    src/Planner/SwingLegPlanner.cpp
    src/fsm/ControlFSM.cpp
    src/Estimator/PositionVelocityEstimator.cpp
)

# =========================
# 7. 头文件路径
# =========================
target_include_directories(Go2Robot PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${MUJOCO_PATH}/include
    /usr/include/eigen3
)

# =========================
# 8. 链接目录与库
# =========================
link_directories(${MUJOCO_PATH}/bin)

target_link_libraries(Go2Robot PRIVATE
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
