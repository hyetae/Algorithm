#include <string>
#include <vector>
#include <queue>
using namespace std;

long long calc(vector<int>& works) {
    long long res = 0;
    for (auto w: works) {
        if (!w)
            continue;
        res += w * w;
    }
    return res;
}

long long solution(int n, vector<int> works) {
    priority_queue<int> pq;
    for (auto w: works)
        pq.push(w);
    
    while (n--) {
        int top = pq.top();
        pq.pop();
        pq.push(top - 1);
    }
    
    long long answer = 0;
    while (!pq.empty()) {
        int top = pq.top();
        if (top > 0)
            answer += top * top;
        pq.pop();
    }
    
    return answer;
}