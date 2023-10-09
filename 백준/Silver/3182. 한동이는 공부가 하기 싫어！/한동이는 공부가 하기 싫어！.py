def dfs(v, cnt):
    visited[v] = True
    if not visited[graph[v][0]]:
        cnt = dfs(graph[v][0], cnt + 1)
    return cnt
    
n = int(input())
graph = [[] for _ in range(n + 1)]
res = [0] * (n + 1)

for i in range(1, n + 1):
    graph[i].append(int(input()))

for i in range(1, n + 1):
    visited = [False] * (n + 1)
    res[i] = dfs(i, 1)

print(res.index(max(res)))