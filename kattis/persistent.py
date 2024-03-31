while (True):
    num = int(input())
    if (num == -1):
        break
    digits = list()
    if num == 0:
        print(10)
    elif num == 1:
        print(11)
    else:
        f = True
        while num != 1:
            f = False
            for i in range(9,1,-1):
                if (num%i==0):
                    f = True
                    num = num // i
                    digits.append(i)
                    break
            if (f==False): 
                break
        if (num!=1):
            print("There is no such number.")
        else:
            digits.sort()
            if len(digits) == 1:
                print(1,end="")
            for d in range(len(digits)):
                print(digits[d],end='')
            print()
