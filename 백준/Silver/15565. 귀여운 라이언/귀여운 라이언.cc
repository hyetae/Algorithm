#include <iostream>
#include <vector>
using namespace std;

int main() {

    int N, K;
    cin >> N >> K;

    vector<int> ryan;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;
        if (n == 1)
            ryan.push_back(i);
    }

    if (ryan.size() < K) {
        cout << -1;
        return 0;
    }

    int res = 1e9;
    for (int i = 0; i <= ryan.size() - K; i++)
        res = min(res, ryan[i + K - 1] - ryan[i] + 1);

    cout << res;

    return 0;
}