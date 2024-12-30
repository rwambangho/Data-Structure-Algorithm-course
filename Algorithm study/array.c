#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 100

typedef char element; //스택이 구조체로 정의된다
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else {
		return s->data[(s->top)--];
	}
}

int check_matching(const char* in) {
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in); //n= 문자열의 길이
	init_stack(&s); //스택의 초기화

	for (i = 0; i < n; i++) {
		ch = in[i]; //ch=다음문자
		switch (ch) {
		case '(': case '[': case '{':
			push(&s, ch);
			break; //switch넣자마자 쓰기

		case ')': case ']': case'}':
			if (is_empty(&s)) return 0;
			else {
				open_ch = pop(&s);
				if ((open_ch == '(' && ch != ')') || (open_ch == '[' && ch != ']') || (open_ch == '{' && ch != '}')){
					return 0;
				}
				break;
			}
		}
	}
	if (!is_empty(&s)) return 0; //스택에 남아있으면 오류
	return 1;
}

int main() {
	char* p[] = { "{ A[(i+1)]=0; }","{ A[(i+1])=0; }", "{ A[(i+1)]=0; "};
	for (int i = 0; i < sizeof(p) / sizeof(p[0]); i++) {
		if (check_matching(p[i]) == 1)
			printf("%s 괄호검사성공\n", p[i]);
		else
			printf("%s 괄호검사실패\n", p[i]);
	}
	return 0;
}