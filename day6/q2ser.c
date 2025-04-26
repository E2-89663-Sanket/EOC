#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd, client_fd;
    struct sockaddr_in addr;
    int num1, num2, sum;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr*)&addr, sizeof(addr));
    listen(server_fd, 1);

    client_fd = accept(server_fd, NULL, NULL);

    read(client_fd, &num1, sizeof(int));
    read(client_fd, &num2, sizeof(int));

    sum = num1 + num2;

    write(client_fd, &sum, sizeof(int));

    close(client_fd);
    close(server_fd);

    return 0;
}

