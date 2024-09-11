#include <string>
#include <vector>
#define ll long long

using namespace std;

const ll MAX = 1e18;

ll solution(int n, vector<int> times) {
    ll res = MAX;
    ll m;
    ll l = 0;
    ll r = MAX;
    while (l <= r) {
        m = (l + r) / 2;

        ll sum = 0;
        for (auto &time: times)
            sum += m / time;

        if (n <= sum) {
            if (m < res)
                res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}