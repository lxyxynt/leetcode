#!/bin/sh
for file in `ls | tr " " "\?"`
do
	new=`echo $file | tr "_" " "`
	mv "$file" "$new"
done
