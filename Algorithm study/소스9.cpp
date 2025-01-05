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
		printf("����%d�߰�\n", u);

		for (int v = 0; v < g->n; v++) { //�� ���� �� �ؼ��ϸ� ���蹮���� Ǯ �� �ֽ��ϴ� �׷����� �ٲ������ ������� ä���������� �����ϱ�(���� ����� ������)
			if (g->weight[u][v] != INF) {
				if (!selected[v] && g->weight[u][v] < distance[v]) {
					distance[v] = g->weight[u][v];
				}
			}
		}

	}
}
int main() {
	GraphType g;
}