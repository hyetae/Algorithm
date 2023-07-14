arr = [0] * 3
unix = []
uniy = []
for i in range(3):
    arr[i] = list(map(int, input().split()))
    
for i in range(3):
    if arr[i][0] not in unix:
        unix.append(arr[i][0])
    else: unix.remove(arr[i][0])
    if arr[i][1] not in uniy:
        uniy.append(arr[i][1])
    else: uniy.remove(arr[i][1])
        
print(unix[0], uniy[0])