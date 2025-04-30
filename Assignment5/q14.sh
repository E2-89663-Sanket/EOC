#Write a shell script to display only executable files of current director

#/bin/bash




ls -l -h -i | grep "rwxrwxrwx"
