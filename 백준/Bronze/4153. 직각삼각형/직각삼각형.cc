#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (1) {
        vector<int> t(3);
        cin >> t[0] >> t[1] >> t[2];

        if (!(t[0] + t[1] + t[2]))
            break;

        sort(t.begin(), t.end());

        if (t[2] * t[2] == t[1] * t[1] + t[0] * t[0])
            cout << "right\n";
        else cout << "wrong\n";
    }

    return 0;
}