s = list(input())

st = []
stick = 0
for i in range(len(s)):
    if s[i] == '(':
        st.append('(')
    else:
        if s[i - 1] == '(':
            st.pop()
            stick += len(st)
        else:
            st.pop()
            stick += 1
                
print(stick)