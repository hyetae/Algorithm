a1, a2 = map(int, input().split())
c = int(input())
n0 = int(input())

f = a1 * n0 + a2
g = c * n0

print(1) if g >= f and c >= a1 else print(0)