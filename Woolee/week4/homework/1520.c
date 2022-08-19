/**
 * @file 1520.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/1520
 * @version 0.1
 * @date 2022-08-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int map[501][501];
int dp[501][501];
int N, M;

int dfs(int row, int col) {
    if (row == 0 && col == 0) {
        // printf("Goal\n");
        return (1);
    }
    if (dp[row][col] != -1)
        return (dp[row][col]);
    dp[row][col] = 0;
    // dp는 row, col 에서 N-1, M-1까지 도달할 수 있는 방법
    // N-1 M-1에서 이동하면서 오르막길이면 dp 테이블에 1을 입력.

    // 맨 끝점에서 시작했으므로 오르막길이면 이동함.
    // 아래 이동
    if (row + 1 < N)
        if (map[row + 1][col] > map[row][col]){
            // printf("here is %d %d. move down\n", row, col);
            // dfs가 성공해서 결과값이 타고타고 내려오면 그건 길이 있는거
            dp[row][col] += dfs(row + 1, col);
        }
    // 위 이동
    if (row - 1 >= 0)
        if (map[row - 1][col] > map[row][col]) {
            // printf("here is %d %d. move up\n", row, col);
            dp[row][col] += dfs(row - 1, col);
        }
    // 왼쪽 이동
    if (col - 1 >= 0)
        if (map[row][col - 1] > map[row][col]) {
            // printf("here is %d %d. move left\n", row, col);
            dp[row][col] += dfs(row, col - 1);
        }
    // 오른쪽 이동
    if (col + 1 < M)
        if (map[row][col + 1] > map[row][col]) {
            // printf("here is %d %d. move right\n", row, col);
            dp[row][col] += dfs(row, col + 1);
        }

    return (dp[row][col]);

}

int main(void) {
    int i, j;

    scanf("%d %d", &N, &M);
    for(i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            scanf("%d", &map[i][j]);
    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++)
            dp[i][j] = -1;
    }
    dfs(N-1, M-1);
    // for (i = 0; i < N; i++) {
    //     for (j = 0; j < M; j++)
    //         printf("%d ", dp[i][j]);
    //     printf("\n");
    // }

    printf("%d", dp[N-1][M-1]);

    return (0);
}