#include <iostream>
#define ll long long
using namespace std;

int a, b, c;

ll power(ll n) {
    if (!n)
        return 1;
    if (n == 1)
        return a % c;

    ll d = power(n / 2) % c;

    if (n % 2)
        return d * d % c * a % c;
    return d * d % c;
}

int main() {
    cin >> a >> b >> c;
    cout << power(b);
    return 0;
}