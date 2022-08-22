import sys
from collections import deque

"""_summary_
재귀를 활용한 dfs
"""
"""
sys.setrecursionlimit
n, m, r = map(int, sys.stdin.readline().split(' '))
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)
count = 1

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)

def dfs(v):
    global count
    visited[v] = count
    count += 1
    graph[v].sort()
    for vertex in graph[v]:
        if visited[vertex] == 0:
            dfs(vertex)
dfs(r)
for i in range(1, n + 1):
    print(visited[i])
"""

n, m, r = map(int, sys.stdin.readline().split(' '))
graph = [[] for _ in range(n + 1)]
visited = [0] * (n + 1)
count = 1

for _ in range(m):
    a, b = map(int, sys.stdin.readline().split(' '))
    graph[a].append(b)
    graph[b].append(a)

# 재귀 없이 스택을 활용
d = deque()
for list in graph:
    list.sort(reverse=True) # 오름차순 방문을 위한 정렬

d.append(r)
while True:
    if len(d) == 0:
        break
    v = d.pop()
    if visited[v] == 0:
        visited[v] = count
        count += 1

    for vertex in graph[v]:
        if visited[vertex] == 0:
            d.append(vertex)

for i in range(1, n + 1):
    print(visited[i])