t = int(input())

for _ in range(t):
    n = int(input())
    a = input().split(' ')
    prev = "0"
    f = False
    for x in a:
        if len(x) > 1 and x[0] <= x[1] and int(prev) <= int(x[0]):
                x = x[1]
        elif int(prev) > int(x):
             print('NO')
             f = True
             break
        prev = x
    if (not f):
         print("YES")
