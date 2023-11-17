for _ in range(int(input())):
    stack = []
    VPS = True
    line = str(input())
    
    for i in line:
        if i == '(':
            stack.append('(')
        elif i == ')':
            if stack:
                stack.pop()
            elif not stack:
                VPS = False
                break
    
    if not stack and VPS:
        print('YES') 
    else: print('NO')