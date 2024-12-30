#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 10

typedef struct GraphType{
	int n; //������ ����
	int adj_mat[MAX_VERTICES][MAX_VERTICES]; //��Ʈ����

}GraphType;

void init(GraphType* g) {
	g->n = 0;
	for (int r = 0; r < MAX_VERTICES; r++) {
		for (int c = 0; c < MAX_VERTICES; c++) {
			g->adj_mat[r][c] = 0; //g�� ����Ű�� ��������� �ε����� 0���� �ʱ�ȭ
		}
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES)
		printf("error: ������ �� �ʰ�\n");
	
	g->n++;
}
void insert_edge(GraphType* g, int start, int end) {
	//if�����ϰ� �ٽ��ڵ常
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

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g); //�ʱ�ȭ
	//������ ǥ��
	for (int i = 0; i < 4; i++) {
		insert_vertex(g, i);
		
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 3);

	print_adj_mat(g);
	}
}