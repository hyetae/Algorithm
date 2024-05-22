#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (auto cmd: commands) {
        vector<int> vec;
        for (int i = cmd[0]; i <= cmd[1]; i++)
            vec.push_back(array[i - 1]);
        sort(vec.begin(), vec.end());
        answer.push_back(vec[cmd[2] - 1]);
    }
    return answer;
}