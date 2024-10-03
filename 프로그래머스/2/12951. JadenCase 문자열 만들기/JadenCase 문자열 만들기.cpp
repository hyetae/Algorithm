#include <string>
#include <vector>

using namespace std;

string solution(string str) {
    string answer = "";
    bool isFirst = true;
    for (char s: str) {
        if (s == ' ') {
            isFirst = true;
            answer += ' ';
        } else if (isFirst) {
            if ('a' <= s && 'z' >= s)
                answer += toupper(s);
            else answer += s;
            isFirst = false;
        } else {
            if ('A' <= s && 'Z' >= s)
                answer += tolower(s);
            else answer += s;
        }
    }
    return answer;
}