#include<stdio.h>
//����ü-���� �ڷ���, ���� �ٸ� �ڷ����� ���� �������� �޸� ����.
//����ü=��������� �ڷ���
//���� -> ����(�޸𸮿�û)
struct Sample
{
	int x;
	double d;
};
int main() {
	//����
	//int i;
	//����� ���ÿ� �ʱ�ȭ
	int i = 10;
	
	//����
	struct Sample test;
	test.x = 20;
	test.d = 3.14;

	//����� ���ÿ� �ʱ�ȭ
	//struct Sample test = { 20, 3.14 };

	printf("%d\n", test.x);
	printf("%f\n", test.d);

	//����ü�� ������
	// �����ʹ� �ּ����� 
	//�޸� �ʿ��ϴ�? ����
	//������ ������ ����
	struct Sample* ptr;
	ptr = &test;
	printf("%d\n", ptr->x);
	printf("%f\n", ptr->d);

	//����ü�� ũ��
	printf("%d\n", sizeof(int));
	printf("%d\n", sizeof(i));

	printf("%d", sizeof(test));
	
}