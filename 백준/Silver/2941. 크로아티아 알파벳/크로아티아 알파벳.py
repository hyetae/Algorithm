CA = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

S = str(input())

for i in CA:
    S = S.replace(i, '*')

print(len(S))
    