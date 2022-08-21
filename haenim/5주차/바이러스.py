# n = int(input())
# e = int(input())

# m = [[0 for _ in range(n)] for _ in range(n)]

# for i in range(e):
#     start, end = map(int, input().split())
#     start -= 1
#     end -= 1

#     m[start][end] = 1
#     m[end][start] = 1

# # print(m)
# for i in range(len(m)):
#     for j in range(len(m)):
#         print(m[i][j], end="")
#     print()

from collections import deque

n = int(input())
e = int(input())

lst = {}

for i in range(e):
    start, end = map(int, input().split())

    if lst.get(start):
        lst[start].append(end)
    else:
        lst[start] = [end]

    if lst.get(end):
        lst[end].append(start)
    else:
        lst[end] = [start]

dq = deque([1])
visited = [1]

count = 0
while dq:
    n = dq.pop()
    # n = dq.popleft()

    for elem in lst[n]:
        if elem not in visited:
            visited.append(elem)
            dq.append(elem)
            count += 1


print(count)
