for i in range(100000):
    m = 1
    c = 1
    if (i%2 == 0 or i %5 == 0):
        continue
    while (m%i):
        m = m*10 + 1
        c+= 1
    print(c)