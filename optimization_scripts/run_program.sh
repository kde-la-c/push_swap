#!/bin/bash

input=nb_db.txt
output=output
i=5

while read -r line
do
	len=$(echo "$line" | awk '{print NF}')
	if (( $len > 3 )); then
		result=""
		for (( j=0; j<=100; j++ ))
		do
			count=$(./push_swap $j $line | wc -l)
			result+=",$count"
			# echo -n "," >> "out/$i.csv";
		done
		printf "%s\n" "${result:1}" >> "out/$i.csv"
		# echo -en "  \n" >> "out/$i.csv";
	else
		(( i += i/3 ));
		echo > "out/$i.csv";
		result=""
		for (( j=0; j<=100; j++ ))
		do
			result+=",$j"
			# echo -n "," >> "out/$i.csv";
		done
		printf "%s\n" "${result:1}" >> "out/$i.csv"
	fi
done < "$input"
