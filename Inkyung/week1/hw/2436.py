# https://www.acmicpc.net/problem/2436
from math import sqrt

A, B = map(int, input().split())


def gcd(a, b):
    return gcd(b % a, a) if b % a else a


a = []
tmp = B // A

for i in range(1, int(sqrt(tmp)) + 1):
    if tmp % i == 0 and gcd(tmp // i, i) == 1:
        a.append((i * A, tmp // i * A))


print(*sorted(a, key=lambda x: x[1] - x[0])[0])
