#!/bin/bash
counter=1
n=$1
while [ $counter -le $n ]
do
if(($counter%2!= 0))
	then 
	printf "$counter\n"
	fi
	((counter++))
done

