#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    int pnt1 = 0, pnt2 = 0, sum = 0;
    int res = 100000001;
    while(pnt1 <= pnt2){
        if(sum >= s){
            res = min(res, pnt2 - pnt1);
            sum -= arr[pnt1++];
        }
        else if(pnt2 == n)
            break;
        else
            sum += arr[pnt2++];
    }
    
    if(res == 100000001)
        cout << 0;
    else
        cout << res;

    return 0;
}