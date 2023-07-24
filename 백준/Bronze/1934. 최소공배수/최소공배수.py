n = int(input())

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def lcm(a, b):
    return a * b // gcd(a, b)

for _ in range(n):
    a, b = map(int, input().split())
    print(lcm(max(a, b), min(a, b)))