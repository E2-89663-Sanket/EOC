//Improve your shell program so that it should not be terminated due to SIGINT (ctrl+C).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

void my_signal_handler(int sig ) {
	return ;

}//my_signal_handler function ends

int main(int n, char *argc[] ) { //main function

	char cmd[512];
	int ret;
	char *exec_cmd[512];
	signal(SIGINT, my_signal_handler);

	while(1) {   //while loop for bash

		int i=0;
		printf("cmd>: ");
		gets(cmd);
		//scanf("%[^\n]s", cmd);
		//scanf("%*c");

		char *ptr;

		ptr = strtok(cmd, " ");
		exec_cmd[i++] = ptr;

		do {
			ptr = strtok(NULL, " ");
			exec_cmd[i++] = ptr;
		} while(ptr!=NULL);


//		if((strlen(cmd) != 0) &&(!strcmp(exec_cmd[0], "exit")))
//			_exit(0);


		ret = fork();
		if(ret == 0) {
			int ret_exec = execvp(exec_cmd[0], exec_cmd);
			if(ret_exec < 0) {
				if(!strcmp(exec_cmd[0], "exit"))
					_exit(10);
				else{
				perror("Execvp failed(): ");
				_exit(1);
				}
			}
		}
		else {
			int sub_wait;
			wait(&sub_wait);
			if(WEXITSTATUS(sub_wait) == 10)
				_exit(0);
		}

	} 

	return 0;
}
