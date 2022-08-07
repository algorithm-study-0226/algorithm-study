"""
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 이제 순서대로 K번째 사람을 제거한다. 한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다. 이 과정은 N명의 사람이 모두 제거될 때까지 계속된다. 원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.



"""

"""
첫번 째 풀이

그냥 리스트에서 pop
"""

n, k = map(int, input().split())

lst = [i for i in range(1, n + 1)]

answer = []
pointer = -1
while True:
    if not lst:
        print("<" + ", ".join(answer) + ">")
        break

    # [1,2,3,4,5,6,7]
    #      ↑
    pointer += k

    # 순환을 위해서 2 % 7 = 2
    # [1,2,3,4,5,6,7]
    #      ↑
    pointer %= n

    answer.append(str(lst.pop(pointer)))

    # [1,2,4,5,6,7]
    #      ↑
    n -= 1  # pop했으니 n을 1 감소

    # [1,2,4,5,6,7]
    #    ↑
    pointer -= 1  # pop했으니 한칸 앞을 가리키도록

"""
두번 째 풀이

pop하지 않고 인덱스만 계산
"""

n, k = map(int, input().split())

lst = [i for i in range(1, n + 1)]

answer = []
pointer = -1
while True:
    if len(answer) == n:
        print("<" + ", ".join(answer) + ">")
        break

    # pop 되지 않은 숫자 중에서 k번 옆으로 이동한 위치 찾기
    # [1,-1,-1,4,5,-1,-1]      [1,-1,-1,4,5,-1,-1]
    #                  ↑   ->             ↑
    count = 0
    while True:
        # k 번 이동 됐으면 그만
        if count == k:
            break

        pointer += 1
        pointer %= n

        # pop된 숫자가 아니면 count를 1증가
        if lst[pointer] != -1:
            count += 1

    # 그 위치 값을 정답에 추가
    answer.append(str(lst[pointer]))

    # 그 위치 값을 진짜 pop하는 대신 pop했다치고 -1로 변경
    lst[pointer] = -1

"""
세번 째 풀이

큐를 이용해서 rotate
"""

from collections import deque

n, k = map(int, input().split())

lst = [i for i in range(1, n + 1)]

q = deque(lst)
answer = []
rotate = k - 1

while q:
    # 왼쪽으로 k-1 만큼 이동
    # [1,2,3,4,5,6,7] -> [3, 4, 5, 6, 7, 1, 2]
    q.rotate(-rotate)

    # 제일 앞에 있는 거 pop
    answer.append(str(q.popleft()))

print("<" + ", ".join(answer) + ">")
