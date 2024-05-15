#include <bits/stdc++.h>
using namespace std;

int sp1[5] = {1, 2, 3, 4, 5};
int sp2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
int sp3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};

vector<int> solution(vector<int> answers) {
    int arr[3] = {0, 0, 0};
    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == sp1[i % 5])
            arr[0]++;
        if (answers[i] == sp2[i % 8])
            arr[1]++;
        if (answers[i] == sp3[i % 10])
            arr[2]++;
    }
    
    vector<int> answer;
    int maxi = max(max(arr[0], arr[1]), arr[2]);
    for (int i = 0; i < 3; i++)
        if (arr[i] == maxi)
            answer.push_back(i + 1);
    
    return answer;
}