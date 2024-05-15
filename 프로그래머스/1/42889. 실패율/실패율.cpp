#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<float> tried(N + 2, 0.0);
    vector<float> failed(N + 2, 0.0);
    for (int stage: stages) {
        for (int i = 1; i <= stage; i++) 
            tried[i]++;
        failed[stage]++;
    }
        
    vector<pair<int, float>> rate;
    for (int i = 1; i < N + 1; i++) {
        float sec;
        if (!tried[i]) sec = 0;
        else sec = failed[i] / tried[i];
        rate.push_back({i, sec});
    }
    
    for (auto i: rate)
        cout << i.first << ' ' << i.second << endl;
        
    sort(rate.begin(), rate.end(), cmp);
    
    vector<int> answer;
    for (auto r:rate)
        answer.push_back(r.first);
    
    return answer;
}