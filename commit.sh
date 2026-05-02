#!/bin/bash

PROBLEM_NUM=$1

if [ $# -ne 0 ]; then
    git add .
    git commit -m "New solved problems ~ #$PROBLEM_NUM and UPDATE README.md"
    git push
else
    echo "Ошибка ввода номера задачи"
    exit 1

fi
