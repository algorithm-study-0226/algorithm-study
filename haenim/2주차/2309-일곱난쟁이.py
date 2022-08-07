"""
9명 중에 키의 합이 100이되는 일곱 난쟁이이를 찾아 오름차순으로 출력하는 문제

이 문제를 보고 먼저 떠올랐던 생각은 가능한 모든 조합을 구한 다음에 그 중 합이 100이 되는 걸 찾아서 출력하면 되겠다였다.
좀 더 효율적으로 짤 수 있는 방법을 생각해 봤는데, 조합을 미리 구해놓는 게 아니라 for문으로 조합을 하나씩 구하면서 합이 100이 되면 break하는 방법이 떠올랐다.
근데 9명중에서 7명을 뽑는다는 걸 7중 for문으로 구현하려니까 끔찍해서 우선은 처음 생각한 대로 코드를 작성했고 통과했다.

참고로 두번 째 아이디어에서 조합의 성질에 따라서 9C7 = 9C2니까 사실 2중 for문으로도 구현할 수 있었다.
확실히 모든 조합을 구하지 않고, 중간에 멈추니까 더 빠를 것이라고 생각된다.
근데 아무래도 나올 수 있는 조합의 개수가 매우 적기 때문에 이 문제에서는 유의미한 시간 차이를 주진 않는 것 같다.
"""

from itertools import combinations

heights = [int(input()) for _ in range(9)]

height_combs = combinations(heights, 7)

for height_comb in height_combs:
    height_sum = sum(height_comb)
    if height_sum == 100:
        for height in sorted(height_comb):
            print(height)
        break
