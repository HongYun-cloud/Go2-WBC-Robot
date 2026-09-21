"""Go2 四足 WBC 仿真节点启动文件.

用法:
  # 方式一: 源码路径启动 (从包根目录执行, 改 config/*.yaml 即时生效, 无需重新 build)
  ros2 launch launch/go2_sim.launch.py

  # 方式二: 按包名启动 (需要先 colcon build --packages-select go2_robot)
  #   注意: 这种方式 <pkg_root> 解析到 install/go2_robot/share/go2_robot,
  #   读的是 install 里那份 config/go2_params.yaml, 改源码树的 yaml 要先 build
  ros2 launch go2_robot go2_sim.launch.py

参数优先级 (高 → 低):
  1. 启动参数 (下面的 gait / overrides)
  2. <pkg_root>/config/go2_params.yaml   ← 数据源, 第一优先
  3. 节点里 declare_parameter 的默认值

路径参数 (mujoco_model / urdf_path / control_config) 同样以 yaml 为准, 只是由本文件
把 yaml 里的**相对路径按 <pkg_root> 解析成绝对路径**再传给节点 (节点自己的默认值是相对
**运行目录**的, 而 ros2 launch 时节点 cwd 取决于启动位置, 不可靠):
      yaml:  mujoco_model: "go2/scene_flat.xml"
   → 实际加载 <pkg_root>/go2/scene_flat.xml
  换模型/换 URDF 改 yaml 即可; 写绝对路径则原样使用。找不到文件会在启动时直接报错。

可调启动参数:
  gait:=TROT|WALK|STAND     覆盖 yaml 的 initial_gait; 留空 (默认) = 用 yaml 的值
  overrides:="{key: value}" 临时覆盖 yaml 里任意参数 (yaml 语法的字典), 用于不编辑文件
                            快速试参数, 例:
        ros2 launch launch/go2_sim.launch.py overrides:="{desired_height: 0.28, touchdown_force: 8.0}"
        ros2 launch launch/go2_sim.launch.py gait:=WALK overrides:="{airborne_hold_ratio: 0.001}"
  注: wbc.W / wbc.FI / wbc.C 是数组, 要整条覆盖:
        overrides:="{wbc: {C: [200,200,200, 200,200,200, 200,200,200, 200,200,200]}}"
"""

import os

import yaml
from ament_index_python.packages import get_package_share_directory
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, OpaqueFunction
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


# 路径参数的 yaml 缺省值 (yaml 里没写这一项时用), 均相对 <pkg_root>
_DEFAULT_PATHS = {
    'mujoco_model':   'go2/scene.xml',
    'urdf_path':      'go2/go2_description.urdf',
    'control_config': 'config/control.yaml',
}


def _make_node(context, *args, **kwargs):
    """按"yaml 为底 + 启动参数覆盖"的优先级拼 parameters 列表后建节点.

    用 OpaqueFunction 而不是静态列表: 启动参数留空时**不能**把覆盖项塞进 parameters
    (launch_ros 的 parameters 列表是后面的覆盖前面的, 塞一个空值或默认值进去
    yaml 就永远赢不了 —— 这正是之前 initial_gait 改了不生效的原因).
    """
    pkg_root = _resolve_pkg_root()
    yaml_path = os.path.join(pkg_root, 'config', 'go2_params.yaml')

    # 读 yaml 只为把三个路径参数解析成绝对路径 (其余参数原样交给节点, 以文件为准)
    with open(yaml_path, 'r', encoding='utf-8') as f:
        node_cfg = ((yaml.safe_load(f) or {}).get('go2_control_node', {})
                    .get('ros__parameters', {})) or {}

    resolved_paths = {}
    for key, default in _DEFAULT_PATHS.items():
        val = node_cfg.get(key) or default
        if not isinstance(val, str):
            raise RuntimeError(f"{key} 应该是字符串路径, yaml 里是 {val!r}")
        path = val if os.path.isabs(val) else os.path.join(pkg_root, val)
        if not os.path.isfile(path):
            raise RuntimeError(
                f"{key} 指向的文件不存在: {path}\n"
                f"  (yaml 里写的是 {val!r}; 相对路径按 <pkg_root>={pkg_root} 解析)")
        resolved_paths[key] = path

    # 优先级从低到高依次 append
    params = [
        yaml_path,          # 1) yaml: 数据源
        resolved_paths,     # 2) 路径参数绝对化 (见文件头说明)
    ]

    # 3) 启动参数覆盖: 留空 = 不覆盖, 让 yaml 生效
    gait = context.launch_configurations.get('gait', '')
    if gait:
        params.append({'initial_gait': gait})

    raw = context.launch_configurations.get('overrides', '')
    if raw:
        try:
            extra = yaml.safe_load(raw)
        except yaml.YAMLError as e:
            raise RuntimeError(f"overrides 不是合法 yaml: {raw!r} ({e})") from e
        if not isinstance(extra, dict):
            raise RuntimeError(
                f"overrides 必须是 {{参数名: 值}} 字典, 收到 {type(extra).__name__}: {raw!r}")
        params.append(extra)

    # MuJoCo 动态库路径: 可执行文件 NEEDED libmujoco.so.3.9.0, 但无内嵌 RUNPATH,
    # 终端里没 export 过 LD_LIBRARY_PATH 就起不来 → launch 统一注入
    mujoco_home = os.environ.get('MUJOCO_HOME', os.path.expanduser('~/.mujoco/mujoco-3.9.0'))
    ld_library_paths = [os.path.join(mujoco_home, 'lib')]
    if os.environ.get('LD_LIBRARY_PATH'):
        ld_library_paths.append(os.environ['LD_LIBRARY_PATH'])

    return [Node(
        package='go2_robot',
        executable='go2_control_node',
        name='go2_control_node',
        output='screen',
        emulate_tty=True,
        additional_env={
            'MUJOCO_HOME': mujoco_home,
            'LD_LIBRARY_PATH': ':'.join(ld_library_paths),
        },
        parameters=params,
    )]


def generate_launch_description():
    return LaunchDescription([
        DeclareLaunchArgument(
            'gait', default_value='',
            description='覆盖 go2_params.yaml 的 initial_gait: TROT / WALK / STAND; '
                        '留空 (默认) = 用 yaml 里的值',
        ),
        DeclareLaunchArgument(
            'overrides', default_value='',
            description='覆盖 yaml 里任意参数 (yaml 语法字典), 例: '
                        'overrides:="{desired_height: 0.28}"',
        ),
        OpaqueFunction(function=_make_node),
    ])
