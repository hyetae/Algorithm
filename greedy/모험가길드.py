n = int(input())
array = list(map(int, input().split()))
array.sort()

count = 0
result = 0
for i in array:
  count += 1
  if count <= i:
    result += 1
  else:
    continue

print(result)