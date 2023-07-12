blk = [1, 1, 2, 2, 2, 8]
wht = list(map(int, input().split()))

for i in range(6):
    print(blk[i] - wht[i], end = ' ')