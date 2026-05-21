#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to direct_lidar_inertial_odometry__srv__SavePCD_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SavePCD_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub leaf_size: f32,


    // This member is not documented.
    #[allow(missing_docs)]
    pub save_path: std::string::String,

}



impl Default for SavePCD_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SavePCD_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SavePCD_Request {
  type RmwMsg = super::srv::rmw::SavePCD_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        leaf_size: msg.leaf_size,
        save_path: msg.save_path.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      leaf_size: msg.leaf_size,
        save_path: msg.save_path.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      leaf_size: msg.leaf_size,
      save_path: msg.save_path.to_string(),
    }
  }
}


// Corresponds to direct_lidar_inertial_odometry__srv__SavePCD_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SavePCD_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for SavePCD_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SavePCD_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SavePCD_Response {
  type RmwMsg = super::srv::rmw::SavePCD_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
    }
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


