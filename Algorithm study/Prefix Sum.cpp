#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 2차원 공간을 나타내는 2차원 벡터 생성
    int rows = 3;
    int cols = 4;
    vector<vector<int>> grid(rows, vector<int>(cols, 0));

    // 2차원 벡터에 값 할당
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = i * cols + j;
        }
    }

    // 2차원 벡터의 내용 출력
    cout << "2차원 벡터의 내용:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}