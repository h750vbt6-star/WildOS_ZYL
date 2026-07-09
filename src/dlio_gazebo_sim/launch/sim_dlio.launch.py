from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, ExecuteProcess, IncludeLaunchDescription, SetEnvironmentVariable, TimerAction
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import EnvironmentVariable, LaunchConfiguration, PathJoinSubstitution, PythonExpression
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare('dlio_gazebo_sim')
    gz_pkg = FindPackageShare('ros_gz_sim')
    dlio_pkg = FindPackageShare('direct_lidar_inertial_odometry')
    elevation_pkg = FindPackageShare('elevation_mapping_cupy')
    wildos_bridge_pkg = FindPackageShare('wildos_rosbag_bridge')
    # 找到各个包的share路径，并将其存储在变量中以供后续使用

    world_name = LaunchConfiguration('world')
    world = PathJoinSubstitution([pkg, 'worlds', world_name])
    model_path = PathJoinSubstitution([pkg, 'models'])
    wildos_source_path = '/root/ros2_ws/src/nebula2-wildos-main'
    cuda_path = '/usr/local/lib/python3.10/dist-packages/nvidia/cuda_runtime'
    cuda_nvrtc_lib = '/usr/local/lib/python3.10/dist-packages/nvidia/cuda_nvrtc/lib'
    # 注意下边这种写法，左边的是变量名
    rviz = LaunchConfiguration('rviz')
    gz_gui = LaunchConfiguration('gz_gui')
    data_source = LaunchConfiguration('data_source')
    dlio_output = LaunchConfiguration('dlio_output')
    gazebo_dlio_extra_params = LaunchConfiguration('gazebo_dlio_extra_params')
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
    gazebo_deskewed_lidar_topic = LaunchConfiguration('gazebo_deskewed_lidar_topic')
    gazebo_deskewed_lidar_frame = LaunchConfiguration('gazebo_deskewed_lidar_frame')
    rosbag_deskewed_lidar_topic = LaunchConfiguration('rosbag_deskewed_lidar_topic')
    rosbag_deskewed_lidar_frame = LaunchConfiguration('rosbag_deskewed_lidar_frame')
    rosbag_elevation_config = LaunchConfiguration('rosbag_elevation_config')
    use_rosbag_deskewed_lidar_bridge = LaunchConfiguration('use_rosbag_deskewed_lidar_bridge')
    go2_rosbag_path = LaunchConfiguration('go2_rosbag_path')
    go2_pointcloud_topic = LaunchConfiguration('go2_pointcloud_topic')
    go2_imu_topic = LaunchConfiguration('go2_imu_topic')
    go2_adapter_input_topic = LaunchConfiguration('go2_adapter_input_topic')
    go2_rosbag_rate = LaunchConfiguration('go2_rosbag_rate')
    go2_rosbag_loop = LaunchConfiguration('go2_rosbag_loop')
    go2_rosbag_start_offset = LaunchConfiguration('go2_rosbag_start_offset')
    go2_rosbag_start_delay = LaunchConfiguration('go2_rosbag_start_delay')
    go2_rosbag_playback_duration = LaunchConfiguration('go2_rosbag_playback_duration')
    go2_dlio_extra_params = LaunchConfiguration('go2_dlio_extra_params')
    go2_deskewed_lidar_topic = LaunchConfiguration('go2_deskewed_lidar_topic')
    go2_deskewed_lidar_frame = LaunchConfiguration('go2_deskewed_lidar_frame')
    go2_elevation_config = LaunchConfiguration('go2_elevation_config')
    go2_acceleration_scale = LaunchConfiguration('go2_acceleration_scale')
    linear_x = LaunchConfiguration('linear_x')
    angular_z = LaunchConfiguration('angular_z')
    start_delay = LaunchConfiguration('start_delay')
    auto_drive = LaunchConfiguration('auto_drive')
    launch_local_dlio = LaunchConfiguration('launch_local_dlio')
    launch_elevation = LaunchConfiguration('launch_elevation')
    launch_graphnav = LaunchConfiguration('launch_graphnav')
    launch_graphnav_markers = LaunchConfiguration('launch_graphnav_markers')
    launch_grid_threshold_markers = LaunchConfiguration('launch_grid_threshold_markers')
    launch_wildos = LaunchConfiguration('launch_wildos')
    launch_explorfm_probe = LaunchConfiguration('launch_explorfm_probe')
    launch_goal_mux = LaunchConfiguration('launch_goal_mux')
    launch_graphnav_planner = LaunchConfiguration('launch_graphnav_planner')
    launch_static_path = LaunchConfiguration('launch_static_path')
    launch_goal_pose_bridge = LaunchConfiguration('launch_goal_pose_bridge')
    launch_nav2 = LaunchConfiguration('launch_nav2')
    wildos_config = LaunchConfiguration('wildos_config')
    explorfm_probe_config = LaunchConfiguration('explorfm_probe_config')
    wildos_object_search = LaunchConfiguration('wildos_object_search')
    wildos_python = LaunchConfiguration('wildos_python')
    triangulation_config = LaunchConfiguration('triangulation_config')
    initial_goal_frame = LaunchConfiguration('initial_goal_frame')
    initial_goal_x = LaunchConfiguration('initial_goal_x')
    initial_goal_y = LaunchConfiguration('initial_goal_y')
    initial_goal_z = LaunchConfiguration('initial_goal_z')
    initial_goal_yaw = LaunchConfiguration('initial_goal_yaw')
    initial_goal_publish_rate = LaunchConfiguration('initial_goal_publish_rate')
    triangulated_goal_topic = LaunchConfiguration('triangulated_goal_topic')
    active_goal_topic = LaunchConfiguration('active_goal_topic')
    nav2_goal_topic = LaunchConfiguration('nav2_goal_topic')
    graphnav_planner_path_topic = LaunchConfiguration('graphnav_planner_path_topic')
    graphnav_planner_nav_graph_topic = LaunchConfiguration('graphnav_planner_nav_graph_topic')
    graphnav_planner_goal_topic = LaunchConfiguration('graphnav_planner_goal_topic')
    graphnav_planner_trav_class = LaunchConfiguration('graphnav_planner_trav_class')
    graphnav_planner_no_goal_strategy = LaunchConfiguration('graphnav_planner_no_goal_strategy')
    graphnav_planner_virtual_goal_frame = LaunchConfiguration('graphnav_planner_virtual_goal_frame')
    graphnav_planner_virtual_goal_x = LaunchConfiguration('graphnav_planner_virtual_goal_x')
    graphnav_planner_virtual_goal_y = LaunchConfiguration('graphnav_planner_virtual_goal_y')
    graphnav_planner_virtual_goal_z = LaunchConfiguration('graphnav_planner_virtual_goal_z')
    graphnav_planner_virtual_goal_yaw = LaunchConfiguration('graphnav_planner_virtual_goal_yaw')
    graphnav_planner_frontier_dist_cost_factor = LaunchConfiguration('graphnav_planner_frontier_dist_cost_factor')
    graphnav_planner_goal_dist_cost_factor = LaunchConfiguration('graphnav_planner_goal_dist_cost_factor')
    graphnav_planner_frontier_score_factor = LaunchConfiguration('graphnav_planner_frontier_score_factor')
    graphnav_planner_use_frontier_scores = LaunchConfiguration('graphnav_planner_use_frontier_scores')
    graphnav_planner_min_frontier_score_for_cost = LaunchConfiguration('graphnav_planner_min_frontier_score_for_cost')
    graphnav_planner_min_local_frontier_score = LaunchConfiguration('graphnav_planner_min_local_frontier_score')
    graphnav_planner_local_frontier_radius = LaunchConfiguration('graphnav_planner_local_frontier_radius')
    graphnav_planner_path_smoothness_period = LaunchConfiguration('graphnav_planner_path_smoothness_period')
    graphnav_planner_goal_radius = LaunchConfiguration('graphnav_planner_goal_radius')
    graphnav_path_follower_lookahead = LaunchConfiguration('graphnav_path_follower_lookahead')
    graphnav_path_follower_arrival_radius = LaunchConfiguration('graphnav_path_follower_arrival_radius')
    graphnav_path_follower_timeout = LaunchConfiguration('graphnav_path_follower_timeout')
    static_path_waypoints = LaunchConfiguration('static_path_waypoints')
    static_path_frame = LaunchConfiguration('static_path_frame')
    static_path_prepend_current_pose = LaunchConfiguration('static_path_prepend_current_pose')
    nav2_launch_file = LaunchConfiguration('nav2_launch_file')
    nav2_params_file = LaunchConfiguration('nav2_params_file')
    nav2_autostart = LaunchConfiguration('nav2_autostart')
    nav2_action_name = LaunchConfiguration('nav2_action_name')
    goal_pose_bridge_send_period = LaunchConfiguration('goal_pose_bridge_send_period')
    goal_pose_bridge_min_goal_distance = LaunchConfiguration('goal_pose_bridge_min_goal_distance')
    goal_pose_bridge_min_goal_yaw = LaunchConfiguration('goal_pose_bridge_min_goal_yaw')
    goal_pose_bridge_cancel_on_new_goal = LaunchConfiguration('goal_pose_bridge_cancel_on_new_goal')
    use_synthetic_sensors = LaunchConfiguration('use_synthetic_sensors')
    use_gazebo_cloud_adapter = LaunchConfiguration('use_gazebo_cloud_adapter')
    show_gazebo_base_link = LaunchConfiguration('show_gazebo_base_link')
    graphnav_grid_map_topic = LaunchConfiguration('graphnav_grid_map_topic')
    graphnav_odom_topic = LaunchConfiguration('graphnav_odom_topic')
    graphnav_topic = LaunchConfiguration('graphnav_topic')
    graphnav_safe_threshold = LaunchConfiguration('graphnav_safe_threshold')
    graphnav_local_map_radius = LaunchConfiguration('graphnav_local_map_radius')
    graphnav_edge_radius = LaunchConfiguration('graphnav_edge_radius')
    graphnav_num_samples = LaunchConfiguration('graphnav_num_samples')
    graphnav_update_every_timestep = LaunchConfiguration('graphnav_update_every_timestep')
    graphnav_update_min_travel = LaunchConfiguration('graphnav_update_min_travel')
    graphnav_update_free_radius_fraction = LaunchConfiguration('graphnav_update_free_radius_fraction')
    graphnav_grid_map_queue_depth = LaunchConfiguration('graphnav_grid_map_queue_depth')
    graphnav_frontier_association_radius = LaunchConfiguration('graphnav_frontier_association_radius')
    graphnav_min_frontier_cluster_size = LaunchConfiguration('graphnav_min_frontier_cluster_size')
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
    go2_rosbag_source = PythonExpression(["'", data_source, "'.lower() == 'go2_rosbag'"])
    go2_live_source = PythonExpression(["'", data_source, "'.lower() == 'go2_live'"])
    gazebo_local_dlio_source = PythonExpression([
        "'", data_source, "'.lower() == 'gazebo' and '", launch_local_dlio, "'.lower() == 'true'"
    ])
    rosbag_local_dlio_source = PythonExpression([
        "'", data_source, "'.lower() == 'rosbag' and '", launch_local_dlio, "'.lower() == 'true'"
    ])
    go2_rosbag_local_dlio_source = PythonExpression([
        "'", data_source, "'.lower() == 'go2_rosbag' and '", launch_local_dlio, "'.lower() == 'true'"
    ])
    go2_live_local_dlio_source = PythonExpression([
        "'", data_source, "'.lower() == 'go2_live' and '", launch_local_dlio, "'.lower() == 'true'"
    ])
    use_sim_time = PythonExpression(["'", data_source, "'.lower() != 'go2_live'"])

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

    rviz_config_path = PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.rviz'])
    rviz_node = Node(
        package='rviz2',
        executable='rviz2',
        name='dlio_gazebo_rviz',
        arguments=['-d', rviz_config_path],
        output='screen',
        condition=IfCondition(rviz),
    )

    dlio_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': 'false',
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
            'dlio_extra_params': gazebo_dlio_extra_params,
        }.items(),
        condition=IfCondition(gazebo_local_dlio_source),
    )

    dlio_rosbag = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': 'false',
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
            'dlio_extra_params': rosbag_dlio_extra_params,
        }.items(),
        condition=IfCondition(rosbag_local_dlio_source),
    )

    dlio_go2_rosbag = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': 'false',
            'pointcloud_topic': pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
            'dlio_extra_params': go2_dlio_extra_params,
        }.items(),
        condition=IfCondition(go2_rosbag_local_dlio_source),
    )

    dlio_go2_live = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([dlio_pkg, 'launch', 'dlio.launch.py'])
        ),
        launch_arguments={
            'rviz': 'false',
            'pointcloud_topic': go2_pointcloud_topic,
            'imu_topic': imu_topic,
            'dlio_output': dlio_output,
            'dlio_extra_params': go2_dlio_extra_params,
        }.items(),
        condition=IfCondition(go2_live_local_dlio_source),
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

    go2_rosbag_play = TimerAction(
        period=go2_rosbag_start_delay,
        actions=[
            ExecuteProcess(
                cmd=[
                    'ros2', 'bag', 'play', go2_rosbag_path,
                    '--clock',
                    '--start-offset', go2_rosbag_start_offset,
                    '--rate', go2_rosbag_rate,
                    '--remap',
                    [go2_pointcloud_topic, ':=', pointcloud_topic],
                    [go2_imu_topic, ':=', go2_adapter_input_topic],
                ],
                name='go2_rosbag_play',
                output='screen',
                condition=IfCondition(PythonExpression([
                    "'", go2_rosbag_loop, "'.lower() != 'true'"
                ])),
            ),
            ExecuteProcess(
                cmd=[
                    'ros2', 'bag', 'play', go2_rosbag_path,
                    '--clock',
                    '--loop',
                    '--start-offset', go2_rosbag_start_offset,
                    '--playback-duration', go2_rosbag_playback_duration,
                    '--rate', go2_rosbag_rate,
                    '--remap',
                    [go2_pointcloud_topic, ':=', pointcloud_topic],
                    [go2_imu_topic, ':=', go2_adapter_input_topic],
                ],
                name='go2_rosbag_play_loop',
                output='screen',
                condition=IfCondition(PythonExpression([
                    "'", go2_rosbag_loop, "'.lower() == 'true'"
                ])),
            ),
        ],
        condition=IfCondition(go2_rosbag_source),
    )

    go2_livox_imu_adapter = Node(
        package='dlio_gazebo_sim',
        executable='livox_imu_adapter',
        name='go2_livox_imu_adapter',
        output='screen',
        condition=IfCondition(go2_rosbag_local_dlio_source),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': go2_adapter_input_topic,
            'output_topic': imu_topic,
            'output_frame': 'livox_imu_frame',
            'acceleration_scale': ParameterValue(go2_acceleration_scale, value_type=float),
        }],
    )

    go2_live_livox_imu_adapter = Node(
        package='dlio_gazebo_sim',
        executable='livox_imu_adapter',
        name='go2_live_livox_imu_adapter',
        output='screen',
        condition=IfCondition(go2_live_local_dlio_source),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': go2_imu_topic,
            'output_topic': imu_topic,
            'output_frame': 'livox_imu_frame',
            'acceleration_scale': ParameterValue(go2_acceleration_scale, value_type=float),
        }],
    )

    rosbag_wildos_camera_bridge = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([wildos_bridge_pkg, 'launch', 'alphasense_to_wildos.launch.py'])
        ),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'rosbag' and '", launch_wildos, "'.lower() == 'true'"
        ])),
    )

    gazebo_deskewed_lidar_bridge = Node(
        package='dlio_gazebo_sim',
        executable='odom_cloud_to_lidar_frame',
        name='gazebo_odom_cloud_to_lidar_frame',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '",
            launch_elevation, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': '/dlio/odom_node/pointcloud/deskewed',
            'output_topic': gazebo_deskewed_lidar_topic,
            'target_frame': gazebo_deskewed_lidar_frame,
        }],
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': '/dlio/odom_node/pointcloud/deskewed',
            'output_topic': rosbag_deskewed_lidar_topic,
            'target_frame': rosbag_deskewed_lidar_frame,
        }],
    )

    go2_deskewed_lidar_bridge = Node(
        package='dlio_gazebo_sim',
        executable='odom_cloud_to_lidar_frame',
        name='go2_odom_cloud_to_lidar_frame',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() in ('go2_rosbag', 'go2_live') and '",
            launch_elevation, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': '/dlio/odom_node/pointcloud/deskewed',
            'output_topic': go2_deskewed_lidar_topic,
            'target_frame': go2_deskewed_lidar_frame,
        }],
    )

    elevation_mapping_gazebo = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([elevation_pkg, 'launch', 'elevation_mapping.launch.py'])
        ),
        launch_arguments={
            'robot_config': 'dlio_gazebo/base.yaml',
            'launch_rviz': 'false',
            'use_sim_time': use_sim_time,
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
            'use_sim_time': use_sim_time,
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'rosbag' and '", launch_elevation, "'.lower() == 'true'"
        ])),
    )

    elevation_mapping_go2_rosbag = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            PathJoinSubstitution([elevation_pkg, 'launch', 'elevation_mapping.launch.py'])
        ),
        launch_arguments={
            'robot_config': go2_elevation_config,
            'launch_rviz': 'false',
            'use_sim_time': use_sim_time,
        }.items(),
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() in ('go2_rosbag', 'go2_live') and '", launch_elevation, "'.lower() == 'true'"
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'input_topic': '/points_raw/points',
            'output_topic': pointcloud_topic,
            'frame_id': 'lidar',
            'scan_period': 0.1,
        }],
    )

    gazebo_odom_tf = Node(
        package='dlio_gazebo_sim',
        executable='gazebo_odom_tf',
        name='gazebo_odom_tf',
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo' and '", show_gazebo_base_link, "'.lower() == 'true'"
        ])),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'odom_topic': '/gazebo/odom',
            'parent_frame': 'odom',
            'child_frame': 'gazebo_base_link',
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
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
            'traversable_radius': 0.35,
            'frontier_association_radius': graphnav_frontier_association_radius,
            'min_frontier_cluster_size': ParameterValue(graphnav_min_frontier_cluster_size, value_type=int),
            'edge_radius': graphnav_edge_radius,
            'num_samples': graphnav_num_samples,
            'graph_update_every_timestep': ParameterValue(graphnav_update_every_timestep, value_type=bool),
            'graph_update_min_travel': graphnav_update_min_travel,
            'graph_update_free_radius_fraction': graphnav_update_free_radius_fraction,
            'grid_map_queue_depth': ParameterValue(graphnav_grid_map_queue_depth, value_type=int),
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
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
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'grid_map_topic': graphnav_grid_map_topic,
            'marker_topic': '/grid_threshold_markers',
            'traversability_layer': 'traversability',
            'observed_layer': 'traversability',
            'safe_threshold': graphnav_safe_threshold,
            'sample_stride': 1,
        }],
    )

    traversability_costmap = Node(
        package='dlio_gazebo_sim',
        executable='traversability_costmap',
        name='traversability_costmap',
        output='screen',
        condition=IfCondition(launch_nav2),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'grid_map_topic': graphnav_grid_map_topic,
            'costmap_topic': '/traversability_costmap',
            'traversability_layer': 'traversability',
            'observed_layer': 'elevation',
            'safe_threshold': graphnav_safe_threshold,
            'unknown_is_free': True,
        }],
    )

    gazebo_livox_frame_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='gazebo_livox_frame_tf',
        arguments=[
            '0.12', '0.0', '0.33',
            '0.0', '0.0', '0.0', '1.0',
            'base_link', 'livox_frame',
        ],
        output='screen',
        condition=IfCondition(PythonExpression([
            "'", data_source, "'.lower() == 'gazebo'"
        ])),
    )

    wildos_front_camera_link_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_front_camera_link_tf',
        arguments=[
            '0.36', '0.0', '0.24',
            '0.0', '0.0', '0.0', '1.0',
            'base_link', 'wildos_front_camera_link',
        ],
        output='screen',
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
        },
    )

    wildos_front_camera_optical_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_front_camera_optical_tf',
        arguments=[
            '0.0', '0.0', '0.0',
            '-0.5', '0.5', '-0.5', '0.5',
            'wildos_front_camera_link', 'wildos_front_camera_color_optical_frame',
        ],
        output='screen',
        additional_env={
            'PYTHONPATH': [wildos_source_path, ':', EnvironmentVariable('PYTHONPATH', default_value='')],
            'MPLCONFIGDIR': '/tmp/matplotlib',
        },
    )

    wildos_left_camera_link_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_left_camera_link_tf',
        arguments=[
            '0.08', '0.25', '0.24',
            '0.0', '0.0', '0.70710678', '0.70710678',
            'base_link', 'wildos_left_camera_link',
        ],
        output='screen',
    )

    wildos_left_camera_optical_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_left_camera_optical_tf',
        arguments=[
            '0.0', '0.0', '0.0',
            '-0.5', '0.5', '-0.5', '0.5',
            'wildos_left_camera_link', 'wildos_left_camera_color_optical_frame',
        ],
        output='screen',
    )

    wildos_right_camera_link_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_right_camera_link_tf',
        arguments=[
            '0.08', '-0.25', '0.24',
            '0.0', '0.0', '-0.70710678', '0.70710678',
            'base_link', 'wildos_right_camera_link',
        ],
        output='screen',
    )

    wildos_right_camera_optical_tf = Node(
        package='tf2_ros',
        executable='static_transform_publisher',
        name='wildos_right_camera_optical_tf',
        arguments=[
            '0.0', '0.0', '0.0',
            '-0.5', '0.5', '-0.5', '0.5',
            'wildos_right_camera_link', 'wildos_right_camera_color_optical_frame',
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
            '-p', ['use_sim_time:=', use_sim_time],
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
            '-p', ['use_sim_time:=', use_sim_time],
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
            '-p', ['use_sim_time:=', use_sim_time],
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

    initial_goal_mux = Node(
        package='dlio_gazebo_sim',
        executable='initial_goal_mux',
        name='initial_goal_mux',
        output='screen',
        condition=IfCondition(launch_goal_mux),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'real_goal_topic': triangulated_goal_topic,
            'output_goal_topic': active_goal_topic,
            'frame_id': initial_goal_frame,
            'initial_goal_x': ParameterValue(initial_goal_x, value_type=float),
            'initial_goal_y': ParameterValue(initial_goal_y, value_type=float),
            'initial_goal_z': ParameterValue(initial_goal_z, value_type=float),
            'initial_goal_yaw': ParameterValue(initial_goal_yaw, value_type=float),
            'publish_rate': ParameterValue(initial_goal_publish_rate, value_type=float),
            'latch_real_goal': True,
        }],
    )

    graphnav_planner = Node(
        package='graphnav_planner',
        executable='planner_node',
        name='graphnav_planner',
        output='screen',
        condition=IfCondition(launch_graphnav_planner),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'trav_class': graphnav_planner_trav_class,
            'no_goal_strategy': graphnav_planner_no_goal_strategy,
            'virtual_goal_frame': graphnav_planner_virtual_goal_frame,
            'virtual_goal_x': ParameterValue(graphnav_planner_virtual_goal_x, value_type=float),
            'virtual_goal_y': ParameterValue(graphnav_planner_virtual_goal_y, value_type=float),
            'virtual_goal_z': ParameterValue(graphnav_planner_virtual_goal_z, value_type=float),
            'virtual_goal_yaw': ParameterValue(graphnav_planner_virtual_goal_yaw, value_type=float),
            'frontier_dist_cost_factor': ParameterValue(graphnav_planner_frontier_dist_cost_factor, value_type=float),
            'goal_dist_cost_factor': ParameterValue(graphnav_planner_goal_dist_cost_factor, value_type=float),
            'frontier_score_factor': ParameterValue(graphnav_planner_frontier_score_factor, value_type=float),
            'use_frontier_scores': ParameterValue(graphnav_planner_use_frontier_scores, value_type=bool),
            'min_frontier_score_for_cost': ParameterValue(graphnav_planner_min_frontier_score_for_cost, value_type=float),
            'min_local_frontier_score': ParameterValue(graphnav_planner_min_local_frontier_score, value_type=float),
            'local_frontier_radius': ParameterValue(graphnav_planner_local_frontier_radius, value_type=float),
            'path_smoothness_period': ParameterValue(graphnav_planner_path_smoothness_period, value_type=float),
            'goal_radius': ParameterValue(graphnav_planner_goal_radius, value_type=float),
        }],
        remappings=[
            ('~/nav_graph', graphnav_planner_nav_graph_topic),
            ('~/odom', graphnav_odom_topic),
            ('~/goal_pose', graphnav_planner_goal_topic),
            ('~/path', graphnav_planner_path_topic),
        ],
    )

    graphnav_path_follower = Node(
        package='graphnav_planner',
        executable='path_follower_node',
        name='graphnav_path_follower',
        output='screen',
        condition=IfCondition(launch_graphnav_planner),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'wp_lookahead_dist': ParameterValue(graphnav_path_follower_lookahead, value_type=float),
            'waypoint_arrival_radius': ParameterValue(graphnav_path_follower_arrival_radius, value_type=float),
            'path_timeout': ParameterValue(graphnav_path_follower_timeout, value_type=float),
        }],
        remappings=[
            ('~/path', graphnav_planner_path_topic),
            ('~/odom', graphnav_odom_topic),
            ('~/goal_pose', nav2_goal_topic),
        ],
    )

    static_path_publisher = Node(
        package='dlio_gazebo_sim',
        executable='static_path_publisher',
        name='static_path_publisher',
        output='screen',
        condition=IfCondition(launch_static_path),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'path_topic': graphnav_planner_path_topic,
            'odom_topic': graphnav_odom_topic,
            'frame_id': static_path_frame,
            'waypoints': static_path_waypoints,
            'prepend_current_pose': ParameterValue(static_path_prepend_current_pose, value_type=bool),
            'wait_for_subscriber': True,
            'publish_period': 0.5,
        }],
    )

    goal_pose_bridge = Node(
        package='dlio_gazebo_sim',
        executable='goal_pose_to_nav2_action',
        name='goal_pose_to_nav2_action',
        output='screen',
        condition=IfCondition(launch_goal_pose_bridge),
        parameters=[{
            'use_sim_time': ParameterValue(use_sim_time, value_type=bool),
            'goal_topic': nav2_goal_topic,
            'action_name': nav2_action_name,
            'default_frame_id': 'odom',
            'send_period': ParameterValue(goal_pose_bridge_send_period, value_type=float),
            'min_goal_distance': ParameterValue(goal_pose_bridge_min_goal_distance, value_type=float),
            'min_goal_yaw': ParameterValue(goal_pose_bridge_min_goal_yaw, value_type=float),
            'stamp_goal_with_now': True,
            'cancel_on_new_goal': ParameterValue(goal_pose_bridge_cancel_on_new_goal, value_type=bool),
        }],
    )

    nav2 = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(nav2_launch_file),
        launch_arguments={
            'use_sim_time': use_sim_time,
            'autostart': nav2_autostart,
            'params_file': nav2_params_file,
        }.items(),
        condition=IfCondition(launch_nav2),
    )

    return LaunchDescription([
        DeclareLaunchArgument('rviz', default_value='true'),
        DeclareLaunchArgument('gz_gui', default_value='true'),
        DeclareLaunchArgument(
            'data_source',
            default_value='go2_rosbag',
            description='Sensor data source: gazebo, rosbag (Oxford), go2_rosbag, or go2_live',
        ),
        DeclareLaunchArgument('dlio_output', default_value='log'),
        DeclareLaunchArgument(
            'gazebo_dlio_extra_params',
            default_value=PathJoinSubstitution([pkg, 'config', 'dlio_gazebo_extrinsics.yaml']),
            description='DLIO extrinsic override used automatically when data_source:=gazebo.',
        ),
        DeclareLaunchArgument('gazebo_deskewed_lidar_topic', default_value='/points_deskewed_lidar'),
        DeclareLaunchArgument('gazebo_deskewed_lidar_frame', default_value='livox_frame'),
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
        DeclareLaunchArgument(
            'go2_rosbag_path',
            default_value='/root/ros2_ws/data/go2_full_debug_2026-06-23_175536',
            description='Path to the Go2 Livox rosbag2 database.',
        ),
        DeclareLaunchArgument('go2_pointcloud_topic', default_value='/livox/lidar'),
        DeclareLaunchArgument('go2_imu_topic', default_value='/livox/imu'),
        DeclareLaunchArgument(
            'go2_adapter_input_topic',
            default_value='/go2/livox/imu_raw_g',
            description='Private topic carrying the unscaled Livox acceleration in g.',
        ),
        DeclareLaunchArgument('go2_rosbag_rate', default_value='0.5'),
        DeclareLaunchArgument('go2_rosbag_loop', default_value='false'),
        DeclareLaunchArgument('go2_rosbag_start_offset', default_value='0.0'),
        DeclareLaunchArgument('go2_rosbag_start_delay', default_value='2.0'),
        DeclareLaunchArgument(
            'go2_rosbag_playback_duration',
            default_value='-1',
            description='Optional playback duration in seconds; -1 plays the complete Go2 bag.',
        ),
        DeclareLaunchArgument(
            'go2_dlio_extra_params',
            default_value=PathJoinSubstitution([pkg, 'config', 'dlio_go2_livox_rosbag.yaml']),
            description='Go2-specific DLIO frames and provisional Livox extrinsics.',
        ),
        DeclareLaunchArgument('go2_deskewed_lidar_topic', default_value='/points_deskewed_lidar'),
        DeclareLaunchArgument('go2_deskewed_lidar_frame', default_value='livox_frame'),
        DeclareLaunchArgument('go2_elevation_config', default_value='dlio_gazebo/go2_livox.yaml'),
        DeclareLaunchArgument(
            'go2_acceleration_scale',
            default_value='9.80665',
            description='Scale Livox accelerometer samples from g to m/s^2.',
        ),
        # DeclareLaunchArgument('world', default_value='dlio_room.sdf'),
        DeclareLaunchArgument('world', default_value='dlio_score_ring_test.sdf'),
        DeclareLaunchArgument('linear_x', default_value='0.45'),
        DeclareLaunchArgument('angular_z', default_value='0.22'),
        DeclareLaunchArgument('start_delay', default_value='4.0'),
        DeclareLaunchArgument('auto_drive', default_value='false'),
        DeclareLaunchArgument(
            'launch_local_dlio',
            default_value='false',
            description='Launch DLIO and Go2 IMU preprocessing on this computer. Keep false when consuming DLIO output from another computer.',
        ),
        DeclareLaunchArgument('launch_elevation', default_value='true'),
        DeclareLaunchArgument('launch_graphnav', default_value='true'),
        DeclareLaunchArgument('launch_graphnav_markers', default_value='true'),
        DeclareLaunchArgument('launch_grid_threshold_markers', default_value='true'),
        DeclareLaunchArgument('launch_wildos', default_value='true'),
        DeclareLaunchArgument('launch_explorfm_probe', default_value='false'),
        DeclareLaunchArgument('launch_goal_mux', default_value='true'),
        DeclareLaunchArgument('launch_graphnav_planner', default_value='true'),
        DeclareLaunchArgument('launch_static_path', default_value='false'),
        DeclareLaunchArgument('launch_goal_pose_bridge', default_value='true'),
        DeclareLaunchArgument('launch_nav2', default_value='false'),
        DeclareLaunchArgument('wildos_config', default_value='dlio_gazebo_wildos.yaml'),
        DeclareLaunchArgument('explorfm_probe_config', default_value='dlio_gazebo_explorfm_probe.yaml'),
        DeclareLaunchArgument('wildos_object_search', default_value='false'),
        DeclareLaunchArgument('wildos_python', default_value='/usr/bin/python3'),
        DeclareLaunchArgument('triangulation_config', default_value='dlio_gazebo_triangulation.yaml'),
        DeclareLaunchArgument('triangulated_goal_topic', default_value='/imgnav_waypoint'),
        DeclareLaunchArgument('active_goal_topic', default_value='/active_imgnav_waypoint'),
        DeclareLaunchArgument('nav2_goal_topic', default_value='/graphnav_lookahead_goal'),
        DeclareLaunchArgument('initial_goal_frame', default_value='odom'),
        DeclareLaunchArgument('initial_goal_x', default_value='100.0'),
        DeclareLaunchArgument('initial_goal_y', default_value='0.0'),
        DeclareLaunchArgument('initial_goal_z', default_value='0.0'),
        DeclareLaunchArgument('initial_goal_yaw', default_value='0.0'),
        DeclareLaunchArgument('initial_goal_publish_rate', default_value='1.0'),
        DeclareLaunchArgument('graphnav_planner_path_topic', default_value='/graphnav_planner/path'),
        DeclareLaunchArgument('graphnav_planner_nav_graph_topic', default_value='/scored_nav_graph'),
        DeclareLaunchArgument('graphnav_planner_goal_topic', default_value='/active_imgnav_waypoint'),
        DeclareLaunchArgument('graphnav_planner_trav_class', default_value='elevation_traversability'),
        DeclareLaunchArgument('graphnav_planner_no_goal_strategy', default_value='best_frontier_score'),#virtual_goal,best_frontier_score
        DeclareLaunchArgument('graphnav_planner_virtual_goal_frame', default_value='odom'),
        DeclareLaunchArgument('graphnav_planner_virtual_goal_x', default_value='100.0'),
        DeclareLaunchArgument('graphnav_planner_virtual_goal_y', default_value='0.0'),
        DeclareLaunchArgument('graphnav_planner_virtual_goal_z', default_value='0.0'),
        DeclareLaunchArgument('graphnav_planner_virtual_goal_yaw', default_value='0.0'),
        DeclareLaunchArgument('graphnav_planner_frontier_dist_cost_factor', default_value='2.0'),
        DeclareLaunchArgument('graphnav_planner_goal_dist_cost_factor', default_value='1.0'),
        DeclareLaunchArgument('graphnav_planner_frontier_score_factor', default_value='4.0'),
        DeclareLaunchArgument('graphnav_planner_use_frontier_scores', default_value='true'),
        DeclareLaunchArgument('graphnav_planner_min_frontier_score_for_cost', default_value='0.001'),
        DeclareLaunchArgument('graphnav_planner_min_local_frontier_score', default_value='0.4'),
        DeclareLaunchArgument('graphnav_planner_local_frontier_radius', default_value='10.0'),
        DeclareLaunchArgument('graphnav_planner_path_smoothness_period', default_value='0.0'),
        DeclareLaunchArgument('graphnav_planner_goal_radius', default_value='3.0'),
        DeclareLaunchArgument('graphnav_path_follower_lookahead', default_value='0.6'),
        DeclareLaunchArgument('graphnav_path_follower_arrival_radius', default_value='0.35'),
        DeclareLaunchArgument('graphnav_path_follower_timeout', default_value='0.0'),
        DeclareLaunchArgument(
            'static_path_waypoints',
            default_value='0,0;2,0;4,0;7,0;9,0;12,0;16,0',
            description='Semicolon-separated x,y waypoints for the static Nav2 path test.',
        ),
        DeclareLaunchArgument('static_path_frame', default_value='odom'),
        DeclareLaunchArgument('static_path_prepend_current_pose', default_value='true'),
        DeclareLaunchArgument(
            'nav2_launch_file',
            default_value=PathJoinSubstitution([pkg, 'launch', 'nav2_dlio_navigation.launch.py']),
        ),
        DeclareLaunchArgument(
            'nav2_params_file',
            default_value=PathJoinSubstitution([pkg, 'config', 'nav2_dlio_gazebo.yaml']),
        ),
        DeclareLaunchArgument('nav2_autostart', default_value='true'),
        DeclareLaunchArgument('nav2_action_name', default_value='/navigate_to_pose'),
        DeclareLaunchArgument('goal_pose_bridge_send_period', default_value='0.2'),
        DeclareLaunchArgument('goal_pose_bridge_min_goal_distance', default_value='0.08'),
        DeclareLaunchArgument('goal_pose_bridge_min_goal_yaw', default_value='0.15'),
        DeclareLaunchArgument('goal_pose_bridge_cancel_on_new_goal', default_value='true'),
        DeclareLaunchArgument('use_synthetic_sensors', default_value='false'),
        DeclareLaunchArgument('use_gazebo_cloud_adapter', default_value='true'),
        DeclareLaunchArgument(
            'show_gazebo_base_link',
            default_value='true',
            description='Publish Gazebo ground-truth odometry as odom->gazebo_base_link for RViz comparison.',
        ),
        DeclareLaunchArgument('graphnav_grid_map_topic', default_value='/elevation_mapping_node/elevation_map_raw'),
        DeclareLaunchArgument('graphnav_odom_topic', default_value='/dlio/odom_node/odom'),
        DeclareLaunchArgument('graphnav_topic', default_value='/nav_graph'),
        DeclareLaunchArgument('graphnav_safe_threshold', default_value='0.2'),
        DeclareLaunchArgument('graphnav_local_map_radius', default_value='5.0'),
        DeclareLaunchArgument('graphnav_edge_radius', default_value='5.0'),
        DeclareLaunchArgument('graphnav_num_samples', default_value='100'),
        DeclareLaunchArgument('graphnav_update_every_timestep', default_value='true'),
        DeclareLaunchArgument('graphnav_update_min_travel', default_value='0.5'),
        DeclareLaunchArgument('graphnav_update_free_radius_fraction', default_value='0.8'),
        DeclareLaunchArgument('graphnav_grid_map_queue_depth', default_value='1'),
        DeclareLaunchArgument('graphnav_frontier_association_radius', default_value='1.5'),
        DeclareLaunchArgument('graphnav_min_frontier_cluster_size', default_value='5'),
        DeclareLaunchArgument('graphnav_publish_global_memory_markers', default_value='false'),
        DeclareLaunchArgument('graphnav_global_memory_marker_topic', default_value='/global_traversability_markers'),
        DeclareLaunchArgument('graphnav_global_memory_marker_stride', default_value='2'),
        DeclareLaunchArgument('graphnav_publish_global_memory_grid', default_value='false'),
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
        rviz_node,
        bridge,
        gazebo_cloud_adapter,
        gazebo_odom_tf,
        synthetic_sensors,
        circle_cmd,
        rosbag_wildos_camera_bridge,
        rosbag_play,
        go2_rosbag_play,
        go2_livox_imu_adapter,
        go2_live_livox_imu_adapter,
        dlio_gazebo,
        dlio_rosbag,
        dlio_go2_rosbag,
        dlio_go2_live,
        gazebo_deskewed_lidar_bridge,
        rosbag_deskewed_lidar_bridge,
        go2_deskewed_lidar_bridge,
        elevation_mapping_gazebo,
        elevation_mapping_rosbag,
        elevation_mapping_go2_rosbag,
        graphnav_builder,
        nav_graph_markers,
        grid_threshold_markers,
        traversability_costmap,
        gazebo_livox_frame_tf,
        wildos_front_camera_link_tf,
        wildos_front_camera_optical_tf,
        wildos_left_camera_link_tf,
        wildos_left_camera_optical_tf,
        wildos_right_camera_link_tf,
        wildos_right_camera_optical_tf,
        wildos,
        explorfm_probe,
        obj_mask_triangulation,
        initial_goal_mux,
        graphnav_planner,
        graphnav_path_follower,
        static_path_publisher,
        goal_pose_bridge,
        nav2,
    ])
