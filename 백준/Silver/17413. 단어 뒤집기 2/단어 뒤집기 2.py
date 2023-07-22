S = list(str(input()))
S.append(' ')
st = []
check = False
for i in S:
    if i == '<':
        if st:
            for _ in range(len(st)):
                print(st.pop(), end = '')
        check = True
        print(i, end = '')
    elif i == '>':
        check = False
        print(i, end = '')
    elif i == ' ':
        if st:
            for _ in range(len(st)):
                print(st.pop(), end = '')
        print(' ', end = '')
    else:
        if check:
            print(i, end = '')
        else: st.append(i)
            
if st:
    for _ in range(len(st)):
        print(st.pop(), end = '')