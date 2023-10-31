import sys

input = sys.stdin.readline

n, q = map(int, input().split())
arr = list(map(int, input().split()))
arr = sorted(arr)
for i in range(n - 1):
    arr[i + 1] += arr[i]

for _ in range(q):
    l, r = map(int, input().split())
    if l == 1:
        print(arr[r - 1])
    else:
        print(arr[r - 1] - arr[l - 2])