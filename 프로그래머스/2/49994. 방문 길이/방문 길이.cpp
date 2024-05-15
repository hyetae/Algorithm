#include <bits/stdc++.h>
using namespace std;

map<pair<pair<int, int>, pair<int, int>>, int> m;

void visit(int a, int b, int c, int d) {
    if (m.find({{a, b},{c, d}}) == m.end()
       && m.find({{c, d},{a, b}}) == m.end()) {
        m[{{a, b},{c, d}}] = 1;
        m[{{c, d},{a, b}}] = 1;
    }
    else {
        m[{{a, b},{c, d}}]++;
        m[{{c, d},{a, b}}]++;
    }
}

bool range(int x, int y) {
    if (x < 0 || x > 10 || y < 0 || y > 10)
        return false;
    return true;
}

int solution(string dirs) {
    int x= 5, y = 5;
    for (auto d: dirs) {
        if (d == 'U' && range(x - 1, y))
            visit(x--, y, x, y);
        else if (d == 'D' && range(x + 1, y))
            visit(x++, y, x, y);
        else if (d == 'R' && range(x, y + 1))
            visit(x, y++, x, y);
        else if (d == 'L' && range(x, y - 1))
            visit(x, y--, x, y);
    }
    
    return m.size() / 2;
}