#include <bits/stdc++.h>
using namespace std;

int solution(int n) {
    vector<int> dp = {0, 1};
    for (int i = 2; i <= n; ++i)
        dp.push_back((dp[i - 1] + dp[i - 2]) % 1234567);
    return dp[n];
}