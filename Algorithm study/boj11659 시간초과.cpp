#include <iostream>
using namespace std; //시간초과코드 

int main() {
	ios_base::sync_with_stdio(false); //iostream의 동기화를 비활성화. 기본적으로는 동기화되어있음. 성능을 높여 실행시간을 줄일 수 있다.
	cin.tie(0); cout.tie(0);
	int n, m;
	int result = 0;

	cin >> n >> m; //수의 개수 N과 합을 구해야 하는 횟수 M

	int* num = new int[n + 1]; //수가 들어갈 배열생성

	for (int a = 1; a <= n; a++) { //수를 입력
		cin >> num[a];
	}

	int i, j;
	for (int b = 0; b < m; b++) {
		cin >> i >> j; //합을 구해야 하는 구간의 수
		for (int c = i; c <= j; c++) {
			result += num[c];

		}
		cout << result << '\n';
		result = 0;
	}

	delete[] num;

	return 0;

}