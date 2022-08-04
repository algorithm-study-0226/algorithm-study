/**
 * @file 11866.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/11866
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int answer[1000];
int answer_size;

void print_array(int *array, int size) {
    int i;

    printf("<");
    for (i = 0; i < size; i++) {
        if (i == size - 1)
            printf("%d", array[i]);
        else
            printf("%d, ", array[i]);
    }
    printf(">");
}

void moving(int *array, int *stack, int *count, int max_count, int *array_size)
{
    int i;
    int j;
    int stack_size;

    i = 0;
    j = 0;
    stack_size = 0;
    for (i = 0; i < *array_size; i++) {
        if (*count == max_count) {
            *count = 1;
            answer[answer_size] = array[i];
            answer_size++;
            continue;
        }
        stack[stack_size] = array[i];
        stack_size++;
        *count += 1;
    }
    *array_size = stack_size;
}

void solve(int N, int K) {
    int *array;
    int *stack;
    int count;
    int i;
    int array_size;

    array_size = N;
    answer_size = 0;
    count = 1;
    array = (int *)malloc(sizeof(int) * N);
    // answer = (int *)malloc(sizeof(int) * N);
    stack = (int *)malloc(sizeof(int) * N);
    for (i = 0; i < N; i++) {
        array[i] = i + 1;
    }
    while (array_size > 0) {
        // N명의 사람을 스택에 쌓는데 K 번째는 안 쌓고 answer 배열에 넣음
        moving(array, stack, &count, K, &array_size);
        // N명의 사람을 모두 옮기면 쌓은 스택기준으로 다른 스택에 옮겨 담음.
        free(array);
        array = stack;
        stack = (int *)malloc(sizeof(int) * N);
    }
    // 위의 과정을 array의 크기가 0이 될 때 까지.

    // answer 배열을 마지막에 출력
    print_array(answer, answer_size);
    // deallocation
    free(array);
    free(stack);
}

int main(void) {
    int N, K;

    scanf("%d %d", &N, &K);
    solve(N, K);
    return (0);
}