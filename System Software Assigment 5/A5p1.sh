#!/bin/bash
exe=0
nexe=0
nsd=0
for i in *
do
   if [ -f $i ]
   then
	if [ -x $i]
	then
	nexe = $((nexe+1))
       	else
	exe=$((exe+1))
	fi
   fi
   if [ -d $i ]
   then
       nsd=$((nsd + 1))
   fi      
done
echo "total number of executable files in $1: $exe"
echo "total number of non-executable files in $1: $nexe"
echo "total number of subdirectories in $1 : $nsd"
