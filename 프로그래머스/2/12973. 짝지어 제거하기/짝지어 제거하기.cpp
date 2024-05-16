#include <bits/stdc++.h>
using namespace std;

int solution(string s) {
    vector<char> vec;
    for (char c: s) {
        if (vec.empty() || vec.back() != c)
            vec.push_back(c);
        else if (vec.back() == c)
            vec.pop_back();
    }
    
    if (vec.empty())
        return 1;
    
    return 0;
}