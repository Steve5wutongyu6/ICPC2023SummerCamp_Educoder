#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;
ll n, a[100005], sum[100005], pos[100005];

int main() {
    // 读入数据
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        sum[i] = sum[i - 1] + a[i]; // 计算前缀和
    }
    // 遍历前缀和数组
    for (int i = 1; i <= n; i++) {
        if (sum[i] % n == 0) { // 如果前i个数的和是n的倍数
            printf("%d\n", i); // 输出i
            for (int j = 1; j <= i; j++) printf("%lld\n", a[j]); // 输出前i个数
            break;
        }
        if (pos[sum[i] % n]) { // 如果前i个数的和对n取模的余数已经出现过
            printf("%d\n", i - pos[sum[i] % n]); // 输出i和第一次出现的位置之间的距离
            for (int j = pos[sum[i] % n] + 1; j <= i; j++) printf("%lld\n", a[j]); // 输出第一次出现的位置之后到i的数
            break;
        }
        pos[sum[i] % n] = i; // 标记前i个数的和对n取模的余数出现的位置
    }
    return 0;
}