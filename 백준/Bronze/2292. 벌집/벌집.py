N = int(input())

HC = 1
cnt = 1

while N > HC:
    HC += 6 * cnt
    cnt += 1
    
print(cnt)