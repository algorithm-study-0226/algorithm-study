/**
 * @file 10844.c
 * @author Woolee (lebind12@naver.com)
 * @brief 
 * @version 0.1
 * @date 2022-08-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#define mod 1000000000

void solve(int N) {
    int array[101][10];
    int answer;
    int i, j;

    answer = 0;
    // array[N][M]은 N자리의 끝자리 숫자가 M인 계단수의 갯수
    for (i = 0; i <= 100; i++) {
        for (j = 0; j < 10; j++) {
            array[i][j] = 0;
        }
    }
    // 첫번째 숫자는 1, 2, 3 ... 9
    for (i = 1; i < 10; i++)
        array[1][i] = 1;
    for (i = 2; i <= N; i++) {
        for (j = 0; j < 10; j++) {
            // 끝 자리 수가 0이면 뒤에 1만 붙을 수 있음
            if (j == 0)
                array[i][j] = array[i - 1][j + 1];
            // 끝 자리 수가 9이면 뒤에 8만 붙을 수 있음
            else if (j == 9)
                array[i][j] = array[i - 1][j - 1];
            // 다른 수들은 앞, 뒤로 하나씩 붙을 수 있음
            else
                array[i][j] = array[i - 1][j - 1] + array[i - 1][j + 1];
            array[i][j] %= mod;
        }
    }
    // for (i = 0; i < 10; i++) {
    //     printf("%lld ", array[N][i]);
    // }
    // printf("\n");

    // 답은 N자리 배열의 총합
    for (i = 0; i < 10; i++) {
        answer = (answer + array[N][i]) % mod;
    }
    printf("%d", answer % mod);
    return;
}

int main(void) {
    int N;

    scanf("%d", &N);
    solve(N);
    return (0);
}