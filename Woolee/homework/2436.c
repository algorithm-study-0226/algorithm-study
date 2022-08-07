#include <stdio.h>

// n > m
int euc(int n, int m) {
    int r;

    r = 1;
    while (r) {
        r = n % m;
        n = m;
        m = r;
    }
    return (n);
}

long long get_sqrt(long long num) {
    long long i;

    for (i = 1; i <= num; i++) {
        if (i * i <= num) {
            if ((i + 1) * (i + 1) > num)
                return (i);
        }
    }
}

void solve(int gcd, int lcm) {
    long long mul;
    long long i;

    mul = gcd * lcm;
    for (i = get_sqrt(mul); i >= 1; i--) {
        if (mul % i == 0) {
            if (euc(mul / i, i) == gcd){
                printf("%lld %lld", i, (mul / i));
                break;
            }
        }
    }
    
}

int main(void) {
    int a, b;

    scanf("%d %d", &a, &b);
    solve(a, b);
    return (0);
}