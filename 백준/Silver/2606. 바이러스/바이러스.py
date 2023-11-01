def dfs(v):
    visited[v] = 1
    for nx in graph[v]:
        if visited[nx] == 0:
            dfs(nx)

n = int(input())
m = int(input())

graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a] += [b]
    graph[b] += [a]

dfs(1)
print(sum(visited) - 1)