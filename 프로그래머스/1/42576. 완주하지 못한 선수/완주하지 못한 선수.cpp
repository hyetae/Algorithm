#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> marathon;
    for (string p: participant) {
        if (marathon.find(p) == marathon.end()) 
             marathon[p] = 1;
        else
            marathon[p]++;
    }
    for (string c: completion)
        marathon[c]--;
    
    for (auto m: marathon)
        if (m.second)
            return m.first;
    
    return "";
}