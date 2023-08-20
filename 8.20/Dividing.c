#include <stdio.h>
#define MAXN 7
#define MAXC 500000

int dp[MAXC];
int num[MAXN];
int n[1000];

int Max(int a, int b) {
    return a > b ? a : b;
}

void init() {
    for (int i = 0; i < MAXN; i++) {
        n[i] = 0;
    }
    for (int j = 0; j < MAXC; j++) {
        dp[j] = 0;
    }
}

int computeSum() {
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        res += num[i] * i;
    }
    return res;
}

int main()
{
    int Case = 1;

    while (scanf("%d%d%d%d%d%d", &num[1], &num[2], &num[3], &num[4], &num[5], &num[6]) != EOF) {
        if (!num[1] && !num[2] && !num[3] && !num[4] && !num[5] && !num[6]) {
            break;
        }
        init();

        int total = computeSum();

        if (total & 1) {
            printf("Collection #%d:\n", Case++);
            printf("Can't be divided.\n\n");
            continue;
        }
        int halfTotal = total / 2;

        int cnt = 1;
        for (int i = 1; i <= 6; i++) {
            int k = 1;
            while (k < num[i]) {
                n[cnt++] = k * i;
                num[i] -= k;
                k *= 2;
            }
            if (num[i]) {
                n[cnt++] = num[i] * i;
            }
        }

        dp[0] = 1;
        for (int i = 1; i < cnt; i++) {
            for (int j = halfTotal; j >= n[i]; j--) {
                dp[j] = dp[j] + dp[j - n[i]];
            }
        }

        if (dp[halfTotal]) {
            printf("Collection #%d:\n", Case++);
            printf("Can be divided.\n\n");
        }
        else {
            printf("Collection #%d:\n", Case++);
            printf("Can't be divided.\n\n");
        }
    }

    return 0;
}