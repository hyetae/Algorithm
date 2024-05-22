#include <bits/stdc++.h>
using namespace std;

int N, cnt;
int board[12][12];

bool isValid(int x, int y) {
    for (int i = 1; i <= x; i++)
        if (x - i >= 0) {
            if (board[x - i][y])
                return true;
            if (y - i >= 0)
                if (board[x - i][y - i])
                    return true;
            if (y + i < N)
                if (board[x - i][y + i])
                    return true;
        }
    
    return false;
}

void backTracking(int x, int y) {
    if (board[x][y] || isValid(x, y))
        return;   
    
    if (x == N -1)
        cnt++;
    
    for (int i = 0; i < N; i++) {
        board[x][y] = 1;
        backTracking(x + 1, i);
        board[x][y] = 0;   
    }
}

int solution(int n) {
    N = n;
    for (int i = 0; i < N; i++)
        backTracking(0, i);
    
    return cnt;
}