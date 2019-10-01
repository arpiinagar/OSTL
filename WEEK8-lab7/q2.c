#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char** arr;
	int front, rear;
}queue;

void init(queue* q) {
	q->arr = (char**)calloc(MAX, sizeof(char*));
	q->front = -1;
	q->rear = -1;
	for(int i = 0; i < MAX; i++) {
		q->arr[i] = (char*)calloc(MAX, sizeof(char));
	}
}
void iback(queue* q, char* x){
	if(q->front == 0 && q->rear == MAX-1 || q->front == (q->rear+1)%MAX) {
		printf("Overflow");
		return;
	}
	if(q->front == -1) {
		q->front = 0;
		q->rear = 0;
	}else if(q->rear == MAX-1){
		q->rear = 0;
	} else {
		q->rear += 1;
	}
	strcpy(q->arr[q->rear], x);
	return;
}

void ifront(queue* q, char* x) {
	if(q->front == 0 && q->rear == MAX-1 || q->front == (q->rear+1)%MAX) {
		printf("Overflow");
		return;
	}
	if(q->front == -1) {
		q->front = 0;
		q->rear = 0;
	}
	for(int j = q->rear + 1; j>q->front; j--){
		q->arr[j] = q->arr[j-1];
	}
	q->rear += 1;
	q->arr[q->front] = x;
	
}

char* dfront(queue* cq) {
    char* element;
    if(cq->front == -1) {
        printf("Queue empty\n");
        exit(0);
    } else {
        element = cq->arr[cq->front];
        if(cq->front == cq->rear) {
            cq->front = 0;
            cq->rear = 0;
        } else {
            cq->front = (cq->front + 1) % MAX;
        }
        //printf("Deleting: %s\n", element);
        return(element);
    }
}
void display(queue* q) {
	if(q->front == -1 && q->rear == -1) {
		printf("Q empty");
		exit(0);
	}
	for(int i = q->front; i <= q->rear; i++){
		printf("%s \n", q->arr[i]);
	}
	printf("\n");
}

int main() {
	queue c;
	queue* q = &c;
	init(q);
	iback(q, "hello");
	iback(q, "my");
	ifront(q, "name");
	display(q);
	dfront(q);
	display(q);
	/*while(1) {
		printf("1)insert front\n");
	printf("2)insert back\n");
	printf("3)delete front\n");
	printf("4)display\n");
	int input;
	scanf("%d", &input);
	switch(input) {
		case 1:
		{
			printf("enter str for front: \n");
			char str1[MAX];
			scanf("%s", str1);
			ifront(q, str1);
			break;
		}
		case 2:
		{
			printf("enter str for back: \n");
			char str2[MAX];
			scanf("%s", str2);
			iback(q, str2);
			break;
		}
		case 3:
		{
			printf("deletint from front: %s\n", dfront(q));
			break;
		}
		case 4:
		{
			display(q);
			break;
		}
	}
	}*/
	return 0;
}