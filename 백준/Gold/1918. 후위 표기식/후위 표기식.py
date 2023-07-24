infix = list(input())

st = []
result = []
for i in infix:
    if i.isalpha():
        result.append(i)
    else:
        if i == '(':
            st.append(i)
        elif i == '+' or i == '-':
            while st and st[-1] != '(':
                result.append(st.pop())
            st.append(i)
        elif i == '*' or i == '/':
            while st and (st[-1] == '*' or st[-1] == '/'):
                result.append(st.pop())
            st.append(i)
        else:
            while st and st[-1] != '(':
                result.append(st.pop())
            st.pop()

while st:
    result.append(st.pop())
    
for i in result:
    print(i, end = '')