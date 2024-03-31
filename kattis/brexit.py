from collections import deque

C, P, X, L = map(int, input().split())

graph = [[] for _ in range(C+1)]
thresh = [0]*(C+1)

for i in range(P):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    thresh[a]+=1
    thresh[b]+=1

left = [0]*(C+1)
explored = set([L])
queue = deque()
queue.append(L)

while len(queue) > 0:
    curr = queue.popleft()
    for i in graph[curr]:
        if i not in explored:
            left[i]+=1
            if 2*left[i] >= thresh[i]:
                explored.add(i)
                queue.append(i)
            
if X in explored:
    print('leave')
else:
    print('stay')