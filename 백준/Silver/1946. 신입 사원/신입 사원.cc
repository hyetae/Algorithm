#include <iostream>
#include <vector>
#define PII pair<int, int>
using namespace std;

bool cmp(PII a, PII b) {
    return a.first < b.first;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;

        vector<PII> v;
        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end(), cmp);

        int res = 0;
        int mini = N + 1;
        for (auto p: v) {
            if (p.second < mini) {
                mini = p.second;
                res++;
            }
        }

        cout << res << '\n';
    }
    return 0;
}