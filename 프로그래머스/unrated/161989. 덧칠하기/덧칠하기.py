def solution(n, m, section):
    if m == 1:
        return len(section)
    
    answer = 1
    check = section[0]
    for i in section:
        if i < check + m:
            continue
        else:
            check = i
            answer += 1
        
    return answer