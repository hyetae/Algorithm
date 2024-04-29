#include <bits/stdc++.h>

using namespace std;

struct Plan {
    string name;
    int start;
    int playTime;
};

bool cmp(Plan a, Plan b) {
    return a.start < b.start;
}

vector<string> answer;
vector<Plan> newPlans;
vector<Plan> waiting;
int currentT;

void solve(Plan &a, Plan &b) {
    currentT = currentT < a.start ? a.start : currentT;
    if (currentT + a.playTime <= b.start){
        answer.push_back(a.name);
        currentT = currentT + a.playTime;
    } else {
        a.playTime -= (b.start - currentT);
        waiting.push_back(a);
        currentT = b.start;
    }
}

vector<string> solution(vector<vector<string>> plans) {
    // Plan 객체로 변경
    for (auto p: plans) {
        Plan plan;
        plan.name = p[0];
        plan.start = stoi(p[1].substr(0, 2)) * 60 + stoi(p[1].substr(3, 2));
        plan.playTime = stoi(p[2]);
        newPlans.push_back(plan);
    }

    // 시작 시간 빠른 순으로 정렬
    sort(newPlans.begin(), newPlans.end(), cmp);

    currentT = newPlans[0].start;

    // 풀이
    for(int i = 0; i < newPlans.size(); i++) {
        // 대기 과제가 실행 가능할 동안
        while (!waiting.empty() && currentT < newPlans[i].start) {
            Plan waitingP = waiting.back();
            waiting.pop_back();
            solve(waitingP, newPlans[i]);
        }
        // 그외 but 마지막 과제가 아닐 때
        if (i != newPlans.size() - 1)
            solve(newPlans[i], newPlans[i + 1]);
    }

    // 마지막 문제 및 대기 과제
    answer.push_back(newPlans.back().name);
    while (!waiting.empty()) {
        answer.push_back(waiting.back().name);
        waiting.pop_back();
    }

    return answer;
}