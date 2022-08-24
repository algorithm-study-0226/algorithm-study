from collections import deque

n = int(input())

m = [list(map(int, list(input()))) for _ in range(n)]

visited = []

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

num_of_blocks = 0
num_of_houses = []


for i in range(n):
    for j in range(n):
        dq = deque()

        if m[i][j] == 1 and (i, j) not in visited:
            visited.append((i, j))
            dq.append((i, j))
            houses = 1

            while dq:
                r, c = dq.pop()
                for _dr, _dc in zip(dr, dc):
                    nr = r + _dr
                    nc = c + _dc

                    if nr >= n or nc >= n or nr < 0 or nc < 0:
                        continue

                    if m[nr][nc] == 1 and (nr, nc) not in visited:
                        visited.append((nr, nc))
                        dq.append((nr, nc))
                        houses += 1

            num_of_blocks += 1
            num_of_houses.append(houses)

print(num_of_blocks)
for house in sorted(num_of_houses):
    print(house)
