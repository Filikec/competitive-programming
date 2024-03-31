import random
cp = lambda x, y: x if len(x) < len(y) else y
a=input();b=input()
n=len(a);m=len(b)

D=[['s'*2002]*(m+1) for _ in range(n+1)]
D[0][0]=''
for i in range(n):
    D[i+1][0]=D[i][0]+a[i]
    for j in range(m):
        D[0][j+1]=D[0][j]+b[j]
        D[i+1][j+1]=cp(D[i][j+1]+a[i],cp(D[i+1][j+1],D[i+1][j]+b[j]))
        if a[i]==b[j]: D[i+1][j+1]=cp(D[i+1][j+1],D[i][j]+a[i])

for i in range(n):
    for j in range(m):
        D[i][j] += chr(random.randint(0,23))
print(D[-1][-1])
