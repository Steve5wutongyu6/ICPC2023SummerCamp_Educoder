#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
const int MAX_N = 55;

#define MAX_N 55
const int MAX_M = 10005;
ll C[MAX_N][MAX_N];

ll init() {
    ll Max = 1;
    for (int i = 1; i < MAX_N; ++i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

ll ans[MAX_N];

ll solve(int k, int s) {
    ll res = 0;
    memset(ans, 0, sizeof(ans));
    int total = 0;
    for (int i = 2; s / i >= k; ++i) {
        ans[i] = C[s / i][k];
        total = i;
    }
    for (int i = total; i >= 2; --i) {
        for (int j = 2; j < i; ++j) {
            if (i % j == 0) ans[j] -= ans[i];
        }
    }
    for (int i = 2; i <= total; ++i) {
        res += ans[i];
    }
    if (res > 10000) res = 10000;
    return res;
}

int main() {
    init();
    int k, s;
    while (~scanf("%d%d", &k, &s)) {
        printf("%lld\n", solve(k, s));
    }
    return 0;
}