#Write a shell script to display only hidden file of current directory.

#!/bin/bash





ls -a | egrep "^\."
