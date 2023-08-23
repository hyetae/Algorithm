def solution(nums):
    num = len(nums) / 2
    s = set(nums)
    if num > len(s):
        return len(s)
    else:
        return num