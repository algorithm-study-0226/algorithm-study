/**
 * @file 15649.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/15649
 * @version 0.1
 * @date 2022-07-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

int N;

int is_duplicated(int *array, int size) {
    int i, j;
    int pivot;

    for (i = 0; i < size; i++) {
        pivot = array[i];
        for (j = 0; j < size; j++) {
            if (i == j)
                continue;
            if (pivot == array[j])
                return (-1);
        }
    }

    return (1);
}

void print_array(int *array, int size) {
    int i;

    for (i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d\n", array[i]);
        else
            printf("%d ", array[i]);
    }
}

void pick(int *array, int *picked, int topick, int start, int size) {
    if (topick == 0) {
        if (is_duplicated(picked, size) > 0){
            print_array(picked, size);
            return;
        }
        else
            return;
    }

    int i;

    for (i = start; i <= N; i++) {
        picked[size - topick] = i;
        pick(array, picked, topick - 1, 1, size);
    }
}

void solve(int M) {
    int array[8];
    int picked[8];
    
    pick(array, picked, M, 1, M);
}

int main(void) {
    int M;

    scanf("%d %d", &N, &M);
    solve(M);

    return (0);
}