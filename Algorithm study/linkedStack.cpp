#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct StackNode {
	element data;
	struct StackNode* link;
}StackNode;

typedef struct {
	StackNode* top;
}LinkedStackType;

void init(LinkedStackType* s) {
	s->top = NULL;
}

int is_empty(LinkedStackType* s) { //공백상태는 연결 리스트와 마찬가지로 top포인터가 NULL인 경우
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) { //스택이 비어있는지 확인
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else { //top의 값을 top->link로 바꾸고 기존의 top이 가리키는 노드를 동적 메모리 해제한다.
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
element peek(LinkedStackType* s) {
	if (is_empty(s)) { //스택이 비어있는지 확인
		fprintf(stderr, "스택이 비어있음\n");
		exit(1);
	}
	else { 
		return s->top->data;
	}
}



int is_full(LinkedStackType* s) { //포화상태는 동적메모리 할당만 된다면 노드를 생성할 수 있기 때문에 없는거나 마찬가지
	return 0;
}
void print_Stack(LinkedStackType* s) {
	for (StackNode* p = s->top; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("NULL \n");
}





int main() {
	LinkedStackType s;
	
	init(&s);
	
	push(&s, 1);
	print_Stack(&s);
	push(&s, 2);
	print_Stack(&s);
	push(&s, 3);
	print_Stack(&s);
	pop(&s);
	print_Stack(&s);
	pop(&s);
	print_Stack(&s);
	pop(&s);
	print_Stack(&s);
	return 0;
}