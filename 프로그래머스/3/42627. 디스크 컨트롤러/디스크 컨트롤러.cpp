#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    
    int sum = 0;
    int idx = 0;
    int time = 0;
    while (idx < jobs.size() || !pq.empty()) {
        if (jobs.size() > idx && time >= jobs[idx][0]) {
            pq.push(jobs[idx++]);
            continue;
        }
        
        if (pq.empty())
            time = jobs[idx][0];
        else {
            time += pq.top()[1];
            sum += time - pq.top()[0];
            pq.pop();
        }
    }
    return sum / jobs.size();
}