from sys import executable
from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration,Command
from ament_index_python.packages import get_package_share_directory
import os
from typing import LiteralString

def generate_launch_description():
    pgk_name:str = 'robot_desc'
    
    urdf_file:LiteralString = os.path.join(get_package_share_directory(pgk_name), 'urdf', 'robot.urdf.xacro')

    robot_descritption:object|Command = Command(['xacro', ' ', urdf_file])
    
    return LaunchDescription([
        Node(
            package=pgk_name,
            executable='rsp',
            name='robot_state_publisher',
            output = 'screen',
            parameters = [{
                'description': robot_descritption
            }]
        ),
        Node(
            package=pgk_name,
            executable='jsp',
            name='joint_state_publisher',
            output = 'screen'
        ),
        Node(
            package='rviz2',
            executable='rviz2',
            name='rviz2',
            arguments = [
                '-d', os.path.join(
                    get_package_share_directory(pgk_name),
                    'rviz',
                    'robot_config.rviz'
                )
            ],
            output = 'screen'
            )
    
    ])