#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 2���� ������ ��Ÿ���� 2���� ���� ����
    int rows = 3;
    int cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    // 2���� ���Ϳ� �� �Ҵ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = i * cols + j;
        }
    }

    // 2���� ������ ���� ���
    cout << "2���� ������ ����:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}