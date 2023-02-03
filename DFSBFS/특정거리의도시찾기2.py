from collections import deque

n,m,k,x = map(int, input().split())
# m -> n+1
graph = [[] for _ in range(n+1)]

for _ in range(m):
  a,b = map(int, input().split())
  graph[a].append(b)

distance = [-1]*(n+1)
distance[x] = 0
q = deque([x])

while q:
  now = q.popleft()
  # q.append(i)는 여기가 아니라 거리 갱신하고!
  for i in graph[now]:
    if distance[i] == -1:
      distance[i] = distance[now] + 1
      q.append(i)

count = 0
# in distance -> in range(1, n+1)
for i in range(1, n+1):
  if distance[i] == k:
    count += 1
    print(i)

if count == 0:
  print("-1")
    