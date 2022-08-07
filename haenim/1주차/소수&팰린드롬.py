"""
N보다 크거나 같고, 소수이면서 팰린드롬인 수 중에서, 가장 작은 수를 구하는 프로그램

"""

import sys

input = sys.stdin.readline

n = int(input())

MAX = 2000000
sieves = [True] * MAX
sieves[1] = False

for i in range(2, MAX):
    if sieves[i]:
        for j in range(i * 2, MAX, i):
            if sieves[j]:
                sieves[j] = False

# def is_prime(n):
#     if n < 2:
#         return False

#     for i in range(2, n):
#         if n % i == 0:
#             return False
#     return True


def is_pelindrome(n):
    splited_numbers = list(str(n))
    return splited_numbers == list(reversed(splited_numbers))


def is_prime(n):
    return sieves[n]


while True:
    if is_pelindrome(n):
        if is_prime(n):
            print(n)
            break

    n += 1


"""

79 197
79 -> 97
197 -> 791

324 -> 423
423 -> 324

31 -> 13
101 -> 101



"""
