n = int(input())
dp = [i for i in range(n + 1)]

for i in range(1, n + 1):
    for j in range(1, i):
        if i < j ** 2:
            break
        if dp[i] > dp[i - j ** 2] + 1:
            dp[i] = dp[i - j ** 2] + 1
            
print(dp[n])