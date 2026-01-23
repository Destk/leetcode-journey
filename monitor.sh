#!/bin/bash

cpu=$(top -bn1 | grep "Cpu(s)" | awk '{print $2}')
ram=$(free -m | grep "Mem" | awk '{print $2}')
ramt=$(free -m | grep "Mem" | awk '{print $3}')
disk=$(df -h / | grep "^/" | tail -1 | awk '{print $2, $3, $4, $5}')
t=$(uptime -p)
p=$(ps aux | wc -l)
echo "=== System Monitor ==="
echo "CPU Usage: $cpu"
echo "RAM Usage: $ram MB / $ramt"
echo "Disk Usage: $disk "
echo "Uptime: $t"
echo "Running Processes: $p"
