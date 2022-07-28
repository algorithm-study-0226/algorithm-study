/**
 * @file 23564.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/23564
 * @version 0.1
 * @date 2022-07-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int size;

int get_string_size(char *s) {
    int i;

    i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return (i);
}

void print_answer(char *s, int *a, int size) {
    int i;

    for (i = 0; i <= size; i++) {
        if (i == size)
            printf("%c\n", s[i]);
        else
            printf("%c", s[i]);
    }

    for (i = 0; i <= size; i++) {
        if (i == size)
            printf("%d", a[i]);
        else
            printf("%d ", a[i]);
    }
}

void solve(char *str, char *s, int *a) {
    int order;
    int idx;
    int step;
    int count;

    idx = 0;
    step = 0;
    order = 0;
    count = 0;
    s[order] = str[0];
    while (1) {
        if (idx >= size)
            break;
        if (str[idx] != s[order]) {
            step = idx;
            a[order] = count;
            order++;
            s[order] = str[idx];
            count = 0;
            continue;
        }
        else {
            count++;
        }
        idx += step + 1;
    }
    a[order] = count;
    print_answer(s, a, order);
}

int main(void) {
    char *str = (char *)malloc(sizeof(char) * 1048576);
    char *s = (char *)malloc(sizeof(char) * 1048576);
    int *a = (int *)malloc(sizeof(int) * 1048576);

    scanf("%s", str);
    size = get_string_size(str);
    solve(str, s, a);

    return (0);
}