n = int(input())

parrot = []
for _ in range(n):
    parrot.append(list(map(str, input().split())))

L = list(map(str, input().split()))

res = 'Possible'
for l in L:
    check1 = False
    for i in parrot:
        if l in i:
            check1 = True
            if l == i[0]:
                i.pop(0)
    if not check1:
        break

check2 = 0
for p in parrot:
    check2 += len(p)

if check1 and not check2:
    print('Possible')
else:
    print('Impossible')