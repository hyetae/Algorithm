def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

n, s = map(int, input().split())

arr = list(map(int, input().split()))
  
length = []
for i in arr:
    length.append(abs(s - i))
    
answer = length[0]
for i in range(1, n):
    answer = gcd(max(answer, length[i]), min(answer, length[i]))
    
print(answer)