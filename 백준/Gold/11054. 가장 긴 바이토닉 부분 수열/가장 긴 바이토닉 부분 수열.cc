#include <iostream>
using namespace std;

const int MAX = 1'000;

int seq[MAX];
int dp1[MAX];
int dp2[MAX];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> seq[i];
        dp1[i] = 1;
    }

    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++)
            if (seq[j] > seq[i])
                dp1[j] = max(dp1[j], dp1[i] + 1);

    for (int i = N - 1; i > 0; i--)
        for (int j = i - 1; j >= 0; j--)
            if (seq[j] > seq[i])
                dp2[j] = max(dp2[j], dp2[i] + 1);

    int res = 0;
    for (int i = 0; i < N; i++)
        res = max(res, dp1[i] + dp2[i]);

    cout << res;
    return 0;
}