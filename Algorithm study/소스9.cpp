#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 1000L

typedef struct GraphType{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int selected[MAX_VERTICES];
int distance[MAX_VERTICES];

int get_min_vertex(int n) {
	int v, i;
	for (i = 0; i < n; i++) {
		if (!selected[i]) {
			v = i;
			break;

		}
		for (i = 0; i < n; i++) {
			if (!selected[i] && (distance[i] < distance[v]))
				return v;
		}

	}
}
void prim(GraphType* g, int s) {
	int u;
	for (int u = 0; u < g->n; u++) {
		distance[u] = INF;
	}
	distance[s] = 0;
	for (int i = 0; i < g->n; i++) {
		u = get_min_vertex(g->n);
		selected[u] = TRUE;
		if (distance[u] == INF) return;
		printf("정점%d추가\n", u);

		for (int v = 0; v < g->n; v++) { //이 줄을 잘 해석하면 시험문제를 풀 수 있습니다 그래프가 바뀌었을때 어떤식으로 채워지는지를 이해하기(가장 어려운 문제임)
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					distance[v] = g->weight[u][v];
				}
			}
		}

	}
}
int main() {
	GraphType g = { 7,
		{{0,29,INF,INF,INF,10,INF},
		{29,0,16,INF,INF,INF,15},
		{INF,16,0,12,INF,INF,INF},
		{INF,INF,12,0,22,INF,18},
		{INF,INF,INF,22,0,27,25},
		{10,INF,INF,INF,27,0,INF},
		{INF,15,INF,18,25,INF,0}}
	};
	prim(&g, 0);
	return 0;
}