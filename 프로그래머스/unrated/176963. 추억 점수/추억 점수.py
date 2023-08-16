def solution(name, yearning, photo):
    answer = []
    dic = {}
    for i in range(len(name)):
        dic[name[i]] = yearning[i]
    
    for i in photo:
        sum = 0
        for j in i:
            try:
                sum += dic[j]
            except: continue
        answer.append(sum)
    return answer