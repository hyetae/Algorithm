#include <bits/stdc++.h>
using namespace std;

//int input[2][100001] = { 0, };
//int dp[2][100001] = { 0, };
//
//int main() {
//    int T;
//    cin >> T;
//
//    for (int tc = 1; tc < T + 1; tc++){
//        int n;
//        cin >> n;
//
//        for (int i = 0; i < 2; i++)
//            for (int j = 0; j < n; j++)
//                cin >> dp[i][j];
//
//        dp[0][0] = input[0][0];
//        dp[1][0] = input[1][0];
//        dp[0][1] = input[0][1] + input[1][0];
//        dp[1][1] = input[1][1] + input[0][0];
//
//        for (int i = 2; i < n; i++){
//            dp[0][i] = dp[i - 2] + ;
//            dp[1][i] = input[1][i];
//        }
//
//
//        memset(input, 0, sizeof(int));
//        memset(dp, 0, sizeof(int));
//    }
//
//    return 0;
//}

#define MAX 1001

struct Edge {
    int v1, v2, flag;
};

int n, m, parent[MAX];
vector<Edge> edges;

bool compare1(const Edge& a, const Edge& b) {
    return a.flag < b.flag;
}

bool compare2(const Edge& a, const Edge& b) {
    return a.flag > b.flag;
}

void init() {
    for (int i = 0; i < MAX; i++)
        parent[i] = i;
}

int Find(int a) {
    if (a == parent[a])
        return a;
    return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
    int pa = Find(a), pb = Find(b);
    parent[pa] = pb;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m + 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }

    init();
    sort(edges.begin(), edges.end(), compare1);

    int ans1 = 0;
    for (auto& edge: edges) {
        if (Find(edge.v1) != Find(edge.v2)) {
            Union(edge.v1, edge.v2);
            if (!edge.flag)
                ans1++;
        }
    }

    init();
    sort(edges.begin(), edges.end(), compare2);

    int ans2 = 0;
    for (auto& edge: edges) {
        if (Find(edge.v1) != Find(edge.v2)) {
            Union(edge.v1, edge.v2);
            if (!edge.flag)
                ans2++;
        }
    }

    cout << int(pow(ans1, 2) - pow(ans2, 2));
    return 0;
}