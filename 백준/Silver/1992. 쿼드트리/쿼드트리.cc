#include <bits/stdc++.h>
using namespace std;

int graph[65][65];

bool check(int row, int col, int num){
    for (int i = row; i < row + num; i++)
        for (int j = col; j < col + num; j++)
            if (graph[i][j] != graph[row][col])
                return false;
    return true;
}

void divide(int row, int col, int num){
    if (check(row, col, num))
        cout << graph[row][col];
    else {
        cout << '(';
        int size = num / 2;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                divide(row + size * i, col + size * j, size);
        cout << ')';
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < n; j++)
            graph[i][j] = input[j] - '0';
    }

    divide(0, 0, n);

    return 0;
}