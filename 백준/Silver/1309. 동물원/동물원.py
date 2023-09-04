n = int(input())

dp = [0] * 100001
dp[1] = 3
dp[2] = 7
dp[3] = 17

for i in range(4, 100001):
    dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901
    
print(dp[n])