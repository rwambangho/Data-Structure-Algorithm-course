#include<iostream>
#include<queue>
using namespace std;


//�迭�� �ڿ��� x�� �ִ´�.
//�迭���� ���� ���� ���� ����ϰ�, �� ���� �迭���� �����Ѵ�.
//���α׷��� ó���� ����ִ� �迭���� �����ϰ� �ȴ�.
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, x;
	cin >> n;//������ ����
	priority_queue <int, vector <int>, greater <int>> q;

	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x != 0)
			q.push(x); //0�� �ƴϸ� �ڿ����� �ִ´�
		else {
			if (q.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << q.top() << '\n'; //��Ʈ���
				q.pop();//��Ʈ����
			}
		}
	}
	return 0;
}