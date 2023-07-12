lst = []
for _ in range(9):
    lst.append(int(input()))
mx = max(lst)
print(mx, lst.index(mx) + 1, sep = '\n')