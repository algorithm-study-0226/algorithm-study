/**
 * @file 1759.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/1759
 * @version 0.1
 * @date 2022-07-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int picked_size;

void sort_array(char *array, int size) {
    int i, j;
    char tmp;

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

void print_array(char *array, int size) {
    int i;
    int count;
    // 최소 한개의 모음과 두개의 자음이 있는지를 여기서 판단
    // 모음의 갯수를 구해서 size에서 빼면 자음의 갯수.
    count = 0;
    for (i = 0; i < size; i++) {
        if (array[i] == 'a' || array[i] == 'e' || array[i] == 'i' || array[i] == 'o' || array[i] == 'u')
            count++;
    }
    if (count <= 0 || size - count <= 1)
        return;

    for (i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%c\n", array[i]);
        else
            printf("%c", array[i]);
    }
}

void pick(char *array, char *picked, int start, int topick, int size) {
    if (topick == 0){
        print_array(picked, picked_size);
        return;
    }

    int i;

    for (i = start; i < size; i++) {
        picked[picked_size - topick] = array[i];
        pick(array, picked, i + 1, topick - 1, size);
    }
}

void solve(char *array, int L, int C) {
    char picked[15];

    pick(array, picked, 0, L, C);
}

int main(void) {
    int L;
    int C;
    int i;
    char array[15];

    scanf("%d %d", &L, &C);
    for (i = 0; i < C; i++) {
        scanf("%s", &array[i]);
    }
    picked_size = L;
    sort_array(array, C);
    // print_array(array, C);
    solve(array, L, C);

    return (0);
}