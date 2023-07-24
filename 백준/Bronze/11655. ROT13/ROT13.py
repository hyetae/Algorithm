s = list(input())

for i in s:
    if i.isalpha():
        if 'a' <= i <= 'z':
            i = ord(i) + 13
            if i > ord('z'):
                i -= ord('z') - ord('a') + 1
            print(chr(i), end = '')
        else:
            i = ord(i) + 13
            if i > ord('Z'):
                i -= ord('Z') - ord('A') + 1
            print(chr(i), end = '')
    else:
        print(i, end = '')