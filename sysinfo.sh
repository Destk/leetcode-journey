#!/bin/bash

echo "1) HEADER"
echo " |-> User name: $USER"
echo " |-> User id: $(id -u)"
echo " |-> Home Directory: $HOME"
echo ""

echo "2) SYSTEM"
echo " |-> Hostname: $HOSTNAME"
echo " |-> OS: $(uname -o)"
echo " |-> Kernel Version: $(uname -r)"
echo " |-> Arhitecture: $(uname -m)"
echo ""

echo "3) DATA & TIME"
echo " |-> DATA: $(date +%Y-%m-%d)"
echo " |-> TIME: $(date +%H:%M:%S)"
echo " |-> TIMEZONE: $(date +%z)"
echo ""

echo "4) EXTRA"
echo " |-> Current Directory: $PWD"
echo " |-> Uptime: $(uptime -p)"
