#include <iostream>
#include <vector>

int main() {
    // 2���� ������ ��Ÿ���� 2���� ���� ����
    int rows = 3;
    int cols = 4;
    std::vector<std::vector<int>> grid(rows, std::vector<int>(cols, 0));

    // 2���� ���Ϳ� �� �Ҵ�
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            grid[i][j] = i * cols + j;
        }
    }

    // 2���� ������ ���� ���
    std::cout << "2���� ������ ����:" << std::endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
