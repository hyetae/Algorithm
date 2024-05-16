#include <bits/stdc++.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    vector<vector<int>> new_board;
    for (int i = 0; i < board.size(); i++) {
        vector<int> tmp;
        for (int j = board.size() - 1; j >= 0; j--) 
            if (board[j][i])
                tmp.push_back(board[j][i]);
        new_board.push_back(tmp);
    }
    
    int cnt = 0;
    vector<int> vec;
    for (int move: moves) {
        if (vec.empty()) {
            vec.push_back(new_board[move - 1].back());
            new_board[move - 1].pop_back();
            continue;
        }
        
        if (!new_board[move - 1].empty() && vec.back() != new_board[move - 1].back()) {
            vec.push_back(new_board[move - 1].back());
            new_board[move - 1].pop_back();
            continue;
        }
        
        if (!new_board[move - 1].empty() && vec.back() == new_board[move - 1].back()) {
            cnt += 2;
            vec.pop_back();
            new_board[move - 1].pop_back();
        }
    }
    return cnt;
}