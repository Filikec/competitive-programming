import sys

for i in sys.stdin:
    ab = i.split()
    a = int(ab[0])
    b = int(ab[1])
    c = int(ab[2])
    print(a*b/c)