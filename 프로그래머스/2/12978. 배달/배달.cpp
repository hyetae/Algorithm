#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> road, int k) {
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 500'001));

    for (auto r: road) {
        graph[r[0]][r[1]] = min(graph[r[0]][r[1]], r[2]);
        graph[r[1]][r[0]] = min(graph[r[1]][r[0]], r[2]);
    }
    
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    for (int l = 1; l <= n; l++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                graph[i][j] = min(graph[i][j], graph[i][l] + graph[l][j]);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (graph[1][i] <= k)
            cnt++;

    return cnt;
}