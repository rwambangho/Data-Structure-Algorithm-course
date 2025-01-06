#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES]; // 방문한 정점을 표시하기 위한 배열

// 노드 구조 하나 만들었다.
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

// 그래프 구조 하나 만들었다.
typedef struct GraphType
{
	int n;
	GraphNode* adj_mat[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE; //정점 v의 방문표시
	printf("정점 %d -> ", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) {

		}
	}
}

// 그래프 초기화
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_mat[v] = NULL;
	}
}

// 정점의 갯수 카운팅
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "그래프: 정점의 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node; // 노드 구조체 선언
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode)); // 메모리 할당
	node->vertex = v; // 노드에 정점을 넣는다.
	node->link = g->adj_list[u]; // 노드의 링크에 그래프의 인접리스트를 넣는다.
	g->adj_list[u] = node; // 그래프의 인접리스트에 노드를 넣는다.
}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접리스트", i);
		while (p != NULL)
		{
			printf("-> %d", p->vertex);
			p = p->link;
		}
		printf("\n");
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
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);

	print_adj_list(g); // 인접리스트 출력
	printf("\n깊이 우선 탐색\n");
	dfs_list(g, 0); // 깊이 우선 탐색
	printf("\n");
	free(g); // 메모리 해제
	return 0;
}