#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //iostream�� ����ȭ�� ��Ȱ��ȭ. �⺻�����δ� ����ȭ�Ǿ�����. ������ ���� ����ð��� ���� �� �ִ�.
	cin.tie(0); cout.tie(0);
	int n, k;
	
	cin >> n >> k;
	int sum = 0;
	vector <int> a(n); //n���� ���Ҹ� ���� vector����
	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}
	sort(a.rbegin(), a.rend()); //�������� ����
	for (int i = 0; i < k; i++) {
		
		sum += a[i];
	}
	cout << sum;
}