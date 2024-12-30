#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6

typedef struct {
	short r;
	short c;
}element; //배열의 자료형이 struct

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType* s) {
	s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType* s) {
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입함수
void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}
// 삭제함수
element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
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

element here = { 1,0 }, entry = { 1,0 }; //자신의 위치와 입구위치


void push_loc(StackType* s, int r, int c) { //가능한 경로 저장함수
	if (r < 0 || c < 0) return; //미로를 벗어남
	if (maze[r][c] != '1' && maze[r][c] != '.') { //이미방문한곳(.) or 벽이 아니라면
		element tmp;
		tmp.r = r;
		tmp.c = c;
		push(s, tmp); //스택에 넣는다
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

void print_path(StackType* s) { //미로의 이동경로를 출력한다
	printf("미로의 이동경로:\n");
	for (int i = 0; i <= s->top; i++) {
		printf("(%d, %d)\n", s->data[i].r, s->data[i].c);
	}
}

int main() {
	int r, c;
	StackType s, path_stack;

	init_stack(&s);
	init_stack(&path_stack);
	here = entry; //구조체복사
	push(&path_stack, here); // 시작 위치를 경로 스택에 추가

	while (maze[here.r][here.c] != 'x') { //x에 도착하지 못한경우
		r = here.r; //복사
		c = here.c; //복사
		maze[r][c] = '.'; //지나옴
		maze_print(maze);
		push_loc(&s, r - 1, c); //전
		push_loc(&s, r + 1, c); //후
		push_loc(&s, r, c - 1); //좌
		push_loc(&s, r, c + 1); //우

		if (is_empty(&s)) {
			printf("실패\n"); //가능한 경로를 전부 탐색하고(전후좌우) 스택이 비어 갈데가 없으면 실패
			return 0;
		}
		else
			here = pop(&s); //스택에서 꺼내 이동 및 while조건 검사
			push(&path_stack, here); // 이동한 위치를 경로 스택에 추가
	}
	printf("성공\n");
	print_path(&path_stack); // 경로 출력
	return 0;
}