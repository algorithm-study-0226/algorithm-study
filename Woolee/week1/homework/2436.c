/**
 * @file 2436.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/2981
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

void sort_array(int *array, int size) {
    int i, j;
    int tmp;

    for (i = size - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            if (array[j-1] > array[j]) {
                tmp = array[j-1];
                array[j-1] = array[j];
                array[j] = tmp;    
            }
        }
    }
}

int get_root(int value) {
    int i;

    i = 1;
    while (1) {
        if (i * i <= value && (i + 1) * (i + 1) > value)
            return (i);
        i++;
    }
}

void create_array(int *array, int *ret_arr, int size) {
    int i;

    for (i = 1; i < size; i++)
        ret_arr[i-1] = array[i] - array[i-1];
}

int get_minimum(int *array, int size) {
    int i;
    int minimum;

    minimum = 1000000000;
    for (i = 0; i < size; i++) {
        if (minimum > array[i])
            minimum = array[i];
    }

    return (minimum);
}

int is_gcd(int value, int *array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (array[i] % value != 0)
            return (-1);
    }
    return (1);
}

void solve(int *array, int size) {
    int diff_array[100];
    int division_array[100];
    int gcd;
    int count;
    int i;
    int min, max;

    sort_array(array, size);
    // print_array(array, size);
    // array를 이용해서 kn - kn-1의 배열을 생성
    create_array(array, diff_array, size);
    // print_array(diff_array, size - 1);

    count = 1;
    division_array[0] = 1;
    min = get_minimum(diff_array, size - 1);
    for (gcd = 2; gcd <= get_root(min); gcd++) {
        if (is_gcd(gcd, diff_array, size - 1) > 0){
            printf("%d ", gcd);
            division_array[count] = gcd;
            count++;
        }
    }
    for (i = count - 1; i >= 0; i--) {
        if (i == 0)
            printf("%d", min / division_array[i]);
        else if (i == count - 1 && min / division_array[i] == division_array[i])
            continue;
        else
            printf("%d ", min / division_array[i]);
    }
}

int main(void) {
    int N;
    int array[100];
    int i;

    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &array[i]);
    solve(array, N);
}