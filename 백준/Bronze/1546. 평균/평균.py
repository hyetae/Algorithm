N = int(input())

grades = list(map(int, input().split()))
M = max(grades)

lst = []
for i in grades:
    lst.append(i / M * 100)
    
print(sum(lst) / N)