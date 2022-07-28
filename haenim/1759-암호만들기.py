"""
첫번 째 방법

암호는 최소 한개의 모음과 최소 두개의 자음으로 구성
알파벳이 암호에서 증가하는 순서로 배열(abc o bac x)
가능한 암호의 종류를 모두 출력


1. 가능한 모든 암호 조합을 구함 (주어진 알파벳 중에서 L개를 순서없이 중복없이 뽑음)
    (이 때 sort 후에 comb를 함으로써 결과가 암호 내부에서도, 각 암호끼리도 정렬되도록 함)

2. 각 조합들을 for문으로 돌면서 조건에 맞는 지 판별 후 맞으면 출력

가능한 모든 조합을 구한 다음에 그 조합이 조건에 맞으면 출력하도록 함

입력
4 6
a t c i s w

출력
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw

"""

from itertools import combinations

L, C = map(int, input().split())

alphabets = input().split()

# 길이가 L인 모든 조합, 증가하는 순서로 배열해야되기 때문에 sort 후 comb
alpha_combs = combinations(sorted(alphabets), L)

answer = []

for alpha_comb in alpha_combs:  # 가능한 조합 중에서
    consonant_count = 0
    vowel_count = 0

    # 자음 모음 개수 세기
    for alpha in alpha_comb:
        if alpha in "aeiou":
            consonant_count += 1
        else:
            vowel_count += 1

    # 모음이 1개 이상, 자음이 2 개 이상이면 출력
    if consonant_count >= 1 and vowel_count >= 2:
        print("".join(alpha_comb))


"""
두 번 째 방법 

=> 전체 다 해보는데 조건에 맞지 않으면 빼면 됨
=> 백트래킹

dfs를 이용해 재귀적으로 품

---

1. 주이진 암호 길이가 되면 자음 모음 개수를 세서 조건에 만족하면 출력한다.

2. 주어진 암호 길이보다 작으면 현재 제일 끝에 있는 알파벳보다 
   사전 순으로 더 큰 알파벳을 골라서 추가해서 dfs를 돌린다.

3. 1,2번을 계속 반복한다.

입력
4 6
a t c i s w

출력
acis
acit
aciw
acst
acsw
actw
aist
aisw
aitw
astw
cist
cisw
citw
istw

"""

L, C = map(int, input().split())

alphabets = sorted(input().split())  # sort를 해줘서 암호 끼리 오름차순이 되도록


def dfs(idx, codes):
    if L == idx:
        vowel_count = 0
        consonant_count = 0

        # 자음 모음 개수 세기
        for code in codes:
            if code in "aeiou":
                consonant_count += 1
            else:
                vowel_count += 1

        # 자음 2개 이상, 모음 한개 이상이면 암호가 될 수 있으므로 출력
        if consonant_count >= 1 and vowel_count >= 2:
            print("".join(codes))

    else:
        for i in range(idx, C):
            if codes and alphabets[i] <= codes[-1]:  # 오름차순 아니면 버림
                continue
            dfs(idx + 1, codes + [alphabets[i]])


dfs(0, [])  # 현재 암호 길이, 현재 암호
