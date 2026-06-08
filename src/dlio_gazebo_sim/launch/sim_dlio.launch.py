from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, SetEnvironmentVariable, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import EnvironmentVariable, LaunchConfiguration, PathJoinSubstitution, PythonExpression
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare('dlio_gazebo_sim')
    gz_pkg = FindPackageShare('ros_gz_sim')
    dlio_pkg = FindPackageShare('direct_lidar_inertial_odometry')
    elevation_pkg = FindPackageShare('elevation_mapping_cupy')
    wildos_bridge_pkg = FindPackageShare('wildos_rosbag_bridge')

    world_name = LaunchConfiguration('world')
    world = PathJoinSubstitution([pkg, 'worlds', world_name])
    model_path = PathJoinSubstitution([pkg, 'models'])
    wildos_source_path = '/root/ros2_ws/src/nebula2-wildos-main'
    cuda_path = '/usr/local/lib/python3.12/dist-packages/nvidia/cuda_runtime'
    cuda_nvrtc_lib = '/usr/local/lib/python3.12/dist-packages/nvidia/cuda_nvrtc/lib'

    rviz = LaunchConfiguration('rviz')
    gz_gui = LaunchConfiguration('gz_gui')
    data_source = LaunchConfiguration('data_source')
    dlio_output = LaunchConfiguration('dlio_output')
    pointcloud_topic = LaunchConfiguration('pointcloud_topic')
    imu_topic = LaunchConfiguration('imu_topic')
    rosbag_path = LaunchConfiguration('rosbag_path')
    rosbag_pointcloud_topic = LaunchConfiguration('rosbag_pointcloud_topic')
    rosbag_imu_topic = LaunchConfiguration('rosbag_imu_topic')
    rosbag_rate = LaunchConfiguration('rosbag_rate')
    rosbag_loop = LaunchConfiguration('rosbag_loop')
    rosbag_start_offset = LaunchConfiguration('rosbag_start_offset')
    rosbag_start_delay = LaunchConfiguration('rosbag_start_delay')
    rosbag_dlio_extra_params = LaunchConfiguration('rosbag_dlio_extra_params')
    rosbag_deskewed_lidar_topic = LaunchConfiguration('rosbag_deskewed_lidar_topic')
    rosbag_deskewed_lidar_frame = LaunchConfiguration('rosbag_deskewed_lidar_frame')
    rosbag_elevation_config = LaunchConfiguration('rosbag_elevation_config')
    use_rosbag_deskewed_lidar_bridge = LaunchConfiguration('use_rosbag_deskewed_lidar_bridge')
    linear_x = LaunchConfiguration('linear_x')
    angular_z = LaunchConfiguration('angular_z')
    start_delay = LaunchConfiguration('start_delay')
    auto_drive = LaunchConfiguration('auto_drive')
    launch_elevation = LaunchConfiguration('launch_elevation')
    launch_graphnav = LaunchConfiguration('launch_graphnav')
    launch_graphnav_markers = LaunchConfiguration('launch_graphnav_markers')
    launch_grid_threshold_markers = LaunchConfiguration('launch_grid_threshold_markers')
    launch_wildos = LaunchConfiguration('launch_wildos')
    launch_explorfm_probe = LaunchConfiguration('launch_explorfm_probe')
    wildos_config = LaunchConfiguration('wildos_config')
    explorfm_probe_config = LaunchConfiguration('explorfm_probe_config')
    wildos_object_search = LaunchConfiguration('wildos_object_search')
    wildos_python = LaunchConfiguration('wildos_python')
    triangulation_config = LaunchConfiguration('triangulation_config')
    use_synthetic_sensors = LaunchConfiguration('use_synthetic_sensors')
    use_gazebo_cloud_adapter = LaunchConfiguration('use_gazebo_cloud_adapter')
    graphnav_grid_map_topic = LaunchConfiguration('graphnav_grid_map_topic')
    graphnav_odom_topic = LaunchConfiguration('graphnav_odom_topic')
    graphnav_topic = LaunchConfiguration('graphnav_topic')
    graphnav_safe_threshold = LaunchConfiguration('graphnav_safe_threshold')
    graphnav_local_map_radius = LaunchConfiguration('graphnav_local_map_radius')
    graphnav_edge_radius = LaunchConfiguration('graphnav_edge_radius')
    graphnav_num_samples = LaunchConfiguration('graphnav_num_samples')
    graphnav_update_min_travel = LaunchConfiguration('graphnav_update_min_travel')
    graphnav_update_free_radius_fraction = LaunchConfiguration('graphnav_update_free_radius_fraction')
    graphnav_frontier_association_radius = LaunchConfiguration('graphnav_frontier_association_radius')
    graphnav_publish_global_memory_markers = LaunchConfiguration('graphnav_publish_global_memory_markers')
    graphnav_global_memory_marker_topic = LaunchConfiguration('graphnav_global_memory_marker_topic')
    graphnav_global_memory_marker_stride = LaunchConfiguration('graphnav_global_memory_marker_stride')
    graphnav_publish_global_memory_grid = LaunchConfiguration('graphnav_publish_global_memory_grid')
    graphnav_global_memory_grid_topic = LaunchConfiguration('graphnav_global_memory_grid_topic')
    graphnav_min_x = LaunchConfiguration('graphnav_min_x')
    graphnav_max_x = LaunchConfiguration('graphnav_max_x')
    graphnav_min_y = LaunchConfiguration('graphnav_min_y')
    graphnav_max_y = LaunchConfiguration('graphnav_max_y')
    gazebo_source = PythonExpression(["'", data_source, "'.lower() == 'gazebo'"])
    rosbag_source = PythonExpression(["'", data_source, "'.lower() == 'rosbag'"])

    gazebo_gui = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([gz_pkg, 'launch', 'gz_sim.launch.py'])
        ),
        launch_arguments={
            'gz_args': ['-r ', world],
            'on_exit_shutdown': 'True',
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", gz_gui, "'.lower() == 'true'"
        ])),
    )

    gazebo_headless = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([gz_pkg, 'launch', 'gz_sim.launch.py'])
        ),
        launch_arguments={
            'gz_args': ['-r -s ', world],
            'on_exit_shutdown': 'True',
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", gz_gui, "'.lower() != 'true'"
        ])),
    )

    dlio_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': rviz,
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
        }.items(),
        condition=IfCondition(gazebo_source),
    )

    dlio_rosbag = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': rviz,
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
            'dlio_extra_params': rosbag_dlio_extra_params,
        }.items(),
        condition=IfCondition(rosbag_source),
    )

    rosbag_play = TimerAction(
        period=rosbag_start_delay,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'bag', 'play', rosbag_path,
                    '--clock',
                    '--start-offset', rosbag_start_offset,
                    '--rate', rosbag_rate,
                    '--remap',
                    [rosbag_pointcloud_topic, ':=', pointcloud_topic],
                    [rosbag_imu_topic, ':=', imu_topic],
                ],
                name='rosbag_play',
                output='screen',
                condition=IfCondition(PythonExpression([
                    "'", rosbag_loop, "'.lower() != 'true'"
                ])),
            ),
            ExecuteProcess(
                cmd=[
                    'ros2', 'bag', 'play', rosbag_path,
                    '--clock',
                    '--loop',
                    '--start-offset', rosbag_start_offset,
                    '--rate', rosbag_rate,
                    '--remap',
                    [rosbag_pointcloud_topic, ':=', pointcloud_topic],
                    [rosbag_imu_topic, ':=', imu_topic],
                ],
                name='rosbag_play_loop',
                output='screen',
                condition=IfCondition(PythonExpression([
                    "'", rosbag_loop, "'.lower() == 'true'"
                ])),
            ),
        ],
        condition=IfCondition(rosbag_source),
    )

    rosbag_wildos_camera_bridge = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([wildos_bridge_pkg, 'launch', 'alphasense_to_wildos.launch.py'])
        ),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'rosbag' and '", launch_wildos, "'.lower() == 'true'"
        ])),
    )

    rosbag_deskewed_lidar_bridge = Node(
        package='dlio_gazebo_sim',
        executable='odom_cloud_to_lidar_frame',
        name='odom_cloud_to_lidar_frame',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'rosbag' and '",
            launch_elevation, "'.lower() == 'true' and '",
            use_rosbag_deskewed_lidar_bridge, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': True,
            'input_topic': '/dlio/odom_node/pointcloud/deskewed',
            'output_topic': rosbag_deskewed_lidar_topic,
            'target_frame': rosbag_deskewed_lidar_frame,
        }],
    )

    elevation_mapping_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([elevation_pkg, 'launch', 'elevation_mapping.launch.py'])
        ),
        launch_arguments={
            'robot_config': 'dlio_gazebo/base.yaml',
            'launch_rviz': 'false',
            'use_sim_time': 'true',
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", launch_elevation, "'.lower() == 'true'"
        ])),
    )

    elevation_mapping_rosbag = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([elevation_pkg, 'launch', 'elevation_mapping.launch.py'])
        ),
        launch_arguments={
            'robot_config': rosbag_elevation_config,
            'launch_rviz': 'false',
            'use_sim_time': 'true',
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'rosbag' and '", launch_elevation, "'.lower() == 'true'"
        ])),
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
            '/wildos/front/color/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/wildos/front/color/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            '/wildos/left/color/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/wildos/left/color/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
            '/wildos/right/color/image_raw@sensor_msgs/msg/Image[gz.msgs.Image',
            '/wildos/right/color/camera_info@sensor_msgs/msg/CameraInfo[gz.msgs.CameraInfo',
        ],
        output='screen',
        condition=IfCondition(gazebo_source),
    )

    synthetic_sensors = Node(
        package='dlio_gazebo_sim',
        executable='synthetic_dlio_sensors',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", use_synthetic_sensors, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': True,
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'start_delay': start_delay,
            'linear_x': linear_x,
            'angular_z': angular_z,
        }],
    )

    gazebo_cloud_adapter = Node(
        package='dlio_gazebo_sim',
        executable='gazebo_cloud_adapter',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", use_gazebo_cloud_adapter, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': True,
            'input_topic': '/points_raw/points',
            'output_topic': pointcloud_topic,
            'frame_id': 'lidar',
            'scan_period': 0.1,
        }],
    )

    circle_cmd = Node(
        package='dlio_gazebo_sim',
        executable='circle_cmd',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", auto_drive, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': True,
            'cmd_vel_topic': '/cmd_vel',
            'start_delay': start_delay,
            'linear_x': linear_x,
            'angular_z': angular_z,
        }],
    )

    graphnav_builder = Node(
        package='graphnav_builder',
        executable='graphnav_builder',
        name='graphnav_builder',
        output='screen',
        condition=IfCondition(launch_graphnav),
        parameters=[{
            'use_sim_time': True,
            'odom_topic': graphnav_odom_topic,
            'grid_map_topic': graphnav_grid_map_topic,
            'nav_graph_topic': graphnav_topic,
            'traversability_layer': 'traversability',
            'observed_layer': 'elevation',
            'trav_class': 'elevation_traversability',
            'safe_threshold': graphnav_safe_threshold,
            'local_map_radius': graphnav_local_map_radius,
            'local_map_resolution': 0.1,
            'max_free_radius': 4.0,
            'traversable_radius': 0.5,
            'frontier_association_radius': graphnav_frontier_association_radius,
            'edge_radius': graphnav_edge_radius,
            'num_samples': graphnav_num_samples,
            'graph_update_min_travel': graphnav_update_min_travel,
            'graph_update_free_radius_fraction': graphnav_update_free_radius_fraction,
            'publish_global_memory_markers': graphnav_publish_global_memory_markers,
            'global_memory_marker_topic': graphnav_global_memory_marker_topic,
            'global_memory_marker_stride': graphnav_global_memory_marker_stride,
            'publish_global_memory_grid': graphnav_publish_global_memory_grid,
            'global_memory_grid_topic': graphnav_global_memory_grid_topic,
            'random_seed': 7,
            'min_x': graphnav_min_x,
            'max_x': graphnav_max_x,
            'min_y': graphnav_min_y,
            'max_y': graphnav_max_y,
        }],
    )

    nav_graph_markers = Node(
        package='dlio_gazebo_sim',
        executable='nav_graph_markers',
        name='nav_graph_markers',
        output='screen',
        condition=IfCondition(launch_graphnav_markers),
        parameters=[{
            'use_sim_time': True,
            'nav_graph_topic': graphnav_topic,
            'marker_topic': '/nav_graph_markers',
            'show_radii': True,
            'show_ids': False,
        }],
    )

    grid_threshold_markers = Node(
        package='dlio_gazebo_sim',
        executable='grid_threshold_markers',
        name='grid_threshold_markers',
        output='screen',
        condition=IfCondition(launch_grid_threshold_markers),
        parameters=[{
            'use_sim_time': True,
            'grid_map_topic': graphnav_grid_map_topic,
            'marker_topic': '/grid_threshold_markers',
            'traversability_layer': 'traversability',
            'observed_layer': 'elevation',
            'safe_threshold': graphnav_safe_threshold,
            'sample_stride': 1,
        }],
    )

    wildos_front_camera_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_front_camera_tf',
        arguments=[
            '0.36', '0.0', '0.24',
            '-0.5', '0.5', '-0.5', '0.5',
            'base_link', 'wildos_front_camera_color_optical_frame',
        ],
        output='screen',
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
        },
    )

    wildos_left_camera_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_left_camera_tf',
        arguments=[
            '0.08', '0.25', '0.24',
            '-0.70710678', '0.0', '0.0', '0.70710678',
            'base_link', 'wildos_left_camera_color_optical_frame',
        ],
        output='screen',
    )

    wildos_right_camera_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_right_camera_tf',
        arguments=[
            '0.08', '-0.25', '0.24',
            '0.0', '0.70710678', '-0.70710678', '0.0',
            'base_link', 'wildos_right_camera_color_optical_frame',
        ],
        output='screen',
    )

    wildos = ExecuteProcess(
        cmd=[
            wildos_python, '-m', 'visual_navigation.wildos.nav',
            '--config', wildos_config,
            '--do_object_search', wildos_object_search,
            '--ros-args',
            '-r', '__node:=wildos',
            '-p', 'use_sim_time:=true',
            '--log-level', 'INFO',
        ],
        name='wildos',
        output='screen',
        condition=IfCondition(launch_wildos),
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
            'PYTHONUNBUFFERED': '1',
            'HF_HUB_DISABLE_XET': '1',
            'HF_HUB_OFFLINE': '1',
            'TRANSFORMERS_OFFLINE': '1',
            'PYTORCH_CUDA_ALLOC_CONF': 'expandable_segments:True',
        },
    )

    explorfm_probe = ExecuteProcess(
        cmd=[
            wildos_python, '-m', 'visual_navigation.wildos.explorfm_camera_probe',
            '--config', explorfm_probe_config,
            '--ros-args',
            '-r', '__node:=explorfm_camera_probe',
            '-p', 'use_sim_time:=true',
            '--log-level', 'INFO',
        ],
        name='explorfm_camera_probe',
        output='screen',
        condition=IfCondition(launch_explorfm_probe),
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
            'PYTHONUNBUFFERED': '1',
            'HF_HUB_DISABLE_XET': '1',
            'HF_HUB_OFFLINE': '1',
            'TRANSFORMERS_OFFLINE': '1',
            'PYTORCH_CUDA_ALLOC_CONF': 'expandable_segments:True',
        },
    )

    obj_mask_triangulation = ExecuteProcess(
        cmd=[
            wildos_python, '-m', 'visual_navigation.explorfm_triangulation.obj_mask_triangulation',
            '--config', triangulation_config,
            '--ros-args',
            '-r', '__node:=obj_mask_triangulation',
            '-p', 'use_sim_time:=true',
            '--log-level', 'INFO',
        ],
        name='obj_mask_triangulation',
        output='screen',
        condition=IfCondition(wildos_object_search),
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
            'PYTHONUNBUFFERED': '1',
        },
    )

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true'),
        DeclareLaunchArgument('gz_gui', default_value='true'),
        DeclareLaunchArgument(
            'data_source',
            default_value='gazebo',
            description='Sensor data source: gazebo or rosbag',
        ),
        DeclareLaunchArgument('dlio_output', default_value='log'),
        DeclareLaunchArgument('pointcloud_topic', default_value='/points_raw'),
        DeclareLaunchArgument('imu_topic', default_value='/imu_raw'),
        DeclareLaunchArgument(
            'rosbag_path',
            default_value='/root/ros2_ws/data/sequences/2024-03-14-blenheim-palace-04/raw/ros2bag/1710408895_2024-03-14-09-44-02_1',
            description='Path to the rosbag2 directory used when data_source:=rosbag',
        ),
        DeclareLaunchArgument('rosbag_pointcloud_topic', default_value='/hesai/pandar'),
        DeclareLaunchArgument('rosbag_imu_topic', default_value='/alphasense_driver_ros/imu'),
        DeclareLaunchArgument('rosbag_rate', default_value='1.0'),
        DeclareLaunchArgument('rosbag_loop', default_value='false'),
        DeclareLaunchArgument(
            'rosbag_dlio_extra_params',
            default_value=PathJoinSubstitution([pkg, 'config', 'dlio_oxford_spires_rosbag.yaml']),
            description='DLIO parameter override used automatically when data_source:=rosbag',
        ),
        DeclareLaunchArgument(
            'rosbag_deskewed_lidar_topic',
            default_value='/points_deskewed_lidar',
            description='Deskewed cloud topic re-expressed in the rosbag LiDAR frame for elevation mapping.',
        ),
        DeclareLaunchArgument(
            'rosbag_deskewed_lidar_frame',
            default_value='pandar',
            description='LiDAR frame used by the rosbag point cloud header.',
        ),
        DeclareLaunchArgument(
            'rosbag_elevation_config',
            default_value='dlio_gazebo/rosbag_deskewed_lidar.yaml',
            description='Elevation mapping robot config used automatically when data_source:=rosbag.',
        ),
        DeclareLaunchArgument(
            'use_rosbag_deskewed_lidar_bridge',
            default_value='true',
            description='Transform DLIO odom-frame deskewed cloud back into the LiDAR frame for elevation mapping.',
        ),
        DeclareLaunchArgument(
            'rosbag_start_offset',
            default_value='0.0',
            description='Start playback this many seconds after the beginning of the bag.',
        ),
        DeclareLaunchArgument('rosbag_start_delay', default_value='2.0'),
        DeclareLaunchArgument('world', default_value='dlio_room.sdf'),
        DeclareLaunchArgument('linear_x', default_value='0.45'),
        DeclareLaunchArgument('angular_z', default_value='0.22'),
        DeclareLaunchArgument('start_delay', default_value='4.0'),
        DeclareLaunchArgument('auto_drive', default_value='false'),
        DeclareLaunchArgument('launch_elevation', default_value='true'),
        DeclareLaunchArgument('launch_graphnav', default_value='true'),
        DeclareLaunchArgument('launch_graphnav_markers', default_value='true'),
        DeclareLaunchArgument('launch_grid_threshold_markers', default_value='false'),
        DeclareLaunchArgument('launch_wildos', default_value='false'),
        DeclareLaunchArgument('launch_explorfm_probe', default_value='false'),
        DeclareLaunchArgument('wildos_config', default_value='dlio_gazebo_wildos.yaml'),
        DeclareLaunchArgument('explorfm_probe_config', default_value='dlio_gazebo_explorfm_probe.yaml'),
        DeclareLaunchArgument('wildos_object_search', default_value='false'),
        DeclareLaunchArgument('wildos_python', default_value='/root/wildos_venv/bin/python3'),
        DeclareLaunchArgument('triangulation_config', default_value='dlio_gazebo_triangulation.yaml'),
        DeclareLaunchArgument('use_synthetic_sensors', default_value='false'),
        DeclareLaunchArgument('use_gazebo_cloud_adapter', default_value='true'),
        DeclareLaunchArgument('graphnav_grid_map_topic', default_value='/elevation_mapping_node/elevation_map_raw'),
        DeclareLaunchArgument('graphnav_odom_topic', default_value='/dlio/odom_node/odom'),
        DeclareLaunchArgument('graphnav_topic', default_value='/nav_graph'),
        DeclareLaunchArgument('graphnav_safe_threshold', default_value='0.2'),
        DeclareLaunchArgument('graphnav_local_map_radius', default_value='4.5'),
        DeclareLaunchArgument('graphnav_edge_radius', default_value='2.5'),
        DeclareLaunchArgument('graphnav_num_samples', default_value='250'),
        DeclareLaunchArgument('graphnav_update_min_travel', default_value='0.75'),
        DeclareLaunchArgument('graphnav_update_free_radius_fraction', default_value='0.8'),
        DeclareLaunchArgument('graphnav_frontier_association_radius', default_value='1.5'),
        DeclareLaunchArgument('graphnav_publish_global_memory_markers', default_value='true'),
        DeclareLaunchArgument('graphnav_global_memory_marker_topic', default_value='/global_traversability_markers'),
        DeclareLaunchArgument('graphnav_global_memory_marker_stride', default_value='2'),
        DeclareLaunchArgument('graphnav_publish_global_memory_grid', default_value='true'),
        DeclareLaunchArgument('graphnav_global_memory_grid_topic', default_value='/global_traversability_grid'),
        DeclareLaunchArgument('graphnav_min_x', default_value='-1000000000.0'),
        DeclareLaunchArgument('graphnav_max_x', default_value='1000000000.0'),
        DeclareLaunchArgument('graphnav_min_y', default_value='-1000000000.0'),
        DeclareLaunchArgument('graphnav_max_y', default_value='1000000000.0'),
        SetEnvironmentVariable('GZ_SIM_RESOURCE_PATH', model_path),
        SetEnvironmentVariable('CUDA_PATH', cuda_path),
        SetEnvironmentVariable(
            'LD_LIBRARY_PATH',
            [cuda_nvrtc_lib, ':', cuda_path, '/lib:', EnvironmentVariable('LD_LIBRARY_PATH', default_value='')]
        ),
        gazebo_gui,
        gazebo_headless,
        bridge,
        gazebo_cloud_adapter,
        synthetic_sensors,
        circle_cmd,
        rosbag_wildos_camera_bridge,
        rosbag_play,
        dlio_gazebo,
        dlio_rosbag,
        rosbag_deskewed_lidar_bridge,
        elevation_mapping_gazebo,
        elevation_mapping_rosbag,
        graphnav_builder,
        nav_graph_markers,
        grid_threshold_markers,
        wildos_front_camera_tf,
        wildos_left_camera_tf,
        wildos_right_camera_tf,
        wildos,
        explorfm_probe,
        obj_mask_triangulation,
    ])
