#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES]; // 방문한 정점을 표시하기 위한 배열
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct { // 큐 타입
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
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; // 그래프 노드의 주소를 가져오므로 포인터 배열만듬
} GraphType;

// 오류 함수
void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

// 공백 상태 검출 함수
void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

// 공백 상태 검출 함수
int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}


// 그래프 초기화
void init(GraphType* g) {

	g->n = 0;

	for (int r = 0; r < MAX_VERTICES; r++)

		for (int c = 0; c < MAX_VERTICES; c++)

			g->adj_mat[r][c] = 0;

}

// 정점의 갯수 카운팅
void insert_vertex(GraphType* g, int v) {

	if (((g->n) + 1) > MAX_VERTICES)

		printf("error: 정점의 수 초과\n");



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

	queue_init(&q); //큐 초기화
	visited[v] = TRUE;	//정점 v 방문 표시
	printf("%d 방문->", v);
	enqueue(&q, v);	//시작 정점을 큐에 저장
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = 0; w < g->n; w++) {
			if (g->adj_mat[v][w] && !visited[w]) {
				visited[w] = TRUE;
				printf("%d ->방문", w);
				enqueue(&q, w);
			}
		}
	}
}

int main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType)); // 메모리 할당 메모리공간에 힙이 있다.
	init(g); // 그래프 초기화
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		insert_vertex(g, i); // 정점 삽입
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
	free(g); // 메모리 해제
	return 0;
}
