#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#ifndef F_GETPIPE_SZ
#define F_GETPIPE_SZ 1032  
#endif

int main() {
    int fd[2];
    pipe(fd);
    int size = fcntl(fd[1], F_GETPIPE_SZ);
    printf("Pipe buffer size: %d bytes\n", size);
    return 0;
}

