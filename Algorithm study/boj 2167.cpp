#include<iostream>


using namespace std;
//2���� �迭�� �־����� �� (i, j) ��ġ���� (x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
//�迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.
int main() {
	int n, m;
	
	cin >> n >> m; //�迭�� ũ�� �Է�
	int** v = new int *[n]; //2���� �迭 �����Ҵ�
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
	cin >> k;//���� ���� �κ��� ����
	for (int a = 0; a < k; a++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y; 
		cout << v[x][y] - v[i - 1][y] - v[x][j - 1] + v[i - 1][j - 1]<<'\n';
	}
	return 0;
}