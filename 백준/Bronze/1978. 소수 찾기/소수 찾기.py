N = int(input())
arr = list(map(int, input().split()))
result = 0

for n in arr:
    cnt = 0
    for i in range(1, n + 1):
        if n % i == 0:
            cnt += 1
    if cnt == 2:
        result += 1
        
print(result)