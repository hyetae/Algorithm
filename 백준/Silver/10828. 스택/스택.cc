#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    stack<int> st;

    for(int i = 0; i < N; i++){
        string input;
        cin >> input;
        if(input == "push"){
            int n;
            cin >> n;
            st.push(n);
        }
        else if(input == "pop"){
            if(st.size() != 0){
                cout << st.top() << endl;
                st.pop();
            }
            else cout << -1 << endl;
        }
        else if(input == "size"){
            cout << st.size() << endl;
        }
        else if(input == "empty"){
            if(st.size() == 0)
                cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if(input == "top"){
            if(st.size() != 0)
                cout << st.top() << endl;
            else cout << -1 << endl;
        }
    }

    return 0;
}