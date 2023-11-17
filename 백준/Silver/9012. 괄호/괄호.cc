#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    int tc;
    cin >> tc;
    
    while(tc > 0){
        tc--;
        string str;
        cin >> str;
        
        stack<char> st;
        string res = "YES";
        for(auto &c: str){
            if(c == '(')
                st.push(c);
            else if(!st.empty() && c == ')')
                st.pop();
            else {
                res = "NO";
                break;
            }
        }
        if(!st.empty())
            res = "NO";
        
        cout << res << endl;
    }
    return 0;
}