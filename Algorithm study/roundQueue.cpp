#include<stdio.h>
#include<stdlib.h> //exit로 빠져나가는거 필요해서
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}
int is_full(QueueType* q) {
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}
void enqueue(QueueType *q, element item) {
	if (is_full(q)) 
		printf("큐가 포화상태");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;

	
}
int is_empty(QueueType* q) {
	return (q->rear == q->front);
}
element dequeue(QueueType* q) {
	if (is_empty(q)) 
		printf("큐가 공백상태");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
	
}

int main() {
	QueueType queue;

	int element;

	init_queue(&queue);

	enqueue(&queue, 10);
	enqueue(&queue, 20);
	enqueue(&queue, 30);

	element = dequeue(&queue);
	printf("%d\n", element);
	element = dequeue(&queue);
	printf("%d\n", element);
}