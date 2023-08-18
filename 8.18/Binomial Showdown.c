#include <stdio.h>

#define LL long long
#define MAXN 1000100

LL Cnm(LL n, LL m) {
    if (m > n / 2)
        m = n - m;
    LL a = 1, b = 1;
    for (int i = 1; i <= m; i++) {
        a *= n + 1 - i;
        b *= i;
        if (a % b == 0) {
            a /= b;
            b = 1;
        }
    }
    return a / b;
}

int main() {
    LL n, m;
    while (scanf("%lld%lld", &n, &m) == 2) {
        if (n == 0 && m == 0)
            break;
        printf("%lld\n", Cnm(n, m));
    }
    return 0;
}