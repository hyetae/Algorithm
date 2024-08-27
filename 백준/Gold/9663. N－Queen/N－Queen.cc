#include <iostream>
using namespace std;

const int MAX = 15;

int N, res;
int col[MAX];

bool isValid(int x) {
    for (int i = 0; i < x; i++)
        if (col[i] == col[x] || abs(col[x] - col[i]) == x - i)
            return false;
    return true;
}

void nQueen(int x) {
    if (x == N) {
        res++;
        return;
    }

    for (int i = 0; i < N; i++) {
        col[x] = i;
        if (isValid(x))
            nQueen(x + 1);
    }
}

int main() {
    cin >> N;
    nQueen(0);
    cout << res;
    return 0;
}