#!/bin/bash

echo "enter the name"
read name

if [ -e $name ]
then
	if [ -f $name ]
	then
		echo "$name  size : `stat -c %s $name`"
	elif [ -d $name ]
	then
		ls $name
	fi
else
	echo "invalid "
fi


