s = str(input())

arr = [s]
for i in range(1, len(s) - 1):
    arr.append(s[i:])
arr.append(s[-1])
    
arr.sort()
for i in arr:
    print(i)