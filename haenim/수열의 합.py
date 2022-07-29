"""
N과 L이 주어질 때, 

합이 N이면서, 
길이가 적어도 L 
가장 짧은 
연속된 
음이 아닌 정수 리스트를 구하는 프로그램.

N은 1,000,000,000보다 작거나 같은 자연수이고, L은 2보다 크거나 같고, 100보다 작거나 같은

리스트의 길이가 100보다 작거나 같으면, 연속된 수를 첫째 줄에 공백으로 구분하여 출력
길이가 100보다 크거나 그러한 수열이 없을 때는 -1을 출력한다

ex) 18, 2
합이 18이면서 길이가 최소 2인 가장 짧은 양수 리스트 구하기
"""

n, l = map(int, input().split())


def solution():
    for i in range(l, 101):
        start = (n - i * (i - 1) / 2) / i

        if start >= 0 and start.is_integer():
            answer = []
            for j in range(i):
                answer.append(str(int(start + j)))

            return " ".join(answer)

    return -1


print(solution())
