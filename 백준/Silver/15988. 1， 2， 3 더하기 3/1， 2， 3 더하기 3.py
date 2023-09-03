import sys
input = sys.stdin.readline

MAX = 1000001
dp = [0] * MAX
dp[1] = 1
dp[2] = 2
dp[3] = 4

for i in range(4, MAX):
    dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % 1000000009
    
for _ in range(int(input())):
    n = int(input())
    print(dp[n])