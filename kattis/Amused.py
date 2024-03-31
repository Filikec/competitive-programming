day = 1

word = input()
enter = {}
came = set()
times = {}


for i in range(20):
    word = input()
    if word == 'CLOSE':
        if day > 1:
            print()
        print("Day",day)

        for i in sorted(times):
            print(i,"$"+str(times[i]/10))
        

        enter = {}
        came = set()
        times = {}
        day += 1
        word = input()

        if word != 'OPEN':
            break

    else:
        line = word.split(" ")
        action,name,time = line[0],line[1], int(line[2])
        
        if action == 'ENTER':
            enter[name] = time
        else:
            if (name in came) == False:
                times[name] = 0
                came.add(name)

            times[name] += time - enter[name]
