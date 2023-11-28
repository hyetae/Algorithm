#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int input[2][MAX] = { 0, };
int dp[2][MAX] = { 0, };

int main() {
    int T;
    cin >> T;


    while (T--){
        int n;
        cin >> n;

        for (int i = 0; i < 2; i++)
            for (int j = 0; j < n; j++)
                cin >> input[i][j];

        dp[0][0] = input[0][0];
        dp[1][0] = input[1][0];
        dp[0][1] = input[0][1] + input[1][0];
        dp[1][1] = input[1][1] + input[0][0];

        for (int i = 2; i < n; i++){
            dp[0][i] = input[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
            dp[1][i] = input[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << endl;

        memset(input, 0, sizeof(int));
        memset(dp, 0, sizeof(int));
    }

    return 0;
}