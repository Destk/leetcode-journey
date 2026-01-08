#!/bin/bash

NAMEDIR=$1
count=0
if [ -d "$NAMEDIR" ]; then
    for file in $NAMEDIR/*; do
        if [ ! -f "$file" ]; then
            continue 
        fi
        if [[ "$file" == *.cpp ]]; then
            continue
        fi
        fn=$(basename "$file")
        nw="build_$fn"
        mv "$file" "$NAMEDIR/$nw"
        echo "Файл $fn был переименован в -> $nw"
        count=$((count+1)) 
    done
else
    echo "Ошибка!, не правильный ввод или папки не существует"
    exit 1
fi
echo "Всего было переименовано: $count файлов"
