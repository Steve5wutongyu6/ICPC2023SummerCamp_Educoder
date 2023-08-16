#include <cstdio>
using namespace std;

typedef long long LL;   // 定义 long long 类型为 LL，方便后面使用
LL A, B, C, a, b, c, k; // 定义变量

// 扩展欧几里得算法，求解 ax + by = d 的一组解
void ex_gcd(LL a, LL b, LL &x, LL &y, LL &d)
{
    if (!b)
        x = 1, y = 0, d = a; // 如果 b 为 0，那么 x = 1, y = 0, d = a
    else
    {
        ex_gcd(b, a % b, y, x, d);
        y -= x * (a / b);
    } // 否则递归求解
}

int main()
{
    while (~scanf("%lld%lld%lld%lld", &A, &B, &C, &k), k)
    { // 循环读入 A, B, C, k
        a = C, b = 1LL << k;
        c = (B - A) % b;                                               // 计算 a, b, c
        LL x, y, d;                                                    // 定义变量
        ex_gcd(a, b, x, y, d);                                         // 求解 ax + by = d 的一组解
        if (c % d == 0)                                                // 如果 c % d == 0，那么有解
            printf("%lld\n", (c / d * x % (b / d) + b / d) % (b / d)); // 输出解
        else
            printf("FOREVER\n"); // 否则输出 FOREVER
    }
    return 0;
}