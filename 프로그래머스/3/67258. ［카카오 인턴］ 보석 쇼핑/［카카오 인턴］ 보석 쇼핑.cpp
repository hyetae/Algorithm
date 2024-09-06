#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {

    vector<int> answer;
    map<string, int> isGotten;

    int num = 0;
    int pt1 = 0;
    int pt2 = 0;
    int res = 1e9;
    int size = gems.size();

    for (int i = 0; i < size; i++) {
        int &gem1 = isGotten[gems[i]];
        gem1++;
        pt2 = i;

        if (gem1 == 1) {
            num++;
            answer = {pt1, pt2};
        } else {
            for (int j = pt1; j < i; j++) {
                int &gem2 = isGotten[gems[j]];
                if (gem2 > 1)
                    gem2--;
                else {
                    pt1 = j;
                    if ((pt2 - pt1) < (answer[1] - answer[0]))
                        answer = {pt1, pt2};
                    break;
                }
            }
        }
    }

    answer[0]++;
    answer[1]++;
    return answer;
}