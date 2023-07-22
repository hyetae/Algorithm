import sys
input = sys.stdin.readline

deq = []
for _ in range(int(input())):
    cmd = list(input().split())
    
    if cmd[0] == 'push_front':
        deq.insert(0, cmd[1])
    elif cmd[0] == 'push_back':
        deq.append(cmd[1])
    elif cmd[0] == 'pop_front':
        if deq: print(deq.pop(0))
        else: print(-1)
    elif cmd[0] == 'pop_back':
        if deq: print(deq.pop())
        else: print(-1)
    elif cmd[0] == 'size':
        print(len(deq))
    elif cmd[0] == 'empty':
        if deq: print(0)
        else: print(1)
    elif cmd[0] == 'front':
        if deq: print(deq[0])
        else: print(-1)
    else:
        if deq: print(deq[len(deq) - 1])
        else: print(-1)