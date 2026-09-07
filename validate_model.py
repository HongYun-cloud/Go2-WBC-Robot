#!/usr/bin/env python3

import xml.etree.ElementTree as ET
import sys

def validate_mujoco_model(xml_file):
    """验证MuJoCo模型的关节和执行器配置"""
    print(f"验证模型文件: {xml_file}")
    
    try:
        tree = ET.parse(xml_file)
        root = tree.getroot()
        
        # 检查关节数量
        joints = root.findall(".//joint")
        print(f"找到 {len(joints)} 个关节:")
        
        for i, joint in enumerate(joints):
            name = joint.get("name", f"joint_{i}")
            joint_class = joint.get("class", "unknown")
            print(f"  {i+1}. {name} (class: {joint_class})")
        
        # 检查执行器数量
        actuators = root.findall(".//actuator")
        total_actuators = len(actuators)
        print(f"\n找到 {total_actuators} 个执行器:")
        
        for i, actuator in enumerate(actuators):
            name = actuator.get("name", f"actuator_{i}")
            joint_name = actuator.get("joint", "unknown")
            actuator_class = actuator.get("class", "unknown")
            print(f"  {i+1}. {name} -> {joint_name} (class: {actuator_class})")
        
        # 检查传感器数量
        sensors = root.findall(".//sensor")
        total_sensors = len(sensors)
        print(f"\n找到 {total_sensors} 个传感器:")
        
        sensor_types = {}
        for sensor in sensors:
            sensor_type = sensor.tag
            sensor_types[sensor_type] = sensor_types.get(sensor_type, 0) + 1
        
        for sensor_type, count in sensor_types.items():
            print(f"  {sensor_type}: {count}")
        
        # 验证关节和执行器数量
        print(f"\n验证结果:")
        if len(joints) == 12:
            print("✓ 关节数量正确 (12个)")
        else:
            print(f"✗ 关节数量错误 (期望12个，实际{len(joints)}个)")
            
        if total_actuators == 12:
            print("✓ 执行器数量正确 (12个)")
        else:
            print(f"✗ 执行器数量错误 (期望12个，实际{total_actuators}个)")
            
        if total_sensors >= 24:  # 12个位置传感器 + 12个速度传感器
            print("✓ 传感器数量充足")
        else:
            print(f"⚠ 传感器数量可能不足 ({total_sensors}个)")
        
        return True
        
    except Exception as e:
        print(f"验证失败: {e}")
        return False

if __name__ == "__main__":
    xml_file = "go2/go2.xml"
    if validate_mujoco_model(xml_file):
        print("\n模型验证完成")
    else:
        print("\n模型验证失败")
        sys.exit(1)