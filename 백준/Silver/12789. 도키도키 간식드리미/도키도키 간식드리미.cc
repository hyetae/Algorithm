#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int num = 1;
    vector<int> vec;
    for (int i = 0; i < N; i++) {
        int n;
        cin >> n;

        vec.push_back(n);
        while (!vec.empty() && vec.back() == num) {
            num++;
            vec.pop_back();
        }
    }

    if (vec.empty())
        cout << "Nice";
    else cout << "Sad";

    return 0;
}