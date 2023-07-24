n = int(input())
post = str(input())

st = []
num = []
dic = {}
cnt = 1
for _ in range(n):
    num.append(int(input()))
    
dic[post[0]] = num[0]
for i in post:
    if 'A' <= i <= 'Z':
        if i in dic:
            st.append(dic[i])
        else:
            dic[i] = num[cnt]
            st.append(dic[i])
            cnt += 1
    else:
        num2 = st.pop()
        num1 = st.pop()
        if i == '+':
            st.append(num1 + num2)
        elif i == '-':
            st.append(num1 - num2)
        elif i == '*':
            st.append(num1 * num2)
        elif i == '/':
            st.append(num1 / num2)
            
print('%0.2f' %st[-1])