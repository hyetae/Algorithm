top = 1
e = False
stack = []
op = []

for i in range(int(input())):
    n = int(input())
    while top <= n:
        stack.append(top)
        op.append('+')
        top += 1

    if stack[-1] == n:
        stack.pop()
        op.append('-')
    else:
        e = True
        break
        
if e:
    print('NO')
else:
    for i in op:
        print(i)