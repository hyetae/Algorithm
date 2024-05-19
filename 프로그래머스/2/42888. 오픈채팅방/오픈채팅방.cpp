#include <bits/stdc++.h>
using namespace std;

vector<string> word(string str) {
    string w = "";
    vector<string> result;
    for (char c: str) {
        if (c == ' ') {
            result.push_back(w);
            w = "";
        } else w += c;
    }
    result.push_back(w);
    return result;
}

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> name;
    for (string re: record) {
        vector<string> vec = word(re);
        if (vec[0] == "Enter") 
            name[vec[1]] = vec[2];
        else if (vec[0] == "Change") 
            name[vec[1]] = vec[2];
    }
    
    for (string re: record) {
        vector<string> vec = word(re);
        if (vec[0] == "Enter")
            answer.push_back(name[vec[1]] + "님이 들어왔습니다.");
        else if (vec[0] == "Leave") 
            answer.push_back(name[vec[1]] + "님이 나갔습니다.");
    }
    return answer;
}