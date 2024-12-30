#include <iostream>
#include<vector>
#include<algorithm>
//슬라이딩 윈도우기법을 이용한 풀이
//k길이의 합을 left와 right를 움직여가며 최댓값을 갱신하는 방법

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); //iostream의 동기화를 비활성화. 기본적으로는 동기화되어있음. 성능을 높여 실행시간을 줄일 수 있다.
	cin.tie(0); cout.tie(0);
	int n, k;
	
	cin >> n >> k;
	int sum = 0;
	vector <int> a(n); //n개의 원소를 넣을 vector생성
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
		
	}
	for (int i = 0; i < k; i++) {
		sum += a[i]; //sum에 입력할 값을 저장
	}
	int left = 0, right = k - 1; //left는 왼쪽 끝, right는 오른쪽 끝
	int maxi = sum; //최댓값을 저장할 변수
	while (true) { 
		sum -= a[left]; //sum에서 현재 left인덱스의 배열 요소값을 뺀다
		left = (left + 1) % n; //left를 다음 인덱스로 업데이트
		right = (right + 1) % n; //right를 다음 인덱스로 업데이트
		sum += a[right]; //sum에 새로운 right인덱스의 배열 요소 값을 더한다.
		if (left == 0) break; //left가 0에 도달하면 배열의 처음으로 돌아간것이므로 루프를 종료함
		maxi = max(maxi, sum); //현재까지의 부분 배열의 합 중 최댓값을 갱신
	}
	
	cout << maxi;
}