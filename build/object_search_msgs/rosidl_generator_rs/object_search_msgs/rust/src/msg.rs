#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to object_search_msgs__msg__ObjectMaskWithTf

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct ObjectMaskWithTf {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub odom: nav_msgs::msg::Odometry,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cam_infos: Vec<sensor_msgs::msg::CameraInfo>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub object_mask: std_msgs::msg::UInt8MultiArray,


    // This member is not documented.
    #[allow(missing_docs)]
    pub cam_transforms: tf2_msgs::msg::TFMessage,

}



impl Default for ObjectMaskWithTf {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::ObjectMaskWithTf::default())
  }
}

impl rosidl_runtime_rs::Message for ObjectMaskWithTf {
  type RmwMsg = super::msg::rmw::ObjectMaskWithTf;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        odom: nav_msgs::msg::Odometry::into_rmw_message(std::borrow::Cow::Owned(msg.odom)).into_owned(),
        cam_infos: msg.cam_infos
          .into_iter()
          .map(|elem| sensor_msgs::msg::CameraInfo::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
        object_mask: std_msgs::msg::UInt8MultiArray::into_rmw_message(std::borrow::Cow::Owned(msg.object_mask)).into_owned(),
        cam_transforms: tf2_msgs::msg::TFMessage::into_rmw_message(std::borrow::Cow::Owned(msg.cam_transforms)).into_owned(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        odom: nav_msgs::msg::Odometry::into_rmw_message(std::borrow::Cow::Borrowed(&msg.odom)).into_owned(),
        cam_infos: msg.cam_infos
          .iter()
          .map(|elem| sensor_msgs::msg::CameraInfo::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
        object_mask: std_msgs::msg::UInt8MultiArray::into_rmw_message(std::borrow::Cow::Borrowed(&msg.object_mask)).into_owned(),
        cam_transforms: tf2_msgs::msg::TFMessage::into_rmw_message(std::borrow::Cow::Borrowed(&msg.cam_transforms)).into_owned(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      odom: nav_msgs::msg::Odometry::from_rmw_message(msg.odom),
      cam_infos: msg.cam_infos
          .into_iter()
          .map(sensor_msgs::msg::CameraInfo::from_rmw_message)
          .collect(),
      object_mask: std_msgs::msg::UInt8MultiArray::from_rmw_message(msg.object_mask),
      cam_transforms: tf2_msgs::msg::TFMessage::from_rmw_message(msg.cam_transforms),
    }
  }
}


