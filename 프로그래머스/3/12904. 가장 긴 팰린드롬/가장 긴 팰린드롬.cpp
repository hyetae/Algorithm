#include <iostream>
#include <string>
using namespace std;

bool slidingWindow(string& s, int len, int start) {
    if (len == 1)
        return true;

    int mid = start + len / 2;
    int end = start + len - 1;

    while (start <= mid)
        if (s[start++] != s[end--])
            return false;
    return true;
}

int solution(string s) {
    int sz = s.size();
    for (int i = sz; i >= 0; i--) {
        for (int j = 0; j < sz; j++) {
            if (i + j > sz)
                break;
            if (slidingWindow(s, i, j))
                return i;
        }
    }
    return 1;
}