#include <iostream>
using namespace std;

int N;
const int MAX = 3;
int graph[MAX][MAX];

bool dfs(int x, int y) {
    if (x == N - 1 && y == N - 1)
        return true;
    
    if (x < 0 || x >= N || y < 0 || y >= N)
        return false;
    
    if (!graph[x][y])
        return false;

    return dfs(x + graph[x][y], y) || dfs(x, y + graph[x][y]);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> graph[i][j];

    if (!dfs(0, 0))
        cout << "Hing";
    else cout << "HaruHaru";

    return 0;
}