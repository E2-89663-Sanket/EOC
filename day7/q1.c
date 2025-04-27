#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock;
pthread_cond_t cond;
int turn = 0;

void* parent_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (turn != 0) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("Sunbeam\n");
        fflush(stdout);
        sleep(1); 

        turn = 1;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

void* child_thread(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        while (turn != 1) {
            pthread_cond_wait(&cond, &lock);
        }

        printf("Infotech\n");
        fflush(stdout);
        sleep(1);

        turn = 0;
        pthread_cond_signal(&cond);

        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t parent_tid, child_tid;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&parent_tid, NULL, parent_thread, NULL);
    pthread_create(&child_tid, NULL, child_thread, NULL);

    pthread_join(parent_tid, NULL);
    pthread_join(child_tid, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}

