#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "gps_visualization__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__gps_visualization__msg__NavSatFixArray() -> *const std::ffi::c_void;
}

#[link(name = "gps_visualization__rosidl_generator_c")]
extern "C" {
    fn gps_visualization__msg__NavSatFixArray__init(msg: *mut NavSatFixArray) -> bool;
    fn gps_visualization__msg__NavSatFixArray__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<NavSatFixArray>, size: usize) -> bool;
    fn gps_visualization__msg__NavSatFixArray__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<NavSatFixArray>);
    fn gps_visualization__msg__NavSatFixArray__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<NavSatFixArray>, out_seq: *mut rosidl_runtime_rs::Sequence<NavSatFixArray>) -> bool;
}

// Corresponds to gps_visualization__msg__NavSatFixArray
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavSatFixArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_fixes: rosidl_runtime_rs::Sequence<sensor_msgs::msg::rmw::NavSatFix>,

}



impl Default for NavSatFixArray {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !gps_visualization__msg__NavSatFixArray__init(&mut msg as *mut _) {
        panic!("Call to gps_visualization__msg__NavSatFixArray__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for NavSatFixArray {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gps_visualization__msg__NavSatFixArray__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gps_visualization__msg__NavSatFixArray__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { gps_visualization__msg__NavSatFixArray__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for NavSatFixArray {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for NavSatFixArray where Self: Sized {
  const TYPE_NAME: &'static str = "gps_visualization/msg/NavSatFixArray";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__gps_visualization__msg__NavSatFixArray() }
  }
}


