#!/bin/bash

if [ -z "$1" ]; then
    echo "Ошибка: укажите имя проекта"
    echo "Использование: $0 <project_name>"
    exit 1
fi

name=$1

if [ -d "$name" ]; then
    echo "Ошибка: папка '$name' уже существует"
    exit 1
fi

mkdir "$name"
cd "$name"

mkdir "src"

cd src

touch "main".cpp
touch "$name".cpp

cd ..

mkdir "include"

cd include

touch "$name".h

cd ..


mkdir build

