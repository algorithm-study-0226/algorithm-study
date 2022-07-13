"""
근처에 보이는 숫자 N개를 종이에 적는다.
종이에 적은 수를 M으로 나누었을 때, 나머지가 모두 같게 되는 M을 모두 찾으려고 한다
M은 1보다 커야 한다.

N개의 수가 주어졌을 때, 가능한 M을 모두 찾는 프로그램

M을 공백으로 구분하여 모두 출력한다. 이때, M은 증가하는 순서이어야 한다.

"""

n = int(input())
numbers = sorted([int(input()) for _ in range(n)])
re_num = []

for i in range(1, n):
    re_num.append(numbers[i] - numbers[i - 1])

# 최대 공약수 찾기
def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)


g = re_num[0]
for idx in range(1, len(re_num)):
    g = gcd(g, re_num[idx])

result = set()
for i in range(2, int(g**0.5) + 1):
    if g % i == 0:
        result.add(i)
        result.add(g // i)

result.add(g)
print(*sorted(list(result)))
