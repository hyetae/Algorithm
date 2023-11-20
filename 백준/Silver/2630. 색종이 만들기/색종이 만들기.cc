#include <bits/stdc++.h>

using namespace std;

int res[2] = {0,};
int graph[128][128];

bool check(int row, int col, int num){
    for(int i = row; i < row + num; i++)
        for(int j = col; j < col + num; j++)
            if(graph[row][col] != graph[i][j])
                return false;
    return true;
}

void divide(int row, int col, int num){
    if(check(row, col, num)) 
        res[graph[row][col]]++;
    else {
        int new_num = num / 2;
        for(int i = 0; i < 2; i++)
            for(int j = 0; j < 2; j++)
                divide(row + new_num * i, col + new_num * j, new_num);
    }
}

int main(){
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> graph[i][j];

    divide(0, 0, n);

    for(auto &x: res)
        cout << x << '\n';

    return 0;
}