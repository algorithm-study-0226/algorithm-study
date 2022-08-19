/**
 * @file 15486.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/15486
 * @version 0.1
 * @date 2022-08-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int T[1500002];
int P[1500002];
int dp[1500002];
int size;

void solve() {
    int i;
    if (T[size - 1] == 1)
        dp[size - 1] = P[size - 1];
    else
        dp[size - 1] = 0;

    for (i = size - 2; i >= 0; i--) {
        if (i + T[i] > size) {
            dp[i] = dp[i + 1];
        }
        else if (dp[i + 1] <= P[i] + dp[i + T[i]]) {
            dp[i] = P[i] + dp[i + T[i]];
        }
        else {
            dp[i] = dp[i + 1];
        }
    }
    printf("%d", dp[0]);
}

int main(void) {
    int i;

    scanf("%d", &size);
    for (i = 0; i < size; i++) 
        scanf("%d %d", &T[i], &P[i]);
    for (i = 0; i < size; i++)
        dp[i] = 0;
    solve();

    return (0);
}