#!/bin/bash
echo "Enter three numbers:"
read num1
read num2
read num3

greatest=$num1

if [ $num2 -gt $greatest ]; then
    greatest=$num2
fi

if [ $num3 -gt $greatest ]; then
    greatest=$num3
fi
echo "The greatest number among $num1, $num2, and $num3 is: $greatest"

