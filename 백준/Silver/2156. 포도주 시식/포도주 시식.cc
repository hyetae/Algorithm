#include <bits/stdc++.h>
using namespace std;

int dp[10001];

int main() {
    int N;
    cin >> N;

    vector<int> arr(N + 1, 0);
    for (int i = 1; i <= N; i++) 
        cin >> arr[i];

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];
    for (int i = 3; i <= N; i++) 
        dp[i] = max(dp[i - 3] + arr[i - 1] + arr[i], max(dp[i - 2] + arr[i], dp[i - 1]));
    
    cout << dp[N];
    return 0;
}