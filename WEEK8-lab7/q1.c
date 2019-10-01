#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	int arr[MAX];
	int front;
	int rear;
}pqueue;

void init(pqueue* pq){
	pq->front = -1;
	pq->rear = -1;
}

void enqueue(pqueue* pq, int x){
	//printf("%d %d\n", pq->rear, pq->front);
	if(pq->rear >= MAX-1) {
		printf("Queue full\n");
	} else if(pq->front == -1 && pq->rear == -1) {
		pq->front += 1;
		pq->rear += 1;
		pq->arr[pq->rear] = x;
		//printf("hello");
		return;
	}else {
		int i,j;
		for(i = 0; i <= pq->rear; i++) {
			if(x <= pq->arr[i]) {
				for(j = pq->rear + 1; j>i; j--){
					pq->arr[j] = pq->arr[j-1];
				}
				pq->arr[i] = x;
				pq->rear += 1;
				return;
			}
		}
		pq->arr[i] = x;
	}
	pq->rear+=1;
}

int dequeue(pqueue* pq) {
	if(pq->front == pq->rear) {
        printf("Queue empty \n");
        exit(0);
    }
    int temp = pq->front;
    pq->front += 1;
    return pq->arr[temp];
}

void display(pqueue* pq) {
	if(pq->front == -1 && pq->rear == -1) {
		printf("Q empty");
		exit(0);
	}
	for(int i = pq->front; i <= pq->rear; i++){
		printf("%d \t", pq->arr[i]);
	}
	printf("\n");
}

int main() {
	pqueue q;
	pqueue* pq = &q;
	init(pq);
	enqueue(pq, 4);
	enqueue(pq, 3);
	enqueue(pq, 5);
	display(pq);
	dequeue(pq);
	display(pq);
}