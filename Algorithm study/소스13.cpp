#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_SIZE 9
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE] = { 5,3,8,4,9,1,6,2,7 };
int n;

void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d", list[i]);
	}
	printf("%\n");
}
int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;
	low = left;
	high = right + 1;
	pivot = list[left];

	do {
		do {
			low++;
		} while (list[low] < pivot);
		do {
			high--;
		} while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);

	SWAP(list[left], list[high], temp);
	//print_sort(list, n);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, 0, q - 1);
		quick_sort(list, q + 1, right);
	}

}
int main() {
	n = MAX_SIZE;
	print_sort(list, n);
	quick_sort(list, 0, n - 1);
	print_sort(list, n);

}