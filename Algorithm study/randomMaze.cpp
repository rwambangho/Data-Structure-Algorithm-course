#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 20
#define MAZE_SIZE 6

typedef struct {
    short r;
    short c;
} element;

typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;

void init_stack(StackType* s) {
    s->top = -1;
}

int is_empty(StackType* s) {
    return (s->top == -1);
}

int is_full(StackType* s) {
    return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
    if (is_full(s)) {
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else {
        s->data[++(s->top)] = item;
    }
}

element pop(StackType* s) {
    if (is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}

char maze[MAZE_SIZE][MAZE_SIZE];
element here, entry;

void push_loc(StackType* s, int r, int c) {
    if (r < 0 || c < 0) return;
    if (maze[r][c] != '1' && maze[r][c] != '.') {
        element tmp;
        tmp.r = r;
        tmp.c = c;
        push(s, tmp);
    }
}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE], int step) {
    printf("\n[%d단계]\n", step);
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            printf("%c ", maze[r][c]);
        }
        printf("\n");
    }
}

void print_path(StackType* s) {
    printf("미로의 이동경로:\n");
    for (int i = 0; i <= s->top; i++) {
        printf("(%d, %d)\n", s->data[i].r, s->data[i].c);
    }
}

void generate_random_maze(char maze[MAZE_SIZE][MAZE_SIZE]) {
    srand(time(NULL));
    for (int r = 0; r < MAZE_SIZE; r++) {
        for (int c = 0; c < MAZE_SIZE; c++) {
            if (r == 0 || r == MAZE_SIZE - 1 || c == 0 || c == MAZE_SIZE - 1) {
                maze[r][c] = '1';
            }
            else {
                maze[r][c] = (rand() % 2) ? '1' : '0';
            }
        }
    }
    // 시작위치 e와 출구 x를 랜덤한 위치에 생성
    do {
        entry.r = rand() % (MAZE_SIZE - 2) + 1;
        entry.c = rand() % (MAZE_SIZE - 2) + 1;
    } while (maze[entry.r][entry.c] == '1');

    do {
        here.r = rand() % (MAZE_SIZE - 2) + 1;
        here.c = rand() % (MAZE_SIZE - 2) + 1;
    } while ((maze[here.r][here.c] == '1') || (here.r == entry.r && here.c == entry.c));

    maze[entry.r][entry.c] = 'e';
    maze[here.r][here.c] = 'x';
}

int main() {
    int r, c;
    StackType s, path_stack;
    int step = 0;

    init_stack(&s);
    init_stack(&path_stack);

    generate_random_maze(maze);

    printf("--- 초기 미로 맵 ---");
    maze_print(maze, step);
    printf("--------------------");

    here = entry;
    push(&path_stack, here);

    while (maze[here.r][here.c] != 'x') {
        r = here.r;
        c = here.c;
        maze[r][c] = '.';
        step++;
        maze_print(maze, step);
        push_loc(&s, r - 1, c);
        push_loc(&s, r + 1, c);
        push_loc(&s, r, c - 1);
        push_loc(&s, r, c + 1);

        if (is_empty(&s)) {
            printf("실패\n");
            return 0;
        }
        else {
            here = pop(&s);
            push(&path_stack, here);
        }
    }
    printf("성공\n");
    print_path(&path_stack);
    return 0;
}
