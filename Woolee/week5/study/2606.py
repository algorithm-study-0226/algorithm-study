import sys
from collections import deque

N = int(sys.stdin.readline())
M = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)
count = 0
stack = deque()

for _ in range(M):
    a, b = map(int, sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)

# dfs
stack.append(1)
while True:
    if len(stack) == 0:
        break
    v = stack.pop()
    if visited[v] != 0:
        continue
    else:
        visited[v] = 1
        count += 1
        for vertex in graph[v]:
            if visited[vertex] == 0:
                stack.append(vertex)  

print(count - 1)