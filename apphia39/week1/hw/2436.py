"""
    공약수
    gcd, lcm이 주어졌을 때, 두 수를 구하여라
    gcd, a_prime, b, lcm
    1, a_prime' = a_prime//gcd, b' = b//gcd, x = lcm//gcd
    a_prime * b = gcd * lcm
    
    a_prime' * b' = x * 1
"""

def ucl(a_prime, b):
    if a_prime < b:
        a_prime, b = b, a_prime
    
    if a_prime % b == 0:
        return b
    else:
        return ucl(b, a_prime%b)

import sys
import math
input = sys.stdin.readline

gcd, lcm = map(int, input().split())
x = lcm // gcd

for i in range(int(math.sqrt(x)), 0, -1):
    # a' * b' = x
    a_prime, b_prime = i, x//i 
    if a_prime * b_prime != x: 
        continue
    
    if ucl(a_prime, b_prime) == 1: # a'와 b'는 서로소 (둘의 공약수는 1만 존재)
        print(a_prime * gcd, b_prime * gcd)
        break