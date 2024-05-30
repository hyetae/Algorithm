#include <bits/stdc++.h>
using namespace std;

map<string, int> profit;
map<string, string> parent;

void calc(string name, int money) {
    if (money < 1 || name == "-")
        return;
    
    int ten = money / 10;
    profit[name] += money - ten;
    calc(parent[name], ten);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    
    for (int i = 0; i < enroll.size(); i++) {
        profit[enroll[i]] = 0;
        parent[enroll[i]] = referral[i];
    }
    
    for (int i = 0; i < seller.size(); i++)
        calc(seller[i], amount[i] * 100);
    
    vector<int> answer;
    for (string en: enroll)
        answer.push_back(profit[en]);
    
    return answer;
}