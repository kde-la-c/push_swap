#!/bin/bash

file=nb_db

echo > $file

for (( i=6; i<800; i+=(i/3) ))
do
	for (( j=0; j<10; j++ ))
	do
		echo $(shuf -i 1-800 -n $i) >> "$file";
	done
	echo "" >> "$file";
done
