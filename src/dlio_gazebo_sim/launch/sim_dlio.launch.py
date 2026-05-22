from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, IncludeLaunchDescription, SetEnvironmentVariable
from launch.conditions import IfCondition, UnlessCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare('dlio_gazebo_sim')
    gz_pkg = FindPackageShare('ros_gz_sim')
    dlio_pkg = FindPackageShare('direct_lidar_inertial_odometry')
    elevation_pkg = FindPackageShare('elevation_mapping_cupy')

    world = PathJoinSubstitution([pkg, 'worlds', 'dlio_room.sdf'])
    model_path = PathJoinSubstitution([pkg, 'models'])

    rviz = LaunchConfiguration('rviz')
    gz_gui = LaunchConfiguration('gz_gui')
    linear_x = LaunchConfiguration('linear_x')
    angular_z = LaunchConfiguration('angular_z')
    start_delay = LaunchConfiguration('start_delay')
    auto_drive = LaunchConfiguration('auto_drive')
    launch_elevation = LaunchConfiguration('launch_elevation')
    use_synthetic_sensors = LaunchConfiguration('use_synthetic_sensors')
    use_gazebo_cloud_adapter = LaunchConfiguration('use_gazebo_cloud_adapter')

    gazebo_gui = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([gz_pkg, 'launch', 'gz_sim.launch.py'])
        ),
        launch_arguments={
            'gz_args': ['-r ', world],
            'on_exit_shutdown': 'True',
        }.items(),
        condition=IfCondition(gz_gui),
    )

    gazebo_headless = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([gz_pkg, 'launch', 'gz_sim.launch.py'])
        ),
        launch_arguments={
            'gz_args': ['-r -s ', world],
            'on_exit_shutdown': 'True',
        }.items(),
        condition=UnlessCondition(gz_gui),
    )

    dlio = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': rviz,
            'pointcloud_topic': '/points_raw',
            'imu_topic': '/imu_raw',
        }.items(),
    )

    elevation_mapping = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([elevation_pkg, 'launch', 'elevation_mapping.launch.py'])
        ),
        launch_arguments={
            'robot_config': 'dlio_gazebo/base.yaml',
            'launch_rviz': 'false',
            'use_sim_time': 'true',
        }.items(),
        condition=IfCondition(launch_elevation),
    )

    bridge = Node(
        package='ros_gz_bridge',
        executable='parameter_bridge',
        name='dlio_gz_bridge',
        arguments=[
            '/clock@rosgraph_msgs/msg/Clock[gz.msgs.Clock',
            '/cmd_vel@geometry_msgs/msg/Twist]gz.msgs.Twist',
            '/gazebo/odom@nav_msgs/msg/Odometry[gz.msgs.Odometry',
            '/model/dlio_car/pose@geometry_msgs/msg/Pose[gz.msgs.Pose',
            '/points_raw/points@sensor_msgs/msg/PointCloud2[gz.msgs.PointCloudPacked',
            '/imu_raw@sensor_msgs/msg/Imu[gz.msgs.IMU',
        ],
        output='screen',
    )

    synthetic_sensors = Node(
        package='dlio_gazebo_sim',
        executable='synthetic_dlio_sensors',
        output='screen',
        condition=IfCondition(use_synthetic_sensors),
        parameters=[{
            'use_sim_time': True,
            'pointcloud_topic': '/points_raw',
            'imu_topic': '/imu_raw',
            'start_delay': start_delay,
            'linear_x': linear_x,
            'angular_z': angular_z,
        }],
    )

    gazebo_cloud_adapter = Node(
        package='dlio_gazebo_sim',
        executable='gazebo_cloud_adapter',
        output='screen',
        condition=IfCondition(use_gazebo_cloud_adapter),
        parameters=[{
            'use_sim_time': True,
            'input_topic': '/points_raw/points',
            'output_topic': '/points_raw',
            'frame_id': 'lidar',
        }],
    )

    circle_cmd = Node(
        package='dlio_gazebo_sim',
        executable='circle_cmd',
        output='screen',
        condition=IfCondition(auto_drive),
        parameters=[{
            'use_sim_time': True,
            'cmd_vel_topic': '/cmd_vel',
            'start_delay': start_delay,
            'linear_x': linear_x,
            'angular_z': angular_z,
        }],
    )

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true'),
        DeclareLaunchArgument('gz_gui', default_value='true'),
        DeclareLaunchArgument('linear_x', default_value='0.45'),
        DeclareLaunchArgument('angular_z', default_value='0.22'),
        DeclareLaunchArgument('start_delay', default_value='4.0'),
        DeclareLaunchArgument('auto_drive', default_value='false'),
        DeclareLaunchArgument('launch_elevation', default_value='true'),
        DeclareLaunchArgument('use_synthetic_sensors', default_value='false'),
        DeclareLaunchArgument('use_gazebo_cloud_adapter', default_value='true'),
        SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', model_path),
        gazebo_gui,
        gazebo_headless,
        bridge,
        gazebo_cloud_adapter,
        synthetic_sensors,
        circle_cmd,
        dlio,
        elevation_mapping,
    ])
