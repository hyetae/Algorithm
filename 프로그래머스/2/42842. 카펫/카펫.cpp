#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int mul = (brown + 4) / 2 - 4;
    
    for (int i = 1; i < mul; i++) {
        int a = i, b = mul - i;
        if (a * b == yellow) {
            if (a >= b) 
                return {a + 2, b + 2};
            else return {b + 2, a + 2};
        }
    }
    
    return {0, 0};
}