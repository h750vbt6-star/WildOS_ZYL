from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def generate_launch_description():
    camera_names = LaunchConfiguration('camera_names')
    cam0_topic = LaunchConfiguration('cam0_topic')
    cam1_topic = LaunchConfiguration('cam1_topic')
    cam2_topic = LaunchConfiguration('cam2_topic')
    horizontal_fov_deg = LaunchConfiguration('horizontal_fov_deg')
    fx = LaunchConfiguration('fx')
    fy = LaunchConfiguration('fy')
    cx = LaunchConfiguration('cx')
    cy = LaunchConfiguration('cy')

    return LaunchDescription([
        DeclareLaunchArgument('camera_names', default_value="['front', 'left', 'right']"),
        DeclareLaunchArgument(
            'cam0_topic',
            default_value='/alphasense_driver_ros/cam0/debayered/image/compressed',
        ),
        DeclareLaunchArgument(
            'cam1_topic',
            default_value='/alphasense_driver_ros/cam1/debayered/image/compressed',
        ),
        DeclareLaunchArgument(
            'cam2_topic',
            default_value='/alphasense_driver_ros/cam2/debayered/image/compressed',
        ),
        DeclareLaunchArgument('horizontal_fov_deg', default_value='90.0'),
        DeclareLaunchArgument('fx', default_value='0.0'),
        DeclareLaunchArgument('fy', default_value='0.0'),
        DeclareLaunchArgument('cx', default_value='0.0'),
        DeclareLaunchArgument('cy', default_value='0.0'),
        Node(
            package='wildos_rosbag_bridge',
            executable='alphasense_to_wildos',
            name='alphasense_to_wildos',
            output='screen',
            parameters=[{
                'camera_names': camera_names,
                'cam0_topic': cam0_topic,
                'cam1_topic': cam1_topic,
                'cam2_topic': cam2_topic,
                'horizontal_fov_deg': horizontal_fov_deg,
                'fx': fx,
                'fy': fy,
                'cx': cx,
                'cy': cy,
            }],
        ),
    ])
