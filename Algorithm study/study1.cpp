#include<iostream>
//��Ұ� int���̰� ��� ���� ���̰� ��� 5�� 2���� �迭�� �����ϰ� ��� ��Ҹ� 0���� �ʱ�ȭ �� ��, 
//���ð���� �����̡� �������� ä���� ����ϴ� ���α׷��� �ۼ��ϼ���.
using namespace std;
//5*5�迭�� �Է¹޴´�.
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