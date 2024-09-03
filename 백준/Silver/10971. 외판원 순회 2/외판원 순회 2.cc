#include <iostream>
using namespace std;

int N, res = 1e9;
int graph[10][10];
bool visited[10];

void bt(int begin, int cur, int cnt, int depth) {
    visited[begin] = depth != N - 1;

    if (cur == begin && cnt)
        res = min(res, cnt);

    for (int i = 0; i < N; i++) {
        if (!graph[cur][i])
            continue;

        if (!visited[i]) {
            visited[cur] = true;
            bt(begin, i, cnt + graph[cur][i], depth + 1);
            visited[cur] = false;
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    bt(0, 0, 0, 0);

    cout << res;
}