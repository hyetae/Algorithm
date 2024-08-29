#include <iostream>
#include <set>
using namespace std;

int N, M;
int seq[8];
int ans[8];
bool visited[8];

void makeSeq(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;
        visited[i] = true;
        ans[cnt] = seq[i];
        makeSeq(cnt + 1);
        ans[cnt] = 0;
        visited[i] = false;
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> seq[i];

    sort(seq, seq + N);

    makeSeq(0);
    return 0;
}