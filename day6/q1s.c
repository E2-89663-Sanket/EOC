
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
	

    printf("pid = %d\n", getpid());
    printf("ppid = %d\n", getppid());


	int num1, num2, sum;
    int fd1 = open("myfifo", O_RDONLY);
    read(fd1, &num1, sizeof(int));
    read(fd1, &num2, sizeof(int));
    close(fd1);

    sum = num1 + num2;

    int fd2 = open("myfifo1", O_WRONLY);
   write(fd2, &sum, sizeof(int));
    close(fd2);

    return 0;
}

