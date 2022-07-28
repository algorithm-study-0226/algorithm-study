"""
ababacababa

첫번 째 패턴 (a)
s1은 제일 처음 나온 알파벳(a)
a1은 제일 처음 나온 알파벳이 반복된 횟수(1)

두번 째 패턴 (ababa)
s2는 s1이 a1만큼 반복된 이후의 알파벳(b)
a2는 첫번 째 패턴과 s2를 합친 서브패턴(ab)이 연속으로 몇번 나왔는 지 계산한 횟수(2)

세번 째 패턴 (ababacababa)
s3는 두번째 패턴 후의 알파벳(c)
a2는 두번 째 패턴과 s3를 합친 서브패턴(ababac)이 연속으로 몇번 나왔는 지 계산한 횟수(1)

.
.
.

"""

T = input()
T_length = len(T)

s = [""]
a = [0]


def recursion(n, previous_pattern_length):
    if n == 0:  # 첫 번 째 패턴을 찾을 경우
        s[0] = T[0]

        for i in range(0, T_length):
            if s[0] != T[i]:
                break

            a[0] += 1

        recursion(n + 1, a[0])

    else:
        if previous_pattern_length == T_length:
            return

        a.append(0)
        s.append("")

        # sn 은 이전 패턴 바로 뒤의 알파벳
        s[n] = T[previous_pattern_length]

        # 처음 ~ 이전패턴 바로 뒤의 알파벳
        sub_pattern = T[: previous_pattern_length + 1]
        sub_pattern_length = len(sub_pattern)

        # 서브 패턴이 연속적으로 몇번 나타나는 지 계산 해서 an 구함
        for i in range(0, T_length, sub_pattern_length):
            # 서브 패턴이 더이상 반복되지 않으면 break
            if sub_pattern != T[i : i + sub_pattern_length]:
                break

            a[n] += 1  # 서브 패턴이 반복됐으면 an 1증가

        # 현재 패턴 길이는 이전 패턴 길이 * (an + 1) + an
        # ex) ababa는 1*(2+1) + 2 = 5
        pattern_length = previous_pattern_length * (a[n] + 1) + a[n]

        recursion(n + 1, pattern_length)


recursion(0, 0)

print("".join(s))
print(" ".join(map(str, a)))
