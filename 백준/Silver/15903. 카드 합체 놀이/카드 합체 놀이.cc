#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

vector<long long> vec;

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        vec.push_back(input);
    }

    for (int i = 0; i < m; i++) {
        sort(vec.begin(), vec.end());
        long long sum = vec[0] + vec[1];
        vec[0] = sum;
        vec[1] = sum;
    }
    
    long long res = 0;
    for (int i = 0; i < n; i++) {
        res += vec[i];
    }

    cout << res;
    return 0;
}