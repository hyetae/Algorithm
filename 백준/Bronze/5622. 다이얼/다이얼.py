S = str(input())

dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
time = 0

for i in S:
    for j in dial:
        if i in j:
            time += dial.index(j) + 3
            
print(time)