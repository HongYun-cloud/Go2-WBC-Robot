# generated from rosidl_generator_py/resource/_idl.py.em
# with input from go2_robot:msg/Go2Telemetry.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Go2Telemetry(type):
    """Metaclass of message 'Go2Telemetry'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('go2_robot')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'go2_robot.msg.Go2Telemetry')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__go2_telemetry
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__go2_telemetry
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__go2_telemetry
            cls._TYPE_SUPPORT = module.type_support_msg__msg__go2_telemetry
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__go2_telemetry

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Go2Telemetry(metaclass=Metaclass_Go2Telemetry):
    """Message class 'Go2Telemetry'."""

    __slots__ = [
        '_header',
        '_p_ref_fl_x',
        '_p_ref_fl_y',
        '_p_ref_fl_z',
        '_p_ref_fr_x',
        '_p_ref_fr_y',
        '_p_ref_fr_z',
        '_p_ref_rl_x',
        '_p_ref_rl_y',
        '_p_ref_rl_z',
        '_p_ref_rr_x',
        '_p_ref_rr_y',
        '_p_ref_rr_z',
        '_p_act_fl_x',
        '_p_act_fl_y',
        '_p_act_fl_z',
        '_p_act_fr_x',
        '_p_act_fr_y',
        '_p_act_fr_z',
        '_p_act_rl_x',
        '_p_act_rl_y',
        '_p_act_rl_z',
        '_p_act_rr_x',
        '_p_act_rr_y',
        '_p_act_rr_z',
        '_v_ref_fl_x',
        '_v_ref_fl_y',
        '_v_ref_fl_z',
        '_v_ref_fr_x',
        '_v_ref_fr_y',
        '_v_ref_fr_z',
        '_v_ref_rl_x',
        '_v_ref_rl_y',
        '_v_ref_rl_z',
        '_v_ref_rr_x',
        '_v_ref_rr_y',
        '_v_ref_rr_z',
        '_v_act_fl_x',
        '_v_act_fl_y',
        '_v_act_fl_z',
        '_v_act_fr_x',
        '_v_act_fr_y',
        '_v_act_fr_z',
        '_v_act_rl_x',
        '_v_act_rl_y',
        '_v_act_rl_z',
        '_v_act_rr_x',
        '_v_act_rr_y',
        '_v_act_rr_z',
        '_a_ref_fl_x',
        '_a_ref_fl_y',
        '_a_ref_fl_z',
        '_a_ref_fr_x',
        '_a_ref_fr_y',
        '_a_ref_fr_z',
        '_a_ref_rl_x',
        '_a_ref_rl_y',
        '_a_ref_rl_z',
        '_a_ref_rr_x',
        '_a_ref_rr_y',
        '_a_ref_rr_z',
        '_a_act_fl_x',
        '_a_act_fl_y',
        '_a_act_fl_z',
        '_a_act_fr_x',
        '_a_act_fr_y',
        '_a_act_fr_z',
        '_a_act_rl_x',
        '_a_act_rl_y',
        '_a_act_rl_z',
        '_a_act_rr_x',
        '_a_act_rr_y',
        '_a_act_rr_z',
        '_f_mpc_fl_x',
        '_f_mpc_fl_y',
        '_f_mpc_fl_z',
        '_f_mpc_fr_x',
        '_f_mpc_fr_y',
        '_f_mpc_fr_z',
        '_f_mpc_rl_x',
        '_f_mpc_rl_y',
        '_f_mpc_rl_z',
        '_f_mpc_rr_x',
        '_f_mpc_rr_y',
        '_f_mpc_rr_z',
        '_f_wbc_fl_x',
        '_f_wbc_fl_y',
        '_f_wbc_fl_z',
        '_f_wbc_fr_x',
        '_f_wbc_fr_y',
        '_f_wbc_fr_z',
        '_f_wbc_rl_x',
        '_f_wbc_rl_y',
        '_f_wbc_rl_z',
        '_f_wbc_rr_x',
        '_f_wbc_rr_y',
        '_f_wbc_rr_z',
        '_contact_fl',
        '_contact_fr',
        '_contact_rl',
        '_contact_rr',
        '_body_x',
        '_body_z',
        '_body_x_v',
        '_body_z_v',
        '_body_x_v_d',
        '_body_z_v_d',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'p_ref_fl_x': 'double',
        'p_ref_fl_y': 'double',
        'p_ref_fl_z': 'double',
        'p_ref_fr_x': 'double',
        'p_ref_fr_y': 'double',
        'p_ref_fr_z': 'double',
        'p_ref_rl_x': 'double',
        'p_ref_rl_y': 'double',
        'p_ref_rl_z': 'double',
        'p_ref_rr_x': 'double',
        'p_ref_rr_y': 'double',
        'p_ref_rr_z': 'double',
        'p_act_fl_x': 'double',
        'p_act_fl_y': 'double',
        'p_act_fl_z': 'double',
        'p_act_fr_x': 'double',
        'p_act_fr_y': 'double',
        'p_act_fr_z': 'double',
        'p_act_rl_x': 'double',
        'p_act_rl_y': 'double',
        'p_act_rl_z': 'double',
        'p_act_rr_x': 'double',
        'p_act_rr_y': 'double',
        'p_act_rr_z': 'double',
        'v_ref_fl_x': 'double',
        'v_ref_fl_y': 'double',
        'v_ref_fl_z': 'double',
        'v_ref_fr_x': 'double',
        'v_ref_fr_y': 'double',
        'v_ref_fr_z': 'double',
        'v_ref_rl_x': 'double',
        'v_ref_rl_y': 'double',
        'v_ref_rl_z': 'double',
        'v_ref_rr_x': 'double',
        'v_ref_rr_y': 'double',
        'v_ref_rr_z': 'double',
        'v_act_fl_x': 'double',
        'v_act_fl_y': 'double',
        'v_act_fl_z': 'double',
        'v_act_fr_x': 'double',
        'v_act_fr_y': 'double',
        'v_act_fr_z': 'double',
        'v_act_rl_x': 'double',
        'v_act_rl_y': 'double',
        'v_act_rl_z': 'double',
        'v_act_rr_x': 'double',
        'v_act_rr_y': 'double',
        'v_act_rr_z': 'double',
        'a_ref_fl_x': 'double',
        'a_ref_fl_y': 'double',
        'a_ref_fl_z': 'double',
        'a_ref_fr_x': 'double',
        'a_ref_fr_y': 'double',
        'a_ref_fr_z': 'double',
        'a_ref_rl_x': 'double',
        'a_ref_rl_y': 'double',
        'a_ref_rl_z': 'double',
        'a_ref_rr_x': 'double',
        'a_ref_rr_y': 'double',
        'a_ref_rr_z': 'double',
        'a_act_fl_x': 'double',
        'a_act_fl_y': 'double',
        'a_act_fl_z': 'double',
        'a_act_fr_x': 'double',
        'a_act_fr_y': 'double',
        'a_act_fr_z': 'double',
        'a_act_rl_x': 'double',
        'a_act_rl_y': 'double',
        'a_act_rl_z': 'double',
        'a_act_rr_x': 'double',
        'a_act_rr_y': 'double',
        'a_act_rr_z': 'double',
        'f_mpc_fl_x': 'double',
        'f_mpc_fl_y': 'double',
        'f_mpc_fl_z': 'double',
        'f_mpc_fr_x': 'double',
        'f_mpc_fr_y': 'double',
        'f_mpc_fr_z': 'double',
        'f_mpc_rl_x': 'double',
        'f_mpc_rl_y': 'double',
        'f_mpc_rl_z': 'double',
        'f_mpc_rr_x': 'double',
        'f_mpc_rr_y': 'double',
        'f_mpc_rr_z': 'double',
        'f_wbc_fl_x': 'double',
        'f_wbc_fl_y': 'double',
        'f_wbc_fl_z': 'double',
        'f_wbc_fr_x': 'double',
        'f_wbc_fr_y': 'double',
        'f_wbc_fr_z': 'double',
        'f_wbc_rl_x': 'double',
        'f_wbc_rl_y': 'double',
        'f_wbc_rl_z': 'double',
        'f_wbc_rr_x': 'double',
        'f_wbc_rr_y': 'double',
        'f_wbc_rr_z': 'double',
        'contact_fl': 'double',
        'contact_fr': 'double',
        'contact_rl': 'double',
        'contact_rr': 'double',
        'body_x': 'double',
        'body_z': 'double',
        'body_x_v': 'double',
        'body_z_v': 'double',
        'body_x_v_d': 'double',
        'body_z_v_d': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.p_ref_fl_x = kwargs.get('p_ref_fl_x', float())
        self.p_ref_fl_y = kwargs.get('p_ref_fl_y', float())
        self.p_ref_fl_z = kwargs.get('p_ref_fl_z', float())
        self.p_ref_fr_x = kwargs.get('p_ref_fr_x', float())
        self.p_ref_fr_y = kwargs.get('p_ref_fr_y', float())
        self.p_ref_fr_z = kwargs.get('p_ref_fr_z', float())
        self.p_ref_rl_x = kwargs.get('p_ref_rl_x', float())
        self.p_ref_rl_y = kwargs.get('p_ref_rl_y', float())
        self.p_ref_rl_z = kwargs.get('p_ref_rl_z', float())
        self.p_ref_rr_x = kwargs.get('p_ref_rr_x', float())
        self.p_ref_rr_y = kwargs.get('p_ref_rr_y', float())
        self.p_ref_rr_z = kwargs.get('p_ref_rr_z', float())
        self.p_act_fl_x = kwargs.get('p_act_fl_x', float())
        self.p_act_fl_y = kwargs.get('p_act_fl_y', float())
        self.p_act_fl_z = kwargs.get('p_act_fl_z', float())
        self.p_act_fr_x = kwargs.get('p_act_fr_x', float())
        self.p_act_fr_y = kwargs.get('p_act_fr_y', float())
        self.p_act_fr_z = kwargs.get('p_act_fr_z', float())
        self.p_act_rl_x = kwargs.get('p_act_rl_x', float())
        self.p_act_rl_y = kwargs.get('p_act_rl_y', float())
        self.p_act_rl_z = kwargs.get('p_act_rl_z', float())
        self.p_act_rr_x = kwargs.get('p_act_rr_x', float())
        self.p_act_rr_y = kwargs.get('p_act_rr_y', float())
        self.p_act_rr_z = kwargs.get('p_act_rr_z', float())
        self.v_ref_fl_x = kwargs.get('v_ref_fl_x', float())
        self.v_ref_fl_y = kwargs.get('v_ref_fl_y', float())
        self.v_ref_fl_z = kwargs.get('v_ref_fl_z', float())
        self.v_ref_fr_x = kwargs.get('v_ref_fr_x', float())
        self.v_ref_fr_y = kwargs.get('v_ref_fr_y', float())
        self.v_ref_fr_z = kwargs.get('v_ref_fr_z', float())
        self.v_ref_rl_x = kwargs.get('v_ref_rl_x', float())
        self.v_ref_rl_y = kwargs.get('v_ref_rl_y', float())
        self.v_ref_rl_z = kwargs.get('v_ref_rl_z', float())
        self.v_ref_rr_x = kwargs.get('v_ref_rr_x', float())
        self.v_ref_rr_y = kwargs.get('v_ref_rr_y', float())
        self.v_ref_rr_z = kwargs.get('v_ref_rr_z', float())
        self.v_act_fl_x = kwargs.get('v_act_fl_x', float())
        self.v_act_fl_y = kwargs.get('v_act_fl_y', float())
        self.v_act_fl_z = kwargs.get('v_act_fl_z', float())
        self.v_act_fr_x = kwargs.get('v_act_fr_x', float())
        self.v_act_fr_y = kwargs.get('v_act_fr_y', float())
        self.v_act_fr_z = kwargs.get('v_act_fr_z', float())
        self.v_act_rl_x = kwargs.get('v_act_rl_x', float())
        self.v_act_rl_y = kwargs.get('v_act_rl_y', float())
        self.v_act_rl_z = kwargs.get('v_act_rl_z', float())
        self.v_act_rr_x = kwargs.get('v_act_rr_x', float())
        self.v_act_rr_y = kwargs.get('v_act_rr_y', float())
        self.v_act_rr_z = kwargs.get('v_act_rr_z', float())
        self.a_ref_fl_x = kwargs.get('a_ref_fl_x', float())
        self.a_ref_fl_y = kwargs.get('a_ref_fl_y', float())
        self.a_ref_fl_z = kwargs.get('a_ref_fl_z', float())
        self.a_ref_fr_x = kwargs.get('a_ref_fr_x', float())
        self.a_ref_fr_y = kwargs.get('a_ref_fr_y', float())
        self.a_ref_fr_z = kwargs.get('a_ref_fr_z', float())
        self.a_ref_rl_x = kwargs.get('a_ref_rl_x', float())
        self.a_ref_rl_y = kwargs.get('a_ref_rl_y', float())
        self.a_ref_rl_z = kwargs.get('a_ref_rl_z', float())
        self.a_ref_rr_x = kwargs.get('a_ref_rr_x', float())
        self.a_ref_rr_y = kwargs.get('a_ref_rr_y', float())
        self.a_ref_rr_z = kwargs.get('a_ref_rr_z', float())
        self.a_act_fl_x = kwargs.get('a_act_fl_x', float())
        self.a_act_fl_y = kwargs.get('a_act_fl_y', float())
        self.a_act_fl_z = kwargs.get('a_act_fl_z', float())
        self.a_act_fr_x = kwargs.get('a_act_fr_x', float())
        self.a_act_fr_y = kwargs.get('a_act_fr_y', float())
        self.a_act_fr_z = kwargs.get('a_act_fr_z', float())
        self.a_act_rl_x = kwargs.get('a_act_rl_x', float())
        self.a_act_rl_y = kwargs.get('a_act_rl_y', float())
        self.a_act_rl_z = kwargs.get('a_act_rl_z', float())
        self.a_act_rr_x = kwargs.get('a_act_rr_x', float())
        self.a_act_rr_y = kwargs.get('a_act_rr_y', float())
        self.a_act_rr_z = kwargs.get('a_act_rr_z', float())
        self.f_mpc_fl_x = kwargs.get('f_mpc_fl_x', float())
        self.f_mpc_fl_y = kwargs.get('f_mpc_fl_y', float())
        self.f_mpc_fl_z = kwargs.get('f_mpc_fl_z', float())
        self.f_mpc_fr_x = kwargs.get('f_mpc_fr_x', float())
        self.f_mpc_fr_y = kwargs.get('f_mpc_fr_y', float())
        self.f_mpc_fr_z = kwargs.get('f_mpc_fr_z', float())
        self.f_mpc_rl_x = kwargs.get('f_mpc_rl_x', float())
        self.f_mpc_rl_y = kwargs.get('f_mpc_rl_y', float())
        self.f_mpc_rl_z = kwargs.get('f_mpc_rl_z', float())
        self.f_mpc_rr_x = kwargs.get('f_mpc_rr_x', float())
        self.f_mpc_rr_y = kwargs.get('f_mpc_rr_y', float())
        self.f_mpc_rr_z = kwargs.get('f_mpc_rr_z', float())
        self.f_wbc_fl_x = kwargs.get('f_wbc_fl_x', float())
        self.f_wbc_fl_y = kwargs.get('f_wbc_fl_y', float())
        self.f_wbc_fl_z = kwargs.get('f_wbc_fl_z', float())
        self.f_wbc_fr_x = kwargs.get('f_wbc_fr_x', float())
        self.f_wbc_fr_y = kwargs.get('f_wbc_fr_y', float())
        self.f_wbc_fr_z = kwargs.get('f_wbc_fr_z', float())
        self.f_wbc_rl_x = kwargs.get('f_wbc_rl_x', float())
        self.f_wbc_rl_y = kwargs.get('f_wbc_rl_y', float())
        self.f_wbc_rl_z = kwargs.get('f_wbc_rl_z', float())
        self.f_wbc_rr_x = kwargs.get('f_wbc_rr_x', float())
        self.f_wbc_rr_y = kwargs.get('f_wbc_rr_y', float())
        self.f_wbc_rr_z = kwargs.get('f_wbc_rr_z', float())
        self.contact_fl = kwargs.get('contact_fl', float())
        self.contact_fr = kwargs.get('contact_fr', float())
        self.contact_rl = kwargs.get('contact_rl', float())
        self.contact_rr = kwargs.get('contact_rr', float())
        self.body_x = kwargs.get('body_x', float())
        self.body_z = kwargs.get('body_z', float())
        self.body_x_v = kwargs.get('body_x_v', float())
        self.body_z_v = kwargs.get('body_z_v', float())
        self.body_x_v_d = kwargs.get('body_x_v_d', float())
        self.body_z_v_d = kwargs.get('body_z_v_d', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.p_ref_fl_x != other.p_ref_fl_x:
            return False
        if self.p_ref_fl_y != other.p_ref_fl_y:
            return False
        if self.p_ref_fl_z != other.p_ref_fl_z:
            return False
        if self.p_ref_fr_x != other.p_ref_fr_x:
            return False
        if self.p_ref_fr_y != other.p_ref_fr_y:
            return False
        if self.p_ref_fr_z != other.p_ref_fr_z:
            return False
        if self.p_ref_rl_x != other.p_ref_rl_x:
            return False
        if self.p_ref_rl_y != other.p_ref_rl_y:
            return False
        if self.p_ref_rl_z != other.p_ref_rl_z:
            return False
        if self.p_ref_rr_x != other.p_ref_rr_x:
            return False
        if self.p_ref_rr_y != other.p_ref_rr_y:
            return False
        if self.p_ref_rr_z != other.p_ref_rr_z:
            return False
        if self.p_act_fl_x != other.p_act_fl_x:
            return False
        if self.p_act_fl_y != other.p_act_fl_y:
            return False
        if self.p_act_fl_z != other.p_act_fl_z:
            return False
        if self.p_act_fr_x != other.p_act_fr_x:
            return False
        if self.p_act_fr_y != other.p_act_fr_y:
            return False
        if self.p_act_fr_z != other.p_act_fr_z:
            return False
        if self.p_act_rl_x != other.p_act_rl_x:
            return False
        if self.p_act_rl_y != other.p_act_rl_y:
            return False
        if self.p_act_rl_z != other.p_act_rl_z:
            return False
        if self.p_act_rr_x != other.p_act_rr_x:
            return False
        if self.p_act_rr_y != other.p_act_rr_y:
            return False
        if self.p_act_rr_z != other.p_act_rr_z:
            return False
        if self.v_ref_fl_x != other.v_ref_fl_x:
            return False
        if self.v_ref_fl_y != other.v_ref_fl_y:
            return False
        if self.v_ref_fl_z != other.v_ref_fl_z:
            return False
        if self.v_ref_fr_x != other.v_ref_fr_x:
            return False
        if self.v_ref_fr_y != other.v_ref_fr_y:
            return False
        if self.v_ref_fr_z != other.v_ref_fr_z:
            return False
        if self.v_ref_rl_x != other.v_ref_rl_x:
            return False
        if self.v_ref_rl_y != other.v_ref_rl_y:
            return False
        if self.v_ref_rl_z != other.v_ref_rl_z:
            return False
        if self.v_ref_rr_x != other.v_ref_rr_x:
            return False
        if self.v_ref_rr_y != other.v_ref_rr_y:
            return False
        if self.v_ref_rr_z != other.v_ref_rr_z:
            return False
        if self.v_act_fl_x != other.v_act_fl_x:
            return False
        if self.v_act_fl_y != other.v_act_fl_y:
            return False
        if self.v_act_fl_z != other.v_act_fl_z:
            return False
        if self.v_act_fr_x != other.v_act_fr_x:
            return False
        if self.v_act_fr_y != other.v_act_fr_y:
            return False
        if self.v_act_fr_z != other.v_act_fr_z:
            return False
        if self.v_act_rl_x != other.v_act_rl_x:
            return False
        if self.v_act_rl_y != other.v_act_rl_y:
            return False
        if self.v_act_rl_z != other.v_act_rl_z:
            return False
        if self.v_act_rr_x != other.v_act_rr_x:
            return False
        if self.v_act_rr_y != other.v_act_rr_y:
            return False
        if self.v_act_rr_z != other.v_act_rr_z:
            return False
        if self.a_ref_fl_x != other.a_ref_fl_x:
            return False
        if self.a_ref_fl_y != other.a_ref_fl_y:
            return False
        if self.a_ref_fl_z != other.a_ref_fl_z:
            return False
        if self.a_ref_fr_x != other.a_ref_fr_x:
            return False
        if self.a_ref_fr_y != other.a_ref_fr_y:
            return False
        if self.a_ref_fr_z != other.a_ref_fr_z:
            return False
        if self.a_ref_rl_x != other.a_ref_rl_x:
            return False
        if self.a_ref_rl_y != other.a_ref_rl_y:
            return False
        if self.a_ref_rl_z != other.a_ref_rl_z:
            return False
        if self.a_ref_rr_x != other.a_ref_rr_x:
            return False
        if self.a_ref_rr_y != other.a_ref_rr_y:
            return False
        if self.a_ref_rr_z != other.a_ref_rr_z:
            return False
        if self.a_act_fl_x != other.a_act_fl_x:
            return False
        if self.a_act_fl_y != other.a_act_fl_y:
            return False
        if self.a_act_fl_z != other.a_act_fl_z:
            return False
        if self.a_act_fr_x != other.a_act_fr_x:
            return False
        if self.a_act_fr_y != other.a_act_fr_y:
            return False
        if self.a_act_fr_z != other.a_act_fr_z:
            return False
        if self.a_act_rl_x != other.a_act_rl_x:
            return False
        if self.a_act_rl_y != other.a_act_rl_y:
            return False
        if self.a_act_rl_z != other.a_act_rl_z:
            return False
        if self.a_act_rr_x != other.a_act_rr_x:
            return False
        if self.a_act_rr_y != other.a_act_rr_y:
            return False
        if self.a_act_rr_z != other.a_act_rr_z:
            return False
        if self.f_mpc_fl_x != other.f_mpc_fl_x:
            return False
        if self.f_mpc_fl_y != other.f_mpc_fl_y:
            return False
        if self.f_mpc_fl_z != other.f_mpc_fl_z:
            return False
        if self.f_mpc_fr_x != other.f_mpc_fr_x:
            return False
        if self.f_mpc_fr_y != other.f_mpc_fr_y:
            return False
        if self.f_mpc_fr_z != other.f_mpc_fr_z:
            return False
        if self.f_mpc_rl_x != other.f_mpc_rl_x:
            return False
        if self.f_mpc_rl_y != other.f_mpc_rl_y:
            return False
        if self.f_mpc_rl_z != other.f_mpc_rl_z:
            return False
        if self.f_mpc_rr_x != other.f_mpc_rr_x:
            return False
        if self.f_mpc_rr_y != other.f_mpc_rr_y:
            return False
        if self.f_mpc_rr_z != other.f_mpc_rr_z:
            return False
        if self.f_wbc_fl_x != other.f_wbc_fl_x:
            return False
        if self.f_wbc_fl_y != other.f_wbc_fl_y:
            return False
        if self.f_wbc_fl_z != other.f_wbc_fl_z:
            return False
        if self.f_wbc_fr_x != other.f_wbc_fr_x:
            return False
        if self.f_wbc_fr_y != other.f_wbc_fr_y:
            return False
        if self.f_wbc_fr_z != other.f_wbc_fr_z:
            return False
        if self.f_wbc_rl_x != other.f_wbc_rl_x:
            return False
        if self.f_wbc_rl_y != other.f_wbc_rl_y:
            return False
        if self.f_wbc_rl_z != other.f_wbc_rl_z:
            return False
        if self.f_wbc_rr_x != other.f_wbc_rr_x:
            return False
        if self.f_wbc_rr_y != other.f_wbc_rr_y:
            return False
        if self.f_wbc_rr_z != other.f_wbc_rr_z:
            return False
        if self.contact_fl != other.contact_fl:
            return False
        if self.contact_fr != other.contact_fr:
            return False
        if self.contact_rl != other.contact_rl:
            return False
        if self.contact_rr != other.contact_rr:
            return False
        if self.body_x != other.body_x:
            return False
        if self.body_z != other.body_z:
            return False
        if self.body_x_v != other.body_x_v:
            return False
        if self.body_z_v != other.body_z_v:
            return False
        if self.body_x_v_d != other.body_x_v_d:
            return False
        if self.body_z_v_d != other.body_z_v_d:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def p_ref_fl_x(self):
        """Message field 'p_ref_fl_x'."""
        return self._p_ref_fl_x

    @p_ref_fl_x.setter
    def p_ref_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fl_x = value

    @builtins.property
    def p_ref_fl_y(self):
        """Message field 'p_ref_fl_y'."""
        return self._p_ref_fl_y

    @p_ref_fl_y.setter
    def p_ref_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fl_y = value

    @builtins.property
    def p_ref_fl_z(self):
        """Message field 'p_ref_fl_z'."""
        return self._p_ref_fl_z

    @p_ref_fl_z.setter
    def p_ref_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fl_z = value

    @builtins.property
    def p_ref_fr_x(self):
        """Message field 'p_ref_fr_x'."""
        return self._p_ref_fr_x

    @p_ref_fr_x.setter
    def p_ref_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fr_x = value

    @builtins.property
    def p_ref_fr_y(self):
        """Message field 'p_ref_fr_y'."""
        return self._p_ref_fr_y

    @p_ref_fr_y.setter
    def p_ref_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fr_y = value

    @builtins.property
    def p_ref_fr_z(self):
        """Message field 'p_ref_fr_z'."""
        return self._p_ref_fr_z

    @p_ref_fr_z.setter
    def p_ref_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_fr_z = value

    @builtins.property
    def p_ref_rl_x(self):
        """Message field 'p_ref_rl_x'."""
        return self._p_ref_rl_x

    @p_ref_rl_x.setter
    def p_ref_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rl_x = value

    @builtins.property
    def p_ref_rl_y(self):
        """Message field 'p_ref_rl_y'."""
        return self._p_ref_rl_y

    @p_ref_rl_y.setter
    def p_ref_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rl_y = value

    @builtins.property
    def p_ref_rl_z(self):
        """Message field 'p_ref_rl_z'."""
        return self._p_ref_rl_z

    @p_ref_rl_z.setter
    def p_ref_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rl_z = value

    @builtins.property
    def p_ref_rr_x(self):
        """Message field 'p_ref_rr_x'."""
        return self._p_ref_rr_x

    @p_ref_rr_x.setter
    def p_ref_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rr_x = value

    @builtins.property
    def p_ref_rr_y(self):
        """Message field 'p_ref_rr_y'."""
        return self._p_ref_rr_y

    @p_ref_rr_y.setter
    def p_ref_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rr_y = value

    @builtins.property
    def p_ref_rr_z(self):
        """Message field 'p_ref_rr_z'."""
        return self._p_ref_rr_z

    @p_ref_rr_z.setter
    def p_ref_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_ref_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_ref_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_ref_rr_z = value

    @builtins.property
    def p_act_fl_x(self):
        """Message field 'p_act_fl_x'."""
        return self._p_act_fl_x

    @p_act_fl_x.setter
    def p_act_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fl_x = value

    @builtins.property
    def p_act_fl_y(self):
        """Message field 'p_act_fl_y'."""
        return self._p_act_fl_y

    @p_act_fl_y.setter
    def p_act_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fl_y = value

    @builtins.property
    def p_act_fl_z(self):
        """Message field 'p_act_fl_z'."""
        return self._p_act_fl_z

    @p_act_fl_z.setter
    def p_act_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fl_z = value

    @builtins.property
    def p_act_fr_x(self):
        """Message field 'p_act_fr_x'."""
        return self._p_act_fr_x

    @p_act_fr_x.setter
    def p_act_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fr_x = value

    @builtins.property
    def p_act_fr_y(self):
        """Message field 'p_act_fr_y'."""
        return self._p_act_fr_y

    @p_act_fr_y.setter
    def p_act_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fr_y = value

    @builtins.property
    def p_act_fr_z(self):
        """Message field 'p_act_fr_z'."""
        return self._p_act_fr_z

    @p_act_fr_z.setter
    def p_act_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_fr_z = value

    @builtins.property
    def p_act_rl_x(self):
        """Message field 'p_act_rl_x'."""
        return self._p_act_rl_x

    @p_act_rl_x.setter
    def p_act_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rl_x = value

    @builtins.property
    def p_act_rl_y(self):
        """Message field 'p_act_rl_y'."""
        return self._p_act_rl_y

    @p_act_rl_y.setter
    def p_act_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rl_y = value

    @builtins.property
    def p_act_rl_z(self):
        """Message field 'p_act_rl_z'."""
        return self._p_act_rl_z

    @p_act_rl_z.setter
    def p_act_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rl_z = value

    @builtins.property
    def p_act_rr_x(self):
        """Message field 'p_act_rr_x'."""
        return self._p_act_rr_x

    @p_act_rr_x.setter
    def p_act_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rr_x = value

    @builtins.property
    def p_act_rr_y(self):
        """Message field 'p_act_rr_y'."""
        return self._p_act_rr_y

    @p_act_rr_y.setter
    def p_act_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rr_y = value

    @builtins.property
    def p_act_rr_z(self):
        """Message field 'p_act_rr_z'."""
        return self._p_act_rr_z

    @p_act_rr_z.setter
    def p_act_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'p_act_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'p_act_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._p_act_rr_z = value

    @builtins.property
    def v_ref_fl_x(self):
        """Message field 'v_ref_fl_x'."""
        return self._v_ref_fl_x

    @v_ref_fl_x.setter
    def v_ref_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fl_x = value

    @builtins.property
    def v_ref_fl_y(self):
        """Message field 'v_ref_fl_y'."""
        return self._v_ref_fl_y

    @v_ref_fl_y.setter
    def v_ref_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fl_y = value

    @builtins.property
    def v_ref_fl_z(self):
        """Message field 'v_ref_fl_z'."""
        return self._v_ref_fl_z

    @v_ref_fl_z.setter
    def v_ref_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fl_z = value

    @builtins.property
    def v_ref_fr_x(self):
        """Message field 'v_ref_fr_x'."""
        return self._v_ref_fr_x

    @v_ref_fr_x.setter
    def v_ref_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fr_x = value

    @builtins.property
    def v_ref_fr_y(self):
        """Message field 'v_ref_fr_y'."""
        return self._v_ref_fr_y

    @v_ref_fr_y.setter
    def v_ref_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fr_y = value

    @builtins.property
    def v_ref_fr_z(self):
        """Message field 'v_ref_fr_z'."""
        return self._v_ref_fr_z

    @v_ref_fr_z.setter
    def v_ref_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_fr_z = value

    @builtins.property
    def v_ref_rl_x(self):
        """Message field 'v_ref_rl_x'."""
        return self._v_ref_rl_x

    @v_ref_rl_x.setter
    def v_ref_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rl_x = value

    @builtins.property
    def v_ref_rl_y(self):
        """Message field 'v_ref_rl_y'."""
        return self._v_ref_rl_y

    @v_ref_rl_y.setter
    def v_ref_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rl_y = value

    @builtins.property
    def v_ref_rl_z(self):
        """Message field 'v_ref_rl_z'."""
        return self._v_ref_rl_z

    @v_ref_rl_z.setter
    def v_ref_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rl_z = value

    @builtins.property
    def v_ref_rr_x(self):
        """Message field 'v_ref_rr_x'."""
        return self._v_ref_rr_x

    @v_ref_rr_x.setter
    def v_ref_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rr_x = value

    @builtins.property
    def v_ref_rr_y(self):
        """Message field 'v_ref_rr_y'."""
        return self._v_ref_rr_y

    @v_ref_rr_y.setter
    def v_ref_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rr_y = value

    @builtins.property
    def v_ref_rr_z(self):
        """Message field 'v_ref_rr_z'."""
        return self._v_ref_rr_z

    @v_ref_rr_z.setter
    def v_ref_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_ref_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_ref_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_ref_rr_z = value

    @builtins.property
    def v_act_fl_x(self):
        """Message field 'v_act_fl_x'."""
        return self._v_act_fl_x

    @v_act_fl_x.setter
    def v_act_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fl_x = value

    @builtins.property
    def v_act_fl_y(self):
        """Message field 'v_act_fl_y'."""
        return self._v_act_fl_y

    @v_act_fl_y.setter
    def v_act_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fl_y = value

    @builtins.property
    def v_act_fl_z(self):
        """Message field 'v_act_fl_z'."""
        return self._v_act_fl_z

    @v_act_fl_z.setter
    def v_act_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fl_z = value

    @builtins.property
    def v_act_fr_x(self):
        """Message field 'v_act_fr_x'."""
        return self._v_act_fr_x

    @v_act_fr_x.setter
    def v_act_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fr_x = value

    @builtins.property
    def v_act_fr_y(self):
        """Message field 'v_act_fr_y'."""
        return self._v_act_fr_y

    @v_act_fr_y.setter
    def v_act_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fr_y = value

    @builtins.property
    def v_act_fr_z(self):
        """Message field 'v_act_fr_z'."""
        return self._v_act_fr_z

    @v_act_fr_z.setter
    def v_act_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_fr_z = value

    @builtins.property
    def v_act_rl_x(self):
        """Message field 'v_act_rl_x'."""
        return self._v_act_rl_x

    @v_act_rl_x.setter
    def v_act_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rl_x = value

    @builtins.property
    def v_act_rl_y(self):
        """Message field 'v_act_rl_y'."""
        return self._v_act_rl_y

    @v_act_rl_y.setter
    def v_act_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rl_y = value

    @builtins.property
    def v_act_rl_z(self):
        """Message field 'v_act_rl_z'."""
        return self._v_act_rl_z

    @v_act_rl_z.setter
    def v_act_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rl_z = value

    @builtins.property
    def v_act_rr_x(self):
        """Message field 'v_act_rr_x'."""
        return self._v_act_rr_x

    @v_act_rr_x.setter
    def v_act_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rr_x = value

    @builtins.property
    def v_act_rr_y(self):
        """Message field 'v_act_rr_y'."""
        return self._v_act_rr_y

    @v_act_rr_y.setter
    def v_act_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rr_y = value

    @builtins.property
    def v_act_rr_z(self):
        """Message field 'v_act_rr_z'."""
        return self._v_act_rr_z

    @v_act_rr_z.setter
    def v_act_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'v_act_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'v_act_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._v_act_rr_z = value

    @builtins.property
    def a_ref_fl_x(self):
        """Message field 'a_ref_fl_x'."""
        return self._a_ref_fl_x

    @a_ref_fl_x.setter
    def a_ref_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fl_x = value

    @builtins.property
    def a_ref_fl_y(self):
        """Message field 'a_ref_fl_y'."""
        return self._a_ref_fl_y

    @a_ref_fl_y.setter
    def a_ref_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fl_y = value

    @builtins.property
    def a_ref_fl_z(self):
        """Message field 'a_ref_fl_z'."""
        return self._a_ref_fl_z

    @a_ref_fl_z.setter
    def a_ref_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fl_z = value

    @builtins.property
    def a_ref_fr_x(self):
        """Message field 'a_ref_fr_x'."""
        return self._a_ref_fr_x

    @a_ref_fr_x.setter
    def a_ref_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fr_x = value

    @builtins.property
    def a_ref_fr_y(self):
        """Message field 'a_ref_fr_y'."""
        return self._a_ref_fr_y

    @a_ref_fr_y.setter
    def a_ref_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fr_y = value

    @builtins.property
    def a_ref_fr_z(self):
        """Message field 'a_ref_fr_z'."""
        return self._a_ref_fr_z

    @a_ref_fr_z.setter
    def a_ref_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_fr_z = value

    @builtins.property
    def a_ref_rl_x(self):
        """Message field 'a_ref_rl_x'."""
        return self._a_ref_rl_x

    @a_ref_rl_x.setter
    def a_ref_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rl_x = value

    @builtins.property
    def a_ref_rl_y(self):
        """Message field 'a_ref_rl_y'."""
        return self._a_ref_rl_y

    @a_ref_rl_y.setter
    def a_ref_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rl_y = value

    @builtins.property
    def a_ref_rl_z(self):
        """Message field 'a_ref_rl_z'."""
        return self._a_ref_rl_z

    @a_ref_rl_z.setter
    def a_ref_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rl_z = value

    @builtins.property
    def a_ref_rr_x(self):
        """Message field 'a_ref_rr_x'."""
        return self._a_ref_rr_x

    @a_ref_rr_x.setter
    def a_ref_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rr_x = value

    @builtins.property
    def a_ref_rr_y(self):
        """Message field 'a_ref_rr_y'."""
        return self._a_ref_rr_y

    @a_ref_rr_y.setter
    def a_ref_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rr_y = value

    @builtins.property
    def a_ref_rr_z(self):
        """Message field 'a_ref_rr_z'."""
        return self._a_ref_rr_z

    @a_ref_rr_z.setter
    def a_ref_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_ref_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_ref_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_ref_rr_z = value

    @builtins.property
    def a_act_fl_x(self):
        """Message field 'a_act_fl_x'."""
        return self._a_act_fl_x

    @a_act_fl_x.setter
    def a_act_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fl_x = value

    @builtins.property
    def a_act_fl_y(self):
        """Message field 'a_act_fl_y'."""
        return self._a_act_fl_y

    @a_act_fl_y.setter
    def a_act_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fl_y = value

    @builtins.property
    def a_act_fl_z(self):
        """Message field 'a_act_fl_z'."""
        return self._a_act_fl_z

    @a_act_fl_z.setter
    def a_act_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fl_z = value

    @builtins.property
    def a_act_fr_x(self):
        """Message field 'a_act_fr_x'."""
        return self._a_act_fr_x

    @a_act_fr_x.setter
    def a_act_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fr_x = value

    @builtins.property
    def a_act_fr_y(self):
        """Message field 'a_act_fr_y'."""
        return self._a_act_fr_y

    @a_act_fr_y.setter
    def a_act_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fr_y = value

    @builtins.property
    def a_act_fr_z(self):
        """Message field 'a_act_fr_z'."""
        return self._a_act_fr_z

    @a_act_fr_z.setter
    def a_act_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_fr_z = value

    @builtins.property
    def a_act_rl_x(self):
        """Message field 'a_act_rl_x'."""
        return self._a_act_rl_x

    @a_act_rl_x.setter
    def a_act_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rl_x = value

    @builtins.property
    def a_act_rl_y(self):
        """Message field 'a_act_rl_y'."""
        return self._a_act_rl_y

    @a_act_rl_y.setter
    def a_act_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rl_y = value

    @builtins.property
    def a_act_rl_z(self):
        """Message field 'a_act_rl_z'."""
        return self._a_act_rl_z

    @a_act_rl_z.setter
    def a_act_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rl_z = value

    @builtins.property
    def a_act_rr_x(self):
        """Message field 'a_act_rr_x'."""
        return self._a_act_rr_x

    @a_act_rr_x.setter
    def a_act_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rr_x = value

    @builtins.property
    def a_act_rr_y(self):
        """Message field 'a_act_rr_y'."""
        return self._a_act_rr_y

    @a_act_rr_y.setter
    def a_act_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rr_y = value

    @builtins.property
    def a_act_rr_z(self):
        """Message field 'a_act_rr_z'."""
        return self._a_act_rr_z

    @a_act_rr_z.setter
    def a_act_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'a_act_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'a_act_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._a_act_rr_z = value

    @builtins.property
    def f_mpc_fl_x(self):
        """Message field 'f_mpc_fl_x'."""
        return self._f_mpc_fl_x

    @f_mpc_fl_x.setter
    def f_mpc_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fl_x = value

    @builtins.property
    def f_mpc_fl_y(self):
        """Message field 'f_mpc_fl_y'."""
        return self._f_mpc_fl_y

    @f_mpc_fl_y.setter
    def f_mpc_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fl_y = value

    @builtins.property
    def f_mpc_fl_z(self):
        """Message field 'f_mpc_fl_z'."""
        return self._f_mpc_fl_z

    @f_mpc_fl_z.setter
    def f_mpc_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fl_z = value

    @builtins.property
    def f_mpc_fr_x(self):
        """Message field 'f_mpc_fr_x'."""
        return self._f_mpc_fr_x

    @f_mpc_fr_x.setter
    def f_mpc_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fr_x = value

    @builtins.property
    def f_mpc_fr_y(self):
        """Message field 'f_mpc_fr_y'."""
        return self._f_mpc_fr_y

    @f_mpc_fr_y.setter
    def f_mpc_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fr_y = value

    @builtins.property
    def f_mpc_fr_z(self):
        """Message field 'f_mpc_fr_z'."""
        return self._f_mpc_fr_z

    @f_mpc_fr_z.setter
    def f_mpc_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_fr_z = value

    @builtins.property
    def f_mpc_rl_x(self):
        """Message field 'f_mpc_rl_x'."""
        return self._f_mpc_rl_x

    @f_mpc_rl_x.setter
    def f_mpc_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rl_x = value

    @builtins.property
    def f_mpc_rl_y(self):
        """Message field 'f_mpc_rl_y'."""
        return self._f_mpc_rl_y

    @f_mpc_rl_y.setter
    def f_mpc_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rl_y = value

    @builtins.property
    def f_mpc_rl_z(self):
        """Message field 'f_mpc_rl_z'."""
        return self._f_mpc_rl_z

    @f_mpc_rl_z.setter
    def f_mpc_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rl_z = value

    @builtins.property
    def f_mpc_rr_x(self):
        """Message field 'f_mpc_rr_x'."""
        return self._f_mpc_rr_x

    @f_mpc_rr_x.setter
    def f_mpc_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rr_x = value

    @builtins.property
    def f_mpc_rr_y(self):
        """Message field 'f_mpc_rr_y'."""
        return self._f_mpc_rr_y

    @f_mpc_rr_y.setter
    def f_mpc_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rr_y = value

    @builtins.property
    def f_mpc_rr_z(self):
        """Message field 'f_mpc_rr_z'."""
        return self._f_mpc_rr_z

    @f_mpc_rr_z.setter
    def f_mpc_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_mpc_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_mpc_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_mpc_rr_z = value

    @builtins.property
    def f_wbc_fl_x(self):
        """Message field 'f_wbc_fl_x'."""
        return self._f_wbc_fl_x

    @f_wbc_fl_x.setter
    def f_wbc_fl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fl_x = value

    @builtins.property
    def f_wbc_fl_y(self):
        """Message field 'f_wbc_fl_y'."""
        return self._f_wbc_fl_y

    @f_wbc_fl_y.setter
    def f_wbc_fl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fl_y = value

    @builtins.property
    def f_wbc_fl_z(self):
        """Message field 'f_wbc_fl_z'."""
        return self._f_wbc_fl_z

    @f_wbc_fl_z.setter
    def f_wbc_fl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fl_z = value

    @builtins.property
    def f_wbc_fr_x(self):
        """Message field 'f_wbc_fr_x'."""
        return self._f_wbc_fr_x

    @f_wbc_fr_x.setter
    def f_wbc_fr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fr_x = value

    @builtins.property
    def f_wbc_fr_y(self):
        """Message field 'f_wbc_fr_y'."""
        return self._f_wbc_fr_y

    @f_wbc_fr_y.setter
    def f_wbc_fr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fr_y = value

    @builtins.property
    def f_wbc_fr_z(self):
        """Message field 'f_wbc_fr_z'."""
        return self._f_wbc_fr_z

    @f_wbc_fr_z.setter
    def f_wbc_fr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_fr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_fr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_fr_z = value

    @builtins.property
    def f_wbc_rl_x(self):
        """Message field 'f_wbc_rl_x'."""
        return self._f_wbc_rl_x

    @f_wbc_rl_x.setter
    def f_wbc_rl_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rl_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rl_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rl_x = value

    @builtins.property
    def f_wbc_rl_y(self):
        """Message field 'f_wbc_rl_y'."""
        return self._f_wbc_rl_y

    @f_wbc_rl_y.setter
    def f_wbc_rl_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rl_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rl_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rl_y = value

    @builtins.property
    def f_wbc_rl_z(self):
        """Message field 'f_wbc_rl_z'."""
        return self._f_wbc_rl_z

    @f_wbc_rl_z.setter
    def f_wbc_rl_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rl_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rl_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rl_z = value

    @builtins.property
    def f_wbc_rr_x(self):
        """Message field 'f_wbc_rr_x'."""
        return self._f_wbc_rr_x

    @f_wbc_rr_x.setter
    def f_wbc_rr_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rr_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rr_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rr_x = value

    @builtins.property
    def f_wbc_rr_y(self):
        """Message field 'f_wbc_rr_y'."""
        return self._f_wbc_rr_y

    @f_wbc_rr_y.setter
    def f_wbc_rr_y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rr_y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rr_y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rr_y = value

    @builtins.property
    def f_wbc_rr_z(self):
        """Message field 'f_wbc_rr_z'."""
        return self._f_wbc_rr_z

    @f_wbc_rr_z.setter
    def f_wbc_rr_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'f_wbc_rr_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'f_wbc_rr_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._f_wbc_rr_z = value

    @builtins.property
    def contact_fl(self):
        """Message field 'contact_fl'."""
        return self._contact_fl

    @contact_fl.setter
    def contact_fl(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'contact_fl' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'contact_fl' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._contact_fl = value

    @builtins.property
    def contact_fr(self):
        """Message field 'contact_fr'."""
        return self._contact_fr

    @contact_fr.setter
    def contact_fr(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'contact_fr' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'contact_fr' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._contact_fr = value

    @builtins.property
    def contact_rl(self):
        """Message field 'contact_rl'."""
        return self._contact_rl

    @contact_rl.setter
    def contact_rl(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'contact_rl' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'contact_rl' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._contact_rl = value

    @builtins.property
    def contact_rr(self):
        """Message field 'contact_rr'."""
        return self._contact_rr

    @contact_rr.setter
    def contact_rr(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'contact_rr' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'contact_rr' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._contact_rr = value

    @builtins.property
    def body_x(self):
        """Message field 'body_x'."""
        return self._body_x

    @body_x.setter
    def body_x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_x = value

    @builtins.property
    def body_z(self):
        """Message field 'body_z'."""
        return self._body_z

    @body_z.setter
    def body_z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_z = value

    @builtins.property
    def body_x_v(self):
        """Message field 'body_x_v'."""
        return self._body_x_v

    @body_x_v.setter
    def body_x_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_x_v' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_x_v' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_x_v = value

    @builtins.property
    def body_z_v(self):
        """Message field 'body_z_v'."""
        return self._body_z_v

    @body_z_v.setter
    def body_z_v(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_z_v' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_z_v' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_z_v = value

    @builtins.property
    def body_x_v_d(self):
        """Message field 'body_x_v_d'."""
        return self._body_x_v_d

    @body_x_v_d.setter
    def body_x_v_d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_x_v_d' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_x_v_d' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_x_v_d = value

    @builtins.property
    def body_z_v_d(self):
        """Message field 'body_z_v_d'."""
        return self._body_z_v_d

    @body_z_v_d.setter
    def body_z_v_d(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'body_z_v_d' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'body_z_v_d' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._body_z_v_d = value
