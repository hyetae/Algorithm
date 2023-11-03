def check(a, b, ine):
    if ine == '<':
        if a < b:
            return True
    if ine == '>':
        if a > b:
            return True
    return False

def dfs(cnt, n):
    if cnt == k + 1:
        result.append(n)
        return
    
    for i in range(10):
        if visited[i]:
            continue
        if cnt == 0 or check(n[cnt - 1], str(i), arr[cnt - 1]):
            visited[i] = 1
            dfs(cnt + 1, n + str(i))
            visited[i] = 0

k = int(input())
arr = list(map(str, input().split()))
visited = [0] * 10
result = []
dfs(0, '')

print(max(result))
print(min(result))