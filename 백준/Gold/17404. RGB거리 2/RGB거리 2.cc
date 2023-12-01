#include <bits/stdc++.h>
#define MAX 1001
using namespace std;

int main() {
    int n;
    int input[MAX][3] = { 0, };

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            cin >> input[i][j];

    int res = MAX * n;
    for (int i = 0; i < 3; i++) {
        int dp[MAX][3];
        for (int j = 0; j < 3; j++) {
            if (i == j)
                dp[1][j] = input[1][j];
            else
                dp[1][j] = MAX * n;
        }

        for (int j = 2; j <= n; j++) {
            dp[j][0] = input[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
            dp[j][1] = input[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
            dp[j][2] = input[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
        }

        for (int j = 0; j < 3; j++) {
            if (i == j)
                continue;
            res = min(res, dp[n][j]);
        }
    }

    cout << res;
    return 0;
}