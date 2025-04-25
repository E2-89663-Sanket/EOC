#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <unistd.h>

struct msg { long type; int a, b, sum; };

int main() {
    int qid = msgget(1234, 0666 | IPC_CREAT);
    struct msg m;
    if (fork() == 0) {
        m.type = 1; m.a = 50; m.b = 20;
        msgsnd(qid, &m, sizeof(m) - sizeof(long), 0);
        msgrcv(qid, &m, sizeof(m) - sizeof(long), 2, 0);
        printf("Sum = %d\n", m.sum);
    } else {
        msgrcv(qid, &m, sizeof(m) - sizeof(long), 1, 0);
        m.sum = m.a + m.b; m.type = 2;
        msgsnd(qid, &m, sizeof(m) - sizeof(long), 0);
        wait(NULL);
        msgctl(qid, IPC_RMID, NULL);
    }
    return 0;
}

