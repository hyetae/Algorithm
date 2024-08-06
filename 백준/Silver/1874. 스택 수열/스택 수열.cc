#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    int idx = 1;
    vector<char> ops;
    vector<int> nums;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;

        while (idx <= input) {
            ops.push_back('+');
            nums.push_back(idx++);
        }

        if (nums.back() == input) {
            ops.push_back('-');
            nums.pop_back();
        } else {
            cout << "NO";
            return 0;
        }
    }

    for (auto o: ops)
        cout << o << '\n';
    
    return 0;
}