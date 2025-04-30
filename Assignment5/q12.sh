#Write a shell script to accept a filename as argument and displays the last modification
#time if the file exists and a suitable message if it doesn’t exist.

#!/bin/bash




if [ -e $1 -a -f $1 ]
then
	stat $1 | grep "Modify"
else
	echo "$1 does not exit"
fi
