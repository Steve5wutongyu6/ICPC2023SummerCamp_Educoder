#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int maxn = 10000;

struct hotel {
    int dist;
    int cost;
} h[maxn];

int com(const void* a, const void* b) {
    const struct hotel* h1 = (const struct hotel*)a;
    const struct hotel* h2 = (const struct hotel*)b;
    
    // 以距离dist为第一关键字，以价格cost为第二关键字排序
    if (h1->dist != h2->dist) {
        return h1->dist - h2->dist;
    } else {
        return h1->cost - h2->cost;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF && n) {
        int i;
        for (i = 0; i < n; ++i) {
            scanf("%d%d", &h[i].dist, &h[i].cost);
        }
        
        // 对数组进行排序
        qsort(h, n, sizeof(struct hotel), com);
        
        int min = INT_MAX;
        int ans = 0;
        for (i = 0; i < n; ++i) {
            if (h[i].cost < min) {
                min = h[i].cost;
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
