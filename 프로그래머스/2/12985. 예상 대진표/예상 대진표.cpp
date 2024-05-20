#include <bits/stdc++.h>
using namespace std;

int solution(int n, int a, int b) {
    float A = a, B = b;
    if (A > B)
        swap (A, B);

    int cnt = 1;
    while (true) {
        if (fmod(A, 2) == 1 && A == B - 1)
            return cnt;
        A = ceil(A / 2);
        B = ceil(B / 2);
        cnt++;
    }
    return cnt;
}