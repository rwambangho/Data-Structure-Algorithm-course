#include <stdio.h>

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

    return (top == (MAX_STACK_SIZE - 1));

}

void push(element item) {

    stack[++top] = item;

}

element pop() {

    int item;

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

}