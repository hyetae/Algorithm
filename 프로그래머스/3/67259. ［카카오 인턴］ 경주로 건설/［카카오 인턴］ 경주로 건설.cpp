#include <string>
#include <vector>
#include <queue>
using namespace std;

int n;
int visited[25][25];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Coor {
    int x, y, c, d;
};

bool isValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n)
        return false;
    return true;
}

int solution(vector<vector<int>> board) {
    int res = 1e9;
    n = board.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            visited[i][j] = 1e9;

    visited[0][0] = 0;

    queue<Coor> q;
    q.push({0, 0, 0, -1});

    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int c = q.front().c;
        int d = q.front().d;
        q.pop();

        // printf("{%d, %d}: %d, %d\n",x, y, c, d);

        if (x == n - 1 && y == n - 1) {
            res = min(res, c);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!isValid(nx, ny) || board[nx][ny])
                continue;

            int cost = c;
            if (d == i || d == -1)
                cost += 100;
            else
                cost += 600;

            if (visited[nx][ny] >= cost) {
                visited[nx][ny] = cost;
                q.push({nx, ny, cost, i});
            } else if (visited[nx][ny] + 500 >= cost)
                q.push({nx, ny, cost, i});
        }
    }

    return res;
}