#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    int count = 0;

    signal(SIGINT, SIG_IGN);

    while (1) {
        pid = fork();

        if (pid < 0) {
            perror("failed");
            break;
        } else if (pid == 0) {
            exit(0);
        } else {
            count++;
            printf("Creat child process with PID %d (Total: %d)\n", pid, count);
        }

        sleep(1); 
    }

    while (wait(NULL) > 0);

    printf("total number of child process creat: %d\n", count);
    return 0;
}

