"""

후위 표기식과 각 피연산자에 대응하는 값들이 주어져 있을 때, 
그 식을 계산하는 프로그램을 작성하시오.

=> 후위 표기식으로 나와있는 식을 계산하는 문제

---

입력

5 #피연산자의 개수

ABC*+DE/- #후위 표기식

# 각 피연산자에 대응하는 값들
1 -> A 
2 -> B
3 -> C
4
5

123*+45/-

---

후위 표기식 계산 방법

- 숫자가 나오면 그냥 스택에 push한다.
- 연산자가 나오면 스택에서 두 수를 pop해서 연산한 후 결과를 다시 push한다.
- 계속 반복한다.

ex) 123*+45/-

1-> [1]
12-> [1,2]
123->[1,2,3]
123* -> 2*3 = 6 -> [1, 6]
123*+ -> 1+6 = 7 -> [7]
123*+4 -> [7,4]
123*+45 -> [7,4,5]
123*+45/ -> 4/5 = 0.8 -> [7, 0.8]
123*+45/- -> 7-0.8 = 6.2 -> [6.2]

"""

import sys
from collections import deque

input = sys.stdin.readline

n = int(input())  # 피연산자의 개수
postfix = input().strip()  # 후위 표기식

numbers = []
for i in range(n):  # 피연산자들
    numbers.append(int(input()))

stack = deque()
for elem in postfix:
    if elem in "*/+-":  # 연산자면

        # 스택에서 두 숫자 pop
        a = stack.pop()
        b = stack.pop()

        # 연산자에 맞게 계산 후 결과를 push
        if elem == "*":
            stack.append(b * a)
        elif elem == "+":
            stack.append(b + a)
        elif elem == "-":
            stack.append(b - a)
        else:
            stack.append(b / a)

    else:  # 피연산자면
        # A의 아스키 코드는 65, B는 66 ...
        # A는 number[0], B는 number[1]... 이기 때문에
        # 각 아스키 코드에서 65를 빼면 인덱스가 나옴
        stack.append(numbers[ord(elem) - 65])  # 스택에 숫자를 push

print(f"{stack.pop():.2f}")  # 소수점 둘 째 짜리까지만 출력
