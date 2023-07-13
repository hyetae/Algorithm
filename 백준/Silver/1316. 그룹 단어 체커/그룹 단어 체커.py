n = int(input())

cnt = 0
for _ in range(n):
    uni = []
    s = str(input())
    uni.append(s[0])
    
    for i in range(len(s) - 1):
        if s[i] != s[i + 1]:
            if s[i + 1] in uni:
                cnt += 1
                break
            else: uni.append(s[i + 1])
        else: continue
            
print(n - cnt)