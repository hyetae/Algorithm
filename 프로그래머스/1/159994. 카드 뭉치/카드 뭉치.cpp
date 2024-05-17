#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> cd1, cd2;
    for (string c: cards1)
        cd1.push(c);
    for (string c: cards2)
        cd2.push(c);
    
    int i = 0;
    while (i < goal.size()) {
        if (!cd1.empty() && cd1.front() == goal[i])
            cd1.pop();
        else if (!cd2.empty() && cd2.front() == goal[i])
            cd2.pop();
        else 
            return "No";
        i++;
    }

    return "Yes";
}