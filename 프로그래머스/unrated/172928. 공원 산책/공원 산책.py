def solution(park, routes):
    x = 0
    y = 0
    for i in range(len(park)):
        for j in range(len(park[i])):
            if park[i][j] == 'S':
                x = i
                y = j
                break
            
    for i in routes:
        n = int(i[-1])
        
        for j in range(1, n + 1):
            
            if i[0] == 'N' and x - j > -1 and park[x - j][y] != 'X':
                if j == n: x -= n
                
            elif i[0] == 'S' and x + j < len(park) and park[x + j][y] != 'X':
                if j == n: x += n
                
            elif i[0] == 'W' and y - j > -1 and park[x][y - j] != 'X':
                if j == n: y -= n
                
            elif i[0] == 'E' and y + j < len(park[0]) and park[x][y + j] != 'X':
                if j == n: y += n
                    
            else: break
                
    return [x, y]