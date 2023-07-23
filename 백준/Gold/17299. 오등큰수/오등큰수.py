import sys
from collections import Counter
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))

st = [0]
result = [-1] * n
cnt = Counter(arr)

for i in range(1, n):
    while st and cnt[arr[st[-1]]] < cnt[arr[i]]:
        result[st.pop()] = arr[i]
    st.append(i)
        
print(*result)