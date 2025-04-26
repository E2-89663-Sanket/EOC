#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int num1 = 7, num2 = 5; 
    int nums[2] = {num1, num2};

    int fd1 = open("myfifo", O_WRONLY);
    if (fd1 < 0) {
        perror("open fifo1");
        exit(1);
    }

    write(fd1, nums, sizeof(nums));
    close(fd1);

    int fd2 = open("myfifo1", O_RDONLY);
    if (fd2 < 0) {
        perror("open myfifo1");
        exit(1);
    }

    int result;
    read(fd2, &result, sizeof(result));
    close(fd2);

    printf("Sum: %d\n", result);

    return 0;
}

