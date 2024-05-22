#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> d, int budget) {
    int cnt = 0;
    sort(d.begin(), d.end());
    for (int a: d) {
        if (budget >= a) {
            cnt++;
            budget -= a;
        }
    }
    return cnt;
}