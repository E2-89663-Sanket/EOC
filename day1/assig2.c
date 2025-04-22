#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(void)
{
    int pid1, pid2, pid3, s1, s2, s3;
    printf("program started\n");
    pid1 = fork();
    if(pid1 == 0){
        pid2 = fork();
        if(pid2 == 0){
            pid3 = fork();
            if(pid3 == 0 ){
                for(int i = 1 ; i <= 3 ; i++){
                    printf("child3 : i = %d\n", i);
                    sleep(1);
                }
            }
            else{
                for(int i = 1 ; i <= 3 ; i++){
                    printf("child2 : i = %d\n", i);
                    sleep(1);
                }
                waitpid(pid3, &s3, 0);
            }
        }
        else{
            for(int i = 1 ; i <= 3 ; i++){
                printf("child1 : i = %d\n", i);
                sleep(1);
            }
            waitpid(pid2, &s2, 0);
        }
    }
    else{
        for(int i = 1 ; i <= 3 ; i++){
            printf("parent : i = %d\n", i);
            sleep(1);
        }
        waitpid(pid1, &s1, 0);
    }
    
    printf("program finished\n");
    return 0;
}





