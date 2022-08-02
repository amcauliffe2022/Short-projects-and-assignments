#!/bin/bash

arr=("$@")
for i in "${arr[@]}"
do
    for j in "${arr[@]}"
    do
        for k in "${arr[@]}"
        do
            for l in "${arr[@]}"
            do
                printf "$i $j\n"
                printf "$k $l\n\n"
            done
        done
    done
done