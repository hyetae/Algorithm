

while True:
    try:
        s = list(input())
        lower, upper, num, space = 0, 0, 0, 0
        
        for j in s:
            if j.isalpha():
                if 'a' <= j <= 'z':
                    lower += 1
                else: upper += 1
            elif j == ' ':
                space += 1
            else: num += 1
        print(f'{lower} {upper} {num} {space}')
    except: break