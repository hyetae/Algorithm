#include <bits/stdc++.h>
using namespace std;
#define MAX 100
#define fast cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)

int graph[MAX][MAX] = {0,};
int visited[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int N, M;

int bfs(int x, int y){
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(graph[nx][ny] == 0)
                continue;
            if(graph[nx][ny] == 1 && visited[nx][ny] == 0){
                graph[nx][ny] = graph[a][b] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return graph[N - 1][M - 1];
}

int main(){
    cin >> N >> M;

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;

        for(int j = 0; j < M; j++)
            graph[i][j] = str[j] - '0';
    }
    cout << bfs(0, 0) << endl;
    return 0;
}