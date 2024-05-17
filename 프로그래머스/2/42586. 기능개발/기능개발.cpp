#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int ptr = 0;
    vector<int> answer;
    while (ptr < progresses.size()) {
        int cnt = 0;
        while(progresses[ptr] >= 100) {
            cnt++;
            ptr++;
            if (ptr >= progresses.size())
                break;
        }
        
        if (cnt)
            answer.push_back(cnt);
        
        for (int i = ptr; i < progresses.size(); i++) 
            progresses[i] += speeds[i];
    }
    
    return answer;
}