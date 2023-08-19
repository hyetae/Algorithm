def solution(sequence, k):
    answer = []
    n = len(sequence)
    sm = 0
    end = 0
    length = n
    for start in range(n):
        while sm < k and end < n:
            sm += sequence[end]
            end += 1
            
        if sm == k and end - start - 1 < length:
            answer = [start, end - 1]
            length = end - start - 1
                
        sm -= sequence[start]
        
    return answer