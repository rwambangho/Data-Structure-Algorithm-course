#include<stdio.h>

typedef int element;
typedef struct ListNode{
	element data;
	struct ListNode *link; //자기참조구조체
}ListNode;

int main() {
	ListNode a, b;
	ListNode* head = &a;
	a.data = 10;
	b.data = 20;
	a.link = &b;
	b.link = NULL;
	printf("%d\n", a.data);//10
	printf("%d\n", head->data); //10
	printf("%d\n", b.data); //20
	printf("%d\n", head->link->data); //20
}