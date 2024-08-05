#include <iostream>
#include <vector>
using namespace std;

int main() {
    while (1) {
        string str;
        getline(cin, str);

        if (str == ".")
            break;

        vector<char> v;
        bool flag = false;
        for (auto s: str) {
            if (isalpha(s) || s == ' ' || s == '.')
                continue;

            if (s == '(' || s == '[') {
                v.push_back(s);
            } else if (s == ')') {
                if (!v.empty() && v.back() == '(')
                    v.pop_back();
                else {
                    flag = true;
                    break;
                }
            } else if (s == ']') {
                if (!v.empty() && v.back() == '[')
                    v.pop_back();
                else {
                    flag = true;
                    break;
                }
            }
        }
        if (!flag && v.empty())
            cout << "yes\n";
        else
            cout << "no\n";
    }
    return 0;
}