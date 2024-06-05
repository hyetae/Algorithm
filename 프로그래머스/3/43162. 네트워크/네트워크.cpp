#include <bits/stdc++.h>
using namespace std;

vector<bool> visited;

void dfs(int x, vector<vector<int>> &coms) {
    visited[x] = true;
    for (int i = 0; i < coms[x].size(); i++) 
        if (coms[x][i] && !visited[i])
            dfs(i, coms);
}

int solution(int n, vector<vector<int>> coms) {
    visited = vector<bool>(coms.size(), false);
    
    int cnt = 0;
    for (int i = 0; i < coms.size(); i++)
        if (!visited[i]) {
            dfs(i, coms);
            cnt++;
        }
    
    return cnt;
}