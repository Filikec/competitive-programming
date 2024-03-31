import math

n = int(input())

points = []
Sx = Sx2 = Sy = Sy2 = 0

for i in range(n):
    line = input()
    x,y = line.split(" ")
    x = float(x)
    y = float(y)
    points.append((x,y))
    Sx += x
    Sx2 += x*x
    Sy += y
    Sy2 += y*y

best = -1
x = Sx/n
y = Sy/n
sum=0
for p in points:
    sum += math.sqrt((x-p[0])**2 + (y-p[1])**2)
if (best==-1 or best>sum):
    best = sum


print(sum)