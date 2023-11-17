#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[101];
bool visited[101];
int cnt = 0;

void dfs(int i){
    visited[i] = true;
    for(int j = 0; j < graph[i].size(); j++){
        int k = graph[i][j];
        if(!visited[k]){
            dfs(k);
            cnt++;
        }
    }
}

int main(void){
    int n, m;
    cin >> n >> m;

    while(m--){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dfs(1);

    cout << cnt << endl;

    return 0;
}