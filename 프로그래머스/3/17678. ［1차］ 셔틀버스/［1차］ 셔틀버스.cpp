#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ttoi(string time) {
    return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}

string ttos(int time) {
    int h = time / 60;
    int m = time % 60;

    string str = "";
    if (h < 10)
        str += '0' + to_string(h);
    else str += to_string(h);
    str += ':';
    if (m < 10)
        str += '0' + to_string(m);
    else str += to_string(m);

    return str;
}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> busTime;
    vector<int> crewTime;

    busTime.push_back(ttoi("09:00"));
    for (int i = 1; i < n; i++)
        busTime.push_back(busTime.back() + t);

    for (auto tt: timetable)
        crewTime.push_back(ttoi(tt));
    sort(crewTime.begin(), crewTime.end());

    int bpt = 0, cpt = 0;
    while (bpt != n - 1) {
        for (int i = 0; i < m; i++)
            if (crewTime[cpt] <= busTime[bpt])
                cpt++;
        bpt++;
    }

    if (crewTime.size() - cpt >= m && crewTime[cpt + m - 1] <= busTime[bpt])
        return ttos(crewTime[cpt + m - 1] - 1);
    else return ttos(busTime[n - 1]);
}