n = int(input())
arr = []
for _ in range(n):
    a, b = map(int, input().split())
    arr.append([a, b])
    
arr = sorted(arr, key = lambda a : a[0])
arr = sorted(arr, key = lambda a : a[1])

m, cnt = 0, 0
for a, b in arr:
    if a >= m:
        cnt += 1
        m = b
        
print(cnt)