#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> trees(N);
    int max_height = 0;

    for (int i = 0; i < N; ++i) {
        cin >> trees[i];
        if (trees[i] > max_height)
            max_height = trees[i];  // 가장 높은 나무 찾기
    }

    int low = 0;
    int high = max_height;
    int result = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long long total = 0;

        for (int i = 0; i < N; ++i) {
            if (trees[i] > mid)
                total += (trees[i] - mid);
        }

        if (total >= M) {
            result = mid;      // 가능한 높이 저장
            low = mid + 1;     // 더 높게 잘라도 되는지 확인
        } else {
            high = mid - 1;    // 너무 많이 잘랐음 → 절단기 낮추기
        }
    }

    cout << result << '\n';
    return 0;
}
