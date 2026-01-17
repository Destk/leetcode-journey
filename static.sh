#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Ошибка передачи пути"
	exit 1
fi
 
dir=$1

if [ ! -d "$dir" ]; then
	echo "Ошибка: '$dir' не является директорией"
	exit 1
fi

cd "$dir" || exit 1

find . -type f | sed 's/.*\.//' | sort | uniq -c | sort -nr | head -5
