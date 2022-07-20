/*
https://www.acmicpc.net/problem/2309
아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다.
주어지는 키는 100을 넘지 않는 자연수이며
아홉 난쟁이의 키는 모두 다르며
가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.
일곱 난쟁이의 키를 오름차순으로 출력한다.
일곱 난쟁이를 찾을 수 없는 경우는 없다.
*/
#include <stdio.h>

short solve_end = 0;

void swap(int *a, int *b) {
    int tmp;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bubble_sort(int *array, int size) {
    int i, j;

    for (i = size - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            if (array[j] < array[j-1])
                swap(&array[j], &array[j-1]);
        }
    }
}

void print_picked_array(int *picked) {
    int i;

    for (i = 0; i < 7; i++) {
        if (i == 6)
            printf("%d", picked[i]);
        else
            printf("%d\n", picked[i]);
    }
}

void pick(int *array, int *picked, int topick, int sum) {
    int start;
    
    if (solve_end == 1)
        return;
    if (topick == 0) {
        if (sum == 100) {
            solve_end = 1;
            print_picked_array(picked);
            return;
        }
        else
            return;
    }
    for (start = 7 - topick; start < 9; start++) {
        picked[7 - topick] = array[start]; // 뽑은걸 뽑은걸 모아두는 배열에 등록
        pick(array, picked, topick - 1, sum + array[start]); // 나머지에서 다시 뽑음
    }
}

void solve(int *array) {
    int picked[7];
    
    bubble_sort(array, 9);
    pick(array, picked, 7, 0);
}

int main(void) {
    int m[9];
    int i;

    for (i = 0; i < 9; i++)
        scanf("%d", &m[i]);

    solve(m);

    return (0);
}