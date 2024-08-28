#include <iostream>
using namespace std;

pair<char, char> tree[26];

void pre(char c) {
    if (c == '.') return;

    cout << c;
    pre(tree[c - 65].first);
    pre(tree[c - 65].second);
}

void in(char c) {
    if (c == '.') return;

    in(tree[c - 65].first);
    cout << c;
    in(tree[c - 65].second);
}

void post(char c) {
    if (c == '.') return;

    post(tree[c - 65].first);
    post(tree[c - 65].second);
    cout << c;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        tree[a - 65].first = b;
        tree[a - 65].second = c;
    }

    pre('A');
    cout << '\n';
    in('A');
    cout << '\n';
    post('A');
    return 0;
}