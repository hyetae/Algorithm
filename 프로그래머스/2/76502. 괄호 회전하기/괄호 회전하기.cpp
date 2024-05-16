#include <bits/stdc++.h>
using namespace std;

bool isValid() {
    
}

int solution(string s) {
    vector<char> vec;
    unordered_map<char, char> m = {{']', '['}, {')', '('}, {'}', '{'}};

    int flag;
    int answer = 0;
    for (int i = 0; i < s.size(); i++) {
        s.append(s.substr(0, 1));
        s.erase(0, 1);
        
        flag = 1;
        for (char c: s) {
            if (c == '[' || c == '(' || c == '{')
                vec.push_back(c);
            else {
                if (vec.empty()) {
                    flag = 0;
                    break;
                }
                if (vec.back() == m[c])
                    vec.pop_back();
                else {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag && vec.empty())
            answer++;
    }
    
    return answer;
}