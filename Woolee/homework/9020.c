#include <stdio.h>
// [BOJ] 골드바흐의 추측 

int get_prime(int input) {
    int num;
    int i;

    for (i = 2; i <= input; i++) {
        if (input % i == 0) {
            if (input == i){
                num = input;
                break;
            }
            else {
                num = -1;
                break;
            }
        }
    }

    return num;
}

void solve(int input) {
    int answer1, answer2;
    int found1, found2;
    int field[10000];
    int i, j;
    // 반 갈라서 소수 찾기.
    // ex) input = 8 이면 4/4 해서 4,3,2,1 소수, 4,5,6,7 소수 찾아서 리턴

    found1 = 0;
    found2 = 0;

    for (i = 0; i < input/2; i++) {
        if (get_prime(input/2 - i) != -1) {
            answer1 = input/2 - i;
            found1 = 1;
        }
        if (get_prime(input/2 + i) != -1) {
            answer2 = input/2 + i;
            found2 = 1;
        }

        if (found1 == 1 && found2 == 1)
            break;
        else {
            found1 = 0;
            found2 = 0;
        }
    }

    printf("%d %d\n", answer1, answer2);
}

int main(void) {
    // 골드바흐의 추측 : 2보다 큰 모든 짝수는 두 소수의 합
    int num;
    int input;
    int answer1, answer2;
    int i;

    scanf("%d", &num);
    for (i = 0; i < num; i++) {
        scanf("%d", &input);
        solve(input);
    }

    return (0);
}