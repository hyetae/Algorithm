#include <iostream>
#include <cstring>
#include <queue>
#define PII pair<int, int>
using namespace std;

int w, h;
const int MAX = 1'000;
char graph[MAX][MAX];
bool visited[MAX][MAX];
queue<PII> fire;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct coor {
    int x, y, cnt = 0;
};

bool isValid(int a, int b) {
    if (a < 0 || a >= h || b < 0 || b >= w)
        return false;
    return true;
}

void setFire() {
    int numOfFire = fire.size();

    for (int i = 0; i < numOfFire; i++) {
        PII current = fire.front();

        for (int j = 0; j < 4; j++) {
            int fx = current.first + dx[j];
            int fy = current.second + dy[j];

            if (!isValid(fx, fy))
                continue;

            if (graph[fx][fy] == '.' || graph[fx][fy] == '@') {
                graph[fx][fy] = '*';
                fire.push({fx, fy});
            }
        }
        fire.pop();
    }
}

int bfs(PII start) {
    queue<coor> q;
    visited[start.first][start.second] = 1;
    q.push({start.first, start.second, 0});

    int step = 0;
    while (!q.empty()) {
        coor current = q.front();
        q.pop();

        if (step <= current.cnt) {
            setFire();
            step++;
        }

        for (int i = 0; i < 4; i++) {
            int nx = current.x + dx[i];
            int ny = current.y + dy[i];

            if (!isValid(nx, ny))
                return current.cnt + 1;

            if (visited[nx][ny])
                continue;

            if (graph[nx][ny] == '.') {
                q.push({nx, ny, current.cnt + 1});
                graph[nx][ny] = '@';
                visited[nx][ny] = 1;
            }
        }
    }
    return 0;
}

PII input() {
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(graph));
    while (!fire.empty())
        fire.pop();

    cin >> w >> h;

    PII start;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char n;
            cin >> n;

            if (n == '@')
                start = {i, j};
            else if (n == '*')
                fire.push({i, j});

            graph[i][j] = n;
        }
    }
    return start;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int res = bfs(input());
        if (!res)
            cout << "IMPOSSIBLE\n";
        else cout << res << '\n';
    }
}