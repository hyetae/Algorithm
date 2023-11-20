#include "bits/stdc++.h"

using namespace std;

int n, x, num;
int mini = INT_MAX;
int maxi = INT_MIN;
priority_queue<int, vector<int>> mq;
priority_queue<int, vector<int>, greater<int>> pq;

int main(){
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x;
        // 0, 큐가 비었을 때
        if(!x && mq.empty() && pq.empty())
            cout << 0 << '\n';
        // 0, 큐가 안 비었을 때
        if(!x && (!mq.empty() || !pq.empty())){
            if(!mq.empty() && !pq.empty()){
                maxi = mq.top();
                mini = pq.top();
                if(-maxi <= mini) {
                    num = maxi;
                    mq.pop();
                } else {
                    num = mini;
                    pq.pop();
                }
            } else if(!pq.empty() && mq.empty()){
                num = pq.top();
                pq.pop();
            } else if(pq.empty() && !mq.empty()){
                num = mq.top();
                mq.pop();
            }
            cout << num << '\n';
        }
        // 0이 아닐 때
        if(x > 0)
            pq.push(x);
        else if (x < 0)
            mq.push(x);
    }
    return 0;
}