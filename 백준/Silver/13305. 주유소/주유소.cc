#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int solution(int n, vector<int> road, vector<int> city) {
    vector<pair<int, int>> v;
    for (int i = 0; i < n - 1; i++)
        v.push_back({i, city[i]});

    sort(v.begin(), v.end(), cmp);

    int sum = 0;
    int isCheapest = 0;
    pair<int, int> cheapest = v.front();
    for (int i = 0; i < n - 1; i++) {
        if (isCheapest)
            sum += road[i] * cheapest.second;
        else
            sum += road[i] * city[i];

        if (i == cheapest.first)
            isCheapest = 1;
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