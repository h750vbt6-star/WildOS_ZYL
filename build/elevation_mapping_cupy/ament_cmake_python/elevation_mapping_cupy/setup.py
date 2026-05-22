from setuptools import find_packages
from setuptools import setup

setup(
    name='elevation_mapping_cupy',
    version='2.1.0',
    packages=find_packages(
        include=('elevation_mapping_cupy', 'elevation_mapping_cupy.*')),
)
