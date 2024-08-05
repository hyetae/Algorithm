#include <iostream>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    while (1) {
        if (s.size() == t.size())
            break;

        char tmp = t.back();
        t.erase(t.end() - 1);
        if (tmp == 'B')
            reverse(t.begin(), t.end());
    }

    if (s == t)
        cout << 1;
    else cout << 0;

    return 0;
}