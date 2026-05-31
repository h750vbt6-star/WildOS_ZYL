#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "object_search_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__object_search_msgs__msg__ObjectMaskWithTf() -> *const std::ffi::c_void;
}

#[link(name = "object_search_msgs__rosidl_generator_c")]
extern "C" {
    fn object_search_msgs__msg__ObjectMaskWithTf__init(msg: *mut ObjectMaskWithTf) -> bool;
    fn object_search_msgs__msg__ObjectMaskWithTf__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ObjectMaskWithTf>, size: usize) -> bool;
    fn object_search_msgs__msg__ObjectMaskWithTf__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ObjectMaskWithTf>);
    fn object_search_msgs__msg__ObjectMaskWithTf__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ObjectMaskWithTf>, out_seq: *mut rosidl_runtime_rs::Sequence<ObjectMaskWithTf>) -> bool;
}

// Corresponds to object_search_msgs__msg__ObjectMaskWithTf
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectMaskWithTf {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub odom: nav_msgs::msg::rmw::Odometry,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cam_infos: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::CameraInfo>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object_mask: std_msgs::msg::rmw::UInt8MultiArray,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cam_transforms: tf2_msgs::msg::rmw::TFMessage,

}



impl Default for ObjectMaskWithTf {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !object_search_msgs__msg__ObjectMaskWithTf__init(&mut msg as *mut _) {
        panic!("Call to object_search_msgs__msg__ObjectMaskWithTf__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ObjectMaskWithTf {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { object_search_msgs__msg__ObjectMaskWithTf__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { object_search_msgs__msg__ObjectMaskWithTf__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { object_search_msgs__msg__ObjectMaskWithTf__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ObjectMaskWithTf {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ObjectMaskWithTf where Self: Sized {
  const TYPE_NAME: &'static str = "object_search_msgs/msg/ObjectMaskWithTf";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__object_search_msgs__msg__ObjectMaskWithTf() }
  }
}


