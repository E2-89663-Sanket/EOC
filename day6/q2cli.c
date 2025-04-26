#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int sockfd;
    struct sockaddr_in addr;
    int num1 = 5, num2 = 7, result;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));

    write(sockfd, &num1, sizeof(int));
    write(sockfd, &num2, sizeof(int));

    read(sockfd, &result, sizeof(int));

    printf("Result: %d\n", result);

    close(sockfd);
    return 0;
}

