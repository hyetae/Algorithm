arr = [['*'] * 15 for _ in range(5)]

for i in range(5):
    string = str(input())
    for j in range(len(string)):
        arr[i][j] = string[j]

for i in range(15):
    for j in range(5):
        if arr[j][i] != '*':
            print(arr[j][i], end = '')