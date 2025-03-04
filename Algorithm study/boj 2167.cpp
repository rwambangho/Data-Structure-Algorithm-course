#include<iostream>


using namespace std;
//2차원 배열이 주어졌을 때 (i, j) 위치부터 (x, y) 위치까지에 저장되어 있는 수들의 합을 구하는 프로그램을 작성하시오. 
//배열의 (i, j) 위치는 i행 j열을 나타낸다.
int main() {
	int n, m;
	
	cin >> n >> m; //배열의 크기 입력
	int** v = new int *[n]; //2차원 배열 동적할당
	for (int i = 0; i < n; i++) {
		v[i] = new int[m];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
			v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i-1][j - 1];
		}
	}
	int k;
	cin >> k;//합을 구할 부분의 개수
	for (int a = 0; a < k; a++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y; 
		cout << v[x][y] - v[i - 1][y] - v[x][j - 1] + v[i - 1][j - 1]<<'\n';
	}
	return 0;
}