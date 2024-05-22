#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    
    int cnt = 0;
    int first = 0;
    int second = people.size() - 1;
    
    while (first <= second) {
        if (people[first] + people[second] <= limit)
            first++;
        cnt++;
        second--;
    }
    
    return cnt;
}