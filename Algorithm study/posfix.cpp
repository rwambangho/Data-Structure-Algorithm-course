#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 10

typedef int element; //element�� ����������
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) { //�ּҷ� �޾�����ϹǷ� ������ �������.
	s->top = -1; //�����ͺ��� s�� �����ؼ� top�� -1�� �����ϱ� ����
}

int is_full(StackType* s) {
	return (s->top == MAX_STACK_SIZE - 1);
}

void push(StackType* s, element item) {
	if (is_full(s)) { //�� ���ִ��� �׽�Ʈ����
		printf("���� ��ȭ����(overflow error)");
		return;
	}
	else {
		s->data[++(s->top)] = item; //s�� ����Ű�� �迭data�� s�� top�� ���� 1��ŭ ������Ű�� �׸��� �װ��� item�� �����Ѵ�.
	}
}
int is_empty(StackType* s) {
	return (s->top == -1); //s�� ����Ű�� top�� -1�� ������ ����ִ� ���̴�
}
element pop(StackType* s) {
	if (is_empty(s)) {//��� �ִ����� �����Ѵ�
		printf("���� ���� ����(underflow error)");
		exit(1); //�����ؾ��ϴµ� ���� ��ȯ�� �ؾ��� stdlib.h�� ����
	}
	else return s->data[(s->top)--]; //���� top���� �ش��ϴ� data�ε����� ���� �����ϰ� top���� ���߿� ���ҽ�Ų��
	// '--'�� ������ �ڿ� �پ���Ѵ�
}
//peek() : ������ top���� Ȯ�θ��ϴ� �Լ�. --����x. top�� �״�� ������.
element peek(StackType* s) {
	if (is_empty(s)) {//��� �ִ����� �����Ѵ�
		printf("���� ���� ����(underflow error)");
		exit(1); //�����ؾ��ϴµ� ���� ��ȯ�� �ؾ��� stdlib.h�� ����
	}
	else return s->data[(s->top)]; 
}
int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}
void infix_to_postfix(const char exp[]) {
	char ch, top_op;
	int len = strlen(exp);

	StackType s;
	init_stack(&s);
	for (int i = 0; i < len; i++) {
		ch = exp[i];
		switch (ch) {
		case '+': case '-': case '*': case '/':
			//�켱���� �Ǵ��ؼ� push
			while (!is_empty(&s) && prec(ch) <= prec(peek(&s)))
				printf("%c", pop(&s));
			push(&s, ch);
			break;
		case '(': //�켱���� �� ����
			push(&s, ch);
			break;
		case ')':
			top_op = pop(&s);
			while (top_op != '(') { //���ʰ�ȣ���� �˻��ϰ� 
				printf("%c", top_op);
				top_op = pop(&s); 
			}
			break;
		default :
			printf("%c", ch);
			break;
		}
	}//end for
	while (!is_empty(&s))
		printf("%c", pop(&s));
}
int main() {
	const char* s = "(2+3)*4+9";
	infix_to_postfix(s);

}