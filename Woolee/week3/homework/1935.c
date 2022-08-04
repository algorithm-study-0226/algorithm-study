/**
 * @file 1935.c
 * @author Woolee (lebind12@naver.com)
 * @brief https://www.acmicpc.net/problem/1935
 * @version 0.1
 * @date 2022-08-04
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <stdio.h>

double stack[100];
int top;

int isEmpty() {
    if (top == 0)
        return (1);
    else
        return (0);
}

void push(double value) {
    top++;
    stack[top] = value;
}

double pop() {
    double result;

    result = stack[top];
    top--;
    return (result);
}

int isAlpha(char value) {
    if (value >= 'A' && value <= 'Z')
        return (1);
    else
        return 0;
}

void solve(int *num, char *str) {
    int i;
    double a, b;

    i = 0;
    while (str[i] != '\0') {

        if (isAlpha(str[i]) == 1)
            push(num[str[i]-'A']);
        else {
            a = pop();
            b = pop();
            switch (str[i]) {
                case '+':
                    push(a + b);
                    break;
                case '-':
                    push(b - a);
                    break;
                case '*': 
                    push(a * b);
                    break;
                case '/':
                    push(b / a);
                    break;
            }
        }
        i++;
    }
    printf("%.2f", stack[top]);
}

int main(void) {
    int count;
    int num[30];
    char string[101];
    int i;

    scanf("%d", &count);
    scanf("%s", string);
    for (i = 0; i < count; i++)
        scanf("%d", &num[i]);
    top = 0;
    solve(num, string);

    return (0);
}