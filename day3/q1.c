#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<string.h>



void sigint_handler(int sig, siginfo_t *si, void *uc)
{
    printf("Signal caught : %d [pid = %d]\n", sig, getpid());
    printf("Sender process ID : %d\n", si->si_pid);
}


int main(void)
{
    int i = 1;
    
    struct sigaction sa, oldsa;

    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_sigaction = sigint_handler;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &sa, &oldsa);

    while(1){
        printf("Running [pid = %d] : i = %d\n", getpid(), i);
        i++;
        sleep(2);
    }

    return 0;
}
