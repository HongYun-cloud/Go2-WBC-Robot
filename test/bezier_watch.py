import numpy as np
import matplotlib.pyplot as plt
from math import comb

def calc_bezier_derivatives(P, s, T):
    """任意阶贝塞尔曲线的位置/速度/加速度 (Bernstein 基通用形式)

    P: (n+1) x 2 控制点矩阵, s: 归一化时间, T: 摆动周期
    """
    n = P.shape[0] - 1  # 阶数
    s = np.asarray(s)

    # B(s) = sum_i C(n,i) (1-s)^(n-i) s^i * Pi
    pos = np.zeros((len(s), P.shape[1]))
    for i in range(n + 1):
        pos += np.outer(comb(n, i) * (1 - s)**(n - i) * s**i, P[i])

    # B'(s) = n * sum_i C(n-1,i) (1-s)^(n-1-i) s^i * (P_{i+1} - P_i)
    d1 = P[1:] - P[:-1]
    vel = np.zeros_like(pos)
    for i in range(n):
        vel += np.outer(comb(n - 1, i) * (1 - s)**(n - 1 - i) * s**i, d1[i])
    vel = n * vel / T

    # B''(s) = n(n-1) * sum_i C(n-2,i) (1-s)^(n-2-i) s^i * (P_{i+2} - 2P_{i+1} + P_i)
    d2 = d1[1:] - d1[:-1]
    acc = np.zeros_like(pos)
    for i in range(n - 1):
        acc += np.outer(comb(n - 2, i) * (1 - s)**(n - 2 - i) * s**i, d2[i])
    acc = n * (n - 1) * acc / (T**2)

    return pos, vel, acc

def segment_derivatives(P, T, t_start=0.0, n_samples=100):
    """计算一段贝塞尔的导数, 返回绝对时间轴 t (从 t_start 到 t_start+T) 及 pos/vel/acc"""
    s = np.linspace(0, 1, n_samples)
    pos, vel, acc = calc_bezier_derivatives(P, s, T)
    t = np.linspace(t_start, t_start + T, n_samples)
    return t, pos, vel, acc

def plot_axis_column(axs, t, pos, vel, acc, title_prefix, axis_name):
    """在一列 3 个子图上画某一方向的位置/速度/加速度 (横轴均为时间)"""
    data = [(pos, '1. Position', 'Position (m)'),
            (vel, '2. Velocity', 'Velocity (m/s)'),
            (acc, '3. Acceleration', 'Acceleration (m/s^2)')]
    for ax, (curve, name, unit) in zip(axs, data):
        ax.plot(t, curve, 'b-', lw=2)
        ax.set_title(f"{title_prefix} {name}")
        ax.set_xlabel("Time (s)")
        ax.set_ylabel(f"{axis_name} {unit}")
        ax.grid(True)

def quartic_bezier(swing_height=0.2, stride=1.0, T_swing=1.0, n_samples=100):
    """四阶贝塞尔摆动腿轨迹 (5 个控制点, 垂直起降策略)

    仅计算并返回轨迹, 不参与绘图
    返回: pos, vel, acc (n_samples x 2)
    """
    P = np.array([
        [0.0,          swing_height],  # P1 垂直抬起
        [0.5 * stride, swing_height],  # P2 中间顶点
        [stride,       swing_height],  # P3 垂直下落
    ])
    P = np.vstack([[0.0, 0.0], P, [stride, 0.0]])  # P0 起点, P4 终点

    s = np.linspace(0, 1, n_samples)
    pos, vel, acc = calc_bezier_derivatives(P, s, T_swing)
    return pos, vel, acc

def visualize_bezier():
    swing_height = 0.2
    stride = 1.0
    T_swing = 1.0  # 摆动时间 (秒)
    h = swing_height

    # 左列: 三阶贝塞尔的 X 方向分量 (起点(0,0) -> 终点(1,0), 垂直起降)
    cubic = np.array([
        [0.0, 0.0],
        [0.0, h],
        [stride, h],
        [stride, 0.0],
    ])
    t, pos, vel, acc = segment_derivatives(cubic, T_swing)
    x_t, x_pos, x_vel, x_acc = t, pos[:, 0], vel[:, 0], acc[:, 0]

    # 右列: Z 方向 = 两段四阶贝塞尔拼合的分段曲线
    # 第一段 (0 ~ T/2): 从 0 平滑升到 h, 段末速度为 0
    seg1 = np.array([[0.0], [0.0], [0.0], [h], [h]])
    # 第二段 (T/2 ~ T): 从 h 平滑降回 0 (拼接点速度连续, 均为 0)
    seg2 = np.array([[h], [h], [0.0], [0.0], [0.0]])
    t1, p1, v1, a1 = segment_derivatives(seg1, T_swing / 2)
    t2, p2, v2, a2 = segment_derivatives(seg2, T_swing / 2, t_start=T_swing / 2)
    z_t = np.concatenate([t1, t2])
    z_pos = np.concatenate([p1.ravel(), p2.ravel()])
    z_vel = np.concatenate([v1.ravel(), v2.ravel()])
    z_acc = np.concatenate([a1.ravel(), a2.ravel()])

    # --- 开始绘图: 左列 X 方向, 右列 Z 方向, 横轴均为时间 ---
    fig, axs = plt.subplots(3, 2, figsize=(14, 10))
    plt.subplots_adjust(hspace=0.4, wspace=0.3)

    plot_axis_column(axs[:, 0], x_t, x_pos, x_vel, x_acc,
                     "[X: Cubic Bezier]", "X")
    plot_axis_column(axs[:, 1], z_t, z_pos, z_vel, z_acc,
                     "[Z: 2-Segment Piecewise Bezier]", "Z")

    # 在右列标出两段的拼接点 (t = T/2)
    for ax in axs[:, 1]:
        ax.axvline(T_swing / 2, color='red', ls='--', alpha=0.6, label='Segment Joint')
        ax.legend()

    plt.show()

if __name__ == "__main__":
    visualize_bezier()
