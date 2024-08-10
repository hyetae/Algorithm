#include <iostream>
#include <deque>
using namespace std;

deque<string> nums;

void div(const string& str) {
    nums.clear();

    string num = "";
    for (auto c: str) {
        if (c == '[')
            continue;
        if (c == ',' || c == ']') {
            if (!num.empty())
                nums.push_back(num);
            num = "";
        } else num += c;
    }
}

void print(bool isR) {
    cout << '[';

    if (isR) {
        for (auto i = nums.rbegin(); i != nums.rend(); i++) {
            if (i == nums.rend() - 1)
                cout << *i;
            else
                cout << *i << ',';
        }
    } else {
        for (auto i = nums.begin(); i != nums.end(); i++){
            if (i == nums.end() - 1)
                cout << *i;
            else
                cout << *i << ',';
        }
    }

    cout << "]\n";
}

int main() {
    int T, n;
    cin >> T;

    while (T--) {
        string p, arr;
        cin >> p >> n >> arr;

        div(arr);

        bool isR = false;
        bool flag = false;
        for (auto c: p) {


            if (c == 'R')
                isR = !isR;
            else {
                if (nums.empty()) {
                    cout << "error\n";
                    flag = true;
                    break;
                }

                if (isR)
                    nums.pop_back();
                else nums.pop_front();
            }
        }

        if (!flag)
            print(isR);
    }
    return 0;
}