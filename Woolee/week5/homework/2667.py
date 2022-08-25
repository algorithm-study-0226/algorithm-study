from collections import deque
import sys


dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
N = int(sys.stdin.readline())
matrix = [[] for _ in range(N)]
counts = []

for i in range(N):
    line = sys.stdin.readline().strip('\n')
    for j in line:
        matrix[i].append(int(j))
        
def bfs(matrix, a, b):
    n = len(matrix)
    queue = deque()
    queue.append((a, b))
    matrix[a][b] = 0
    count = 1
    
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= n:
                continue
            if matrix[nx][ny] == 1:
                matrix[nx][ny] = 0
                queue.append((nx, ny))
                count += 1
    return count

for i in range(N):
    for j in range(N):
        if matrix[i][j] == 1:
            counts.append(bfs(matrix, i, j))

counts.sort()
print(len(counts))
for i in range(len(counts)):
    print(counts[i])