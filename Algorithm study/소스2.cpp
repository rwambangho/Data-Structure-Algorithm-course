#include <stdio.h>
//배열과포인터 파트 공부
//알고리즘 들어가기 전 필요
int arr[] = { 10, 20, 30 };
int main() {
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[1]);
	printf("%p\n", &arr[2]);
	
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);

	int* p = arr; //포인터: 주소를 저장
	printf("%d\n", *p + 0); //해당 주소로가서 데이터를 전달
	printf("%d\n", *p + 1);
	printf("%d\n", *p + 2);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", *(p + i));
	}
}