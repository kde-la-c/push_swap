#!/bin/bash

input=nb_db.txt
output=output
i=5

while read -r line
do
	len=$(echo "$line" | awk '{print NF}')
	if (( $len > 3 )); then
		for (( j=0; j<=12; j++ ))
		do
			result= ./push_swap $j $line | wc -l >> "out/$i.csv";
			printf $result "," >> "out/$i.csv";
			# echo -n "," >> "out/$i.csv";
		done
		# echo -en "  \n" >> "out/$i.csv";
	else
		(( i += i/3 ));
		echo > "out/$i.csv";
	fi
done < "$input"