#include <iostream>
using namespace std;

int arr[10];
int main() {
    string n;
    cin >> n;

    for (char c: n) {
        arr[c - '0']++;
    }

    int res = (arr[6] + arr[9] + 1) / 2;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) {
            continue;
        }
        res = max(res, arr[i]);
    }

    cout << res;
    return 0;
}