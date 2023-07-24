s = list(input())
alpha = 'abcdefghijklmnopqrstuvwxyz'

dic = dict.fromkeys(alpha)
for i in s:
    if dic[i] == None:
        dic[i] = 1
    else: dic[i] += 1

for i in alpha:
    if dic[i] == None:
        print(0, end = ' ')
    else:
        print(dic[i], end = ' ')