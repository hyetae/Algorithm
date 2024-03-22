#include <bits/stdc++.h>
#define fastio cin.tie(0) -> sync_with_stdio(0)
using namespace std;

int solution(vector<vector<int>> tri) {
    for (int i = 1; i < tri.size(); i++) {
        for (int j = 0; j < i + 1; j++) {
            if (j == 0)
                tri[i][j] += tri[i - 1][j];
            else if (j == i)
                tri[i][j] += tri[i - 1][j - 1];
            else 
                tri[i][j] += max(tri[i - 1][j - 1], tri[i - 1][j]);
        }
    }
    
    int ans = 0;
    for (int i: tri[tri.size() - 1])
        if (i > ans)
            ans = i;
    
    return ans;
}