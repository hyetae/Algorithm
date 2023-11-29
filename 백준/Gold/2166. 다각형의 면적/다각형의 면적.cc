#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tri;

long double cal(int a) {
    long double x1 = tri[0].first;
    long double y1 = tri[0].second;
    long double x2 = tri[a].first;
    long double y2 = tri[a].second;
    long double x3 = tri[a + 1].first;
    long double y3 = tri[a + 1].second;

    return ((x1 * y2 + x2 * y3 + x3 * y1) - (x1 * y3 + x2 * y1 + x3 * y2)) / 2;
}

int main() {
    int n;
    cin >> n;

    int x, y;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        tri.push_back({x, y});
    }

    long double res = 0;
    for (int i = 1; i < n - 1; i++)
        res += cal(i);

    cout << fixed;
    cout.precision(1);
    cout << abs(res);
    return 0;
}