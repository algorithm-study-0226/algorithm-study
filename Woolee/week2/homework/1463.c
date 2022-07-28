/**
 * @file 1463.c
 * @author woolee (lebind12@naver.com)
 * @brief 
 * https://www.acmicpc.net/problem/1463
 *   1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
 * 2. X가 2로 나누어 떨어지면, 2로 나눈다. 
 * 3. 1을 뺀다.
 * 첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.
 * 첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.
 * @version 0.1
 * @date 2022-07-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int store[1000002];

int select_minium(int a, int b, int c) {
    int smallest;

    smallest = a;
    if (smallest > b)
        smallest = b;
    if (smallest > c)
        smallest = c;
    return (smallest);
}

void reset_array(int *array, int x) {
    int i;

    for (i = 0; i <= x; i++) {
        array[i] = -1;
    }
    array[1] = 0;
    array[2] = 1;
    array[3] = 1;
}

int cal(int x, int input) {
    if (store[x] != -1)
        return store[x];
    
    if (x == input - 100)
        return 100000;
    
    int a, b, c;

    a = 100000;
    b = 100000;
    c = 100000;

    if (x % 3 == 0)
        a = cal(x/3, input / 3);
    if (x % 2 == 0)
        b = cal(x/2, input / 2);
    if (x > 3)
        c = cal(x-1, input);

    store[x] = select_minium(a, b, c) + 1;
    return store[x];
}

int main(void) {
    int x;

    scanf("%d", &x);
    reset_array(store, x);
    printf("%d", cal(x, x));

    return (0);
}