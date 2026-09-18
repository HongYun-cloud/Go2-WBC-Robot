#!/usr/bin/env bash
# clean.sh — 清理 ROS2 colcon 编译缓存 (build / install / log)
# 用法: ./clean.sh [--dry-run]
set -euo pipefail
cd "$(dirname "$0")"

dirs=(build install log)

echo "清理前磁盘占用:"
du -sh "${dirs[@]}" 2>/dev/null || true

if [[ "${1:-}" == "--dry-run" ]]; then
    echo "(dry-run 模式,未执行删除)"
    exit 0
fi

for d in "${dirs[@]}"; do
    rm -rf "$d"
done

echo "清理完成。如需重新编译: colcon build --packages-select go2_robot"
