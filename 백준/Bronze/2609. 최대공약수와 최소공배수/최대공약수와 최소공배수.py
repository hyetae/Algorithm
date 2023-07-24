import sys
input = sys.stdin.readline

a, b = map(int, input().split())

def gcd(a, b):
    while b > 0:
        a, b = b, a % b
    return a

def lcm(a, b, c):
    return a * b // gcd(a, b)

g = gcd(max(a, b), min(a, b))
l = lcm(max(a, b), min(a, b), g)
print(g)
print(l)