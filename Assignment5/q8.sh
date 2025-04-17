#!/bin/bash

echo -n "enter a number: "
read num

echo "multiplication table for $num: "
for((i=1; i<=10; i++));  do
     echo "$num x $i = $((num*i))"
done
