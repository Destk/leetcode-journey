#!/bin/bash


if [ $# -eq 0 ]; then
    echo "Ошибка передачи аргументов, попробуйте ещё раз"
    exit 1
fi

filename=$1

if [ ! -f "$filename" ]; then
    echo "Такого файла не существует, попробуйте ещё раз"
    exit 1
fi

if [[ "$filename" != *.cpp ]]; then
    echo "Ошибка, файл должен быть расширением .cpp"
    exit 1
fi

com="${filename%%[A-Za-z]*}"

g++ -Wall -Wextra -std=c++17 -O2 "$filename" -o "$com"

if [ $? -eq 0 ]; then
    echo "Компиляция успешна"
    ./$com
else
    echo "Ошикба компиляции"
    exit 1
fi

