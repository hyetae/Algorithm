#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

int calc(int mine, int pick) {
    float calc = mine / pick;
    if (calc >= 1.0)
        return int(calc);
    return 1;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    int num_picks = 0;
    for (auto p: picks)
        num_picks += p;
    
    // 각 구간을 5로 나누어 구간 별 피로도 계산
    int sum_tired = 0;
    vector<pair<int, int>> tired;
    for (int i = 0; i < minerals.size(); i += 5) {
        if (i >= num_picks * 5)
            break;
        for (int j = 0; j < 5; j++) {
            if (i + j >= minerals.size())
                break;
            if (minerals[i + j] == "diamond")
                sum_tired += 25;
            else if (minerals[i + j] == "iron")
                sum_tired += 5;
            else sum_tired += 1;
        }
        tired.push_back({i, sum_tired});
        sum_tired = 0;
    }
    
    // 피로도 내림차순 정렬
    sort(tired.begin(), tired.end(), cmp);
    
    // 실제 피로도 계산
    for (auto t: tired) {
        // 다이아몬드부터 곡괭이부터 선택
        int pick;
        for (int i = 0; i < 3; i++) {
            if (picks[i]) {
                if (i == 0)
                    pick = 25;
                else if (i == 1)
                    pick = 5;
                else pick = 1;
                --picks[i];
                break;
            }
        }
        
        // 실제 피로도 계산
        for (int i = 0; i < 5; i++) {
            int idx = t.first + i;
            if (idx >= minerals.size())
                break;
            if (minerals[idx] == "diamond") 
                answer += calc(25, pick);
            else if (minerals[idx] == "iron")
                answer += calc(5, pick);
            else answer += calc(1, pick);
        }
    }
        
    return answer;
}