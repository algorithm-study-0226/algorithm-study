"""
d[i] = i일 부터 시작해서 얻을 수 있는 이득
 
탑다운으로

d[i] = 현재 이득 + d[i+그 일자]

"""

n = int(input())
schedules = []

d = [0] * (n + 3)

for i in range(n):
    t, p = map(int, input().split())
    schedules.append((t, p))


for day in range(n, 0, -1):
    time, pay = schedules[day - 1]

    next_day = day + time

    if next_day <= n + 1:
        d[day] = max(d[day + 1], d[next_day] + pay)

    else:
        d[day] = d[day + 1]

print(d[1])

"""
3
1 1
1 2
1 3

11
5 10
5 10
5 200
5 10
5 10
5 10
5 10
5 10
5 10
5 10
5 10

9
5 2
5 1
5 1
5 1
5 1
5 1
5 1
5 1
5 1

5
4 10
2 9
2 3
2 2
3 100

5
3 50
1 1
3 3
2 2 
1 1
"""
