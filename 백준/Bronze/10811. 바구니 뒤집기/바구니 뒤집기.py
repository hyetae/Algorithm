N, M = map(int, input().split())
lst = [n for n in range(1, N + 1)]

for _ in range(M):
    i, j = map(int, input().split())
    tmp = lst[i - 1:j]
    tmp.reverse()
    lst[i - 1:j] = tmp
        
for n in lst:
    print(n, end = ' ')