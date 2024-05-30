#include <bits/stdc++.h>
using namespace std;

vector<string> detach(string str) {
    vector<string> names;
    string name = "";
    for (char c: str) {
        if (c == ' ') {
            names.push_back(name);
            name = "";
        }
        else name += c;
    }
    names.push_back(name);
    return names;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    map<string, int> idx_map;
    map<string, int> cnt_map;
    map<string, unordered_set<string>> rpt_map;
    
    for (int i = 0; i < id_list.size(); i++) {
        idx_map[id_list[i]] = i;
        cnt_map[id_list[i]] = 0;
    }
    
    for (string re: report) {
        vector<string> names = detach(re);
        if (rpt_map[names[1]].insert(names[0]).second)
            cnt_map[names[1]]++;
    }
    
    vector<int> answer(id_list.size(), 0);
    for (string id: id_list)
        if (cnt_map[id] >= k)
            for (auto itr = rpt_map[id].begin(); itr != rpt_map[id].end(); itr++)
                answer[idx_map[*itr]]++;
    
    return answer;
}