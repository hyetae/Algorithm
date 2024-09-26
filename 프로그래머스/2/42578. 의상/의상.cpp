#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> closet;
    for (auto& cloth: clothes)
        closet[cloth[1]]++;
    
    for (auto& cloth : closet)
        answer *= cloth.second + 1;
    
    return --answer;
}