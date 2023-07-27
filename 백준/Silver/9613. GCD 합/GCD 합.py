def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

t = int(input())

for _ in range(t):
    sum = 0
    arr = list(map(int, input().split()))
    for i in range(1, arr[0]):
        for j in range(i + 1, arr[0] + 1):
            sum += gcd(max(arr[i], arr[j]), min(arr[i], arr[j]))
            
    print(sum)