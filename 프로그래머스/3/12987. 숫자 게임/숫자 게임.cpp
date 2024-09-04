#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int sz = B.size();
    vector<bool> isValid(sz, 0);

    int idx = 0;
    int cnt = 0;
    for (auto a: A) {
        for (int i = idx; i < sz; i++) {
            if (isValid[i])
                continue;
            
            if (a < B[i]) {
                cnt++;
                isValid[i] = 1;
                idx = i + 1;
                break;
            }
        }
    }
    
    return cnt;
}