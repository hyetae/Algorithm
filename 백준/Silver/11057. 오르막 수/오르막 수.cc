#include <bits/stdc++.h>
using namespace std;

int main() {
    int dp[1001][10] = { 0, };
    for (int i = 0; i < 10; i++)
        dp[1][i] = 1;

    int N;
    cin>>N;

    for (int i = 2; i <= N; i++)
        for (int j = 0; j < 10; j++){
            if (j == 0)
                dp[i][0] = 1;
            else {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                dp[i][j] %= 10007;
            }
        }

    int res = 0;
    for(int i = 0; i < 10; i++)
        res = res + dp[N][i];

    cout<< res % 10007;

    return 0;
}