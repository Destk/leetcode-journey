#!/bin/bash

if [ $# -eq 0 ]; then
	echo "Ошибка передачи Директории!"
	exit 1
fi

dirname=$1

cd "$dirname" && git log --oneline --since="1h ago" | wc -l
cd "$dirname" && git diff --stat HEAD~1
cd "$dirname" && git log -1 --pretty=format:"%s"
