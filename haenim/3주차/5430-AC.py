"""
함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다. 
배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

첫째 줄에 테스트 케이스의 개수 T가 주어진다. T는 최대 100이다.
각 테스트 케이스의 첫째 줄에는 수행할 함수 p가 주어진다. p의 길이는 1보다 크거나 같고, 100,000보다 작거나 같다.
다음 줄에는 배열에 들어있는 수의 개수 n이 주어진다. (0 ≤ n ≤ 100,000)
다음 줄에는 [x1,...,xn]과 같은 형태로 배열에 들어있는 정수가 주어진다. (1 ≤ xi ≤ 100)


---
R 연산을 할 때 굳이 리스트를 뒤집지 않아도
다음 번 D연산을 반대편에서 pop하게 되는 거랑 똑같으니 
덱을 써서 양쪽으로 pop하면 되겠다고 생각했음

예를 들어서 
[1,2,3,4] 에
RDD 연산을 한다고 하면

[4,3,2,1] 로 뒤집고
[2,1] 이렇게 앞에서 두개를 pop한 결과나

[1,2,3,4] 에서 뒤집어졌다고 치고 뒤쪽부터 2개를 pop하면
[1,2] 이렇게 되는데, 여기서 최종 방향에 따라서
[2,1] 로 바꿔주는 거나 똑같음 (여기선 한번만 뒤집었기 때문에 최종 방향이 뒤집힌 방향이니 뒤집어줌)

"""

from collections import deque

T = int(input())

for i in range(T):
    try:
        p = input()  # 연산들
        n = int(input())  # 리스트 개수
        lst = input().strip("[]")  # 리스트

        dq = deque()

        if lst != "":
            dq.extend(lst.split(","))

        # 연산 방향 (리스트가 뒤집어졌는 지 여부)
        # False면 앞에서 부터, True면 뒤에서 부터 pop
        reversed = False
        for command in p:
            if command == "R":  # 뒤집으라는 명령이면 연산을 먹일 방향을 반대로
                reversed = not reversed

            else:
                if reversed:  # 뒤집어져있으면
                    dq.pop()  # 뒤에서 부터 pop
                else:  # 아니면
                    dq.popleft()  # 앞에서 부터 pop

        if reversed:  # 최종적으로 뒤집어진 방향이면
            dq.reverse()  # 한번 뒤집어줌

        print("[" + ",".join((dq)) + "]")
    except:
        print("error")
