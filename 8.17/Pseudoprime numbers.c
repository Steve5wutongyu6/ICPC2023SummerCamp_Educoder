#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define ll long long

// 快速幂算法
ll QuickPow(ll x, ll N, ll p)
{
    ll res = x;
    ll ans = 1;
    while (N)
    {
        if (N & 1) // 如果N的二进制末位为1
        {
            ans = ans * res % p; // 将ans乘上res并对p取模
        }
        res = res * res % p; // 将res平方并对p取模
        N = N >> 1;          // 将N右移一位
    }
    return ans % p; // 返回ans对p取模的结果
}

// 判断是否为素数
bool prime(ll n)
{
    if (n == 2) // 特判2
        return true;
    for (ll i = 2; i <= sqrt(1.0 * n); i++) // 从2到sqrt(n)枚举i
        if (n % i == 0)                     // 如果n能被i整除
            return false;                   // n不是素数
    return true;                            // n是素数
}

int main()
{
    ll p, a;
    while (scanf("%lld%lld", &p, &a) == 2) // 循环读入p和a
    {
        if (a == 0 && p == 0) // 如果p和a都为0，退出循环
            break;
        if (!prime(p) && a == QuickPow(a, p, p)) // 如果p不是素数且a^p mod p等于a
            printf("yes\n");                     // 输出yes
        else
            printf("no\n"); // 输出no
    }
    return 0;
}
