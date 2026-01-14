#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Вы не передали название директории"
    exit 1
fi

DIRNAME="$1"

if [ ! -d "$DIRNAME" ]; then
    echo "Такой директории не существует, попробуйте еще раз"
    exit 1
fi

countcpp=0
counth=0
countl=0

it=$(find "$DIRNAME" \( -name "*.cpp" -o -name "*.h" \))
for file in $it
do
    if [[ "$file" == *.cpp ]];then
         countcpp=$((countcpp+1))
    fi

    if [[ "$file" == *.h ]]; then
         counth=$((counth+1))
    fi
    tmp=$(wc -l "$file" | awk '{print $1}')
    countl=$((countl+tmp))
done

echo "Кол-во файлов .срр - $countcpp"
echo "Кол-во файлов .h - $counth"
echo "Кол-во строк в файлах - $countl"

