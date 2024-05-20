#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Point {
    int x, y, cnt;
};

Point findStart(char begin, vector<string> &maps) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            if (maps[i][j] == begin)
                return {i, j, 0};
    return {-1, -1, -1};
}

int bfs(char begin, char end, vector<string> &maps) {
    bool visited[101][101] = {false};
    
    queue<Point> q;
    q.push(findStart(begin, maps));
    
    while (!q.empty()) {
        Point p = q.front();
        q.pop();
        
        if (maps[p.x][p.y] == end)
            return p.cnt;
        
        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];
            
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (visited[nx][ny] || maps[nx][ny] == 'X')
                continue;
            q.push({nx, ny, p.cnt + 1});
            visited[nx][ny] = true;
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    int stol = bfs('S', 'L', maps);
    if (stol == -1)
        return -1;
    
    int ltoe = bfs('L', 'E', maps);
    
    return ltoe == -1 ? -1 : stol + ltoe;
}