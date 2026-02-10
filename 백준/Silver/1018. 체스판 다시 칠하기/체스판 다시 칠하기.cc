#include <iostream>
#include <string>

using namespace std;

string arr_w[8] = { "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW"};

string arr_b[8] = { "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB",
                "BWBWBWBW",
                "WBWBWBWB"};

string arr[50];

int diff_w(int x, int y) {
    int diff = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[x + i][y + j] != arr_w[i][j]) {
                diff++;
            }
        }
    }
    return diff;
}

int diff_b(int x, int y) {
    int diff = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (arr[x + i][y + j] != arr_b[i][j]) {
                diff++;
            }
        }
    }
    return diff;
}

int main() {
    int n, m, res;
    cin >> n >> m;
    res = n * m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i <= n - 8; i++) {
        for (int j = 0; j <= m - 8; j++) {
            int mini = min(diff_w(i, j), diff_b(i, j));
            res = res < mini ? res : mini;
        }
    }

    cout << res;
    return 0;
}