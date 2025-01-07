#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 10
#define INF 10000

typedef struct GraphType {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphType;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (int i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos; //4
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("\nSTEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf("*");
		else
			printf("%2d ", distance[i]);
	}
}

void shortest_path(GraphType* g, int start) {
	for (int i = 0; i < g->n; i++) {
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
	}
	found[start] = TRUE;
	distance[start] = 0;

	for (int i = 0; i < g->n; i++) {
		print_status(g);
		int u = choose(distance, g->n, found);
		found[u] = TRUE; //4

		for (int w = 0; w < g->n; w++) {
			if (!found[w]) {
				if (distance[u] + g->weight[u][w] < distance[w]) //(4,1)로 가는 distance와 (0,1) 로 가는 distance를 비교
					distance[w] = distance[u] + g->weight[u][w];

			}
		}
	}
}

int main() {
	GraphType g = { 7,
		{{ 0,7,INF,INF,3,10,INF},
		{7,0,4,10,2,6,INF},
		{INF,4,0,2,INF,INF,INF},
		{INF,10,2,0,11,9,4},
		{3,2,INF,11,0,INF,5},
		{10,6,INF,9,INF,0,INF},
		{INF,INF,INF,4,5,INF,0}}


	};
	shortest_path(&g, 0);
	
}