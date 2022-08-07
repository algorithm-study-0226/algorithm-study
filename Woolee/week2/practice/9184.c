/**
 * @file 9184.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/9184
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int mem[21][21][21];

int solve(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return (1);
    if (a > 20 || b > 20 || c > 20)
        return solve(20, 20, 20);
    if (mem[a][b][c] != -1)
        return (mem[a][b][c]);
    if (a < b && b < c){
        mem[a][b][c] = solve(a, b, c - 1) + solve (a, b - 1, c - 1) - solve(a, b - 1, c);
        return (mem[a][b][c]);
    }
        
    mem[a][b][c] = solve(a-1, b, c) + solve(a-1, b-1, c) + solve(a-1, b, c-1) - solve(a-1, b-1, c-1);
    return (mem[a][b][c]);
}

int main(void) {
    int a;
    int b;
    int c;
    int i, j, k;

    for (i = 0; i <= 20; i++) {
        for (j = 0; j <= 20; j++) {
            for (k = 0; k <= 20; k++)
                mem[i][j][k] = -1;
        }
    }
    while (1) {
        scanf("%d %d %d", &a, &b, &c);
        if (a == -1 && b == -1 && c == -1)
            break;
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, solve(a, b, c));
    }

    return (0);
}