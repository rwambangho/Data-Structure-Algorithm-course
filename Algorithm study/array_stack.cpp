#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element; //element�� ����������
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) { //�ּҷ� �޾�����ϹǷ� ������ �������.
	s->top = -1; //�����ͺ��� s�� �����ؼ� top�� -1�� �����ϱ� ����
}

int is_full(StackType *s) {
	return (s->top == MAX_STACK_SIZE - 1); 
}

void push(StackType *s, element item) { 
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


int main() {
	StackType s; //����ü ����

	init_stack(&s);
	push(&s, 10);//0��
	push(&s, 20);//1��
	push(&s, 30); //2��

	int res = pop(&s); //�ּҸ� ���� ������ ����ü�� �������� �ʴ´�
	printf("pop value: %d\n", res); //top���� 1
	printf("pop value: %d\n", pop(&s)); //top���� 0
}