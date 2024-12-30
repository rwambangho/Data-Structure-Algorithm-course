#include <stdio.h>

#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;

element stack[MAX_STACK_SIZE];

int top = -1;



// ���� ���� ���� �Լ�

int is_empty() {

    return (top == -1);

}

// ��ȭ ���� ���� �Լ�

int is_full() {

    return (top == MAX_STACK_SIZE - 1);

}

void push(element item) {

    //overflow �߻� �˻�-���ÿ� push���� ���ϰ� ��

    if (is_full()) {

        printf("������ ��á��\n");

        return;

    }

    stack[++top] = item;

}

int is_empty() {

    return (top == -1);

}

element pop() {

    int item;

    //underflow �߻� �˻�-���ð� ���� �Ұ�

    if (is_empty()) {

        printf("������ �������!\n");

        exit(1); //#include <stdlib.h> �ʿ�

    }

    item = stack[top--];

    return item;

}

int main() {

    push(1);

    push(2);

    push(3);

    element item = pop();

    printf("%d\n", item); //3

    printf("%d\n", pop());//2

    printf("%d\n", pop());

    printf("%d\n", pop()); //�����߻���

}