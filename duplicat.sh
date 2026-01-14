#!/bin/bash

if [ $# -eq 0 ];then 
   echo "Вы не передали путь"
   exit 1
fi

filepath=$1

declare -a array

for file in $(find "$filepath" -type f)
do
    sizef=$(ls -l "$file" | awk '{print $5}')
    array+=("$sizef $file")
done

for i in "${array[@]}"
do
   size="${i%% *}"
   count=$(printf '%s\n' "${array[@]}" | grep "^$size " | wc -l )
   if [[ "$count" -ge 2 ]]; then
       echo "Размер $size встречается $count раз"
       echo "$(printf '%s\n' "${array[@]}" | grep "^$size ")"
   fi
done
