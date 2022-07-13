"""
    수열의 합
    합이 N이면서 길이가 적어도 L인 연속된 정수 리스트
"""

import sys
input = sys.stdin.readline

n, l = map(int, input().split())

# x + (x+1) + (x+2) + (x+l-1) = n
# x = (2n - l^2 + l) / 2l

for l_prime in range(l, 101):
    bottom = 2 * l_prime
    top = 2 * n - l_prime * l_prime + l_prime
    
    if top % bottom == 0:
        start = top // bottom
        l = l_prime
        break
    else:
        start = -1
        continue

if start < 0:
    print(-1)
else:
    for i in range(start, start + l):
        print(i, end = " ")