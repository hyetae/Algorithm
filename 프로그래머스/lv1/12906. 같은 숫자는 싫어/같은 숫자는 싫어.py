def solution(arr):
    answer = []
    
    save = -1
    for num in arr:
        if num != save:
            answer.append(num)
        save = num
    return answer