#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
}

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), cmp);
    
    int i = 0, j = 1;
    int answer = routes.size();
    while (j < routes.size()) {
        
        if (routes[i][1] >= routes[j][0])
            answer--;
        else
            i = j;
        j++;
    }
    return answer;
}