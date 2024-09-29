#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> dict;
    for (int i = 0; i < priorities.size(); i++)
        dict.push({i, priorities[i]});
    
    vector<int> sorted(priorities.begin(), priorities.end());
    sort(sorted.begin(), sorted.end());
    
    int i = 0, cnt = 0;
    while (true) {
        if (dict.front().second == sorted.back()) {
            cnt++;
            if (dict.front().first == location)
                return cnt;
            dict.pop();
            sorted.pop_back();
        } else {
            dict.push(dict.front());
            dict.pop();
        }
    }
    return 0;
}