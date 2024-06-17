#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int ss;
int nmonth[50];
int graph[50][50];
unordered_map<string, int> ntoi;
unordered_map<int, int> score;

void calc() {
    for (int i = 0; i < ss; i++) {
        int sum = 0;
        for (int j = 0; j < ss; j++) {
            if (i == j)
                continue;
            sum += graph[i][j] - graph[j][i];
        }
        score[i] = sum;
    }
}

vector<string> divide(string str) {
    string tmp = "";
    vector<string> res;
    for (auto s: str) {
        if (s == ' ') {
            res.push_back(tmp);
            tmp = "";
        } else tmp += s;
    }
    res.push_back(tmp);
    return res;
}

int answer() {
    int res = -1;
    for (int i = 0; i < ss; i++)
        res = max(res, nmonth[i]);
    return res;
}

int solution(vector<string> friends, vector<string> gifts) {
    ss = friends.size();

    for (int i = 0; i < ss; i++)
        ntoi[friends[i]] = i;

    for (auto g: gifts) {
        vector<string> names = divide(g);
        graph[ntoi[names.front()]][ntoi[names.back()]]++;
    }

    calc();

    for (int i = 0; i < ss; i++) {
        for (int j = i + 1; j < ss; j++) {
            if (i == j)
                continue;

            if (graph[i][j] < graph[j][i])
                nmonth[j]++;
            else if (graph[i][j] > graph[j][i])
                nmonth[i]++;
            else {
                if (score[i] > score[j])
                    nmonth[i]++;
                else if (score[i] < score[j])
                    nmonth[j]++;
            }
        }
    }
    return answer();
}

