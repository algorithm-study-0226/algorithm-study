# 최대공약수, 최소공배수 - 유클리드호제법

import sys
input = sys.stdin.readline

# a * b = gcd * lcm
# lcm = a * b / gcd

def uclide(a, b):
    if b > a:
        a, b = b, a
        
    if a%b == 0:
        return b
    
    return uclide(b, a%b)

a, b = map(int, input().split())
print(uclide(a,b))
print(a * b // uclide(a,b))