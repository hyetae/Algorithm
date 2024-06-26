#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    
    vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = (dp[i - 2] + dp[i - 1]) % 1000000007;
    
    return dp[n];
}