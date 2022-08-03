# https://www.acmicpc.net/problem/1935

"""
### 리스트 받기

1. lst = input().split()
2. lst = map(int, input().split())

# 후위 연산자 계산

숫자를 스택에 쌓아가면서 계산하는데,
연산자를 만나게 된다면 pop_top() 2개 해서 가져온 것들을 연산 후 치환

## 자리수 맞춰 출력
print("%.2f" % 값)

"""

N = int(input())

info = dict()
lst = str(input())
num_lst = [int(input()) for _ in range(N)]
num_idx = 0
new_num_lst = []
for idx, l in enumerate(lst):
    if l.upper() != l.lower():  # A
        if l not in info:
            info[l] = num_lst[num_idx]
            num_idx += 1
        new_num_lst.append(info[l])
    else:
        new_num_lst.append(l)

calc_lst = []
while len(new_num_lst) > 1 or len(calc_lst) > 1:
    one = new_num_lst.pop(0)  # front
    if isinstance(one, int):
        calc_lst.append(one)  # end
    else:
        i, j = calc_lst.pop(), calc_lst.pop()
        if one == "+":
            two = i + j
        elif one == "-":
            two = j - i
        elif one == "/":
            two = float(j / i)
        elif one == "*":
            two = i * j
        calc_lst.append(two)  # end

print("%.2f" % (calc_lst[0]))
