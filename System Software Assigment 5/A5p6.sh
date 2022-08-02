#!/bin/bash
start=$1
end=$2
curr=$start
while [ $curr -le $end ]
do
	./A5p2.sh $curr
	printf "\n"
	((curr++))
done
