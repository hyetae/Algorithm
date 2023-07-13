big = 0
iloc = 0
jloc = 0

arr = [list(map(int, input().split())) for _ in range(9)]
for i in range(9):
    for j in range(9):
        if arr[i][j] >= big:
            iloc = i + 1
            jloc = j + 1
            big = arr[i][j]

print(big)
print(iloc, jloc)