#include <stdio.h>

// ���� Ž��
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // �߰� �ε��� ��� (�����÷ο� ����)

        if (arr[mid] == target) {
            return mid;  // ��ǥ���� ã��
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // ������ Ž��
        }
        else {
            right = mid - 1; // ���� Ž��
        }
    }
    return -1;  // ��ǥ���� ����
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int result = binarySearch(arr, size, target);
    
    if (result != -1) {
        
        printf("ã������ ��: %d, ���� ��ġ: [%d]\n", target, result);
    }
    else {
        printf("ã������ ��: %d, ���� ã�� �� �����ϴ�.\n", target);
    }

    return 0;
}
