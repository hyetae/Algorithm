#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    vector<int> vec;
    string integer = "";
    for (auto str: s) {
        if (str == ' ') {
            vec.push_back(stoi(integer));
            integer = "";
            continue;
        }
        integer += str;
    }
    vec.push_back(stoi(integer));
    
    string answer = "";
    
    sort(vec.begin(), vec.end());
    answer += to_string(vec.front());
    answer += ' ';
    answer += to_string(vec.back());
    
    return answer;
}