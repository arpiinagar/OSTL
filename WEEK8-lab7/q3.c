#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
	char* arr;
	int front, rear;
}queue;

void init(queue* q) {
	q->arr = (char*)calloc(MAX, sizeof(char));
	q->front = -1;
	q->rear = -1;
}
void iback(queue* q, char x){
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
	q->arr[q->rear] = x;
	return;
}
char dfront(queue* cq) {
    char element;
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
        return(element);
    }
}
char dback(queue* q) {
	char element;
	if(q->front == -1) {
		printf("Q empty");
		exit(0);
	} else {
		element = q->arr[q->rear];
		if(q->front == q->rear) {
			q->front = 0;
			q->rear = 0;
		} else {
			q->rear = (q->rear - 1);
		}
		return element;
	}
}
int check(char* str) {
	queue s;
	queue* q = &s;
	init(q);
	int len = 0;
	for(int i = 0; str[i] != '\0';i++){
		len++;
		iback(q, str[i]);
	}
	for(int i = 0; i < len/2; i++) {
		char a = dfront(q);
		char b = dback(q);
		if(a != b) {
			return 0;
		}
	}
	return 1;
}
int main() {
	char str[MAX];
	scanf("%s", str);
	if(check(str)) {
		printf("Palindrome!\n");
	} else {
		printf("Not Palindrome!\n");
	}
	return 0;
}