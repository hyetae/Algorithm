#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    int N;
    cin >> N;

    ll cnt = 0;
    vector<int> v;
    while(N--) {
        int h;
        cin >> h;

        if (v.empty()) {
            v.push_back(h);
            continue;
        }

        while (!v.empty() && v.back() <= h)
            v.pop_back();

        cnt += v.size();
        v.push_back(h);
    }

    cout << cnt;
    return 0;
}