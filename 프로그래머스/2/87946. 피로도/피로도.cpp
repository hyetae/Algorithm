#include <bits/stdc++.h>
using namespace std;

int res;
bool visited[8];

void backTracking(int cnt, int k, vector<vector<int>> &dg) {
    res = max(res, cnt);
    
    for (int i = 0; i < dg.size(); i++) {
        if (dg[i][0] > k || visited[i]) 
            continue;
        visited[i] = true;
        backTracking(cnt + 1, k - dg[i][1], dg);
        visited[i] = false;
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    backTracking(0, k, dungeons);
    return res;
}