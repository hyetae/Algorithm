#include <iostream>
#include <string>
using namespace std;

const int MAX = 100'000;
int graph[MAX];
int N, M;

bool binarySearch(int target) {
    int m;
    int l = 0;
    int r = N - 1;
    
    while (l <= r) {
        m = (l + r) / 2;
        if (graph[m] == target)
            return true;
        if (target < graph[m])
            r = m - 1;
        else
            l = m + 1;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> graph[i];

    sort(graph, graph + N);

    cin >> M;
    while (M--) {
        int input;
        cin >> input;
        if (binarySearch(input))
            cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}