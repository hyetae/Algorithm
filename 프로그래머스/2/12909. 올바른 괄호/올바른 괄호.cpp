#include<string>
#include <iostream>

using namespace std;

bool solution(string s){
    int n = 0;
    for (auto str: s) {
        if (str == '(')
            n++;
        else {
            if (n <= 0)
                return false;
            else n--;
        }
    }

    if (n != 0)
        return false;
        
    return true;
}