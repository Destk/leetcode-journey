#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Ошибка: укажите правильный путь к директории"
    exit 1
fi

if [ ! -d "$1" ]; then
    echo "Ошибка: такой директории не существует"
    exit 1
fi

filepath=$1
count=0
cstr=0

for file in $(find "$filepath" -name "*.cpp"); do
     lin=$(wc -1 < "$file")
     cstr=$((cstr+lin))
     count=$((count+1))
done

echo "Кол-во файлов с расширением *.cpp - $count"
echo "Общее кол-во строк во всех файлах *.cpp - $cstr"

