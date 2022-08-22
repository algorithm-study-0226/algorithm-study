from collections import deque
import sys


n, m, r = map(int, sys.stdin.readline().split(' '))
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)
queue = deque()
count = 1

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)

# bfs using queue
queue.append(r)
visited[r] = count
count += 1
while True:
    if len(queue) == 0:
        break
    v = queue.popleft()
    graph[v].sort(reverse=True)
    for vertex in graph[v]:
        if visited[vertex] == 0:
            visited[vertex] = count
            count += 1
            queue.append(vertex)

for i in range(1, n + 1):
    print(visited[i])