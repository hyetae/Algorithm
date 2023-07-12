N, M = map(int, input().split())
basket = [n for n in range(N + 1)]

for n in range(M):
    i, j = map(int, input().split())
    basket[i], basket[j] = basket[j], basket[i]

for n in range(1, N + 1):
    print(basket[n], end = ' ')