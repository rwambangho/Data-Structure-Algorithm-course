#include <iostream>
using namespace std; //�ð��ʰ��ڵ� 

int main() {
	ios_base::sync_with_stdio(false); //iostream�� ����ȭ�� ��Ȱ��ȭ. �⺻�����δ� ����ȭ�Ǿ�����. ������ ���� ����ð��� ���� �� �ִ�.
	cin.tie(0); cout.tie(0);
	int n, m;
	int result = 0;

	cin >> n >> m; //���� ���� N�� ���� ���ؾ� �ϴ� Ƚ�� M

	int* num = new int[n + 1]; //���� �� �迭����

	for (int a = 1; a <= n; a++) { //���� �Է�
		cin >> num[a];
	}

	int i, j;
	for (int b = 0; b < m; b++) {
		cin >> i >> j; //���� ���ؾ� �ϴ� ������ ��
		for (int c = i; c <= j; c++) {
			result += num[c];

		}
		cout << result << '\n';
		result = 0;
	}

	delete[] num;

	return 0;

}