#include <iostream>
using namespace std;

const int MAX = 10'001;
int arr[MAX];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        arr[i] = arr[i - 1] + n;
    }

    int cnt = 0, pt1 = 0, pt2 = 0;
    while (pt2 <= N) {
        int diff = arr[pt2] - arr[pt1];
        if (diff == M) {
            cnt++;
            pt1++;
            pt2++;
        } else if (diff < M)
            pt2++;
        else pt1++;
    }

    cout << cnt;

    return 0;
}