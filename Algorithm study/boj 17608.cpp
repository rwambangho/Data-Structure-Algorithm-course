#include<iostream>
#include<stack>

using namespace std;
//높이가 다른 막대기를 세워 왼쪽부터 차례로 번호를 붙임
//오른쪽에서 봤을때 몇개가 보이는지 출력
int main() {
	int n, h;
	int memory = 0;
	stack<int> stack;
	cin >> n; //막대기 개수입력
	
	for (int i = 0; i < n; i++) {
		cin >> h; //막대기 높이 입력
		stack.push(h); 
		
	}
	
	int p = 0; //막대기 개수
	int s = stack.size();
	for (int i = 0; i < s; i++) {
		if (memory < stack.top()) { //top이 왼쪽 막대기보다 크면
			memory = stack.top(); // top을 변수에 저장하고
			p++; //1 증가시킴
		}
		stack.pop(); //맨 오른쪽 막대기는 지워줌 
	}
	
	cout << p; //맨앞의 막대기도 포함시켜서 출력
	
	
	
}