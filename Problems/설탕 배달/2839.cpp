// https://www.acmicpc.net/problem/2839

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    
    vector<int> dp(N);

    for (int i = 0; i < N; ++i) {
        dp[i] = 1e9;
    }
    if (N > 2) {dp[2] = 1;}
    if (N > 4) {dp[4] = 1;}
    
    for (int k = 0; k < N; ++k) {
        if (dp[k] == 1e9) continue;

        if (k + 3 >= N) break;
        dp[k + 3] = min(dp[k+3], dp[k] + 1);

        if (k + 5 >= N) continue;
        dp[k + 5] = min(dp[k+5], dp[k] + 1);
    }
    
    if (dp[N-1] == 1e9) {cout << -1 << '\n';}
    else {cout << dp[N-1] << '\n';}
    return 0;
}