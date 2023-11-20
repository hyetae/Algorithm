#include "bits/stdc++.h"
using namespace std;

int result[3];
int paper[2187][2187];

bool check(int row, int col, int num){
    int start = paper[row][col];
    for (int i = row; i < row + num; i++)
        for (int j = col; j < col + num; j++)
            if (start != paper[i][j])
                return false;
    return true;
}

void divide(int row, int col, int num){
    if (check(row, col, num))
        result[paper[row][col]]++;
    else{
        int size = num / 3;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                divide(row + size * i, col + size * j, size);
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            int input;
            scanf("%d", &input);
            input++;
            paper[i][j] = input;
        }

    divide(0, 0, n);
    for (auto &x: result)
        cout << x << '\n';
    return 0;
}