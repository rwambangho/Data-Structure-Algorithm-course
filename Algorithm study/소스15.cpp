#include <stdio.h>

// 이진 탐색
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // 중간 인덱스 계산 (오버플로우 방지)

        if (arr[mid] == target) {
            return mid;  // 목표값을 찾음
        }
        else if (arr[mid] < target) {
            left = mid + 1;  // 오른쪽 탐색
        }
        else {
            right = mid - 1; // 왼쪽 탐색
        }
    }
    return -1;  // 목표값이 없음
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
        
        printf("찾으려는 수: %d, 수의 위치: [%d]\n", target, result);
    }
    else {
        printf("찾으려는 수: %d, 수를 찾을 수 없습니다.\n", target);
    }

    return 0;
}
