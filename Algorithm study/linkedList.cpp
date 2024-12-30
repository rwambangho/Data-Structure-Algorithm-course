#include<stdio.h>
#include<stdlib.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link; //�ڱ���������ü
}ListNode;

ListNode* insert_first(ListNode* head, element value) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //�߿��ϹǷ� �� �����ϱ�
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
ListNode* search_List(ListNode* head, element value) { //�̷� �Լ��ۼ��ϴ°� ��������
	ListNode* p = head; //head�� ���� �� �� �ֵ���
	while (p != NULL) {
		if (p->data == value) return p;
		p = p->link;
	}
	return NULL; //��� ����
}


int main() {
	ListNode* head = NULL;

	head = insert_first(head, 10); //��尡 10�� ����Ű�� p�� 10�� ����Ű�� �ִ�
	head = insert_first(head, 20); //p�� 20�� ����Ű��
	head = insert_first(head, 30);
	print_list(head); //30->20->10->NULL
	head = delete_first(head);
	printf("\n");
	print_list(head); //20->10->NULL

	head = insert_first(head, 40);
	head = insert_first(head, 50);
	head = insert_first(head, 60);

	print_list(head); //60->50->40->20->10->NULL

	//Ű����� '�Է�'�޾Ƽ� ó���� �� �� ����
	if (search_List(head, 30) != NULL)
		printf("����Ʈ�� �����ϴ� ��\n");
	else
		//printf("����Ʈ���� ã�� ����\n");
		head = insert_first(head, 30); 
}