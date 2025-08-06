#include <iostream>
#include <deque>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    deque<int> dq;

    for (int i = 1; i <= N; ++i) {
        dq.push_back(i);
    }

    while (dq.size() > K) {
        int first = dq[0];

        for (int i = 0; i < K; ++i) {
            dq.pop_front();  
        }

        dq.push_back(first);  // 첫 번째 청설모를 마지막에 추가
    }

    cout << dq[0] << '\n';
    return 0;
}