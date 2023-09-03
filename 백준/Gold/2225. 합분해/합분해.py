n, k = map(int, input().split())

dp = [[1 for _ in range(k)] for _ in range(n)]

for i in range(k):
    dp[0][i] += i
    
for i in range(1, n):
    for j in range(1, k):
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        
print(dp[-1][-1] % 1000000000)