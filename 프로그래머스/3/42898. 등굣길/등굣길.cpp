#include <bits/stdc++.h>
using namespace std;

int solution(int m, int n, vector<vector<int>> pud) {
    vector<vector<int>> graph(n + 1, vector<int>(m + 1, 0));
    for (vector<int> v: pud)
        graph[v[1]][v[0]] = 1;
    
    graph[0][1] = 1;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (graph[i][j])
                graph[i][j] = 0;
            else
                graph[i][j] = (graph[i - 1][j] + graph[i][j - 1]) % 1'000'000'007;
        }
    }
    
    return graph[n][m];
}