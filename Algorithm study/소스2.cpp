#include <stdio.h>
//�迭�������� ��Ʈ ����
//�˰��� ���� �� �ʿ�
int arr[] = { 10, 20, 30 };
int main() {
	printf("%p\n", arr);
	printf("%p\n", &arr[0]);
	printf("%p\n", &arr[1]);
	printf("%p\n", &arr[2]);
	
	printf("%d\n", arr[0]);
	printf("%d\n", arr[1]);
	printf("%d\n", arr[2]);

	int* p = arr; //������: �ּҸ� ����
	printf("%d\n", *p + 0); //�ش� �ּҷΰ��� �����͸� ����
	printf("%d\n", *p + 1);
	printf("%d\n", *p + 2);

	for (int i = 0; i < 3; i++) {
		printf("%d\n", *(p + i));
	}
}