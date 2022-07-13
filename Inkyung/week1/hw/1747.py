# https://www.acmicpc.net/problem/1747

from math import sqrt

N = int(input())


def prime(n):
    if n < 2:
        return False
    for i in range(2, int(sqrt(n)) + 1):
        if not (n % i):
            return False
    return True


def pal(num):
    str_num = list(str(num))  # 몇자리수 숫자인지
    str_num = [i for i in str_num]

    c = len(str_num)
    m = int(c / 2)

    while m <= c:
        left = m
        right = c - m - 1

        if left < 0 or right < 0 or left > c or right > c:
            return True

        if str_num[left] != str_num[right]:
            return False
        m += 1

    return True


answer = N

while True:
    if prime(answer) and pal(answer):
        break
    answer += 1

print(answer)
