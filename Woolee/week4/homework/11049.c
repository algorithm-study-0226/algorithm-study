/**
 * @file 11049.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/11049
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int M[501][2];
int N;

int min(int a, int b) {
    if (a > b)
        return (b);
    else
        return (a);
}

void solve() {
    int dp[501][501];
    int i, j;

    for (i = 1; i < N; i++) {
        dp[i-1][i] = M[i-1][0] * M[i-1][1] * M[i][1];
    }

    // dp[i][j] = min(dp[i][j-1] + M[i][0]*M[j-1][1]*M[j][1], dp[i+1][j] + M[i][0] * M[i+i][0] * M[j][1])
    // 3
    // 5 3
    // 3 2
    // 2 6
    // dp[1][3] = min(dp[1][2] + M[1][0] * M[2][1] * M[3][1], dp[2][3] + M[1][0] * M[2][0] * M[3][1])
    
    for (i = 2; i <= N - 1; i++) {
        for (j = i; j < N; j++) {
            dp[j-i][j] = min(dp[j-i][j-i+1] + M[j-i][0] * M[j-1][1] * M[j][1], 
                             dp[j-i+1][j] + M[j-i][0] * M[j-i+1][0] * M[j][1]);
        }
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }

    printf("%d", dp[0][N-1]);
}

int main(void) {
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d %d", &M[i][0], &M[i][1]);

    solve();
}