#include <bits/stdc++.h>
#define MAX 50
using namespace std;

int w, h, cnt;
int graph[MAX][MAX] = {0, };
bool visited[MAX][MAX] = {false, };
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void bfs(int h, int w){
    queue<pair<int, int>> q;
    q.push({h, w});
    visited[h][w] = true;

    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int nh = a + dy[i];
            int nw = b + dx[i];

            if(nh < 0 || nw < 0 || nw >= MAX || nh >= MAX)
                continue;
            if(!graph[nh][nw])
                continue;
            if(graph[nh][nw] && !visited[nh][nw]){
                visited[nh][nw] = true;
                q.push({nh, nw});
            }
        }
    }
}

int main(){
    while(true){
        cnt = 0;
        cin >> w >> h;
        if(!w && !h)
            break;

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++)
                cin >> graph[i][j];
        }

        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++) {
                if (graph[i][j] && !visited[i][j]){
                    cnt++;
                    bfs(i, j);
                }
            }
        }
        cout << cnt << '\n';
        memset(graph, 0, sizeof(graph));
        memset(visited, false, sizeof(visited));
    }
    return 0;
}