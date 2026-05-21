#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "direct_lidar_inertial_odometry__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD_Request() -> *const std::ffi::c_void;
}

#[link(name = "direct_lidar_inertial_odometry__rosidl_generator_c")]
extern "C" {
    fn direct_lidar_inertial_odometry__srv__SavePCD_Request__init(msg: *mut SavePCD_Request) -> bool;
    fn direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Request>, size: usize) -> bool;
    fn direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Request>);
    fn direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SavePCD_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Request>) -> bool;
}

// Corresponds to direct_lidar_inertial_odometry__srv__SavePCD_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SavePCD_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub leaf_size: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub save_path: rosidl_runtime_rs::String,

}



impl Default for SavePCD_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !direct_lidar_inertial_odometry__srv__SavePCD_Request__init(&mut msg as *mut _) {
        panic!("Call to direct_lidar_inertial_odometry__srv__SavePCD_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SavePCD_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SavePCD_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SavePCD_Request where Self: Sized {
  const TYPE_NAME: &'static str = "direct_lidar_inertial_odometry/srv/SavePCD_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD_Request() }
  }
}


#[link(name = "direct_lidar_inertial_odometry__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD_Response() -> *const std::ffi::c_void;
}

#[link(name = "direct_lidar_inertial_odometry__rosidl_generator_c")]
extern "C" {
    fn direct_lidar_inertial_odometry__srv__SavePCD_Response__init(msg: *mut SavePCD_Response) -> bool;
    fn direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Response>, size: usize) -> bool;
    fn direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Response>);
    fn direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SavePCD_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SavePCD_Response>) -> bool;
}

// Corresponds to direct_lidar_inertial_odometry__srv__SavePCD_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SavePCD_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SavePCD_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !direct_lidar_inertial_odometry__srv__SavePCD_Response__init(&mut msg as *mut _) {
        panic!("Call to direct_lidar_inertial_odometry__srv__SavePCD_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SavePCD_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { direct_lidar_inertial_odometry__srv__SavePCD_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SavePCD_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SavePCD_Response where Self: Sized {
  const TYPE_NAME: &'static str = "direct_lidar_inertial_odometry/srv/SavePCD_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD_Response() }
  }
}






#[link(name = "direct_lidar_inertial_odometry__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD() -> *const std::ffi::c_void;
}

// Corresponds to direct_lidar_inertial_odometry__srv__SavePCD
#[allow(missing_docs, non_camel_case_types)]
pub struct SavePCD;

impl rosidl_runtime_rs::Service for SavePCD {
    type Request = SavePCD_Request;
    type Response = SavePCD_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__direct_lidar_inertial_odometry__srv__SavePCD() }
    }
}


