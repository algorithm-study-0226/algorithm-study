from collections import deque


def solution(n, edge):
    graph = [[] for _ in range(n + 1)]
    visited = [0] * (n + 1)
    depth = [0] * (n + 1)
    queue = deque()
    
    for e in edge:
        a, b = e
        graph[b].append(a)
        graph[a].append(b)
        
    # bfs
    queue.append(1)
    depth[1] = 1
    while True:
        if len(queue) == 0:
            break
        v = queue.popleft()
        if visited[v] != 0:
            continue
        else:
            visited[v] = 1
            for vertex in graph[v]:
                if visited[vertex] == 0:
                    if depth[vertex] == 0:
                        depth[vertex] = depth[v] + 1
                    queue.append(vertex)
    print(visited)
    print(depth)
    answer = depth.count(max(depth))
    return answer