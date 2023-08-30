n = int(input())
arr = list(map(int, input().split()))

dp = [1] * n
for i in range(1, n):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j] + 1)

cnt = max(dp)
print(cnt)
ans = []
for i in range(n - 1, -1, -1):
    if dp[i] == cnt:
        ans.append(arr[i])
        cnt -= 1
        
ans.sort()
print(*ans)