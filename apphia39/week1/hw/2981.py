"""
    검문
    n개의 숫자를 m으로 나누었을 때 나머지가 모두 같게 되는 m을 모두 찾자! ( m > 1 )
    
    n0 = a0 * m + r
    n1 = a1 * m + r
    n2 = a2 * m + r

    (n1-n0) = m * (a1-a0)
    (n2-n1) = m * (a2-a1)
    (n2-n0) = m * (a2-a0)
    m은 각각의 두 수의 차들에 대한 공약수
    최대공약수 구하고 그 수의 약수들을 구하자!
"""

import math

def get_yaksu(num):
    results = []
    for i in range(1, int(math.sqrt(num)) + 1):
        if num % i == 0:
            results.append(i)
            if i * i != num:
                results.append(num // i)
    return results

def ucl(a, b):
    if a < b:
        a, b = b, a
    
    if a % b == 0:
        return b
    else:
        return ucl(b, a%b)

import sys
input = sys.stdin.readline

n = int(input())
nums = []
for _ in range(n):
    num = int(input())
    nums.append(num)
    

# 두 수의 차들 구하기
diff_list = []
for i in range(len(nums) - 1):
    diff_list.append(abs(nums[i+1] - nums[i]))

# 각 차들 사이의 최대공약수 구하기
gcd = ucl(max(diff_list), min(diff_list))
for i in range(len(diff_list) - 1):
    gcd_prime = ucl(diff_list[i+1], diff_list[i])
    if gcd % gcd_prime == 0 and gcd_prime < gcd:
        gcd = gcd_prime

results = list(set(get_yaksu(gcd)))
results.sort()
for r in results:
    if r > 1:
        print(r, end = " ")