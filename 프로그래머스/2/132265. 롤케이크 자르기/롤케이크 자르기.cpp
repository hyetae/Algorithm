#include <bits/stdc++.h>
using namespace std;

void push(unordered_map<int, int> &m, int tp) {
    if (m.find(tp) == m.end())
            m[tp] = 1;
    else 
        m[tp]++;
}

void pop(unordered_map<int, int> &m, int tp) {
    m[tp]--;
    if (!m[tp])
        m.erase(tp);
}

bool isValid(unordered_map<int, int> &m1, unordered_map<int, int> &m2) {
    if (m1.size() == m2.size())
        return true;
    return false;
}

int solution(vector<int> topping) {
    unordered_map<int, int> m1, m2;
    m1[topping[0]] =1;
    for (int i = 1; i < topping.size(); i++) 
        push(m2, topping[i]);
    
    int cnt = 0;
    if (isValid(m1, m2))
        cnt++;
    
    for (int i = 1; i < topping.size(); i++) {
        push(m1, topping[i]);
        pop(m2, topping[i]);
        if (isValid(m1, m2))
            cnt++;
    }
    
    return cnt;
}