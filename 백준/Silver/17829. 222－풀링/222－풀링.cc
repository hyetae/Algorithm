#include <iostream>
#include <vector>
using namespace std;

int findMax(int a, int b, int c, int d) {
    vector<int> v = {a, b, c, d};
    sort(v.begin(), v.end());
    return v[2];
}

vector<int> pooling(vector<int> vec, int n) {
    if (n == 1)
        return vec;

    vector<int> v;
    for (int i = 0; i < n; i += 2) {
        for (int j = 0; j < n; j += 2) {
            int k = i * n + j;
            v.push_back(findMax(vec[k], vec[k + 1], vec[k + n], vec[k + 1 + n]));
        }
    }

    return pooling(v, n / 2);
}

int main() {
    int N, NN;
    cin >> N;
    NN = N * N;

    vector<int> vec;
    for (int i = 0; i < NN; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    vector<int> res = pooling(vec, N);

    cout << res[0];
    return 0;
}