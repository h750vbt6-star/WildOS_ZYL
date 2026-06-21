from glob import glob
from setuptools import find_packages, setup

package_name = 'dlio_gazebo_sim'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/config', glob('config/*.yaml')),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
        ('share/' + package_name + '/models/dlio_car', glob('models/dlio_car/*')),
        ('share/' + package_name + '/worlds', glob('worlds/*')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros2_ws',
    maintainer_email='user@example.com',
    description='Gazebo simulation helpers for DLIO.',
    license='MIT',
    entry_points={
        'console_scripts': [
            'synthetic_dlio_sensors = dlio_gazebo_sim.synthetic_dlio_sensors:main',
            'circle_cmd = dlio_gazebo_sim.circle_cmd:main',
            'gazebo_cloud_adapter = dlio_gazebo_sim.gazebo_cloud_adapter:main',
            'gazebo_odom_tf = dlio_gazebo_sim.gazebo_odom_tf:main',
            'livox_imu_adapter = dlio_gazebo_sim.livox_imu_adapter:main',
            'odom_cloud_to_lidar_frame = dlio_gazebo_sim.odom_cloud_to_lidar_frame:main',
            'nav_graph_markers = dlio_gazebo_sim.nav_graph_markers:main',
            'grid_threshold_markers = dlio_gazebo_sim.grid_threshold_markers:main',
            'traversability_costmap = dlio_gazebo_sim.traversability_costmap:main',
            'initial_goal_mux = dlio_gazebo_sim.initial_goal_mux:main',
            'goal_pose_to_nav2_action = dlio_gazebo_sim.goal_pose_to_nav2_action:main',
            'static_path_publisher = dlio_gazebo_sim.static_path_publisher:main',
        ],
    },
)
