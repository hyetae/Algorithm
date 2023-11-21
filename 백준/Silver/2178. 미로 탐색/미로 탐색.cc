#include <bits/stdc++.h>
using namespace std;

int n, m;
int graph[100][100];
bool visited[100][100] = { false, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int x, int y){
    queue<pair<int,int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if(!graph[nx][ny])
                continue;
            if(graph[nx][ny] && !visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
                graph[nx][ny] = graph[a][b] + 1;
            }
        }
    }
    return graph[n - 1][m - 1];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            graph[i][j] = str[j] - '0';
    }



    cout << bfs(0, 0);

    return 0;
}