#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    deque<pair<int, int>>dq; //{Á¡¼ö, ÀÎµ¦½º};
    vector<int>ans;

    int N; 
    cin >> N;

    for (int i = 0; i < N; i++) {
        int num; cin >> num;
        dq.push_back({ num,i });
    }

    while (!dq.empty()) {
        int num = dq.front().first;
        int index = dq.front().second;
        ans.push_back(index + 1);
        dq.pop_front();

        for (int i = 1; i < num; i++) {
            dq.push_back(dq.front());
            dq.pop_front();

        }
        for (int i = 0; i > num; i--) {
            dq.push_front(dq.back());
            dq.pop_back();

        }
    }

    for (int i : ans) cout << i << ' ';
}