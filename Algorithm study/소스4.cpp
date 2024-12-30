#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENT 10

typedef struct {
	int key;
}element;
typedef struct { //typedef ����ڰ� ���ϴ� �̸����� �ٲܼ��� �ִ�
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;
HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));

}
void init(HeapType* h) {
	h->heap_size = 0;
} 
void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && item.key > h->heap[i / 2].key) {
		h->heap[i] = h->heap[i / 2];
		i = i / 2;
	}
	h->heap[i] = item;
}
element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--]; //������ ������

	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break;

		h->heap[parent] = h->heap[child]; //temp���� �Ʒ��� ������
		parent = child;
		child = child * 2;
	}
	h->heap[parent] = temp;
	return item;
}
int main() {
	element e1 = { 10 }, e2 = { 5 }, e3 = { 30 };
	element tmp = { 40 };
	element e4;
	HeapType* heap;

	heap = create();//�޸��Ҵ�

	//�ʱ�ȭ
	init(heap);

	//���� ������ �߰�
	insert_max_heap(heap, e1); insert_max_heap(heap, e2);
	insert_max_heap(heap, e3); insert_max_heap(heap, tmp);

	//���� ����, 1�� �ε��� �� ����
	e4 = delete_max_heap(heap);
	printf("%d\n", e4.key);



}
