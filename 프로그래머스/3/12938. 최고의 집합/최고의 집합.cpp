#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    int div = s / n;

    if (!div)
        return {-1};
    
    int remain = s % n > 0 ? s % n : 0;

    for (int i = 0; i < n; i++)
        answer.push_back(div);

    for (int i = n - 1; remain > 0; i--) {
        if (i < 0)
            i = n - 1;
        answer[i]++;
        remain--;
    }

    return answer;
}