#include <bits/stdc++.h>
using namespace std;

int N;
int op[4];
int nums[11];
vector<int> res;

void backTracking(int num, int i) {
    if (i >= N) {
        res.push_back(num);
        return;
    }

    if (op[0]) {
        op[0]--;
        backTracking(num + nums[i], i + 1);
        op[0]++;
    } if (op[1]) {
        op[1]--;
        backTracking(num - nums[i], i + 1);
        op[1]++;
    } if (op[2]) {
        op[2]--;
        backTracking(num * nums[i], i + 1);
        op[2]++;
    } if (op[3]) {
        op[3]--;
        backTracking(num / nums[i], i + 1);
        op[3]++;
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> nums[i];
    for (int & i : op)
        cin >> i;

    backTracking(nums[0], 1);

    sort(res.begin(), res.end());

    cout << res.back() << '\n' << res.front();

    return 0;
}