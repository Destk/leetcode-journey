#!/bin/bash
cd ~/Рабочий\ стол/leetcode-journey || exit 1
for name in Scanner_Ports tcp_chat tg_bot task_manager Filemonitor passcheck htppclient timer game; do
    if [ -d "$name" ]; then
        mv "$name" ~/Рабочий\ стол/projects/
        echo "Moved: $name"
    else
        echo "Not found: $name"
    fi
done
