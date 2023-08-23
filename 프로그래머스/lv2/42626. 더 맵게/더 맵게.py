from heapq import heappush, heappop, heapify

def solution(scoville, K):
    heapify(scoville)
        
    cnt = 0
    mix = 0
    while scoville:
        first = heappop(scoville)
        if first >= K:
            return cnt
        sec = heappop(scoville)
        mix = first + (sec * 2)
        heappush(scoville, mix)
        cnt += 1
        
        if len(scoville) == 1 and scoville[0] < K:
            return -1
        
    return cnt