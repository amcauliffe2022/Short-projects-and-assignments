#!/bin/bash
for((i=0;i<=1;i++));
do
    for((j=0;j<=1;j++));
do
        for((k=0;k<=1;k++));
do
            for((l=0;l<=1;l++));
do
               printf "${i} ${j}\n"
               printf "${k} ${l}\n\n"
            done
        done
    done
done
