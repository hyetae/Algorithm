#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations) {
    multiset<int, less<int>> ms;

    for (auto op: operations) {
        if (op[0] == 'I') {
            int n = stoi(op.substr(2, op.size() - 2));
            ms.insert(n);
        } else {
            if (ms.empty())
                continue;

            if (op[2] == '1')
                ms.erase(--ms.end());
            else
                ms.erase(ms.begin());
        }
    }

    if (ms.empty())
        return {0, 0};
    return {*(--ms.end()), *ms.begin()};
}