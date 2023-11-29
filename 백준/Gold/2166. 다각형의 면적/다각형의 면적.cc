#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> tri;

double cal(int a) {
    double x1 = tri[0].first;
    double y1 = tri[0].second;
    double x2 = tri[a].first;
    double y2 = tri[a].second;
    double x3 = tri[a + 1].first;
    double y3 = tri[a + 1].second;

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

    double res = 0;
    for (int i = 1; i < n - 1; i++)
        res += cal(i);

    cout << fixed;
    cout.precision(1);
    cout << abs(res);
    return 0;
}