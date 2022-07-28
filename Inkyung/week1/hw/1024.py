# https://www.acmicpc.net/problem/1024


N, L = map(int, input().split())


def a(n, l):

    if l > 100:
        return [-1]

    result = []
    start = int((2 * n - l * l + l) * (2 * l) ** -1)
    end = start + l - 1

    if start < 0:
        start += abs(start)
        end += abs(start)

    for i in range(start, end + 1):
        result.append(i)

    if sum(result) == n:
        return result

    return a(n, l + 1)


print(*sorted(a(N, L)))
