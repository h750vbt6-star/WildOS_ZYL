from glob import glob
from setuptools import find_packages, setup

package_name = 'wildos_rosbag_bridge'

setup(
    name=package_name,
    version='0.0.1',
    packages=find_packages(),
    data_files=[
        ('share/ament_index/resource_index/packages', ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', glob('launch/*.launch.py')),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros2_ws',
    maintainer_email='user@example.com',
    description='ROS bag camera adapter for WildOS.',
    license='MIT',
    entry_points={
        'console_scripts': [
            'alphasense_to_wildos = wildos_rosbag_bridge.alphasense_to_wildos:main',
        ],
    },
)
