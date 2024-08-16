#include <iostream>
#include <vector>
#define PII pair<int, int>
using namespace std;

int graph[1001];

bool cmp(PII a, PII b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first < b.first;
}

int main(){
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        graph[i] = 1;

    vector<PII> v;
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        v.push_back({A, B});
    }

    sort(v.begin(), v.end(), cmp);

    for (auto p: v)
        graph[p.second] = max(graph[p.first] + 1, graph[p.second]);

    for (int i = 1; i <= N; i++)
        cout << graph[i] << ' ';

    return 0;
}