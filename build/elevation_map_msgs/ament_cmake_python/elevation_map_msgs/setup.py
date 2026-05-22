from setuptools import find_packages
from setuptools import setup

setup(
    name='elevation_map_msgs',
    version='2.1.0',
    packages=find_packages(
        include=('elevation_map_msgs', 'elevation_map_msgs.*')),
)
