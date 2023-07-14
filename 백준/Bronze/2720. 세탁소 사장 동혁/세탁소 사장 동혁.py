t = int(input())
lst = [25, 10, 5, 1]

for _ in range(t):
    change = int(input())
    for i in lst:
        print(change // i, end = ' ')
        change %= i