#include<stdio.h>
//구조체-같은 자료형, 서로 다른 자료형에 대한 연속적인 메모리 공간.
//구조체=사용자정의 자료형
//정의 -> 선언문(메모리요청)
struct Sample
{
	int x;
	double d;
};
int main() {
	//선언문
	//int i;
	//선언과 동시에 초기화
	int i = 10;
	
	//선언문
	struct Sample test;
	test.x = 20;
	test.d = 3.14;

	//선언과 동시에 초기화
	//struct Sample test = { 20, 3.14 };

	printf("%d\n", test.x);
	printf("%f\n", test.d);

	//구조체와 포인터
	// 포인터는 주소저장 
	//메모리 필요하다? 선언
	//포인터 변수의 선언
	struct Sample* ptr;
	ptr = &test;
	printf("%d\n", ptr->x);
	printf("%f\n", ptr->d);

	//구조체의 크기
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(i));

	printf("%d", sizeof(test));
	
}