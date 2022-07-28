#include <stdio.h>

int get_smallest(int *array, int size, int remain) {
    int smallest;
    int i;

    smallest = 1000000001;
    for (i = 0; i < size; i++) {
        if (array[i] - remain == 0)
            continue;
        if (smallest > array[i] - remain)
            smallest = array[i] - remain;
    }
    return (smallest);
}

int is_gcd(int *array, int size, int gcd, int remain) {
    int i;

    for (i = 0; i < size; i++) {
        if ((array[i] - remain) % gcd != 0)
            return (-1);
    }
    return(gcd);
}

int get_sqrt(int num) {
    int i;

    for (i = 1; i <= num; i++) {
        if (i * i <= num) {
            if ((i + 1) * (i + 1) > num) {
                return (i);
            }
        }
    }
}

void print_gcd(int gcd) {
    int i, j;
    int array[100];

    i = 0;
    for (j = 2; j <= get_sqrt(gcd); j++) {
        if (gcd % j == 0) {
            array[i] = j;
            i++;
        }
    }

    for (j = 0; j < i; j++)
        printf("%d ", array[j]);

    for (j = i - 1; j >= 0; j--) {
        printf("%d ", gcd / array[j]);
    }
    printf("%d", gcd);
}

void solve(int *array, int size) {
    int smallest;
    int _smallest;
    int i, j;
    int gcd;

    // 가장 작은 값이 나머지 그 자체인 경우
    smallest = get_smallest(array, size, 0);
    gcd = get_smallest(array, size, smallest);
    // 나머지를 뺀 다음 작은 값이 공약수의 최소 배수.
    // 따라서 최대공약수는 다음 작은 값의 약수 중 하나.
    for (i = gcd; i >= 2; i--) {
        if (gcd % i != 0)
            continue;
        else {
            if (is_gcd(array, size, i, smallest) != -1) {
                print_gcd(i);
                return;
            }
        }
    }

    // 그렇지 않으면 큰 값에서 차례로 빼서 최대공약수를 구함.
    for (i = 0; i < smallest; i++) {
        if (is_gcd(array, size, smallest - i, i) != -1) {
            print_gcd((smallest - i));
            break;
        }
    }
    return;
}

int main(void) {
    int n;
    int m[101];
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &m[i]);
    solve(m, n);

    return (0);
}