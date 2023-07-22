N, K = map(int, input().split())

st1 = []
st2 = []
for i in range(1, N + 1):
    st1.append(i)

i = 0
for _ in range(N):
    i += K - 1
    if i >= len(st1):
        i %= len(st1)
    st2.append(str(st1.pop(i)))

print('<', ', '.join(st2), '>', sep = '')