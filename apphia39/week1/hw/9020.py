""" 
    * 골드바흐의 추측 *
    1과 자기자신을 제외한 약수가 없는 경우 == 소수
    골드바흐의 추츨: 2보다 큰 모든 짝수는 두 소수의 합이다
    차이가 가장 큰 경우에는 두 차이가 가장 작은 것을 출력
"""

# 에라토스테네스의 체
MAX_N = 10000
eratos = [1 for _ in range(MAX_N+1)]
eratos[0] = 0
eratos[1] = 0

for i in range(2, MAX_N+1):
    if not eratos[i]: # 이미 누군가의 배수로 지워진 애
        continue
    
    for j in range(i, MAX_N+1, i):
        if j == i: # 자기자신은 지우지 않음
            continue
        if j % i == 0: # 누군가의 배수는 지우기
            eratos[j] = 0

# 골드바흐
def goldbach(num):
    a, b = 0, num
    min_diff = abs(b - a)
    
    for i in range(2, num):
        if eratos[i] and eratos[num-i]:
            if abs(num - i - i) < min_diff:
                a, b = i, num-i
                min_diff = abs(b-a)
            
    return a, b

# 입출력
import sys
input = sys.stdin.readline
t = int(input())

for _ in range(t):
    # 한 줄씩 입력받기
    num = int(input())
    
    # 골드바흐 파티션 구하기
    a, b = goldbach(num) 
    
    # 더 작은 수가 먼저 출력되도록 한다
    if a > b:
        a, b = b, a
    print(a, b)