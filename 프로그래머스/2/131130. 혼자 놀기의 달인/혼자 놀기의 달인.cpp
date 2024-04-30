#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> cards) {
    int answer = 1;
    int visited[101];
    vector<int> res;
    
    memset(visited, 0, sizeof(visited));
    
    for(int card: cards) {
        int cnt = 0;
        while(!visited[card]) {
            visited[card] = 1;
            cnt++;
            card = cards[card - 1];
        }
        
        if (cnt)
            res.push_back(cnt);
    }
    
    if (res.size() < 2)
        return 0;
    
    sort(res.begin(), res.end());
    
    for (int i = 0; i < 2; i++) {
        answer *= res.back();
        res.pop_back();
    }
    
    return answer;
}