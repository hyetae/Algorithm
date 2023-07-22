import sys
input = sys.stdin.readline

string = list(input().rstrip())
stack = []

for _ in range(int(input())):
    cmd = list(map(str, input().split()))
    
    if cmd[0] == 'L':
        if string:
            stack.append(string.pop())
            
    elif cmd[0] == 'D':
        if stack:
            string.append(stack.pop())
            
    elif cmd[0] == 'B':
        if string:
            string.pop()
    else:
        string.append(cmd[1])
        
string.extend(reversed(stack))
print(''.join(string))