#include <iostream>
#include <vector>
using namespace std;

int weight[1'000];

int main() {

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> weight[i];

    sort(weight, weight + N);

    int sum = 1;
    for (int i = 0; i < N; i++) {
        if (weight[i] > sum)
            break;
        sum += weight[i];
    }

    cout << sum;
}