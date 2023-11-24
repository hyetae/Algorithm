#include <bits/stdc++.h>
using namespace std;

int len;

int addIndex(int idx) {
    return idx + 1 >= 2 * len ? 0 : idx + 1; // 인덱스가 배열의 크기 넘어가면 맨 앞으로
}

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);

    len = queue1.size();
    queue1.insert(queue1.end(), queue2.begin(), queue2.end());

    int sp1 = 0, ep1 = len - 1;
    int sp2 = len, ep2 = 2 * len - 1;

    while(answer <= 4 * len){
        if (sum1 > sum2) {
            sum1 -= queue1[sp1];
            sum2 += queue1[sp1];

            sp1 = addIndex(sp1);
            ep2 = addIndex(ep2);
        } else if (sum1 < sum2) {
            sum1 += queue1[sp2];
            sum2 -= queue1[sp2];

            sp2 = addIndex(sp2);
            ep1 = addIndex(ep1);
        } else {
            return answer;
        }
        answer++;
    }
    return -1;
}