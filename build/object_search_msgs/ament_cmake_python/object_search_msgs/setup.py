from setuptools import find_packages
from setuptools import setup

setup(
    name='object_search_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('object_search_msgs', 'object_search_msgs.*')),
)
