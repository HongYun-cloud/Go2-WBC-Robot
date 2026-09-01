import numpy as np
import matplotlib.pyplot as plt

def visualize_bezier():
    # 1. 定义 4 个控制点 (三阶贝塞尔)
    # 设定：从 (0,0) 到 (1,0)，抬腿高度 0.2
    p0 = np.array([0.0, 0.0])      # 起点
    p3 = np.array([1.0, 0.0])      # 终点
    
    # 采用“垂直起降”策略设置中间点
    swing_height = 0.2
    p1 = np.array([0.0, swing_height]) # P1 在 P0 正上方
    p2 = np.array([1.0, swing_height]) # P2 在 P3 正上方

    # 2. 生成归一化时间 s (从 0 到 1)
    s = np.linspace(0, 1, 100)
    T_swing = 1.0  # 假设摆动时间为 1 秒
    
    # 3. 计算位置 P(s)
    # B(s) = (1-s)^3*P0 + 3s(1-s)^2*P1 + 3s^2(1-s)*P2 + s^3*P3
    pos = (np.outer((1-s)**3, p0) + 
           np.outer(3*s*(1-s)**2, p1) + 
           np.outer(3*(s**2)*(1-s), p2) + 
           np.outer(s**3, p3))

    # 4. 计算速度 V(s) —— 一阶导数
    # B'(s) = 3(1-s)^2(P1-P0) + 6s(1-s)(P2-P1) + 3s^2(P3-P2)
    # 实际速度 = B'(s) / T_swing
    vel = (np.outer(3*(1-s)**2, p1 - p0) + 
           np.outer(6*s*(1-s), p2 - p1) + 
           np.outer(3*s**2, p3 - p2)) / T_swing

    # 5. 计算加速度 A(s) —— 二阶导数
    # B''(s) = 6(1-s)(P2 - 2P1 + P0) + 6s(P3 - 2P2 + P1)
    # 实际加速度 = B''(s) / T_swing^2
    acc = (np.outer(6*(1-s), p2 - 2*p1 + p0) + 
           np.outer(6*s, p3 - 2*p2 + p1)) / (T_swing**2)

    # --- 开始绘图 ---
    fig = plt.figure(figsize=(12, 10))
    plt.subplots_adjust(hspace=0.4)

    # 子图 1: 足端空间轨迹 (X-Z 坐标)
    ax1 = plt.subplot(3, 1, 1)
    ax1.plot(pos[:, 0], pos[:, 1], 'b-', lw=3, label='Foot Trajectory')
    ax1.scatter([p0[0], p1[0], p2[0], p3[0]], [p0[1], p1[1], p2[1], p3[1]], 
                color='red', label='Control Points')
    ax1.set_title("1. Foot Space Trajectory (X vs Z)")
    ax1.set_xlabel("Horizontal Position (X)")
    ax1.set_ylabel("Vertical Height (Z)")
    ax1.grid(True)
    ax1.legend()
    ax1.set_aspect('equal')

    # 子图 2: 速度曲线 (随时间变化)
    ax2 = plt.subplot(3, 1, 2)
    ax2.plot(s, vel[:, 0], 'r--', label='Vel X (Forward)')
    ax2.plot(s, vel[:, 1], 'g-', label='Vel Z (Up/Down)')
    ax2.set_title("2. Velocity Curves (B's)")
    ax2.set_xlabel("Normalized Time (s)")
    ax2.set_ylabel("Velocity")
    ax2.grid(True)
    ax2.legend()

    # 子图 3: 加速度曲线 (随时间变化)
    ax3 = plt.subplot(3, 1, 3)
    ax3.plot(s, acc[:, 0], 'r--', label='Acc X')
    ax3.plot(s, acc[:, 1], 'g-', label='Acc Z')
    ax3.set_title("3. Acceleration Curves (B''s)")
    ax3.set_xlabel("Normalized Time (s)")
    ax3.set_ylabel("Acceleration")
    ax3.grid(True)
    ax3.legend()

    plt.show()

if __name__ == "__main__":
    visualize_bezier()