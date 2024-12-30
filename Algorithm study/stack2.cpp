#include <stdio.h>

#include <stdlib.h>

#define MAX_STACK_SIZE 5

typedef int element;

element stack[MAX_STACK_SIZE];

int top = -1;



// 공백 상태 검출 함수

int is_empty() {

    return (top == -1);

}

// 포화 상태 검출 함수

int is_full() {

    return (top == MAX_STACK_SIZE - 1);

}

void push(element item) {

    //overflow 발생 검사-스택에 push하지 못하게 함

    if (is_full()) {

        printf("스택이 곽찼음\n");

        return;

    }

    stack[++top] = item;

}

int is_empty() {

    return (top == -1);

}

element pop() {

    int item;

    //underflow 발생 검사-스택값 인출 불가

    if (is_empty()) {

        printf("스택이 비어있음!\n");

        exit(1); //#include <stdlib.h> 필요

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

    printf("%d\n", pop()); //에러발생함

}