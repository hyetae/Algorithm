A, B, V = map(int, input().split())

day = divmod(V - B, A - B)

print(day[0]) if day[1] == 0 else print(day[0] + 1)