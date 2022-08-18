/**
 * @file 11049.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/11049
 * @version 0.1
 * @date 2022-08-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#define INF 2100000000

int M[501][2];
int dp[501][501];

int get_min(int a, int b) {
    if (a > b)
        return (b);
    else
        return (a);
}

void solve(int N) {
    int i, j, k;
    int minimum_value;
    int value;

    minimum_value = INF;
    // dp[i][i+1] 은 그냥 곱셈 
    for (i = 1; i < N; i++) {
            dp[i][i+1] = M[i][0] * M[i+1][0] * M[i+1][1];
    }

    // i는 행렬간의 거리
    for (i = 2; i <= N - 1; i++) {
        // j는 시작 지점, j + i 가 N을 넘기면 안됨
        for (j = 1; j + i <= N; j++) {
            for (k = 0; k < i; k++) {
                value = dp[j][j + k] + dp[j + k + 1][j + i] + (M[j][0] * M[j + k][1] * M[j + i][1]);
                minimum_value = get_min(value, minimum_value);
            }
            // 최소값을 구하고 미니멈 값을 dp에 넣어준 뒤 미니멈을 다시 최대로 돌림
            dp[j][j+i] = minimum_value;
            minimum_value = INF;
        }
    }

    printf("%d", dp[1][N]);
}

int main(void) {
    int N;
    int i;

    scanf("%d", &N);
    for (i = 1; i <= N; i++)
        scanf("%d %d", &M[i][0], &M[i][1]);
    solve(N);
    return (0);
}