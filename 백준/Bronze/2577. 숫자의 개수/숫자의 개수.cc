#include <iostream>
using namespace std;

int arr[10];

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string res = to_string(a * b * c);

    for (char r: res)
        arr[r - '0']++;

    for (int a: arr)
        cout << a << '\n';

    return 0;
}