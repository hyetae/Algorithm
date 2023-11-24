#include <bits/stdc++.h>
using namespace std;

string num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s) {
    for (int i = 0; i < s.size(); i++){
        if (isdigit(s[i])) {
            cout << "i: " << i << endl;
            continue;
        }
        for (int j = 0; j < 10; j++) {
            if (s.substr(i, num[j].size()) == num[j]) {
                s.replace(i, num[j].size(), to_string(j));
                break;
            }
        }
    }
    return stoi(s);
}