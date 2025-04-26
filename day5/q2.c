#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int fd1[2], fd2[2];  
    if (pipe(fd1) == -1 || pipe(fd2) == -1) {
        perror("pipe failed");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0) {  // Child process
        int num1 = 10, num2 = 20;
        write(fd1[1], &num1, sizeof(num1));
        write(fd1[1], &num2, sizeof(num2));
        close(fd1[0]);
        close(fd2[1]); 
        exit(0);
    } else {  // Parent process
        int num1, num2, sum;
        read(fd1[0], &num1, sizeof(num1));
        read(fd1[0], &num2, sizeof(num2));
        close(fd1[0]);
        close(fd1[1]); 
        sum = num1 + num2;
        write(fd2[1], &sum, sizeof(sum));
        close(fd2[1]);
        wait(NULL); 
        read(fd2[0], &sum, sizeof(sum)); 
        printf("The sum is: %d\n", sum);
        close(fd2[0]);
    }

    return 0;
}
