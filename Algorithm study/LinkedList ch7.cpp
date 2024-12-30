#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
}QueueNode;

typedef struct {
	QueueNode*front;
	QueueNode*rear;
}LinkedQueueType;

void init(LinkedQueueType*q) {
	q->front = q->rear = NULL;
}

int is_empty(LinkedQueueType* q){
	return q->front == NULL;
}

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;

	}
}
void print_queue(LinkedQueueType* q) {
	QueueNode* p = q->front; //front를 초기값으로 잡고
	for (; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL\n");
}
element dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element item;
	if (is_empty(q)) {
		printf("큐가 비어있음");
		exit(1);
	}
	else {
		item = temp->data; //10
		q->front = q->front->link; //temp->link
		if (q->front == NULL) {
			q->rear = NULL;
		}
		free(temp);
		return item;
	}
}

int main() {
	LinkedQueueType queue;
	init(&queue);
	enqueue(&queue, 10);
	enqueue(&queue, 20);
	print_queue(&queue);

	element item = dequeue(&queue);
	printf("삭제값: %d\n", item);
}