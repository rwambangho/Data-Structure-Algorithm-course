#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //iostream의 동기화를 비활성화. 기본적으로는 동기화되어있음. 성능을 높여 실행시간을 줄일 수 있다.
	cin.tie(0); cout.tie(0);
	int n, k;
	
	cin >> n >> k;
	int sum = 0;
	vector <int> a(n); //n개의 원소를 넣을 vector생성
	int input = 0;
	for (int i = 0; i < n; i++) {
		cin >> input;
		a.push_back(input);
	}
	sort(a.rbegin(), a.rend()); //내림차순 정렬
	for (int i = 0; i < k; i++) {
		
		sum += a[i];
	}
	cout << sum;
}