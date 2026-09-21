"""Go2 四足 WBC 仿真节点启动文件.

用法:
  # 方式一: 源码路径启动 (从包根目录执行, 改 config/*.yaml 即时生效, 无需重新 build)
  ros2 launch launch/go2_sim.launch.py

  # 方式二: 按包名启动 (需要先 colcon build --packages-select go2_robot)
  ros2 launch go2_robot go2_sim.launch.py

可调启动参数:
  gait:=TROT|WALK|STAND   初始步态 (默认 TROT)
"""

import os

from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration
from launch_ros.actions import Node


def _resolve_pkg_root() -> str:
    """定位包根目录 (包含 go2/ 模型与 config/ 的目录).

    优先源码树: launch 文件在 <包根>/launch/ 下, 上级即包根;
    若源码树中没有模型 (从 install 分享目录启动), 回退到安装目录.
    """
    src_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    if os.path.isfile(os.path.join(src_root, 'go2', 'scene.xml')):
        return src_root
    return get_package_share_directory('go2_robot')


def generate_launch_description():
    pkg_root = _resolve_pkg_root()

    # MuJoCo 动态库路径: 可执行文件 NEEDED libmujoco.so.3.9.0, 但无内嵌 RUNPATH,
    # 终端里没 export 过 LD_LIBRARY_PATH 就起不来 → launch 统一注入
    mujoco_home = os.environ.get('MUJOCO_HOME', os.path.expanduser('~/.mujoco/mujoco-3.9.0'))
    ld_library_paths = [os.path.join(mujoco_home, 'lib')]
    if os.environ.get('LD_LIBRARY_PATH'):
        ld_library_paths.append(os.environ['LD_LIBRARY_PATH'])

    return LaunchDescription([
        DeclareLaunchArgument(
            'gait', default_value='TROT',
            description='初始步态: TROT / WALK / STAND',
        ),

        Node(
            package='go2_robot',
            executable='go2_control_node',
            name='go2_control_node',
            output='screen',
            emulate_tty=True,
            additional_env={
                'MUJOCO_HOME': mujoco_home,
                'LD_LIBRARY_PATH': ':'.join(ld_library_paths),
            },
            # parameters=[
            #     # 频率/步态/限幅等参数来自 config/go2_params.yaml
            #     os.path.join(pkg_root, 'config', 'go2_params.yaml'),
            #     {
            #         # 路径参数用绝对路径覆盖: 节点里的默认值相对运行目录,
            #         # 而 ros2 launch 时节点 cwd 取决于启动位置, 不可靠
            #         'mujoco_model': os.path.join(pkg_root, 'go2', 'scene.xml'),
            #         'urdf_path': os.path.join(pkg_root, 'go2', 'go2_description.urdf'),
            #         'control_config': os.path.join(pkg_root, 'config', 'control.yaml'),
            #         'initial_gait': LaunchConfiguration('gait'),
            #     },
            # ],
        ),
    ])
