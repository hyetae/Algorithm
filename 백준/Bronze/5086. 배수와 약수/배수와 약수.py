while True:
    a, b = map(int, input().split())
    if a == 0 and b == 0 :
        break
    else:
        result = divmod(a, b)
        if result[1] == a:
            print('factor')
        elif result[1] == 0:
            print('multiple')
        else: print('neither')