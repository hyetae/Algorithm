n = int(input())
p = [0] + list(map(int, input().split()))

arr = [0] + [10001] * (n)
for i in range(1, n + 1):
    for j in range(1, i + 1):
        arr[i] = min(arr[i], arr[i - j] + p[j])
        
print(arr[-1])