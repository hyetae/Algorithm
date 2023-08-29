arr = []
for _ in range(9):
    arr.append(int(input()))

check = False
sm = sum(arr)
for i in range(8):
    for j in range(1, 9):
        if sm - (arr[i] + arr[j]) == 100:
            del arr[j]
            del arr[i]
            check = True
            break
    if check:
        break
            
arr.sort()
for i in arr:
    print(i)