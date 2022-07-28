/**
 * @file 2436.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/2436
 * @version 0.1
 * @date 2022-07-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int euc(int n, int m) {
    int r;

    r = 1;
    while (r) {
        r = n % m;
        n = m;
        m = r;
    }
    return (n);
}

int get_root(int n) {
    int i;

    i = 1;
    while (1) {
        if (i * i <= n && (i+1)*(i+1) > n)
            return (i);
        i++;
    }
}

void solve(int gcd, int lcm) {
    // a * b * gcd = lcm (a와 b는 서로소)
    // lcm / gcd = a * b
    // lcm / gcd 의 약수 중 서로소면서 서로의 차이가 최소인 값을 찾으면 된다.
    int div;
    int a;
    int b;
    int sub;
    int div_root;
    int answer[2];

    div = lcm / gcd;
    sub = 99999999;
    div_root = get_root(div);
    for (a = 1; a <= div_root; a++) {
        b = div / a;
        if (div % a != 0)
            continue;
        if (euc(a, b) != 1)
            continue;
        if (b - a < sub){
            sub = b - a;
            answer[0] = a;
            answer[1] = b; 
        }
    }
    printf("%d %d", answer[0] * gcd, answer[1] * gcd);
}

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b); 
    // A * B = gcd * lcm
    solve(a, b);

    return (0);
}