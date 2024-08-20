#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int h, w, n;
        cin >> h >> w >> n;

        bool flag = false;
        for (int i = 1; i <= w; i++) {
            if (flag)
                break;
            for (int j = 1; j <= h; j++) {
                n--;
                if (!n) {
                    if (i < 10)
                        cout << j << 0 << i << '\n';
                    else
                        cout << j << i << '\n';
                    flag = true;
                }
            }
        }
    }

    return 0;
}