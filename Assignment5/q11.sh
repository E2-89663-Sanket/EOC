#!/bin/bash
echo "enter the basic salary:"
read b
g=$( echo "$b+((40/100)*$b)+((20/100)*$b)" | bc -l)
echo "The gross salary : $g"
