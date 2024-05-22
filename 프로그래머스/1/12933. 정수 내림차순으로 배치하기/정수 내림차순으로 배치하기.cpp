#include <bits/stdc++.h>
using namespace std;

long long solution(long long n) {
    priority_queue<int> pq;
    string str = to_string(n);
    for (char c: str) 
        pq.push(c - '0');
    
    long long answer = 0;
    while (!pq.empty()) {
        answer = answer * 10 + pq.top();
        pq.pop();
    }
    return answer;
}