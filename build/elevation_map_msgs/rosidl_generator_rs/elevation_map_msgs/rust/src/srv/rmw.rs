#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__CheckSafety_Request() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__srv__CheckSafety_Request__init(msg: *mut CheckSafety_Request) -> bool;
    fn elevation_map_msgs__srv__CheckSafety_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Request>, size: usize) -> bool;
    fn elevation_map_msgs__srv__CheckSafety_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Request>);
    fn elevation_map_msgs__srv__CheckSafety_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CheckSafety_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Request>) -> bool;
}

// Corresponds to elevation_map_msgs__srv__CheckSafety_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckSafety_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub polygons: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::PolygonStamped>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub compute_untraversable_polygon: bool,

}



impl Default for CheckSafety_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__srv__CheckSafety_Request__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__srv__CheckSafety_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CheckSafety_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CheckSafety_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CheckSafety_Request where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/srv/CheckSafety_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__CheckSafety_Request() }
  }
}


#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__CheckSafety_Response() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__srv__CheckSafety_Response__init(msg: *mut CheckSafety_Response) -> bool;
    fn elevation_map_msgs__srv__CheckSafety_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Response>, size: usize) -> bool;
    fn elevation_map_msgs__srv__CheckSafety_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Response>);
    fn elevation_map_msgs__srv__CheckSafety_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<CheckSafety_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<CheckSafety_Response>) -> bool;
}

// Corresponds to elevation_map_msgs__srv__CheckSafety_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckSafety_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_safe: rosidl_runtime_rs::Sequence<bool>,

    /// Estimate of the traversability of the path.
    /// Ranges from 0 to 1 where 0 means not traversable and 1 highly traversable.
    pub traversability: rosidl_runtime_rs::Sequence<f64>,

    /// Polygons that are untraversable.
    pub untraversable_polygons: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::PolygonStamped>,

}



impl Default for CheckSafety_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__srv__CheckSafety_Response__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__srv__CheckSafety_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for CheckSafety_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__CheckSafety_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for CheckSafety_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for CheckSafety_Response where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/srv/CheckSafety_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__CheckSafety_Response() }
  }
}


#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__Initialize_Request() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__srv__Initialize_Request__init(msg: *mut Initialize_Request) -> bool;
    fn elevation_map_msgs__srv__Initialize_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Initialize_Request>, size: usize) -> bool;
    fn elevation_map_msgs__srv__Initialize_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Initialize_Request>);
    fn elevation_map_msgs__srv__Initialize_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Initialize_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<Initialize_Request>) -> bool;
}

// Corresponds to elevation_map_msgs__srv__Initialize_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Initialize_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub type_: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub method: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub points: rosidl_runtime_rs::Sequence<geometry_msgs::msg::rmw::PointStamped>,

}

impl Initialize_Request {

    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POINTS: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const NEAREST: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const LINEAR: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const CUBIC: u8 = 2;

}


impl Default for Initialize_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__srv__Initialize_Request__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__srv__Initialize_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Initialize_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Initialize_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Initialize_Request where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/srv/Initialize_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__Initialize_Request() }
  }
}


#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__Initialize_Response() -> *const std::ffi::c_void;
}

#[link(name = "elevation_map_msgs__rosidl_generator_c")]
extern "C" {
    fn elevation_map_msgs__srv__Initialize_Response__init(msg: *mut Initialize_Response) -> bool;
    fn elevation_map_msgs__srv__Initialize_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Initialize_Response>, size: usize) -> bool;
    fn elevation_map_msgs__srv__Initialize_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Initialize_Response>);
    fn elevation_map_msgs__srv__Initialize_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Initialize_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<Initialize_Response>) -> bool;
}

// Corresponds to elevation_map_msgs__srv__Initialize_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Initialize_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Initialize_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !elevation_map_msgs__srv__Initialize_Response__init(&mut msg as *mut _) {
        panic!("Call to elevation_map_msgs__srv__Initialize_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Initialize_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { elevation_map_msgs__srv__Initialize_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Initialize_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Initialize_Response where Self: Sized {
  const TYPE_NAME: &'static str = "elevation_map_msgs/srv/Initialize_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__elevation_map_msgs__srv__Initialize_Response() }
  }
}






#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__elevation_map_msgs__srv__CheckSafety() -> *const std::ffi::c_void;
}

// Corresponds to elevation_map_msgs__srv__CheckSafety
#[allow(missing_docs, non_camel_case_types)]
pub struct CheckSafety;

impl rosidl_runtime_rs::Service for CheckSafety {
    type Request = CheckSafety_Request;
    type Response = CheckSafety_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__elevation_map_msgs__srv__CheckSafety() }
    }
}




#[link(name = "elevation_map_msgs__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__elevation_map_msgs__srv__Initialize() -> *const std::ffi::c_void;
}

// Corresponds to elevation_map_msgs__srv__Initialize
#[allow(missing_docs, non_camel_case_types)]
pub struct Initialize;

impl rosidl_runtime_rs::Service for Initialize {
    type Request = Initialize_Request;
    type Response = Initialize_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__elevation_map_msgs__srv__Initialize() }
    }
}


