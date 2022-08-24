"""
토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수


정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1

6:22 
"""

from collections import deque
import sys

input = sys.stdin.readline

width, height = map(int, input().split())

tomatos = []

dq = deque()

# ripe_tomatos = 0
unripe_tomatos = 0
for i in range(height):
    # tomatos.append(map(int, input().split()))

    numbers = []
    for j, number in enumerate(input().split()):
        number = int(number)
        numbers.append(number)
        if number == 1:
            dq.append((i, j, 0))
            # ripe_tomatos += 1

        if number == 0:
            unripe_tomatos += 1

    tomatos.append(numbers)

_dr = [0, 1, 0, -1]
_dc = [1, 0, -1, 0]

visited = {}

riped_tomatos = 0
min_days = 0

while dq:
    r, c, days = dq.popleft()

    for dr, dc in zip(_dr, _dc):
        nr = r + dr
        nc = c + dc

        if nr < 0 or nc < 0 or nr >= height or nc >= width:
            continue

        if tomatos[nr][nc] == 0 and (nr, nc) not in visited:
            riped_tomatos += 1
            visited[(nr, nc)] = 1
            dq.append((nr, nc, days + 1))

    min_days = days

if unripe_tomatos == riped_tomatos:
    print(min_days)
else:
    print(-1)
