#include <stdio.h>

int get_number(int input, int digit) {
    int division;
    int i;
    int remain;

    division = 1;
    for (i = 0; i < digit; i++) {
        division *= 10;
    }
    // 나머지 만들기
    remain = input % division;
    // 자리수로 나누기
    remain = remain / (division / 10);

    return (remain);
}

int get_digit(int input) {
    int count;
    int digit;

    count = 1;
    digit = 1;
    while (1) {
        if (input / digit == 0)
            break;
        digit *= 10;
        count++;
    }

    return (count - 1);
}

int is_prime(int input) {
    int i;
    int is_right;
    
    is_right = 0;
    for (i = 2; i <= input; i++) {
        if (input % i == 0) {
            if (input == i) {
                is_right = 1;
                break;
            }
            else {
                is_right = -1;
                break;
            }
        }
    }
    return (is_right);
}

int is_palindrome(int input) {
    int is_right;
    int digit;
    int left;
    int right;
    int i;

    // 일단 값의 자리수를 구함
    digit = get_digit(input);
    i = 0;
    if (digit == 1)
        return (is_right = 1);
    while (1) {
        if (digit % 2 == 1) {
            // 자리수가 홀수면 /2 후 +2자리랑 자기자신 비교
            if (digit/2 + 2 + i > digit) {
                is_right = 1;
                break;
            }
            right = get_number(input, digit/2 - i);
            left = get_number(input, digit/2 + 2 + i);
            if (right != left) {
                is_right = -1;
                break;
            }
        }
        else {
            // 자리수가 짝수면 /2 후 +1자리랑 자기자신 비교
            if (digit/2 + 1 + i > digit) {
                is_right = 1;
                break;
            }
            right = get_number(input, digit/2 - i);
            left = get_number(input, digit/2 + 1 + i);
            if (right != left) {
                is_right = -1;
                break;
            }
        }
        i++;
    }
    return (is_right);
}

int main(void) {
    // num보다 크고 소수이면서 펠린드롬인 수 중 가장 작은 수
    int num;
    int i;
    int answer;

    scanf("%d", &num);
    answer = -1;
    i = num;
    while (1) {
        // 펠린드롬 판별
        if (is_palindrome(i) <= 0) {
            i++;
            continue;
        }
        // 소수판별
        if (is_prime(i) <= 0) {
            i++;
            continue;
        }
        answer = i;
        break;
    }
    printf("%d\n", answer);
    return (0);
}