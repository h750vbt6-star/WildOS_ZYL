#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to gps_visualization__msg__NavSatFixArray

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct NavSatFixArray {

    // This member is not documented.
    #[allow(missing_docs)]
    pub gps_fixes: Vec<sensor_msgs::msg::NavSatFix>,

}



impl Default for NavSatFixArray {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::NavSatFixArray::default())
  }
}

impl rosidl_runtime_rs::Message for NavSatFixArray {
  type RmwMsg = super::msg::rmw::NavSatFixArray;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gps_fixes: msg.gps_fixes
          .into_iter()
          .map(|elem| sensor_msgs::msg::NavSatFix::into_rmw_message(std::borrow::Cow::Owned(elem)).into_owned())
          .collect(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        gps_fixes: msg.gps_fixes
          .iter()
          .map(|elem| sensor_msgs::msg::NavSatFix::into_rmw_message(std::borrow::Cow::Borrowed(elem)).into_owned())
          .collect(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      gps_fixes: msg.gps_fixes
          .into_iter()
          .map(sensor_msgs::msg::NavSatFix::from_rmw_message)
          .collect(),
    }
  }
}


