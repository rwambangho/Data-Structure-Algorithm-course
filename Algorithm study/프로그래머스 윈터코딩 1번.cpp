#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;

    // ���� ������ ���� ���ڿ� ��Ʈ��
    stringstream ss(s);
    string token;

    vector<int> arr;  // ������ ������ �迭
    vector<vector<int>> passwords;  // 2���� ����

    // '#'�� �����ڷ� ����Ͽ� ���ڿ� �Ľ�
    while (getline(ss, token, '#')) {
        if (!token.empty()) {
            int num = stoi(token);
            arr.push_back(num);
        }
    }

    // passwords 2���� ���� �ʱ�ȭ
    // ���� ���, passwords[0][0]�� passwords[0][1]�� arr[0]�� arr[1]�� ���ٰ� ����
    passwords.push_back({ arr[0], arr[1] });
    // passwords[1][0]�� passwords[1][1]�� arr[2]�� arr[3] ��

    int answer = 0;

    // passwords�� arr ��
    for (int i = 0; i < passwords.size(); i++) {
        if (passwords[i][0] == arr[i * 2] && passwords[i][1] == arr[i * 2 + 1]) {
            answer++;
        }
    }

    cout << "answer: " << answer << endl;

    return 0;
}
