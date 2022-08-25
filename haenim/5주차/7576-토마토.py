"""
토마토들이 며칠이 지나면 다 익게 되는지, 그 최소 일수

정수 1은 익은 토마토, 정수 0은 익지 않은 토마토, 정수 -1은 토마토가 들어있지 않은 칸

모든 토마토가 익어있는 상태이면 0을 출력해야 하고, 토마토가 모두 익지는 못하는 상황이면 -1

---

6 4 -> 열 개수, 행 개수

# 1: 익은 토마토, -1: 토마토 없음, 0:안익은 토마토
1 -1 0 0 0 0 
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

뭔가 상하좌우로 탐색해서 최소를 구해야 함 -> bfs 
토마토 위치 부터 시작해서 더이상 익힐 토마토가 없을 때 까지 bfs를 쭉 해보면 되겠다

"""

from collections import deque
import sys

input = sys.stdin.readline

width, height = map(int, input().split())

tomatos = []

dq = deque()

# 안익은 토마토 개수
# 처음에 주어진 안익은 토마토 개수 탐색을 끝낸 후 익힌 토마토 개수가 같으면
# 모든 토마토를 익힐 수 있는 상황이니까 그 때 까지 걸린 일수를 출력
# 그게 아니라면 -1을 출력하기 위해
unripe_tomatos = 0
for i in range(height):

    numbers = []
    for j, number in enumerate(input().split()):
        number = int(number)
        numbers.append(number)

        # 익은 토마토면
        if number == 1:
            # 익은 토마토 위치부터 bfs로 탐색해야되니까 그위치를 큐에 넣음
            dq.append((i, j, 0))  # (익은 토마토의 행, 익은 토마토의 열, 현재 탐색 일수)

        # 안 익은 토마토면
        if number == 0:
            unripe_tomatos += 1

    tomatos.append(numbers)

# 상하좌우로 움직이기 위해
_dr = [0, 1, 0, -1]
_dc = [1, 0, -1, 0]

# 방문 정보를 저장
# 리스트로 하면 시간초과남(O(n)), dict로 찾는 게 훨씬 빠름 (O(1))
visited = {}

# 탐색을 통해 익혀진 토마토 개수
riped_tomatos = 0
# 최소 일 수
min_days = 0

while dq:
    r, c, days = dq.popleft()  # 행, 열, 현재 일 수

    for dr, dc in zip(_dr, _dc):  # 상하좌우로 움직여봄
        nr = r + dr
        nc = c + dc

        # 다음 좌표가 범위를 벗어나면 신경안씀
        if nr < 0 or nc < 0 or nr >= height or nc >= width:
            continue

        # 다음 좌표의 토마토가 익지 않았고 탐색되지 않은 토마토면
        if tomatos[nr][nc] == 0 and (nr, nc) not in visited:
            # 익혀진 토마토 개수 1증가
            riped_tomatos += 1

            # 방문 정보 저장
            visited[(nr, nc)] = 1

            # 다음 좌표와 현재 일 수를 +1해서 큐에 저장
            dq.append((nr, nc, days + 1))

    # 큐가 빌 때 마지막에 나온 days가 최소 일 수 일 것
    # 그러니까 min_days값은 days로 계속 갱신해주면 됨
    min_days = days

# 처음에 안익은 토마토 개수가 탐색으로 익혀진 토마토 개수와 같으면 min_days 출력
if unripe_tomatos == riped_tomatos:
    print(min_days)

# 아니면 다 익히지 못한다는 거니까 -1 출력
else:
    print(-1)


"""
다른 사람의 풀이
=> 나는 days를 큐에다 계속 저장해줬는데 아래처럼하면 더 깔끔함

1 -1 0 0 0 0 
0 -1 0 0 0 0
0 0 0 0 -1 0
0 0 0 0 -1 1

1일 후
1 -1 0 0 0 0 
2 -1 0 0 0 0
0 0 0 0 -1 2
0 0 0 0 -1 1

2일 후
1 -1 0 0 0 0 
2 -1 0 0 0 3
3 0 0 0 -1 2
0 0 0 0 -1 1

3일 후
1 -1 0 0 0 4 
2 -1 0 0 4 3
3 4 0 0 -1 2
4 0 0 0 -1 1

.
.
.

6일 후
1  -1  7  6   5  4 
2  -1  6  5   4  3
3   4  5  6  -1  2
4   5  6  7  -1  1

이 행렬을 톨면서 0이 하나라도 있으면 -1 출력
아니라면 '최댓값 -1'이 최소일수가 됨

"""
