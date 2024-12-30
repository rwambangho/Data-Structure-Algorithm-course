#include<iostream>
#include<queue>
#include<string>
#define endl '\n'

using namespace std;

int main() {
	queue<int> q;
	int n;
	int x;
	int result = 0;
	string order;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> order;
		
		if (order == "push") { //push X : ���� X�� ť�� �ִ� �����̴�.
			cin >> x;
			q.push(x); //������ �߰�

		}
		else if (order == "pop") { //pop : ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
			if (q.empty()==true) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = q.front();
				cout << result << endl;//�ֻ��� �����͹�ȯ
				q.pop(); //front������ ����
			}
		}
		else if (order == "size") { //size: ť�� ����ִ� ������ ������ ����Ѵ�.
			cout << q.size() << endl; //ť�� ������ ��ȯ

		}
		else if (order == "empty") { //empty : ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
			if (q.empty()==true) {
				cout << true << endl;
			}
			else
				cout << false << endl;

		}
		else if (order == "front") { //front : ť�� ���� �տ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
			
			if (q.empty()==true) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = q.front();
				cout << result << endl;
			}
		}
		else if (order == "back") { //back : ť�� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ť�� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
			
			if (q.empty()==true) {
				result = -1;
				cout << result << endl;
			}
			else {
				result = q.back();
				cout << result << endl; //���� ������ �����͹�ȯ
			}
		}
	}
	return 0;
}