t = input()


for i in range(int(t)):
    input()
    n = int(input())
    res  = 0
    while n != 0:
        res += n
        n //= 10
        print(res)
    print(res)