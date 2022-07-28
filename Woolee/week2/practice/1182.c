/**
 * @file 1182.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/1182
 * @version 0.1
 * @date 2022-07-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int S;
int N;
int count;

void print_array(int *array, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d\n", array[i]);
        else
            printf("%d ", array[i]);
    }
}

void pick(int *array, int *picked, int topick, int start, int size, int sum)
{
    if (topick == 0) {
        if (sum == S) {
            count++;
            // print_array(picked, size);
            // printf("sum == %d\n", sum);
            return;
        }
        else {
            // print_array(picked, size);
            // printf("sum == %d\n", sum);
            return;
        }
    }

    int i;

    for (i = start; i < N; i++) {
        picked[size - topick] = array[i];
        pick(array, picked, topick - 1, i + 1, size, sum + array[i]);
    }
}

void solve(int *array)
{
    int picked[20];
    int i;

    for (i = 1; i <= N; i++) {
        pick(array, picked, i, 0, i, 0);
    }
}

int main(void) {
    int array[20];
    int i;

    count = 0;
    scanf("%d %d", &N, &S);
    for (i = 0; i < N; i++)
        scanf("%d", &array[i]);
    solve(array);
    printf("%d", count);
    return (0);
}