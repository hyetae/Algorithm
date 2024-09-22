#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int solution(int k, vector<int> tangerine) {
    map<int, int> tg_m;
    for (int i = 0; i < tangerine.size(); i++) 
        tg_m[tangerine[i]]++;
    
    vector<pair<int, int>> tg_v(tg_m.begin(), tg_m.end());
    sort(tg_v.begin(), tg_v.end(), cmp);
    
    int cnt = 0;
    for (auto tg: tg_v) {
        if (k <= 0)
            break;
        
        cnt++;
        k -= tg.second;
    }
    
    return cnt;
}