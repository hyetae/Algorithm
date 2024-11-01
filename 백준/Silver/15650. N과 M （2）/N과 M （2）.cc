#include <iostream>
using namespace std;

int N, M;
const int MAX = 9;
int graph[MAX];
bool visited[MAX];

void dfs(int num, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << graph[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            graph[cnt] = i;
            dfs(i + 1, cnt + 1);
            visited[i] = false;
        }
    }
}

int main(){

    cin >> N >> M;

    dfs(1, 0);
    return 0;
}
