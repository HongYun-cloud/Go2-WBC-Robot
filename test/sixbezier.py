import matplotlib.pyplot as plt
import numpy as np

# 参数
T_swing = 0.35  # 摆动周期
H = 0.2  # 抬腿高度
t = np.linspace(0, 1, 500)  # 归一化时间

# 6阶贝塞尔解析展开式 (仅 P3 = 3.2*H 生效)
# Z(t) = 20 * (1-t)^3 * t^3 * P3
P3 = 3.2 * H

pos_z = 20 * P3 * (t**3 - 3 * t**4 + 3 * t**5 - t**6)
vel_z = 20 * P3 * (3 * t**2 - 12 * t**3 + 15 * t**4 - 6 * t**5) / T_swing
acc_z = 20 * P3 * (6 * t - 36 * t**2 + 60 * t**3 - 30 * t**4) / (T_swing**2)

# 画图
plt.figure(figsize=(6, 8))
plt.subplot(3, 1, 1)
plt.plot(t, pos_z, "b")
plt.title("6th-Order Bezier Z Position")
plt.grid(True)

plt.subplot(3, 1, 2)
plt.plot(t, vel_z, "g")
plt.title("Velocity (m/s)")
plt.grid(True)

plt.subplot(3, 1, 3)
plt.plot(t, acc_z, "r")
plt.title("Acceleration (m/s^2) - No Spike at t=0.5!")
plt.grid(True)
plt.tight_layout()
plt.show()