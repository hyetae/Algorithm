#include <string>
#include <vector>
#include <set>

using namespace std;
int cnt = 0;
bool visited[8];
vector<vector<string>> id_list;
set<set<string>> res;

bool isBanned(string a, string b) {
    if (a.size() != b.size())
        return true;

    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '*' || a[i] == b[i])
            continue;
        else return true;
    }

    return false;
}

void dfs(set<string> id_set, int depth) {
    if (depth == id_list.size()) {
        res.insert(id_set);
        return;
    }
    
    for (auto id: id_list[depth]) {
    // for (int i = 0; i < id_list[depth].size(); i++) {
        if (id_set.find(id) != id_set.end())
            continue;
        
        set<string> tmp = id_set;
        tmp.insert(id);
        dfs(tmp, depth + 1);
    }
    
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for (auto b: banned_id) {
        vector<string> tmp;
        for (auto u: user_id)
            if (!isBanned(b, u))
                tmp.push_back(u);
        id_list.push_back(tmp);
    }
    
    dfs({}, 0);
    return res.size();
}