#include <iostream>
using namespace std;

const int MAX = 500;
int dp[MAX][MAX];

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> dp[i][j];

    dp[1][0] += dp[0][0];
    dp[1][1] += dp[0][0];

    for (int i = 2; i < n; i++)
        for (int j = 0; j <= i; j++) {
            if (!j)
                dp[i][j] += dp[i - 1][j];
            else if (j == i)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }

    int res = 0;
    for (int i = 0; i < n; i++)
        res = max(res, dp[n - 1][i]);

    cout << res;
    return 0;
}