import sys

while True:
    start_line = sys.stdin.readline().split()
    if start_line:
        N = int(start_line[0])
        costs = []
        for i in range(N):
            costs.append(int(sys.stdin.readline().split()[0]))
        min_cost = (float('inf'))
        for i in range(len(costs)):
            curr_cost = costs[i] + costs[(i-2)%N]
            if curr_cost < min_cost:
                min_cost = curr_cost
        print(min_cost)
    else:
        break