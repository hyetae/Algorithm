def solution(wallpaper):
    answer = []
    minx = 51
    miny = 51
    maxx = 0
    maxy = 0
    
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if wallpaper[i][j] == '#':
                minx = min(i, minx)
                miny = min(j, miny)
                maxx = max(i, maxx)
                maxy = max(j, maxy)
        
    return [minx, miny, maxx + 1, maxy + 1]