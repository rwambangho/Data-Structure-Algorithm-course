#include<iostream>
#include<stack>

using namespace std;
//���̰� �ٸ� ����⸦ ���� ���ʺ��� ���ʷ� ��ȣ�� ����
//�����ʿ��� ������ ��� ���̴��� ���
int main() {
	int n, h;
	int memory = 0;
	stack<int> stack;
	cin >> n; //����� �����Է�
	
	for (int i = 0; i < n; i++) {
		cin >> h; //����� ���� �Է�
		stack.push(h); 
		
	}
	
	int p = 0; //����� ����
	int s = stack.size();
	for (int i = 0; i < s; i++) {
		if (memory < stack.top()) { //top�� ���� ����⺸�� ũ��
			memory = stack.top(); // top�� ������ �����ϰ�
			p++; //1 ������Ŵ
		}
		stack.pop(); //�� ������ ������ ������ 
	}
	
	cout << p; //�Ǿ��� ����⵵ ���Խ��Ѽ� ���
	
	
	
}