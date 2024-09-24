#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100'000;
int dp1[MAX];
int dp2[MAX];

int solution(vector<int> sticker) {
    int n = sticker.size() - 1;
    if (!n)
        return sticker[0];
    
    dp1[0] = sticker[0];
    dp1[1] = sticker[0];
    dp2[0] = 0;
    dp2[1] = sticker[1];
    
    for (int i = 2; i < n; i++)
        dp1[i] = max(sticker[i] + dp1[i - 2], dp1[i - 1]);
    for (int i = 2; i <= n; i++)
        dp2[i] = max(sticker[i] + dp2[i - 2], dp2[i - 1]);
    
    return max(dp1[n - 1], dp2[n]);
}