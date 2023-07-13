S = input().upper()
uni = list(set(S))

dic = dict.fromkeys(uni, 0)

for i in S:
    dic[i] += 1
    
m = [k for k,v in dic.items() if max(dic.values()) == v]
if len(m) > 1:
    print('?')
else: print(m[0])