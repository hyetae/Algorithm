#include <string>
#include <vector>
#include <queue>
using namespace std;

bool isValid(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++){
        if (a[i] != b[i])
            cnt++;
        if (cnt > 1)
            break;
    }
    
    if (cnt == 1)
        return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> visited(words.size(), false);
    queue<pair<string, int>> que;
    que.push({begin, 0});
             
    while (!que.empty()) {
        pair<string, int> cur = que.front();
        que.pop();
        
        if (cur.first == target)
            return cur.second;
        
        for (int i = 0; i < words.size(); i++) {
            if (visited[i])
                continue;
            if (isValid(cur.first, words[i])) {
                que.push({words[i], cur.second + 1});
                visited[i] = true;
            }
        }
    }
    return 0;
}