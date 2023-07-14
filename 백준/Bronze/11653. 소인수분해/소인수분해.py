N = int(input())

M = 2
while True:
    if N == 1:
        break
    if N % M == 0:
        N /= M
        print(M)
    elif N == M:
        break
    else:
        M += 1