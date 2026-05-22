#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__msg__Statistics() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__msg__Statistics__init(msg: *mut Statistics) -> bool;
    fn elevation_map_msgs__msg__Statistics__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Statistics>, size: usize) -> bool;
    fn elevation_map_msgs__msg__Statistics__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Statistics>);
    fn elevation_map_msgs__msg__Statistics__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Statistics>, out_seq: *mut rosidl_runtime_rs::Sequence<Statistics>) -> bool;
}

// Corresponds to elevation_map_msgs__msg__Statistics
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Statistics {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pointcloud_process_fps: f64,

}



impl Default for Statistics {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__msg__Statistics__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__msg__Statistics__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Statistics {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__Statistics__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__Statistics__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__Statistics__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Statistics {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Statistics where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/msg/Statistics";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__msg__Statistics() }
  }
}


#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__msg__ChannelInfo() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__msg__ChannelInfo__init(msg: *mut ChannelInfo) -> bool;
    fn elevation_map_msgs__msg__ChannelInfo__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<ChannelInfo>, size: usize) -> bool;
    fn elevation_map_msgs__msg__ChannelInfo__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<ChannelInfo>);
    fn elevation_map_msgs__msg__ChannelInfo__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<ChannelInfo>, out_seq: *mut rosidl_runtime_rs::Sequence<ChannelInfo>) -> bool;
}

// Corresponds to elevation_map_msgs__msg__ChannelInfo
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ChannelInfo {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,

    /// channel names for each layer
    pub channels: rosidl_runtime_rs::Sequence<rosidl_runtime_rs::String>,

}



impl Default for ChannelInfo {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__msg__ChannelInfo__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__msg__ChannelInfo__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for ChannelInfo {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__ChannelInfo__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__ChannelInfo__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__msg__ChannelInfo__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for ChannelInfo {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for ChannelInfo where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/msg/ChannelInfo";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__msg__ChannelInfo() }
  }
}


