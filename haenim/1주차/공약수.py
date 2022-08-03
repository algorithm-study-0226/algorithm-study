"""
공약수 

두 개의 자연수가 주어졌을 때, 
이 두 수를 최대공약수와 최소공배수로 하는 두 개의 자연수를 구하는 프로그램을 작성하시오. 
ex) 6 180

두 개의 자연수 쌍이 여러 개 있는 경우에는 두 자연수의 합이 최소가 되는 두 수를 출력한다

----------
g = 최대공약수
l = 최소공배수

A = a * g 
B = b * g 

l = a * b * g (a,b는 서로소)
ex) 2 ㅣ 60 48
    2 | 30 24
    3 | 15 12
      -------
        5  4
    
    => 최대공약수 : 2*2*3
    => 최소공배수: 2*2*3*5*4 (5,4는 서로소, 2*2*3은 최소공배수)

--------

구해야 하는 것 : A, B
=> 우선 a,b를 구하고 각각에 g를 곱하면 됨
=> a,b를 구하자


a,b를 구하기 위해 사용할 수 있는 건 l,g
위 식에서 알 수 있는건 a*b = l/g
서로소인 a와 b를 곱하면 l/g가 되어야 함
=> l/g의 약수 중에 서로소이면서 곱해서 다시 l/g가 되는 두 수를 구하면 됨


서로소인 a,b를 구해야 함
=> 최대공약수가 1이면 됨
=> 유클리드 호제법 사용

--------

1. for문을 돌면서 a*b(즉 l/g)의 약수 두개를 뽑음
2. 서로소아니면 후보에서 탈락
3. 나온 후보들 중 두 값의 차이가 최소인 걸 찾아서 출력


"""

import sys

input = sys.stdin.readline
from math import sqrt

min_sum = 200000000

g, l = map(int, input().split())

divide = l // g  # a*b = l/g

# 유클리드 호제법
def gcd(a, b):
    if a % b == 0:
        return b  # 최대공약수

    return gcd(b, a % b)


# 1 2  3 4 6 12

for a in range(1, int(sqrt(divide)) + 1):  # 1부터 divide의 제곱근까지 돌면서
    b = int(divide / a)  # b = (l/g)/a

    if divide % a == 0 and gcd(a, b) == 1:  # 약수고 서로소면
        if b - a < min_sum:  # 합이 최소면
            min_sum = b - a
            answer = f"{a*g} {b*g}"

print(answer)


# for a in range(int(sqrt(divide)), 0, -1):  # 반대로 돌면서
#     b = int(divide / a)  # b = (l/g)/a

#     if divide % a == 0 and gcd(a, b) == 1:  # 약수고 서로소면
#         print(a * g, b * g)
#         break
