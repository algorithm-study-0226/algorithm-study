from collections import deque
import sys

sys.setrecursionlimit(10**4)
N = int(sys.stdin.readline())
graph = [[] for _ in range(N + 1)]
visited = [0] * (N + 1)
max_length = 0
far_node = -1
stack = deque()
for _ in range(N - 1):
    a, b, v = map(int, sys.stdin.readline().split(' '))
    graph[a].append((b, v))
    graph[b].append((a, v))
def dfs(e, length):
    global max_length
    global far_node
    visited[e[0]] = 1
    length += e[1]
    if max_length < length:
        max_length = length
        far_node = e[0]
    for vertex in graph[e[0]]:
        if visited[vertex[0]] == 0:
            dfs(vertex, length)
# 임의의 노드 1에서 가장 먼 노드 찾기
visited[1] = 1 
for e in graph[1]:
    dfs(e, 0)
# 1에서 가장 먼 노드에서 에서 가장 먼 노드 찾기
max_length = 0
visited = [0] * (N + 1)
visited[far_node] = 1
for e in graph[far_node]:
    dfs(e, 0)
print(max_length)