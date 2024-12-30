#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_ELEMENT 10

// 요소 구조체
typedef struct {
    int key;
} element;

// 힙 구조체
typedef struct {
    element heap[MAX_ELEMENT];
    int heap_size;
} HeapType;

// 힙 생성
HeapType* create() {
    return (HeapType*)malloc(sizeof(HeapType));
}

// 힙 초기화
void init(HeapType* h) {
    h->heap_size = 0;
}

// Max Heap 삽입
void insert_max_heap(HeapType* h, element item) {
    int i = ++(h->heap_size);

    while ((i != 1) && item.key > h->heap[i / 2].key) {
        h->heap[i] = h->heap[i / 2];
        i = i / 2;
    }
    h->heap[i] = item;
}

// 배열 출력
void print_heap(HeapType* h) {
    for (int i = 1; i <= h->heap_size; i++) {
        printf("%d ", h->heap[i].key);
    }
    printf("\n");
}

int main() {
    HeapType* heap;
    heap = create();
    init(heap);

    // 난수 생성 및 삽입
    srand(time(NULL));
    printf("Random numbers: ");
    for (int i = 0; i < 8; i++) {
        int rand_num = rand() % 100 + 1;
        printf("%d ", rand_num);

        element item = { rand_num };
        insert_max_heap(heap, item);

        // 현재 배열 출력
        printf("\nHeap after inserting %d: ", rand_num);
        print_heap(heap);
    }

    free(heap);
    return 0;
}
