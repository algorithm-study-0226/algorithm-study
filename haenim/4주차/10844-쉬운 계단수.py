N = int(input())

dp = [[0 for _ in range(10)] for _ in range(101)]

# 한자릿수의 계단수 개수 초기화 [0,1,1,1,1,1,1,1,1,1]
dp[1] = [0] + [1 for _ in range(1, 10)]

# bottom up
for i in range(2, N + 1):
    for j in range(10):
        last_num_count = dp[i - 1][j]  # j로 끝나는 i-1자리의 계단 수 개수

        if j == 0:  # 끝자리가 0일 때
            dp[i][j + 1] += last_num_count

        elif j == 9:  # 끝자리가 9일 때
            dp[i][j - 1] += last_num_count

        else:
            dp[i][j - 1] += last_num_count
            dp[i][j + 1] += last_num_count

answer = 0
for i in dp[N]:
    answer += i

print(answer % 1000000000)
