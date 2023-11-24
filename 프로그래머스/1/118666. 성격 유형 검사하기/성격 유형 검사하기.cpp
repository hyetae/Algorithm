#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> m;
    m.insert({'R', 0});
    m.insert({'T', 0});
    m.insert({'C', 0});
    m.insert({'F', 0});
    m.insert({'J', 0});
    m.insert({'M', 0});
    m.insert({'A', 0});
    m.insert({'N', 0});

    for (int i = 0; i < survey.size(); i++){
        if (choices[i] == 1)
            m[survey[i][0]] += 3;
        else if (choices[i] == 2)
            m[survey[i][0]] += 2;
        else if (choices[i] == 3)
            m[survey[i][0]] += 1;
        else if (choices[i] == 4)
            continue;
        else if (choices[i] == 5)
            m[survey[i][1]] += 1;
        else if (choices[i] == 6)
            m[survey[i][1]] += 2;
        else if (choices[i] == 7)
            m[survey[i][1]] += 3;
    }

    if (m['R'] >= m['T'])
        answer.push_back('R');
    else
        answer.push_back('T');
    if (m['C'] >= m['F'])
        answer.push_back('C');
    else
        answer.push_back('F');
    if (m['J'] >= m['M'])
        answer.push_back('J');
    else
        answer.push_back('M');
    if (m['A'] >= m['N'])
        answer.push_back('A');
    else
        answer.push_back('N');
    
    return answer;
}