A, B = map(int, input().split())
m = int(input())
arr = list(map(int, input().split()))

a = 0
for i in range(m):
    if i == 0:
        a += arr[-1]
    else:
      a += A ** i * arr[-i-1]

answer = []
while a != 0:
    if a % B == 0:
        answer.append(0)
        a //= B
    else:
        answer.append(a % B)
        a //= B

for i in reversed(answer):
    print(i, end = ' ')