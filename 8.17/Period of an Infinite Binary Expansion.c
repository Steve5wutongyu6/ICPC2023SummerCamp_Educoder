#include <stdio.h>
#include <stdlib.h>

typedef long long LL;

// 求最大公约数
LL gcd(LL x, LL y)
{
    return (y == 0) ? x : gcd(y, x % y);
}

// 快速乘法
LL mul(LL a, LL b, LL c)
{
    LL res = (a * b - (LL)((long double)a / c * b) * c) % c;
    return res < 0 ? res + c : res;
}

// 快速幂
LL fpow(LL pnt, LL q)
{
    LL res = 1, base = 2;
    for (; pnt; pnt >>= 1, base = mul(base, base, q))
    {
        if (pnt & 1)
        {
            res = mul(res, base, q);
        }
    }
    return res;
}

// 求欧拉函数
void getphi(LL x, LL *phi)
{
    *phi = x;
    LL i;
    for (i = 2; i * i <= x; ++i)
    {
        if (!(x % i))
        {
            *phi = *phi / i * (i - 1);
            while (!(x % i))
            {
                x /= i;
            }
        }
    }
    if (x ^ 1)
    {
        *phi = *phi / x * (x - 1);
    }
}

int main()
{
    LL p, q, ans1, ans2, d, n, i, id, phi;
    id = 0;
    while (~scanf("%lld/%lld", &p, &q))
    {
        ++id;
        d = gcd(p, q);
        p /= d, q /= d;
        ans1 = 1;
        while (!(q & 1))
        {
            ++ans1, q >>= 1;
        }
        if (q == 1)
        {
            ans2 = 0;
        }
        else
        {
            getphi(q, &phi);
            ans2 = 0x7f7f7f7f;
            for (i = 1; i * i <= phi; ++i)
            {
                if (!(phi % i))
                {
                    if (fpow(i, q) == 1)
                    {
                        ans2 = i;
                        break;
                    }
                    if (fpow(phi / i, q) == 1)
                    {
                        ans2 = phi / i;
                    }
                }
            }
        }
        printf("Case #%lld: %lld,%lld\n", id, ans1, ans2);
    }
    return 0;
}