#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n, maxi, far;
const int MAX = 10'001;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];

void dfs(int node, int w) {
    if (visited[node])
        return;

    visited[node] = true;
    if (maxi < w) {
        maxi = w;
        far = node;
    }
    for (auto n: tree[node])
        dfs(n.first, w + n.second);
}

int main() {
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    dfs(1, 0);
    maxi = 0;
    memset(visited, false, sizeof(visited));
    dfs(far, 0);

    cout << maxi;
    return 0;
}