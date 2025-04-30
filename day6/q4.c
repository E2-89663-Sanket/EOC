#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

#define SIZE 5
#define SHM_KEY 0x1234

typedef struct queue {
	int arr[SIZE];
	int rear,front,count;

} queue_t;

queue_t *ptr;
int shm_id;

void init_queue(queue_t *q1) { // function to initialize queue
	memset(q1->arr, 0, sizeof(q1->arr));
	q1->rear = -1;
	q1->front = -1;
	q1->count = 0;
} //init_queue function ends 


int is_queue_full(queue_t *q1){
	return q1->count == SIZE;
}

int is_queue_empty(queue_t *q1) {
	return q1->count == 0;
}

void enqueue_data(int data, queue_t *q1) { //function to add data to queue

	if(!is_queue_full(q1)) {
		q1->rear = (q1->rear + 1) % SIZE;
		q1->arr[q1->rear] = data;
		q1->count++;
	}
	
} //enqueue_data function ends


int dequeue_data(queue_t *q1) { //function to pop data from the queue;
		q1->front = (q1->front + 1)%SIZE;
		q1->count--;

	return q1->arr[q1->front];
} //dequeue_data function ends


void sigint_handler(int sig) {
	shmdt(ptr);
	shmctl(shm_id, IPC_RMID, NULL);
	_exit(0);
}

void sigchld_handler(int sig) {
	int n;
	waitpid(-1, &n, 0);
}

int main() {  //main function
		
	struct sigaction sa;
	memset(&sa, 0, sizeof(sigaction));
	sa.sa_handler = sigint_handler;
	sigaction(SIGINT, &sa, NULL);
	sa.sa_handler = sigchld_handler;
	sigaction(SIGCHLD, &sa, NULL);

	//1. Create sharememoryq
	shm_id = shmget(SHM_KEY, sizeof(queue_t), IPC_CREAT | 0600);
	if(shm_id < 0) {
		perror("shmget failed(): ");
		_exit(10);
	}

	ptr = shmat(shm_id, NULL, 0);  
	if(ptr == (void *)-1){
		perror("shmat failed(): ");
		shmctl(shm_id, IPC_RMID, NULL);
		_exit(10);
	}

	init_queue(ptr);
	int pid = fork(); //create child process
	if(pid == 0) {  //child execution content
		while(1) {
			int val = dequeue_data(ptr);
			printf("RD: %d\n", val);
			sleep(1);
	 }

	} //child execution content

	else {  //parent execution content
		while(1) {
			int val = rand() % 100;
			enqueue_data(val, ptr);
			printf("WR: %d\n", val);
			sleep(1);
		}

	} //parent execution content ends

	return 0;
} //main function ends
