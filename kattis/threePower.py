n = int(input())
while (n!=0):
    bin = []
    n-=1
    while (n!=0):
        bin.append(n%2)
        n //= 2
    res = ""
    res += "{ "
    for i in range(len(bin)):
        if (bin[i]): res += str(3**i)+", "
    if (len(res) > 2): res = res[:-2]+" "
    res += "}"
    print(res)
    n = int(input())