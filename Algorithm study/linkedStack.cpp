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

int is_empty(LinkedStackType* s) { //������´� ���� ����Ʈ�� ���������� top�����Ͱ� NULL�� ���
	return (s->top == NULL);
}

void push(LinkedStackType* s, element item) {
	StackNode* temp = (StackNode*)malloc(sizeof(StackNode));
	temp->data = item;
	temp->link = s->top;
	s->top = temp;
}

element pop(LinkedStackType* s) {
	if (is_empty(s)) { //������ ����ִ��� Ȯ��
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else { //top�� ���� top->link�� �ٲٰ� ������ top�� ����Ű�� ��带 ���� �޸� �����Ѵ�.
		StackNode* temp = s->top;
		int data = temp->data;
		s->top = s->top->link;
		free(temp);
		return data;
	}
}
element peek(LinkedStackType* s) {
	if (is_empty(s)) { //������ ����ִ��� Ȯ��
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else { 
		return s->top->data;
	}
}



int is_full(LinkedStackType* s) { //��ȭ���´� �����޸� �Ҵ縸 �ȴٸ� ��带 ������ �� �ֱ� ������ ���°ų� ��������
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