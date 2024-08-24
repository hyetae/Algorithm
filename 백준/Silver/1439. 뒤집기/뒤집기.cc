#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;

    int cnt[2] = {0, 0};

    char pre = str[0];
    cnt[pre - '0']++;

    for (int i = 1; i < str.size(); i++) {
        if (pre == str[i])
            continue;
        else {
            pre = str[i];
            cnt[str[i] - '0']++;
        }
    }

    int res = min(cnt[0], cnt[1]);
    cout << res;

    return 0;
}