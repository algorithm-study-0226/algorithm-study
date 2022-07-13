"""

    소수 & 팰린드롬
    N보다 크거나 같고, 소수이면서 팰린드롬인 수 중 가장 작은 수 구하기
    
"""

MAX_N = 2000000
eratos = [1 for _ in range(MAX_N+1)]
eratos[0] = 0
eratos[1] = 0
for i in range(2, MAX_N+1):
    if eratos[i] == 0: # 이미 누군가의 배수
        continue
    for j in range(i, MAX_N+1, i):
        if i == j: # 자기자신은 지우지 않음
            continue 
        if j % i == 0: # 소수가 아니면 지우기
            eratos[j] = 0

def check_palindrome(num):
    num_list = list(str(num))
    for i in range(len(num_list) // 2):
        if num_list[i] != num_list[len(num_list) - i - 1]:
            return False
    return True


import sys
input = sys.stdin.readline

n = int(input())     
for i in range(n, MAX_N+1):
    if eratos[i] and check_palindrome(i):
        print(i)
        break