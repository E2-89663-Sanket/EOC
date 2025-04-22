#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    const int num_child = 5; 
    pid_t pids[num_child];    

    for (int i = 0; i < num_child; i++) {
        pid_t pid = fork();
		if (pid < 0) {
            
            perror("failed");
            exit(EXIT_FAILURE);
        } 
		else if (pid == 0) 
		{
            for (int count = 1; count <= 5; count++) 
			{
                printf("Child PID: %d, Count: %d\n", getpid(), count);
                sleep(1); 
            }
            exit(0); 
        }
		else 
		{
            pids[i] = pid; 
        }
    }

    for (int i = 0; i < num_child; i++) 
	{
        waitpid(pids[i], NULL, 0); 
    }

    return 0;
}

