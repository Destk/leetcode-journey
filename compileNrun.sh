#!/bin/bash


if [ $# -eq 0 ]; then
    echo "Ошибка передачи аргументов, попробуйте ещё раз"
    exit 1
fi

filename="$PWD/$1"

if [ ! -f "$filename" ]; then
    echo "Такого файла не существует, попробуйте ещё раз"
    exit 1
fi

if [[ "$filename" != *.cpp ]]; then
    echo "Ошибка, файл должен быть расширением .cpp"
    exit 1
fi

com=$(basename "$filename" .cpp)

g++ -Wall -Wextra -std=c++17 -O2 "$filename" -o "$com"

if [ $? -eq 0 ]; then
    echo "Компиляция успешна"
    "$com"
else
    echo "Ошикбvа компиляции"
    exit 1
fi

