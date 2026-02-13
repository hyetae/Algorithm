#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[101];
vector<pair<int, int>> vec;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec.push_back({a, b});
    }

    sort(vec.begin(), vec.end());

    int res = 0;
    for (int i = 1; i < n + 1; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (vec[i - 1].second > vec[j - 1].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }

    cout << n - res;
    return 0;
}