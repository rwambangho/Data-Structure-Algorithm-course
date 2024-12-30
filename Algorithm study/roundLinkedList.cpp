#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* insert_first(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
	}
	return head; //변경된 헤드 포인터를 반환한다
}

ListNode* insert_last(ListNode* head, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;
		head = node;
	}
	return head;
}
void print_list(ListNode* head) {
	ListNode* p;
	if (head == NULL) return; //리스트가 존재하지 않는 것이므로 종료
	p = head->link; //첫번째 노드
	do { //p가 head에 올때까지 반복
		printf("%d->", p->data);
		p = p->link;
	} while (p != head);
	printf("%d->", p->data); //마지막 노드 출력
}



int main() {
	ListNode* head = NULL;
	head = insert_last(head, 20); //insert_last가 반환한 헤드 포인터를 head에 대입함
	head = insert_last(head, 30);
	head = insert_last(head, 40);
	head = insert_first(head, 10); //first에선 head의 위치를 node로 바꾸지 않음
	print_list(head);
	return 0;
}