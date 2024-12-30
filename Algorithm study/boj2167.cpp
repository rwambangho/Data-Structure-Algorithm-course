#include<iostream>

using namespace std;
//2���� �迭�� �־����� �� (i, j) ��ġ���� (x, y) ��ġ������ ����Ǿ� �ִ� ������ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
//�迭�� (i, j) ��ġ�� i�� j���� ��Ÿ����.
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;

	cin >> n >> m; //�迭�� ũ�� �Է�
	long long v[300][300];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> v[i][j];
			v[i][j] += v[i][j - 1] + v[i - 1][j] - v[i - 1][j - 1];
		}
	}
	int k;
	cin >> k;//���� ���� �κ��� ����
	for (int a = 0; a < k; a++) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		int result = v[x][y] - v[i - 1][y] - v[x][j - 1] + v[i - 1][j - 1];
		cout << result << '\n';
	}
	return 0;
}