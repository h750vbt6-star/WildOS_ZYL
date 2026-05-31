# generated from rosidl_generator_py/resource/_idl.py.em
# with input from object_search_msgs:msg/ObjectMaskWithTf.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_ObjectMaskWithTf(type):
    """Metaclass of message 'ObjectMaskWithTf'."""

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
            module = import_type_support('object_search_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'object_search_msgs.msg.ObjectMaskWithTf')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__object_mask_with_tf
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__object_mask_with_tf
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__object_mask_with_tf
            cls._TYPE_SUPPORT = module.type_support_msg__msg__object_mask_with_tf
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__object_mask_with_tf

            from nav_msgs.msg import Odometry
            if Odometry.__class__._TYPE_SUPPORT is None:
                Odometry.__class__.__import_type_support__()

            from sensor_msgs.msg import CameraInfo
            if CameraInfo.__class__._TYPE_SUPPORT is None:
                CameraInfo.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

            from std_msgs.msg import UInt8MultiArray
            if UInt8MultiArray.__class__._TYPE_SUPPORT is None:
                UInt8MultiArray.__class__.__import_type_support__()

            from tf2_msgs.msg import TFMessage
            if TFMessage.__class__._TYPE_SUPPORT is None:
                TFMessage.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class ObjectMaskWithTf(metaclass=Metaclass_ObjectMaskWithTf):
    """Message class 'ObjectMaskWithTf'."""

    __slots__ = [
        '_header',
        '_odom',
        '_cam_infos',
        '_object_mask',
        '_cam_transforms',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'odom': 'nav_msgs/Odometry',
        'cam_infos': 'sequence<sensor_msgs/CameraInfo>',
        'object_mask': 'std_msgs/UInt8MultiArray',
        'cam_transforms': 'tf2_msgs/TFMessage',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['nav_msgs', 'msg'], 'Odometry'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['sensor_msgs', 'msg'], 'CameraInfo')),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'UInt8MultiArray'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['tf2_msgs', 'msg'], 'TFMessage'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        from nav_msgs.msg import Odometry
        self.odom = kwargs.get('odom', Odometry())
        self.cam_infos = kwargs.get('cam_infos', [])
        from std_msgs.msg import UInt8MultiArray
        self.object_mask = kwargs.get('object_mask', UInt8MultiArray())
        from tf2_msgs.msg import TFMessage
        self.cam_transforms = kwargs.get('cam_transforms', TFMessage())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
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
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.odom != other.odom:
            return False
        if self.cam_infos != other.cam_infos:
            return False
        if self.object_mask != other.object_mask:
            return False
        if self.cam_transforms != other.cam_transforms:
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
        if self._check_fields:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def odom(self):
        """Message field 'odom'."""
        return self._odom

    @odom.setter
    def odom(self, value):
        if self._check_fields:
            from nav_msgs.msg import Odometry
            assert \
                isinstance(value, Odometry), \
                "The 'odom' field must be a sub message of type 'Odometry'"
        self._odom = value

    @builtins.property
    def cam_infos(self):
        """Message field 'cam_infos'."""
        return self._cam_infos

    @cam_infos.setter
    def cam_infos(self, value):
        if self._check_fields:
            from sensor_msgs.msg import CameraInfo
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, CameraInfo) for v in value) and
                 True), \
                "The 'cam_infos' field must be a set or sequence and each value of type 'CameraInfo'"
        self._cam_infos = value

    @builtins.property
    def object_mask(self):
        """Message field 'object_mask'."""
        return self._object_mask

    @object_mask.setter
    def object_mask(self, value):
        if self._check_fields:
            from std_msgs.msg import UInt8MultiArray
            assert \
                isinstance(value, UInt8MultiArray), \
                "The 'object_mask' field must be a sub message of type 'UInt8MultiArray'"
        self._object_mask = value

    @builtins.property
    def cam_transforms(self):
        """Message field 'cam_transforms'."""
        return self._cam_transforms

    @cam_transforms.setter
    def cam_transforms(self, value):
        if self._check_fields:
            from tf2_msgs.msg import TFMessage
            assert \
                isinstance(value, TFMessage), \
                "The 'cam_transforms' field must be a sub message of type 'TFMessage'"
        self._cam_transforms = value
