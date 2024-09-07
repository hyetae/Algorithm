#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<int> stones, int k) {
    if (stones.size() == 1)
        return stones[0];
    
    int res = 200'000'001;
    deque<pair<int, int>> dq;
    for (int i = 0; i < stones.size(); i++) {
        if (dq.empty()) {
            dq.emplace_back(i, stones[i]);
            continue;
        }

        while(!dq.empty() && dq.back().second < stones[i])
            dq.pop_back();

        dq.emplace_back(i, stones[i]);

        if (!dq.empty() && dq.front().first + k <= i)
            dq.pop_front();

        if (k <= i + 1)
            res = min(res, dq[0].second);
    }

    return res;
}