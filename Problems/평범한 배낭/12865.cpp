// https://www.acmicpc.net/problem/12865

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int w, v;

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; ++i) {
        cin >> w >> v;

        for (int j = K; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }

    cout << dp[K] << '\n';
    return 0;
}
