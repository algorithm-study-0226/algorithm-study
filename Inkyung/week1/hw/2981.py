# https://www.acmicpc.net/problem/2981

import sys
from math import sqrt


def cal(b, s):
    if s > b:
        b, s = s, b
    if b % s == 0:
        return s
    else:
        return cal(s, b % s)


def checkpoint(ns: list):
    # 차를 구함
    tp_list = [ns[idx + 1] - ns[idx] for idx in range(0, len(ns) - 1)]

    gcd = tp_list[0]
    for idx in range(0, len(tp_list)):
        gcd = cal(gcd, tp_list[idx])

    ans_list = set()
    ans_list.add(gcd)
    for i in range(2, int(sqrt(gcd)) + 1):
        if not gcd % i:
            ans_list.add(i)
            ans_list.add(gcd // i)

    return ans_list


if __name__ == "__main__":
    input = sys.stdin.readline
    N = int(input())

    ns = sorted([int(input()) for _ in range(N)])

    print(*sorted(list(checkpoint(ns))))
