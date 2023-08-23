def solution(sizes):
    max_w = 0
    max_h = 0
    for size in sizes:
        i, j = map(int, size)
        w = max(i, j)
        h = min(i, j)
        if w > max_w:
            max_w = w
        if h > max_h:
            max_h = h
    
    return max_w * max_h