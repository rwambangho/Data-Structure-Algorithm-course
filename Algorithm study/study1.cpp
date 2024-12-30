#include<iostream>
//요소가 int형이고 행과 열의 길이가 모두 5인 2차원 배열을 선언하고 모든 요소를 0으로 초기화 한 후, 
//‘시계방향 달팽이’ 형식으로 채워서 출력하는 프로그램을 작성하세요.
using namespace std;
//5*5배열을 입력받는다.
int main() {
        int array[5][5];
        int i = 0, j = -1, k = 0, tmp = 1, p=5;
        
        while (true) {
            for (int l = 0; l < p; l ++) {
                k += 1;
                j += tmp;
                array[i][j] = k;

            }
            p = p - 1;
            if (p <= 0) break;
            for (int m = 0; m < p; m++) {
                k += 1;
                i += tmp;
                array[i][j] = k;
            }
            tmp *= -1;
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << array[i][j] << '\t';
            }
            cout << endl;
        }
       
        
    }