# Install script for directory: /home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/hong/Movement_Control/Go2Robot/install/go2_robot")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0"
         RPATH "\$ORIGIN/:\$ORIGIN/../lib:/usr/local/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/lib/libOsqpEigen.so.0.11.0")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0"
         OLD_RPATH "/usr/local/lib::::::::::::::::::::::::"
         NEW_RPATH "\$ORIGIN/:\$ORIGIN/../lib:/usr/local/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so.0.11.0")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xshlibx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so"
         RPATH "\$ORIGIN/:\$ORIGIN/../lib:/usr/local/lib")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/lib/libOsqpEigen.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so"
         OLD_RPATH "/usr/local/lib::::::::::::::::::::::::"
         NEW_RPATH "\$ORIGIN/:\$ORIGIN/../lib:/usr/local/lib")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libOsqpEigen.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xruntimex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/OsqpEigen" TYPE FILE FILES
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/OsqpEigen.h"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Constants.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/SparseMatrixHelper.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/SparseMatrixHelper.tpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Data.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Data.tpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Settings.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Solver.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Solver.tpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Compat.hpp"
    "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/include/OsqpEigen/Debug.hpp"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xOsqpEigenx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen" TYPE FILE FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/OsqpEigenConfigVersion.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xOsqpEigenx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen" TYPE FILE RENAME "OsqpEigenConfig.cmake" FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/third_party/osqp-eigen/CMakeFiles/OsqpEigenConfig.cmake.install")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xOsqpEigenx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen/OsqpEigenTargets.cmake")
    file(DIFFERENT EXPORT_FILE_CHANGED FILES
         "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen/OsqpEigenTargets.cmake"
         "/home/hong/Movement_Control/Go2Robot/build/go2_robot/third_party/osqp-eigen/CMakeFiles/Export/lib/cmake/OsqpEigen/OsqpEigenTargets.cmake")
    if(EXPORT_FILE_CHANGED)
      file(GLOB OLD_CONFIG_FILES "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen/OsqpEigenTargets-*.cmake")
      if(OLD_CONFIG_FILES)
        message(STATUS "Old export file \"$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen/OsqpEigenTargets.cmake\" will be replaced.  Removing files [${OLD_CONFIG_FILES}].")
        file(REMOVE ${OLD_CONFIG_FILES})
      endif()
    endif()
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen" TYPE FILE FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/third_party/osqp-eigen/CMakeFiles/Export/lib/cmake/OsqpEigen/OsqpEigenTargets.cmake")
  if("${CMAKE_INSTALL_CONFIG_NAME}" MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
    file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/cmake/OsqpEigen" TYPE FILE FILES "/home/hong/Movement_Control/Go2Robot/build/go2_robot/third_party/osqp-eigen/CMakeFiles/Export/lib/cmake/OsqpEigen/OsqpEigenTargets-release.cmake")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/cmake/osqp-eigen" TYPE FILE FILES "/home/hong/Movement_Control/Go2Robot/third_party/osqp-eigen/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/home/hong/Movement_Control/Go2Robot/build/go2_robot/third_party/osqp-eigen/tests/cmake_install.cmake")
endif()

