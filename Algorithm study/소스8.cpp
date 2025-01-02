#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES]; // �湮�� ������ ǥ���ϱ� ���� �迭
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct { // ť Ÿ��
	element  queue[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;


typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;


typedef struct GraphType
{
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // �׷��� ����� �ּҸ� �������Ƿ� ������ �迭����
} GraphType;

// ���� �Լ�
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// ���� ���� ���� �Լ�
void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

// ���� ���� ���� �Լ�
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// ���� �Լ�
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("ť�� ��ȭ�����Դϴ�");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// ���� �Լ�
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("ť�� ��������Դϴ�");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


// �׷��� �ʱ�ȭ
void init(GraphType* g) {

	g->n = 0;

	for (int r = 0; r < MAX_VERTICES; r++)

		for (int c = 0; c < MAX_VERTICES; c++)

			g->adj_mat[r][c] = 0;

}

// ������ ���� ī����
void insert_vertex(GraphType* g, int v) {

	if (((g->n) + 1) > MAX_VERTICES)

		printf("error: ������ �� �ʰ�\n");



	g->n++;

}

void insert_edge(GraphType* g, int start, int end) {

	g->adj_mat[start][end] = 1;

	g->adj_mat[end][start] = 1;

}

void print_adj_mat(GraphType* g) {

	for (int r = 0; r < g->n; r++) {

		for (int c = 0; c < g->n; c++) {

			printf("%2d", g->adj_mat[r][c]);
		}
		printf("\n");

	}
}
void bfs_mat(GraphType* g, int v) {
	int w;
	QueueType q;

	queue_init(&q); //ť �ʱ�ȭ
	visited[v] = TRUE;	//���� v �湮 ǥ��
	printf("%d �湮->", v);
	enqueue(&q, v);	//���� ������ ť�� ����
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d ->�湮", w);
				enqueue(&q, w);
			}
		}
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType)); // �޸� �Ҵ� �޸𸮰����� ���� �ִ�.
	init(g); // �׷��� �ʱ�ȭ
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		insert_vertex(g, i); // ���� ����
	}
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 4);
	insert_edge(g, 1, 5);
	insert_edge(g, 2, 1);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 5);
	insert_edge(g, 3, 5);
	insert_edge(g, 4, 5);
	

	print_adj_mat(g); 
	bfs_mat(g, 0); 
	printf("\n");
	free(g); // �޸� ����
	return 0;
}
