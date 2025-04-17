#!/bin/bash



echo -n "Enter num : "
read num

if 1
then
	echo "Num is Even: $num"
else
	echo "Num is ODD : $num"

fi






echo -n "Enter the year : "
read  y

if [ `expr $y % 4` -eq 0 -a $(($y%100)) -ne 0 -o `expr $y % 400` -eq 0 ]
then
	echo "Year is leap year : $y"
else
	echo "Year not leap year : $y"
fi

