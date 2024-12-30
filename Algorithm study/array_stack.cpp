#include<stdio.h>
#include<stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element; //element는 별명같은거임
typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) { //주소로 받아줘야하므로 포인터 변수사용.
	s->top = -1; //포인터변수 s로 접근해서 top에 -1로 저장하기 위해
}

int is_full(StackType *s) {
	return (s->top == MAX_STACK_SIZE - 1); 
}

void push(StackType *s, element item) { 
	if (is_full(s)) { //꽉 차있는지 테스트하자
		printf("스택 포화에러(overflow error)");
		return;
	}
	else { 
		s->data[++(s->top)] = item; //s가 가리키는 배열data에 s의 top을 먼저 1만큼 증가시키고 그리고 그곳에 item을 저장한다.
	}
}
int is_empty(StackType* s) {
	return (s->top == -1); //s가 가리키는 top이 -1과 같으면 비어있는 것이다
}
element pop(StackType* s) {
	if (is_empty(s)) {//비어 있는지를 조사한다
		printf("스택 공백 에러(underflow error)");
		exit(1); //종료해야하는데 뭐라도 반환을 해야함 stdlib.h에 있음
	}
	else return s->data[(s->top)--]; //현재 top값에 해당하는 data인덱스의 값을 리턴하고 top값을 나중에 감소시킨다
	// '--'가 무적권 뒤에 붙어야한다
 }
//peek() : 스택의 top값을 확인만하는 함수. --수행x. top은 그대로 유지함.


int main() {
	StackType s; //구조체 변수

	init_stack(&s);
	push(&s, 10);//0번
	push(&s, 20);//1번
	push(&s, 30); //2번

	int res = pop(&s); //주소를 쓰지 않으면 구조체가 공유되지 않는다
	printf("pop value: %d\n", res); //top값은 1
	printf("pop value: %d\n", pop(&s)); //top값은 0
}