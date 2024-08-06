#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 101;
int item[MAX];
int dist[MAX][MAX];

int main() {

    int n, m, r;
    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++)
        for (int j = 1 ; j <= n; j++)
            if (i != j)
                dist[i][j] = 1e9;

    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 0; i < r; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int maxi = 0;
    for (int i = 1; i <=n; i++) {
        int sum = item[i];
        for (int j = 1; j <= n; j++)
            if (i != j && dist[i][j] <= m)
                sum += item[j];
        maxi = max(maxi, sum);
    }

    cout << maxi;
    return 0;
}