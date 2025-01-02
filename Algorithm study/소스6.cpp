#include<stdio.h>
#include<stdlib.h>//메모리할당
#define MAX_VERTICES 5

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
}GraphType;
void init(GraphType* g) {
	g->n = 0;
	for (int i = 0; i < MAX_VERTICES; i++) {
		g->adj_list[i] = NULL;
	}
}
void insert_vertex(GraphType* g, int v) { //정점을 삽입
	if ((g->n) + 1 > MAX_VERTICES) {
		printf("그래프 정정 개수 초과\n");
		return;
	}
	g->n++;
}
void insert_edge(GraphType* g, int u, int v) {
	//에러처리생략
	GraphNode* node;
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}
void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("->%d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}
void calc_degree(GraphType* g, int* in_degree, int* out_degree) {
	// Initialize degrees
	for (int i = 0; i < g->n; i++) {
		in_degree[i] = 0;
		out_degree[i] = 0;
	}

	// Calculate out-degree and in-degree
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		while (p != NULL) {
			out_degree[i]++;
			in_degree[p->vertex]++;
			p = p->link;
		}
	}
}

int main() {
	GraphType* g; //주소저장
	g = (GraphType*)malloc(sizeof(GraphType));
	
	init(g);
	
	for (int i = 0; i < 5; i++) {
		insert_vertex(g, i);
	}
	insert_edge(g, 0, 4);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 1);
	insert_edge(g, 1, 4);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 0);
	insert_edge(g, 4, 3);
	
	
	

	
	print_adj_list(g);
	int in_degree[MAX_VERTICES] = { 0 };
	int out_degree[MAX_VERTICES] = { 0 };
	calc_degree(g, in_degree, out_degree);

	printf("\n정점\t진입 차수\t진출 차수\n");
	for (int i = 0; i < g->n; i++) {
		printf("%d\t%d\t\t%d\n", i, in_degree[i], out_degree[i]);
	}
	free(g);
	return 0;
}