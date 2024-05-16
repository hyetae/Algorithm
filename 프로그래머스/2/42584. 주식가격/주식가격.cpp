#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    vector<int> vec;
    
    for (int i = 0; i < prices.size(); i++) {
        while (!vec.empty() && prices[vec.back()] > prices[i]) {
            answer[vec.back()] = i - vec.back();
            vec.pop_back();
        }
        vec.push_back(i); 
    }
    
    while (!vec.empty()) {
        answer[vec.back()] = prices.size() - vec.back() - 1;
        vec.pop_back();
    }
    
    return answer;
}