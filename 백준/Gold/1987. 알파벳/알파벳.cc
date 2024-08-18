#include <iostream>
#include <queue>
#include <set>
using namespace std;

int R, C, res;
const int MAX = 20;
char graph[MAX][MAX];
bool visited[26];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y) {
    if (0 > x || R <= x || 0 > y || C <= y)
        return false;
    return true;
}

void backTracking(int x, int y, int cnt) {

    res = max(res, cnt);
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        int num = graph[nx][ny] - 'A';
        if (!isValid(nx, ny) || visited[num])
            continue;

        visited[num] = true;
        backTracking(nx, ny, cnt + 1);
        visited[num] = false;
    }
}

int main() {

    cin >> R >> C;
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> graph[i][j];

    visited[graph[0][0] - 'A'] = true;
    backTracking(0, 0, 1);
    cout << res;
    return 0;
}