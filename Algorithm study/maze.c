#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
}element; //�迭�� �ڷ����� struct

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// ���� �ʱ�ȭ �Լ�
void init_stack(StackType* s) {
	s->top = -1;
}

// ���� ���� ���� �Լ�
int is_empty(StackType* s) {
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}



char maze[MAZE_SIZE][MAZE_SIZE] = {
	{'1', '1', '1', '1', '1', '1'},
	{'e', '0', '1', '0', '0', '1'},
	{'1', '0', '0', '0', '1', '1'},
	{'1', '0', '1', '0', '1', '1'},
	{'1', '0', '1', '0', '0', 'x'},
	{'1', '1', '1', '1', '1', '1'}

};

element here = { 1,0 }, entry = { 1,0 }; //�ڽ��� ��ġ�� �Ա���ġ


void push_loc(StackType* s, int r, int c) { //������ ��� �����Լ�
	if (r < 0 || c < 0) return; //�̷θ� ���
	if (maze[r][c] != '1' && maze[r][c] != '.') { //�̹̹湮�Ѱ�(.) or ���� �ƴ϶��
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp); //���ÿ� �ִ´�
	}
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE]) {
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++) {
		for (int c = 0; c < MAZE_SIZE; c++) {
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}
}

void print_path(StackType* s) { //�̷��� �̵���θ� ����Ѵ�
	printf("�̷��� �̵����:\n");
	for (int i = 0; i <= s->top; i++) {
		printf("(%d, %d)\n", s->data[i].r, s->data[i].c);
	}
}

int main() {
	int r, c;
	StackType s, path_stack;

	init_stack(&s);
	init_stack(&path_stack);
	here = entry; //����ü����
	push(&path_stack, here); // ���� ��ġ�� ��� ���ÿ� �߰�

	while (maze[here.r][here.c] != 'x') { //x�� �������� ���Ѱ��
		r = here.r; //����
		c = here.c; //����
		maze[r][c] = '.'; //������
		maze_print(maze);
		push_loc(&s, r - 1, c); //��
		push_loc(&s, r + 1, c); //��
		push_loc(&s, r, c - 1); //��
		push_loc(&s, r, c + 1); //��

		if (is_empty(&s)) {
			printf("����\n"); //������ ��θ� ���� Ž���ϰ�(�����¿�) ������ ��� ������ ������ ����
			return 0;
		}
		else
			here = pop(&s); //���ÿ��� ���� �̵� �� while���� �˻�
			push(&path_stack, here); // �̵��� ��ġ�� ��� ���ÿ� �߰�
	}
	printf("����\n");
	print_path(&path_stack); // ��� ���
	return 0;
}