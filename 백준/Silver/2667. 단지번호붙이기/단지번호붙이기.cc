#include <bits/stdc++.h>
#define MAX 25
using namespace std;

int N, cnt;
string graph[MAX];
int visited[MAX][MAX] = {0,};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
vector<int> res;

void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;
    cnt++;

    while(!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N)
                continue;
            if (graph[nx][ny] == '0')
                continue;
            if (graph[nx][ny] == '1' && visited[nx][ny] == 0) {
                visited[nx][ny] = 1;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> graph[i];

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == '1' && visited[i][j] == 0) {
                cnt = 0;
                bfs(i, j);
                res.push_back(cnt);
            }
        }
    }

    sort(res.begin(), res.end());

    cout << res.size() << '\n';
    for(auto &x: res)
        cout << x << '\n';

    return 0;
}