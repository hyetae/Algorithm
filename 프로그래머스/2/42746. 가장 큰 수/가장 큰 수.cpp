#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strings;
    for (int n: numbers) 
        strings.push_back(to_string(n));
    
    sort(strings.begin(), strings.end(), cmp);
    
    for (auto s: strings) 
        answer += s;
    
    return answer[0] == '0' ? "0": answer;
}