#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
	int coef;
	int expon;
	struct ListNode* link;
}ListNode;

typedef struct ListType{
	int size;
	ListNode* head; //시작점
	ListNode* tail; //끝점
}ListType;

ListType* create() {
	ListType* p = (ListType*)malloc(sizeof(ListType)); 
	p->size = 0; //노드가 아무것도 없으니 size의 값은 0
	p->head = NULL;
	p->tail = NULL;
	return p;
}

void insert_Node(ListType* plist, int coef, int expon) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL) { //노드가 첫번째 노드인지 알아야함
		plist->head = plist->tail = temp;
	}
	else {
		plist->tail->link = temp;
		plist->tail = temp;
	}
	plist->size++;
}

void poly_add(ListType* plist1, ListType* plist2, ListType* plist3) {
	ListNode* a = plist1->head;
	ListNode* b = plist2->head;
	int sum; //선언을 for루프 밖에 해주는게 반복적인 메모리할당을 막을 수 있음
	while (a != NULL && b != NULL) {
		if (a->expon == b->expon) {
			sum = a->coef + b->coef;
			insert_Node(plist3, sum, a->expon);
			a = a->link;
			b = b->link;
		}
		else if (a->expon < b->expon) {
			insert_Node(plist3, b->coef, b->expon);
			b = b->link;
		}
		else {
			insert_Node(plist3, a->coef, a->expon);
			a = a->link;
		}
	} //end While
	for (; a != NULL; a = a->link)
		insert_Node(plist3, a->coef, a->expon);
}

void poly_print(ListType* plist) {
	ListNode* p = plist->head;
	printf("polynomial =");
	for (; p; p = p->link){
		printf("%d^%d + ", p->coef, p->expon);
	}
	printf("\n");
}


int main() {
	ListType* list1, * list2, * list3;
	
	list1 = create();
	list2 = create();
	list3 = create();
	
	insert_Node(list1, 3, 12);
	insert_Node(list1, 2, 8);
	insert_Node(list1, 1, 0);

	insert_Node(list2, 8, 12);
	insert_Node(list2, -3, 10);
	insert_Node(list2, 10, 6);

	poly_add(list1, list2, list3);
	
	poly_print(list1);
	poly_print(list2);
	poly_print(list3);
}