def binary_search(array, target, start, end):
  while start <= end:
    mid = (start + end)//2
    if array[mid] == target:
      return mid
    elif array[mid] > target:
      end = mid - 1
    else:
      start = mid + 1
      
  return None

n = int(input())
store = list(map(int, input().split()))
store.sort()

m = int(input())
guest = list(map(int, input().split()))
guest.sort()

for i in guest:
  result = binary_search(store,i,0,n-1)
  if result != None:
    print('yes', end=' ')
  else:
    print('no', end=' ')