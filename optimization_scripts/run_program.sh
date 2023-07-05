#!/bin/bash

input=nb_db.txt
output=/out/output
i=6

while read -r line
do
	len=$(echo "$line" | awk '{print NF}')
	if (( $len > 1 )); then
		for (( j=0; (( j<=12 && j<$i )); j++ ))
		do
			./push_swap $j $line | wc -l > $(output)$i.csv;
			echo ";" > $(output)$i.csv;
		done
		echo -e "\n" > $(output)$i.csv;
	else
		(( i += i/3 ))
	fi
done < "$input"