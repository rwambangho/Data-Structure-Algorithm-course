#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link; //자기참조구조체
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //중요하므로 꼭 이해하기
	p->data = value;
	p->link = head;
	head = p;
	return head;
}
void print_list(ListNode* head) {
	for (ListNode* p = head; p != NULL; p = p->link) 
		printf("%d->", p->data);
	printf("NULL \n");
	
}
ListNode* delete_first(ListNode* head) {
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;
	head = removed->link;
	free(removed);
	return head;
}
ListNode* search_List(ListNode* head, element value) { //이런 함수작성하는거 시험출제
	ListNode* p = head; //head가 일을 할 수 있도록
	while (p != NULL) {
		if (p->data == value) return p;
		p = p->link;
	}
	return NULL; //노드 없음
}


int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10); //헤드가 10을 가리키고 p가 10을 가리키고 있다
	head = insert_first(head, 20); //p가 20을 가리키고
	head = insert_first(head, 30);
	print_list(head); //30->20->10->NULL
	head = delete_first(head);
	printf("\n");
	print_list(head); //20->10->NULL

	head = insert_first(head, 40);
	head = insert_first(head, 50);
	head = insert_first(head, 60);

	print_list(head); //60->50->40->20->10->NULL

	//키보드로 '입력'받아서 처리할 수 도 있음
	if (search_List(head, 30) != NULL)
		printf("리스트에 존재하는 값\n");
	else
		//printf("리스트에서 찾지 못함\n");
		head = insert_first(head, 30); 
}