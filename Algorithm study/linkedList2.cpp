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
ListNode* concat_List(ListNode* head1, ListNode* head2) {
	if (head1 != NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		ListNode* p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}


int main() {
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;

	head1 = insert_first(head1, 30);
	head1 = insert_first(head1, 20);
	head1 = insert_first(head1, 10);

	head2 = insert_first(head2, 60);
	head2 = insert_first(head2, 50);
	head2 = insert_first(head2, 40);

	ListNode* head3 = concat_List(head1, head2); //두 노드를 연결
	print_list(head3);
	return 0;
}