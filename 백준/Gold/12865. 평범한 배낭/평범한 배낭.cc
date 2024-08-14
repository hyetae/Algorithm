#include <iostream>
using namespace std;

const int MAX = 100'001;
int dp[101][MAX];
int w[MAX];
int v[MAX];

int main(){

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++)
        cin >> w[i] >> v[i];

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= K; j++) {
            if(w[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j - w[i]] + v[i], dp[i - 1][j]);
        }


    cout << dp[N][K];
}