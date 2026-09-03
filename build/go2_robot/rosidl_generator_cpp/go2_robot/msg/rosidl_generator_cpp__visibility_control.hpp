// generated from rosidl_generator_cpp/resource/rosidl_generator_cpp__visibility_control.hpp.in
// generated code does not contain a copyright notice

#ifndef GO2_ROBOT__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
#define GO2_ROBOT__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_

#ifdef __cplusplus
extern "C"
{
#endif

// This logic was borrowed (then namespaced) from the examples on the gcc wiki:
//     https://gcc.gnu.org/wiki/Visibility

#if defined _WIN32 || defined __CYGWIN__
  #ifdef __GNUC__
    #define ROSIDL_GENERATOR_CPP_EXPORT_go2_robot __attribute__ ((dllexport))
    #define ROSIDL_GENERATOR_CPP_IMPORT_go2_robot __attribute__ ((dllimport))
  #else
    #define ROSIDL_GENERATOR_CPP_EXPORT_go2_robot __declspec(dllexport)
    #define ROSIDL_GENERATOR_CPP_IMPORT_go2_robot __declspec(dllimport)
  #endif
  #ifdef ROSIDL_GENERATOR_CPP_BUILDING_DLL_go2_robot
    #define ROSIDL_GENERATOR_CPP_PUBLIC_go2_robot ROSIDL_GENERATOR_CPP_EXPORT_go2_robot
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_go2_robot ROSIDL_GENERATOR_CPP_IMPORT_go2_robot
  #endif
#else
  #define ROSIDL_GENERATOR_CPP_EXPORT_go2_robot __attribute__ ((visibility("default")))
  #define ROSIDL_GENERATOR_CPP_IMPORT_go2_robot
  #if __GNUC__ >= 4
    #define ROSIDL_GENERATOR_CPP_PUBLIC_go2_robot __attribute__ ((visibility("default")))
  #else
    #define ROSIDL_GENERATOR_CPP_PUBLIC_go2_robot
  #endif
#endif

#ifdef __cplusplus
}
#endif

#endif  // GO2_ROBOT__MSG__ROSIDL_GENERATOR_CPP__VISIBILITY_CONTROL_HPP_
