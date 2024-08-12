#include <iostream>
#include <queue>
#define MAX 1000
using namespace std;

int graph[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

struct Tomato {
    int x, y, n;
};

int main() {
    int m, n; cin >> m >> n;

    int isRipen = 0;
    int tomatos = n * m;
    queue<Tomato> ripen;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int t; cin >> t;
            if (t == 1) {
                ripen.push({i, j, 0});
                isRipen++;
            } else if (t == -1)
                tomatos--;
            graph[i][j] = t;
        }

    if (isRipen == n * m) {
        cout << 0;
        return 0;
    }

    int day = 0;
    while (!ripen.empty()) {
        Tomato now = ripen.front();
        day = max(day, now.n);
        ripen.pop();

        for (int i = 0; i < 4; i++) {
            int nx = now.x + dx[i];
            int ny = now.y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            if (!graph[nx][ny]) {
                graph[nx][ny] = 1;
                isRipen++;
                ripen.push({nx, ny, now.n + 1});
            }

        }
    }

    if (isRipen == tomatos)
        cout << day;
    else cout << -1;

    return 0;
}