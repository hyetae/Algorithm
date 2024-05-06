#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<>> cards;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        cards.push(input);
    }

    int res = 0;
    while (cards.size() > 1) {
        int sum = 0;
        sum += cards.top();
        cards.pop();
        sum += cards.top();
        cards.pop();
        res += sum;
        cards.push(sum);
    }

    cout << res;
    return 0;
}