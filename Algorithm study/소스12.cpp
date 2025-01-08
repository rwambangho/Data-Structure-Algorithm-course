#include<stdio.h>
#define MAX_SIZE 6
#define SWAP(x,y,t) ((t) = (x) , (x) = (y) , (y) = (t))
int list[MAX_SIZE] = { 5,3,8,1,2,7 };

void insertion_sort(int list[], int n) {
	int i, j, key;
	for (i = 1; i < n; i++) {
		key = list[i];
			for (j = 1; j >= 0 && list[j] > key; j++) {
				list[j + 1] = list[j];
			}
			list[j + 1] = key;

	}
	


}
void print_sort(int list[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%2d", list[i]);
	}
	printf("\n");
}

void selection(int list[], int n) {
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) {
			if (list[j] < list[least]) least = j;
		}
	print_sort(list, n);
	SWAP(list[i], list[least], temp);
	
	}
	
}



int main() {
	int n = MAX_SIZE;
	selection(list, MAX_SIZE);
	print_sort(list, n);
	
}