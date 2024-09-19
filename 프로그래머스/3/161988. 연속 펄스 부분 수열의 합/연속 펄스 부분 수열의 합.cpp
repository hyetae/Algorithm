#include <string>
#include <vector>
#include <cmath>
#define ll long long
using namespace std;

ll seq[500001];

ll solution(vector<int> sequence) {
    ll answer, maxi, mini;
    seq[0] = answer = maxi = mini = sequence[0];

    for (int i = 1; i < sequence.size(); i++) 
        seq[i] += seq[i-1] + sequence[i] * ((i % 2) ? -1 : 1);

    for (auto s: seq) {
        if (maxi < s)
            maxi = s;
        if (mini > s)
            mini = s;
    }
    
    return max(max(maxi - mini, maxi), abs(mini));
}