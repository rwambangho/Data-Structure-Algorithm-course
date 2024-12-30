#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    string s;
    cin >> s;

    // 정수 추출을 위한 문자열 스트림
    stringstream ss(s);
    string token;

    vector<int> arr;  // 정수를 저장할 배열
    vector<vector<int>> passwords;  // 2차원 벡터

    // '#'을 구분자로 사용하여 문자열 파싱
    while (getline(ss, token, '#')) {
        if (!token.empty()) {
            int num = stoi(token);
            arr.push_back(num);
        }
    }

    // passwords 2차원 벡터 초기화
    // 예를 들어, passwords[0][0]과 passwords[0][1]이 arr[0]과 arr[1]과 같다고 가정
    passwords.push_back({ arr[0], arr[1] });
    // passwords[1][0]과 passwords[1][1]과 arr[2]과 arr[3] 비교

    int answer = 0;

    // passwords와 arr 비교
    for (int i = 0; i < passwords.size(); i++) {
        if (passwords[i][0] == arr[i * 2] && passwords[i][1] == arr[i * 2 + 1]) {
            answer++;
        }
    }

    cout << "answer: " << answer << endl;

    return 0;
}
