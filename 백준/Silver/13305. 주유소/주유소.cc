#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solution(int n, vector<ll> road, vector<ll> city) {
    ll sum = 0;
    ll sel = 1e9;
    for (int i = 0; i < n - 1; i++) {
        sel = min(sel, city[i]);
        sum += sel * road[i];
    }
    return sum;
}

int main() {
    int N;
    vector<ll> road;
    vector<ll> city;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        ll input;
        cin >> input;
        road.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        ll input;
        cin >> input;
        city.push_back(input);
    }

    cout << solution(N, road, city);
    return 0;
}