import sys
sys.setrecursionlimit(10**6)

def dfs(x, y):
    graph[x][y] = 0
    for i in range(8):
        nx = x + dx[i]
        ny = y + dy[i]
        if -1 < nx < h and -1 < ny < w and graph[nx][ny] == 1:
            dfs(nx, ny)

while True:
    w, h = map(int, input().split())
    if w == 0 and h == 0:
        break
        
    graph = []   
    for _ in range(h):
        graph.append(list(map(int, input().split())))
        
    res = 0
    dx = [-1, -1, -1, 0, 0, 1, 1, 1]
    dy = [-1, 0, 1, -1, 1, -1, 0, 1]
    for i in range(h):
        for j in range(w):
            if graph[i][j] == 1:
                dfs(i, j)
                res += 1
    print(res)
        