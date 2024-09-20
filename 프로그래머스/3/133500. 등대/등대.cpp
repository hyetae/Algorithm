#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int answer;
bool lighted[100'001];
unordered_map<int, vector<int>> graph;

void dfs(int node, int parent) {
    for (auto child: graph[node]) {
        if (child == parent)
            continue;
        
        dfs(child, node);
        
        if (!lighted[child] && !lighted[node]) {
            lighted[node] = true;
            answer++;
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    for (auto lh: lighthouse) {
        graph[lh[0]].push_back(lh[1]);
        graph[lh[1]].push_back(lh[0]);
    }
    
    dfs(1, 1);
    return answer;
}