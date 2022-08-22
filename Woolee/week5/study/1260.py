import sys
from collections import deque


n, m, r = map(int, sys.stdin.readline().split(' '))
graph = [[] for _ in range(n + 1)]
dfs_visited = [0] * (n + 1)
bfs_visited = [0] * (n + 1)
visited_order = []

count = 1
stack = deque()
queue = deque()

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)

stack.append(r)
queue.append(r)
while True:
    if len(stack) == 0:
        break
    v = stack.pop()
    if dfs_visited[v] != 0:
        continue
    else:
        dfs_visited[v] = 1
        visited_order.append(v)
        graph[v].sort(reverse=True)
        for vertex in graph[v]:
            stack.append(vertex)
print(" ".join(map(str, visited_order)))
visited_order = []
while True:
    if len(queue) == 0:
        break
    v = queue.popleft()
    if bfs_visited[v] != 0:
        continue
    else:
        bfs_visited[v] = 1
        visited_order.append(v)
        graph[v].sort()
        for vertex in graph[v]:
            queue.append(vertex)
print(" ".join(map(str, visited_order)))