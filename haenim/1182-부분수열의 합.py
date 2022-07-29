"""
N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 정수의 개수를 나타내는 N과 정수 S가 주어진다. (1 ≤ N ≤ 20, |S| ≤ 1,000,000) 둘째 줄에 N개의 정수가 빈 칸을 사이에 두고 주어진다. 주어지는 정수의 절댓값은 100,000을 넘지 않는다.

입력
5 0
-7 -3 -2 5 8

출력
1

---

암호만들기랑 똑같음

dfs로 백트랙킹

"""

n, s = map(int, input().split())
numbers = list(map(int, input().split()))
count = 0


def dfs(sum, idx):
    global count

    if sum == s and idx:
        count += 1

    for i in range(idx, n):
        dfs(sum + numbers[i], i + 1)


dfs(0, 0)

print(count)
