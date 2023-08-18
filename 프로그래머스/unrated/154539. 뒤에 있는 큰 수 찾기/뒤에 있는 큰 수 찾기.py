from heapq import heappop, heappush

def solution(numbers):
    answer = [-1 for _ in numbers]
    heap = []
    
    for i, num in enumerate(numbers):
        while heap and heap[0][0] < num:
            _, idx = heappop(heap)
            answer[idx] = num
        heappush(heap, (num, i))
    return answer