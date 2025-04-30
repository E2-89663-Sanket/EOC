#Accept the two file names from user and append the contents in reverse case of first file
#into second file.
#!/bin/bash





echo -n " Enter the first file name: "
read f1

echo -n " Enter the second file name: "
read f2

if [ -e $f1 ]
then
	if [ -f $f1 ]
	then
		cat $f1 | tac | cat >> $f2
		echo " Data added Successfully "
	else
		echo " $f1 is not the regular file "
	fi
else
	echo " $f1 does not exit "
fi
