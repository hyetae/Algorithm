n = int(input())
store = set(map(int, input().split()))

m = int(input())
guest = list(map(int, input().split()))

for i in guest:
  if i in store:
    print('yes', end=' ')
  else:
    print('no', end=' ')