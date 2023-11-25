#include <bits/stdc++.h>
using namespace std;

// 상우하좌
int dx1[4] = {-1, 0, 1, 0};
int dy1[4] = {0, 1, 0, -1};
int dx2[4] = {-1, 1, 1, -1};
int dy2[4] = {1, 1, -1, -1};
int dx3[4] = {-2, 0, 2, 0};
int dy3[4] = {0, 2, 0, -2};

bool bfs(int x, int y, vector<string> places){
    bool check[5] = { false, };

    for (int i = 0; i < 4; i++) {
        int nx = x + dx1[i];
        int ny = y + dy1[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        if (places[nx][ny] == 'P')
            return false;
        if (places[nx][ny] == 'X')
            check[i] = true;
    }

    check[4] = check[0];
    for (int i = 0; i < 4; i++) {
        int nx = x + dx2[i];
        int ny = y + dy2[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        if (places[nx][ny] == 'P') {
            if (check[i] && check[i + 1])
                continue;
            else
                return false;
        }
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + dx3[i];
        int ny = y + dy3[i];

        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
            continue;
        if (places[nx][ny] == 'P') {
            if (check[i])
                continue;
            else
                return false;
        }
    }
    return true;
}

bool loop(vector<string> places){
    for (int i = 0; i < places.size(); i++)
        for (int j = 0; j < places[i].size(); j++)
            if (places[i][j] == 'P')
                if (!bfs(i, j, places))
                    return false;

    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    for (int i = 0; i < places.size(); i++) {
        if (loop(places[i]))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}