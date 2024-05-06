#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solution(int n, vector<int> road, vector<int> city) {
    int sum = 0;
    int sel = 1e9;
    for (int i = 0; i < n - 1; i++) {
        sel = min(sel, city[i]);
        sum += sel * road[i];
    }
    return sum;
}

int main() {
    int N;
    vector<int> road;
    vector<int> city;

    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int input;
        cin >> input;
        road.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        city.push_back(input);
    }

    cout << solution(N, road, city);
    return 0;
}