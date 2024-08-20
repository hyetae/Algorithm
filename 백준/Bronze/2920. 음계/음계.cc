#include <iostream>
using namespace std;

int main() {
    string input;
    getline(cin, input);

    string res;
    if (input == "1 2 3 4 5 6 7 8")
        res = "ascending";
    else if (input == "8 7 6 5 4 3 2 1")
        res = "descending";
    else res = "mixed";

    cout << res;

    return 0;
}