# https://www.acmicpc.net/problem/9020

from math import sqrt


def p(n):
    if n <= 1:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if not (n % i):
            return False
    return True


def g(n):
    # 우선 반절
    if n // 2:
        one = two = int(n / 2)
    else:
        one = int(n / 2)
        two = n - one

    while one > 1 and two > 1:
        if p(one) and p(two):
            return one, two
        one -= 1
        two += 1
    return one, two


if __name__ == "__main__":
    T = int(input())

    case = []
    for _ in range(T):
        t = int(input())
        case.append(t)

    for c in case:
        a, b = g(c)
        print(a, b)
