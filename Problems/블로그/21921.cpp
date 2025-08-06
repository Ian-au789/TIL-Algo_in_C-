#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;
    int x_visit = 0;

    vector<int> visitors(N);
    for (int i = 0; i < N; ++i) {
        cin >> visitors[i];

        if (i < X) {
            x_visit += visitors[i];    // 초깃값 설정 
        }
    }
    int max_visit = x_visit;
    int check = 1;

    for (int j = 0; j < N - X; ++j) {
        x_visit = x_visit - visitors[j] + visitors[j + X];

        if (max_visit < x_visit) {
            max_visit = x_visit;
            check = 1;
        }
        else if (max_visit == x_visit) {
            check += 1;
        }
    }

    if (max_visit > 0) {
        cout << max_visit << '\n';
        cout << check << '\n';
    }

    else {
        cout << "SAD" << '\n';
    }
    return 0;
}
