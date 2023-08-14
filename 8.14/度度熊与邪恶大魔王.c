#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef long long ll;
const int INF = 0x3f3f3f3f; // 定义正无穷
#define N 100005

struct Tuple // 定义结构体Tuple，表示怪兽的生命值和防御力
{
    int a, b;
} t[N];
int p[1001], c[1001]; // 定义数组p和c，表示技能的消耗晶石数目和技能的伤害值
int dp[1001][1001]; // 定义dp数组，表示使用前i种技能攻击生命值为j的怪兽所需要的最小晶石数

// 比较函数，用于排序
int cmp(const void *a, const void *b)
{
    return ((struct Tuple*)a)->b - ((struct Tuple*)b)->b;
}

int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m)) // 多组数据
    {
        for (int i = 1; i <= n; i++) scanf("%d%d", &t[i].a, &t[i].b); // 输入每个怪兽的生命值和防御力
        qsort(t + 1, n, sizeof(struct Tuple), cmp); // 对怪兽按照防御力从小到大排序
        for (int i = 1; i <= m; i++) scanf("%d%d", &c[i], &p[i]); // 输入每种技能的消耗晶石数目和伤害值
        int l = 1; // 定义l表示当前处理的怪兽数组的起始下标
        ll ans = 0; // 定义ans表示最小的晶石消耗数量
        int flag = 0; // 定义flag表示是否存在无法击败的怪兽
        while (l <= n) // 遍历每一组怪兽
        {
            int k = t[l].b; // 当前组怪兽的防御力
            int r = l + 1;
            while (r <= n && t[r].b == k) r++; // 找到所有防御力相同的怪兽
            int maxa = 0;
            for (int i = l; i < r; i++) maxa = max(maxa, t[i].a); // 找到当前组怪兽中生命值最大的
            for (int j = 1; j <= maxa; j++) dp[0][j] = INF; // 初始化dp数组，dp[0][j]表示使用前0种技能攻击生命值为j的怪兽所需要的最小晶石数
            for (int i = 0; i <= m; i++) dp[i][0] = 0; // dp[i][0]表示使用前i种技能攻击生命值为0的怪兽所需要的最小晶石数，显然为0
            for (int i = 1; i <= m; i++)
                for (int j = 1; j <= maxa; j++)
                {
                    dp[i][j] = dp[i - 1][j]; // 不使用第i种技能
                    if (p[i] - k > 0) dp[i][j] = (dp[i][j] < dp[i][max(j - p[i] + k, 0)] + c[i]) ? dp[i][j] : dp[i][max(j - p[i] + k, 0)] + c[i]; // 使用第i种技能
                }
            for (int i = l; i < r; i++)
            {
                if (dp[m][t[i].a] == INF) { flag = 1; break; } // 如果存在无法击败的怪兽，flag设为1
                ans += dp[m][t[i].a]; // 累加晶石消耗数量
            }
            if (flag) break;
            l = r;
        }
        if (flag) printf("-1\n"); // 存在无法击败的怪兽，输出-1
        else printf("%lld\n", ans); // 输出最小的晶石消耗数量
    }
    return 0;
}
