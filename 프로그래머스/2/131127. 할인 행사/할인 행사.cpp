#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> want_map;

bool check() {
    for (auto w: want_map)
        if (w.second > 0)
            return false;
    return true;
}

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    for (int i = 0; i < want.size(); i++)
        want_map[want[i]] = number[i];
    
    for (int i = 0; i < 10; i++)
        if (want_map.find(discount[i]) != want_map.end())
            want_map[discount[i]]--;
    
    int cnt = 0;
    if (check())
        cnt++;
    
    for (int i = 10; i < discount.size(); i++) {
        // for (auto w: want_map)
        //     cout << w.first << ' ' << w.second << endl;
        
        if (want_map.find(discount[i]) != want_map.end()) {
            // cout << "minus " << discount[i] << endl;
            want_map[discount[i]] -= 1;
        }
        if (want_map.find(discount[i - 10]) != want_map.end()) {
            // cout << "plus " << discount[i - 10] << endl;
            want_map[discount[i - 10]] += 1;
        }
        
        // cout << endl;
        if (check())
            cnt++;
    }
    return cnt;
}