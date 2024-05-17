#include <bits/stdc++.h>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    int a = 1, b = 1;
    unordered_map<string, int> m;
    m[words[0]] = 0;
    
    for (int i = 1; i < words.size(); i++) {
        a = i % n + 1;
        if (a == 1)
            b++;
        if (m.find(words[i]) != m.end())
            return {a, b};
        else {
            if (words[i - 1].back() != words[i].front())
                return {a, b};
            m[words[i]] = 0;
        }
    }
    return {0, 0};
}