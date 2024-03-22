#include <bits/stdc++.h>
#define MAX 1'000'000
using namespace std;

int dp1[MAX];
int dp2[MAX];

int solution(vector<int> money) {
    dp1[0] = money[0];
    dp1[1] = dp1[0];
    dp2[0] = 0;
    dp2[1] = money[1];
    
    int n = money.size() - 1;
    for (int i = 2; i < n; i++)
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);
    for (int i = 2; i <= n; i++)
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);
    
    return max(dp1[n - 1], dp2[n]);
}