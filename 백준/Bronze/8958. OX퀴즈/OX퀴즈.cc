#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        string input;
        cin >> input;

        int con = 0;
        int res = 0;
        for (auto i: input) {
            if (i == 'O') {
                con++;
                res += con;
            } else con = 0;
        }

        cout << res << '\n';
    }

    return 0;
}