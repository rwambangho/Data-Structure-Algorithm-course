#include <iostream>
#include<vector>
#include<algorithm>
//�����̵� ���������� �̿��� Ǯ��
//k������ ���� left�� right�� ���������� �ִ��� �����ϴ� ���

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //iostream�� ����ȭ�� ��Ȱ��ȭ. �⺻�����δ� ����ȭ�Ǿ�����. ������ ���� ����ð��� ���� �� �ִ�.
	cin.tie(0); cout.tie(0);
	int n, k;
	
	cin >> n >> k;
	int sum = 0;
	vector <int> a(n); //n���� ���Ҹ� ���� vector����
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		
	}
	for (int i = 0; i < k; i++) {
		sum += a[i]; //sum�� �Է��� ���� ����
	}
	int left = 0, right = k - 1; //left�� ���� ��, right�� ������ ��
	int maxi = sum; //�ִ��� ������ ����
	while (true) { 
		sum -= a[left]; //sum���� ���� left�ε����� �迭 ��Ұ��� ����
		left = (left + 1) % n; //left�� ���� �ε����� ������Ʈ
		right = (right + 1) % n; //right�� ���� �ε����� ������Ʈ
		sum += a[right]; //sum�� ���ο� right�ε����� �迭 ��� ���� ���Ѵ�.
		if (left == 0) break; //left�� 0�� �����ϸ� �迭�� ó������ ���ư����̹Ƿ� ������ ������
		maxi = max(maxi, sum); //��������� �κ� �迭�� �� �� �ִ��� ����
	}
	
	cout << maxi;
}