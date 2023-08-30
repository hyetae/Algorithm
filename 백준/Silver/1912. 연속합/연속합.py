n = int(input())
arr = list(map(int, input().split()))

sm = 0
best = arr[0]
for i in range(n):
    sm = max(arr[i], arr[i] + sm)
    best = max(sm, best)
    
print(best)