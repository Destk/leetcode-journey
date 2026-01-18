#!/bin/bash

echo "Введите имя директории"

if [ $# -eq 0 ]; then
	echo "Вы ничего не передали"
	exit 1
fi

dir=$1

if [ ! -d "$dir" ]; then
	echo "Ошибка в имени, попробуйте еще раз"
	exit 1
fi

count=$(find "$dir" -maxdepth 1 -type f \( -name "a.out" -o -name "*.out" \) -executable)
prefix="o."
for file in $count
do
save=$(basename "$file" .out)     # main (без .out)
prefixed_name="${prefix}${save}"  # o.main
new_full_path="$dir/${prefixed_name}.out"  # src/o.main.out
mv "$file" "$new_full_path"

done

echo "Файлы были переименованы"


