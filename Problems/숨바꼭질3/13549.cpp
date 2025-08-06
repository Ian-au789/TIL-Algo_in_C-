// 1. 시간을 소비하는 이동은 +1, -1 / *2는 시간 소비 X
// 2. N이 K를 초과하면 *2는 의미가 없음. -1로 가까워질 수 밖에
// 3. heapq...가 아니라 prioirity_queue로 0초, 1초, 2초... 일 때 (현재 시각, N의 위치) 형태로 push
// 4. N의 위치가 K에 도달하는 그 순간의 현재 시각 return
// https://www.acmicpc.net/problem/13549

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int MAX = 100001;
    vector<bool> visited(MAX, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // (time, loc)

    pq.push({0, N}); // 시작점

    while (!pq.empty()) {
        auto [time, loc] = pq.top();
        pq.pop();

        if (loc == K) {
            cout << time << '\n';
            break;
        }

        if (visited[loc]) continue;
        visited[loc] = true;

        // 순간이동 (0초)
        if (loc * 2 < MAX && !visited[loc * 2] ) {
            pq.push({time, loc * 2});
        }

        // +1 이동 (1초)
        if (loc + 1 < MAX && !visited[loc + 1]) {
            pq.push({time + 1, loc + 1});
        }

        // -1 이동 (1초)
        if (loc - 1 >= 0 && !visited[loc - 1]) {
            pq.push({time + 1, loc - 1});
        }

    }

    return 0;
}