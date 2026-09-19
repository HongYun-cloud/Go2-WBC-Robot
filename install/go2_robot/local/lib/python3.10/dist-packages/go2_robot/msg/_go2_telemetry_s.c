// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from go2_robot:msg/Go2Telemetry.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "go2_robot/msg/detail/go2_telemetry__struct.h"
#include "go2_robot/msg/detail/go2_telemetry__functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool go2_robot__msg__go2_telemetry__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("go2_robot.msg._go2_telemetry.Go2Telemetry", full_classname_dest, 41) == 0);
  }
  go2_robot__msg__Go2Telemetry * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // p_ref_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_ref_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_ref_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_ref_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // p_act_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "p_act_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->p_act_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_ref_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_ref_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_ref_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // v_act_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "v_act_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->v_act_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_ref_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_ref_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_ref_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_act_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_act_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_act_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_mpc_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_mpc_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_mpc_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_fr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_fr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_fr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rl_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rl_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rl_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rl_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rl_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rl_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rl_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rl_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rl_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rr_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rr_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rr_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rr_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rr_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rr_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_wbc_rr_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_wbc_rr_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_wbc_rr_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // contact_fl
    PyObject * field = PyObject_GetAttrString(_pymsg, "contact_fl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->contact_fl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // contact_fr
    PyObject * field = PyObject_GetAttrString(_pymsg, "contact_fr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->contact_fr = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // contact_rl
    PyObject * field = PyObject_GetAttrString(_pymsg, "contact_rl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->contact_rl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // contact_rr
    PyObject * field = PyObject_GetAttrString(_pymsg, "contact_rr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->contact_rr = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_x_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_x_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_x_v = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_z_v
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_z_v");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_z_v = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_x_v_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_x_v_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_x_v_d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // body_z_v_d
    PyObject * field = PyObject_GetAttrString(_pymsg, "body_z_v_d");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->body_z_v_d = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_lin_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_lin_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_lin_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_lin_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_lin_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_lin_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_lin_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_lin_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_lin_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_ang_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_ang_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_ang_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_ang_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_ang_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_ang_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_ang_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_ang_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_ang_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_0
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_2 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_3
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_3 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_4
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_4 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_5
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_5");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_5 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_6
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_6");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_6 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_7
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_7");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_7 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_8
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_8");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_8 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_9
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_9");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_9 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_10
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_10");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_10 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // q_des_joint_11
    PyObject * field = PyObject_GetAttrString(_pymsg, "q_des_joint_11");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->q_des_joint_11 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_yaw_mpc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_yaw_mpc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_yaw_mpc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_yaw_wbc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_yaw_wbc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_yaw_wbc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_cone_fl
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_cone_fl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_cone_fl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_cone_fr
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_cone_fr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_cone_fr = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_cone_rl
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_cone_rl");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_cone_rl = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // f_cone_rr
    PyObject * field = PyObject_GetAttrString(_pymsg, "f_cone_rr");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->f_cone_rr = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_roll_mpc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_roll_mpc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_roll_mpc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_roll_wbc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_roll_wbc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_roll_wbc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_pitch_mpc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_pitch_mpc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_pitch_mpc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_pitch_wbc
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_pitch_wbc");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_pitch_wbc = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_wbc_ang_x
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_wbc_ang_x");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_wbc_ang_x = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_wbc_ang_y
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_wbc_ang_y");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_wbc_ang_y = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // a_wbc_ang_z
    PyObject * field = PyObject_GetAttrString(_pymsg, "a_wbc_ang_z");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->a_wbc_ang_z = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_0
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_0");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_0 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_1
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_1");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_1 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_2
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_2");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_2 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_3
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_3");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_3 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_4
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_4");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_4 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_5
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_5");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_5 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_6
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_6");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_6 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_7
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_7");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_7 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_8
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_8");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_8 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_9
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_9");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_9 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_10
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_10");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_10 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // tau_joint_11
    PyObject * field = PyObject_GetAttrString(_pymsg, "tau_joint_11");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->tau_joint_11 = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * go2_robot__msg__go2_telemetry__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Go2Telemetry */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("go2_robot.msg._go2_telemetry");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Go2Telemetry");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  go2_robot__msg__Go2Telemetry * ros_message = (go2_robot__msg__Go2Telemetry *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_ref_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_ref_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_ref_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // p_act_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->p_act_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "p_act_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_ref_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_ref_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_ref_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // v_act_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->v_act_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "v_act_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_ref_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_ref_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_ref_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_act_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_act_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_act_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_mpc_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_mpc_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_mpc_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_fr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_fr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_fr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rl_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rl_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rl_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rl_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rl_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rl_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rl_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rl_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rl_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rr_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rr_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rr_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rr_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rr_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rr_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_wbc_rr_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_wbc_rr_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_wbc_rr_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // contact_fl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->contact_fl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contact_fl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // contact_fr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->contact_fr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contact_fr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // contact_rl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->contact_rl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contact_rl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // contact_rr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->contact_rr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "contact_rr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_x_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_x_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_x_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_z_v
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_z_v);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_z_v", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_x_v_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_x_v_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_x_v_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // body_z_v_d
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->body_z_v_d);
    {
      int rc = PyObject_SetAttrString(_pymessage, "body_z_v_d", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_lin_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_lin_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_lin_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_lin_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_lin_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_lin_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_lin_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_lin_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_lin_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_ang_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_ang_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_ang_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_ang_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_ang_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_ang_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_ang_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_ang_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_ang_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_5
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_6
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_6);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_6", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_7
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_7);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_7", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_8
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_8);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_8", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_9
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_9);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_9", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_10
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_10);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_10", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // q_des_joint_11
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->q_des_joint_11);
    {
      int rc = PyObject_SetAttrString(_pymessage, "q_des_joint_11", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_yaw_mpc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_yaw_mpc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_yaw_mpc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_yaw_wbc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_yaw_wbc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_yaw_wbc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_cone_fl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_cone_fl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_cone_fl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_cone_fr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_cone_fr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_cone_fr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_cone_rl
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_cone_rl);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_cone_rl", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // f_cone_rr
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->f_cone_rr);
    {
      int rc = PyObject_SetAttrString(_pymessage, "f_cone_rr", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_roll_mpc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_roll_mpc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_roll_mpc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_roll_wbc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_roll_wbc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_roll_wbc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_pitch_mpc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_pitch_mpc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_pitch_mpc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_pitch_wbc
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_pitch_wbc);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_pitch_wbc", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_wbc_ang_x
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_wbc_ang_x);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_wbc_ang_x", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_wbc_ang_y
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_wbc_ang_y);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_wbc_ang_y", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // a_wbc_ang_z
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->a_wbc_ang_z);
    {
      int rc = PyObject_SetAttrString(_pymessage, "a_wbc_ang_z", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_0
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_0", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_1
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_1);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_1", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_2
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_2);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_2", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_3
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_3);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_3", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_4
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_4);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_4", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_5
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_5);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_5", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_6
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_6);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_6", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_7
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_7);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_7", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_8
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_8);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_8", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_9
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_9);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_9", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_10
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_10);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_10", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // tau_joint_11
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->tau_joint_11);
    {
      int rc = PyObject_SetAttrString(_pymessage, "tau_joint_11", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
