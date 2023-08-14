#include <stdio.h>
#include <stdlib.h>

struct Jew {
    int w;
    int d;
};

int dp[13000] = { 0 };

int main() {
    //freopen("in.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    struct Jew* jew = (struct Jew*)malloc((N + 1) * sizeof(struct Jew));
    for (int i = 1; i <= N; ++i)
        scanf("%d %d", &jew[i].w, &jew[i].d);

    for (int i = 1; i <= M; ++i)//边界条件
        dp[i] = (jew[1].w <= i) ? jew[1].d : 0;

    for (int i = 2; i <= N; ++i)
        for (int j = M; j >= 1; --j)
            if (j >= jew[i].w)
                dp[j] = (dp[j - jew[i].w] + jew[i].d > dp[j]) ? dp[j - jew[i].w] + jew[i].d : dp[j];

    printf("%d\n", dp[M]);

    free(jew);
    return 0;
}
