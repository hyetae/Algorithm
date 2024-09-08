#include <string>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 20'001;
int cnt[MAX];
bool visited[MAX];

int bfs(vector<int>* graph, int& n) {
    queue<pair<int, int>> q;
    q.emplace(1, 1);
    visited[1] = true;

    int maxi = 0;
    // first = edge
    // second = cnt
    while (!q.empty()) {
        pair<int, int> x = q.front();
        cnt[x.second]++;
        q.pop();

        maxi = max(maxi, x.second);
        for (auto& g: graph[x.first])
            if (!visited[g]) {
                visited[g] = true;
                q.emplace(g, x.second + 1);
            }
    }

    return cnt[maxi];
}

int solution(int n, vector<vector<int>> edge) {
    vector<int> graph[n + 1];
    for (auto& e: edge) {
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
    }

    return bfs(graph, n);
}