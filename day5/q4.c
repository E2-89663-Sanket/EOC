//Write a program that will launch two programs (e.g. who and wc). The output of ﬁrst program (e.g.
//who) should be given as input to second program .

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() { //main function
	int err, arr[2];
	//1. create pipe
	err = pipe(arr);
	int pid1, pid2;

	if (err < 0){
		perror("pipe command failed: ");
		_exit(10);
	}

	pid1 = fork(); //creating first child
	if (pid1 == 0){ //first child execution content;
		close(arr[0]);
		dup2(arr[1], 1); //set at stdout
		close(arr[1]);
		err = execlp("who", "who", NULL);
		if (err < 0) {
			perror("execlp command failed");
			_exit(10);
		}
		_exit(0);

	}    //first child execution content ends

	pid2 = fork(); //creating second child
	if (pid2 == 0) { //first child execution content

		close(arr[1]);
		dup2(arr[0], 0); //set at stdin
		close(arr[0]);
		err = execlp("wc", "wc", NULL);
		if (err < 0) {
			perror("execlp command faild\n");
			_exit(10);
		}

		_exit(0);

	} //second child execution content ends

	close(arr[1]); //closing write process(parent);
	close(arr[0]); //closing read process(parent);

	int n;
	while(waitpid(-1, &n, 0) != -1);
	return 0;

} //main function ends
