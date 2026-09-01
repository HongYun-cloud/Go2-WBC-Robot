#include <OsqpEigen/OsqpEigen.h>
#include <Eigen/Dense>
#include <iostream>

int main() {
    // 1. 打印当前环境版本
    std::cout << "Current Project Eigen Version: " << EIGEN_WORLD_VERSION << "." 
              << EIGEN_MAJOR_VERSION << "." << EIGEN_MINOR_VERSION << std::endl;

    // 2. 构造一个向量
    Eigen::VectorXd v(10);
    v.setConstant(1.23456789);

    // 3. 检查 VectorXd 对象的头部和数据指针
    double* actual_data_ptr = v.data();
    void* object_base_ptr = &v;

    std::cout << "Vector object address: " << object_base_ptr << std::endl;
    std::cout << "Actual data address:   " << actual_data_ptr << std::endl;
    std::cout << "Pointer Offset:        " << (size_t)actual_data_ptr - (size_t)object_base_ptr << " bytes" << std::endl;

    // 4. 【核心测试】模拟 OsqpEigen 的传递
    OsqpEigen::Solver solver;
    solver.data()->setNumberOfVariables(10);
    solver.data()->setNumberOfConstraints(10);
    
    // 如果这里报错，说明 OsqpEigen 内部对 VectorXd 的解析方式和当前不一致
    if(solver.data()->setLowerBound(v)) {
        std::cout << "OsqpEigen accept the vector successfully." << std::endl;
    }

    return 0;
}