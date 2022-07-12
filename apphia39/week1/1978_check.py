import sys
input = sys.stdin.readline

# 그냥 소수 문제

n = int(input())
num_list = map(int, input().split())

result = 0
for num in num_list:
    flag = True
    if num >= 2:
        for i in range(2, num):  # 2부터 n-1까지
            if num % i == 0:
                flag = False
                break
        if not flag:
            continue
        
        result += 1
print(result)