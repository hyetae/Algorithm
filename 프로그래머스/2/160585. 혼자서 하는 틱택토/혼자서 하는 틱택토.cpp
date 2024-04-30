#include <bits/stdc++.h>
using namespace std;

int winO = 0;
int winX = 0;

void isWin(char a, char b, char c) {
    if (a == b && b == c) {
        if (a == 'O')
            winO++;
        if (b == 'X')
            winX++;
    }
}

int solution(vector<string> board) {
    int numO = 0;
    int numX = 0;
    
    isWin(board[0][0], board[1][1], board[2][2]);
    isWin(board[0][2], board[1][1], board[2][0]);
    
    for (int i = 0; i < 3; i++) {
        isWin(board[i][0], board[i][1], board[i][2]);
        isWin(board[0][i], board[1][i], board[2][i]);
        
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == 'O')
                numO++;
            if (board[j][i] == 'X')
                numX++;
        }
    }
    
    if (numX > numO || numO > numX + 1 || (winO && winX))
        return 0;
    
    if ((winO && numO != numX + 1) || (winX && numO != numX))
        return 0;
    
    return 1;
}