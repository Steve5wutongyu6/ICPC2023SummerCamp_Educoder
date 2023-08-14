#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

const int MAX = 50010;

int n, k;

struct node {
    int a;    // 牛的a值
    int b;    // 牛的b值
    int num;  // 牛的编号
} cow[MAX];

// 比较函数，用于按照a从大到小排序，若a相等，则按照b从大到小排序
int cmpa(const void *p, const void *q) {
    const struct node *a = (const struct node *)p;
    const struct node *b = (const struct node *)q;
    
    if (a->a == b->a) {
        return b->b - a->b;
    }
    return b->a - a->a;
}

// 比较函数，用于按照b从大到小排序，若b相等，则按照a从大到小排序
int cmpb(const void *p, const void *q) {
    const struct node *a = (const struct node *)p;
    const struct node *b = (const struct node *)q;
    
    if (a->b == b->b) {
        return b->a - a->a;
    }
    return b->b - a->b;
}

int main() {
    int i;
    while (scanf("%d%d", &n, &k) != EOF) {
        // 输入牛的a和b值，并记录牛的编号
        for (i = 0; i < n; i++) {
            scanf("%d%d", &cow[i].a, &cow[i].b);
            cow[i].num = i + 1;
        }
        
        // 按照cmpa函数定义的规则对cow数组进行排序，排序范围是[0, n)
        qsort(cow, n, sizeof(struct node), cmpa);
        
        // 按照cmpb函数定义的规则对cow数组的前k个元素进行排序，排序范围是[0, k)
        qsort(cow, k, sizeof(struct node), cmpb);
        
        // 输出排序后的第一个牛的编号
        printf("%d\n", cow[0].num);
    }
    return 0;
}
