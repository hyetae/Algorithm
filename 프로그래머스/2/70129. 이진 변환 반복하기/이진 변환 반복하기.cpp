#include <bits/stdc++.h>
using namespace std;

string change(int size) {
    string res = "";
    while (size) {
        res += to_string(size % 2);
        size /= 2;
    }
    
    reverse(res.begin(), res.end());
    return res;
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while (true) {
        if (s == "1")
            break;
        
        answer[0]++;
        string str = "";
        for (char c: s) {
            if (c == '1')
                str += '1';
            else
                answer[1]++;
        }
        s = change(str.size());
    }
    return answer;
}