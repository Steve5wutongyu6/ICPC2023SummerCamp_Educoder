#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int INF = 0x3f3f3f3f;
const int N = 1e5 + 5;

// 定义怪兽的结构体
struct Tuple {
    int a, b; // 怪兽的生命值和防御力
} t[N];

int p[1001], c[1001];
int dp[1001][1001]; // 动态规划数组

bool cmp(Tuple &a, Tuple &b) {
    return a.b < b.b;
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) { // 多组测试数据
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &t[i].a, &t[i].b);
        }
        sort(t + 1, t + n + 1, cmp); // 按照防御力从小到大排序
        for (int i = 1; i <= m; i++) {
            scanf("%d%d", c + i, p + i);
        }
        int l = 1;
        ll ans = 0;
        bool flag = false; // 是否无法击败所有怪兽的标志位
        while (l <= n) { // 每次处理相同防御力的怪兽
            int k = t[l].b; // 当前处理的怪兽的防御力
            int r = l + 1;
            while (r <= n && t[r].b == k) { // 找到相同防御力的怪兽的范围
                r++;
            }
            int maxa = 0; // 当前怪兽范围内生命值的最大值
            for (int i = l; i < r; i++) {
                maxa = max(maxa, t[i].a);
            }
            for (int j = 1; j <= maxa; j++) { // 初始化动态规划数组
                dp[0][j] = INF; // 前0个技能攻击生命值为j的怪兽所需晶石数目为无穷大
            }
            for (int i = 0; i <= m; i++) {
                dp[i][0] = 0; // 前i个技能攻击生命值为0的怪兽所需晶石数目为0
            }
            for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= maxa; j++) {
                    dp[i][j] = dp[i - 1][j]; // 不使用第i个技能攻击生命值为j的怪兽所需晶石数目等于使用前i-1个技能攻击生命值为j的怪兽所需晶石数目
                    if (p[i] - k > 0) { // 如果第i个技能可以攻击当前处理的怪兽
                        dp[i][j] = min(dp[i][j], dp[i][max(j - p[i] + k, 0)] + c[i]); // 使用第i个技能攻击生命值为j的怪兽所需晶石数目等于使用第i个技能攻击生命值为j-p[i]+k的怪兽所需晶石数目加上消耗的晶石数目c[i]
                    }
                }
            }
            for (int i = l; i < r; i++) { // 把当前范围内的所有怪兽都攻击一遍
                if (dp[m][t[i].a] == INF) { // 如果无法将该怪兽击败
                    flag = true;
                    break;
                }
                ans += dp[m][t[i].a]; // 使用m个技能攻击生命值为t[i].a的怪兽所需晶石数目加入答案
            }
            if (flag) { // 如果无法击败所有怪兽，退出循环
                break;
            }
            l = r; // 处理下一个相同防御力的怪兽
        }
        if (flag) {
            printf("-1\n");
        } else {
            printf("%lld\n", ans);
        }
    }
    return 0;
}
