#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 5
#define TRUE 1
#define FALSE 0
int visited[MAX_VERTICES]; // �湮�� ������ ǥ���ϱ� ���� �迭

// ��� ���� �ϳ� �������.
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

// �׷��� ���� �ϳ� �������.
typedef struct GraphType
{
	int n;
	GraphNode* adj_mat[MAX_VERTICES][MAX_VERTICES]; 
} GraphType;

void dfs_mat(GraphType* g, int v) {
	int w;
	visited[v] = TRUE; //���� v�� �湮ǥ��
	printf("���� %d -> ", v);
	for (w = 0; w < g->n; w++) {
		if (g->adj_mat[v][w] && !visited[w]) {

		}
	}
}

// �׷��� �ʱ�ȭ
void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
	{
		g->adj_mat[v] = NULL;
	}
}

// ������ ���� ī����
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "�׷���: ������ ���� �ʰ�\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node; // ��� ����ü ����
	if (u >= g->n || v >= g->n)
	{
		fprintf(stderr, "�׷���: ���� ��ȣ ����\n");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode)); // �޸� �Ҵ�
	node->vertex = v; // ��忡 ������ �ִ´�.
	node->link = g->adj_list[u]; // ����� ��ũ�� �׷����� ��������Ʈ�� �ִ´�.
	g->adj_list[u] = node; // �׷����� ��������Ʈ�� ��带 �ִ´�.
}

void print_adj_list(GraphType* g)
{
	for (int i = 0; i < g->n; i++)
	{
		GraphNode* p = g->adj_list[i];
		printf("���� %d�� ��������Ʈ", i);
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
	g = (GraphType*)malloc(sizeof(GraphType)); // �޸� �Ҵ� �޸𸮰����� ���� �ִ�.
	init(g); // �׷��� �ʱ�ȭ
	for (int i = 0; i < MAX_VERTICES; i++)
	{
		insert_vertex(g, i); // ���� ����
	}
	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);

	print_adj_list(g); // ��������Ʈ ���
	printf("\n���� �켱 Ž��\n");
	dfs_list(g, 0); // ���� �켱 Ž��
	printf("\n");
	free(g); // �޸� ����
	return 0;
}