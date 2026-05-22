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
        ],
    },
)
