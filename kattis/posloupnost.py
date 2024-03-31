N = []
M = []

for i in range(100001):
    N.append(0)
    if (i<101):
        M.append(0)

n = int(input())

for i in range(n):
    N[int(input())] = 1

m = int(input())

for i in range(m):
    M[int(input())] = 1



for i in range(100001):
    if N[i]:
        print(i)
    if i<101 and M[i]:
        print(i)


