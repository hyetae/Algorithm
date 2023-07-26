n, m = map(int, input().split())

def two(n):
    two = 0
    while n != 0:
        n //= 2
        two += n
    return two
        
def five(n):
    five = 0
    while n != 0:
        n //= 5
        five += n
    return five


print(min(two(n) - two(n - m) - two(m), five(n) - five(n - m) - five(m)))