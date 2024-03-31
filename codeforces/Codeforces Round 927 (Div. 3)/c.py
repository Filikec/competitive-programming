t = int(input())

for i in range(t):
    n,m = input().split(' ')
    nums = input().split(' ')
    p = 1
    for n in nums:
        p *= int(n)
    s = input()
    for c in s:
        print(p,end=' ')
        if (c == 'L'):
            p /= int(nums.pop(0))
        else:
            p /= int(nums.pop())
    print()


