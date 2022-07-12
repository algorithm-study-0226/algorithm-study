# 에라토스테네스의 체

import sys
input = sys.stdin.readline
n, k = map(int, input().split())

c = [1 for _ in range(n+1)]

for i in range(2, n+1):
    for j in range(i, n+1, i): # 배수를 지운다(자기 자신도 지운다)
        if c[j]: # 배수인데 1이라고 세팅된 경우 
            c[j] = 0 # 소수라고 바꿔준다
            k -= 1 # 카운트를 하나 빼준다
            
            if not k: # 카운트가 끝나면 결과를 출력
                print(j)
                break