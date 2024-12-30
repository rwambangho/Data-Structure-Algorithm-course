#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //iostream�� ����ȭ�� ��Ȱ��ȭ. ������ ���� ����ð��� ���� �� �ִ�.
	cin.tie(0); cout.tie(0); //������� �����ش�.
	int n, m; 
	
	cin >> n >> m; //���� ���� N�� ���� ���ؾ� �ϴ� Ƚ�� M

	int* num = new int[n + 1]; //���� �� �迭����
	
	int temp;
	for (int a = 1; a <= n; a++) { //���� �Է�
		cin >> temp;
		num[a] = num[a - 1] + temp;
	}
	
	int i, j; 
	for (int b = 0; b < m; b++) {
		cin >> i >> j; //���� ���ؾ� �ϴ� ������ ��
		int result = num[j] - num[i - 1];
		cout << result <<'\n';
	}
	delete[] num;
	return 0;
}