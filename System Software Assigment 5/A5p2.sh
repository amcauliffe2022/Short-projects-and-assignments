#!/bin/bash
x=$1
count=1
printf "Here is the list beginning with $1:\n"
while [ $x -gt 1 ]
do
	printf "$x,"
	if [ $(($x%2)) -ne 0 ]
	then
    x=$(((3*$x+1)/2))
	else
    x=$(($x/2))
	fi
	((count++))
done
printf "1\nLength of the list: $count"
