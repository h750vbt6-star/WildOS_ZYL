#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to elevation_map_msgs__srv__CheckSafety_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckSafety_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub polygons: Vec<geometry_msgs::msg::PolygonStamped>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub compute_untraversable_polygon: bool,

}



impl Default for CheckSafety_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::CheckSafety_Request::default())
  }
}

impl rosidl_runtime_rs::Message for CheckSafety_Request {
  type RmwMsg = super::srv::rmw::CheckSafety_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        polygons: msg.polygons
          .into_iter()
          .map(|elem| geometry_msgs::msg::PolygonStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        compute_untraversable_polygon: msg.compute_untraversable_polygon,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        polygons: msg.polygons
          .iter()
          .map(|elem| geometry_msgs::msg::PolygonStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      compute_untraversable_polygon: msg.compute_untraversable_polygon,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      polygons: msg.polygons
          .into_iter()
          .map(geometry_msgs::msg::PolygonStamped::from_rmw_message)
          .collect(),
      compute_untraversable_polygon: msg.compute_untraversable_polygon,
    }
  }
}


// Corresponds to elevation_map_msgs__srv__CheckSafety_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct CheckSafety_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub is_safe: Vec<bool>,

    /// Estimate of the traversability of the path.
    /// Ranges from 0 to 1 where 0 means not traversable and 1 highly traversable.
    pub traversability: Vec<f64>,

    /// Polygons that are untraversable.
    pub untraversable_polygons: Vec<geometry_msgs::msg::PolygonStamped>,

}



impl Default for CheckSafety_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::CheckSafety_Response::default())
  }
}

impl rosidl_runtime_rs::Message for CheckSafety_Response {
  type RmwMsg = super::srv::rmw::CheckSafety_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_safe: msg.is_safe.into(),
        traversability: msg.traversability.into(),
        untraversable_polygons: msg.untraversable_polygons
          .into_iter()
          .map(|elem| geometry_msgs::msg::PolygonStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        is_safe: msg.is_safe.as_slice().into(),
        traversability: msg.traversability.as_slice().into(),
        untraversable_polygons: msg.untraversable_polygons
          .iter()
          .map(|elem| geometry_msgs::msg::PolygonStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      is_safe: msg.is_safe
          .into_iter()
          .collect(),
      traversability: msg.traversability
          .into_iter()
          .collect(),
      untraversable_polygons: msg.untraversable_polygons
          .into_iter()
          .map(geometry_msgs::msg::PolygonStamped::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to elevation_map_msgs__srv__Initialize_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
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
    pub points: Vec<geometry_msgs::msg::PointStamped>,

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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Initialize_Request::default())
  }
}

impl rosidl_runtime_rs::Message for Initialize_Request {
  type RmwMsg = super::srv::rmw::Initialize_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        type_: msg.type_,
        method: msg.method,
        points: msg.points
          .into_iter()
          .map(|elem| geometry_msgs::msg::PointStamped::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      type_: msg.type_,
      method: msg.method,
        points: msg.points
          .iter()
          .map(|elem| geometry_msgs::msg::PointStamped::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      type_: msg.type_,
      method: msg.method,
      points: msg.points
          .into_iter()
          .map(geometry_msgs::msg::PointStamped::from_rmw_message)
          .collect(),
    }
  }
}


// Corresponds to elevation_map_msgs__srv__Initialize_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Initialize_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,

}



impl Default for Initialize_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::Initialize_Response::default())
  }
}

impl rosidl_runtime_rs::Message for Initialize_Response {
  type RmwMsg = super::srv::rmw::Initialize_Response;

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


