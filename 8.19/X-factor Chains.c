#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef long long ll;

int su[1025];  // 存储素数
bool he[1025]; // 标记是否为素数
ll t[1025];    // 存储每个素数的出现次数
int cnt = 0;   // 素数的个数
ll sum = 0;    // X的因子数

void Euler(int n)
{ // 欧拉筛法求素数
    for (int i = 2; i <= n; i++)
    {
        if (he[i] == 0)
        {
            cnt++;
            su[cnt] = i;
        }
        for (int j = 1; j <= cnt && i * su[j] <= n; j++)
        {
            he[su[j] * i] = 1;
            if (i % su[j] == 0)
                break;
        }
    }
    return;
}

void fen(ll x)
{ // 分解质因数
    for (int i = 1; i <= cnt && su[i] * su[i] <= x; i++)
    {
        ll p = su[i];
        if (x % p == 0)
        {
            while (x % p == 0)
            {
                sum++;
                t[i]++;
                x /= p;
            }
        }
    }
    if (x > 1)
        sum++;
    return;
}

ll jie(int k)
{ // 求阶乘
    ll ans = 1;
    for (int i = 2; i <= k; i++)
    {
        ans *= i;
    }
    return ans;
}

int main()
{
    Euler(1024); // 预处理素数
    ll x;
    while (scanf("%lld", &x) != EOF)
    {
        if (x == 0)
            break;
        memset(t, 0, sizeof(t)); // 初始化
        sum = 0;
        fen(x); // 分解质因数
        printf("%lld ", sum);
        ll ans = jie(sum);
        for (int i = 1; i <= cnt; i++)
        {
            ans /= jie(t[i]); // 求解排列数
        }
        printf("%lld\n", ans);
    }
    return 0;
}