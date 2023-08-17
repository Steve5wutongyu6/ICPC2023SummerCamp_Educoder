// 比较神奇，vjudge里头没有过，到这里AC了，奇怪
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MAXN (100 + 5)

long long ans;
long long X[MAXN];

long long multi(long long x, long long y, long long n)
{
    long long ret = 0;

    while (y)
    {
        if (y & 1LL)
            ret = (ret + x) % n;
        x = (x + x) % n;
        y >>= 1;
    }

    return ret;
}

long long Base(long long x, long long y, long long n)
{
    long long ret = 1LL;

    while (y)
    {
        if (y & 1LL)
            ret = multi(ret, x, n);
        x = multi(x, x, n);
        y >>= 1;
    }

    return ret;
}

bool Miller_Rabin(long long n)
{
    if (n == 2)
        return true;

    long long s = 20, t = 0, u = n - 1;
    while (!(u & 1))
    {
        t++;
        u >>= 1;
    }

    while (s--)
    {
        long long a = rand() % (n - 1) + 1;

        X[0] = Base(a, u, n);
        for (long long i = 1; i <= t; i++)
        {
            X[i] = multi(X[i - 1], X[i - 1], n);
            if (X[i] == 1 && X[i - 1] != 1 && X[i - 1] != (n - 1))
                return false;
        }
        if (X[t] != 1)
            return false;
    }

    return true;
}

long long gcd(long long a, long long b)
{
    return !b ? a : gcd(b, a % b);
}

long long Pollard_Rho(long long n, long long c)
{
    long long i = 1LL, k = 2LL, x = rand() % (n - 1) + 1, y = x;

    while (true)
    {
        i++;
        x = (multi(x, x, n) + c) % n;
        long long p = gcd((y - x + n) % n, n);

        if (p != 1 && p != n)
            return p;
        if (x == y)
            return n;

        if (i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}

void find(long long n, long long c)
{
    if (n == 1)
        return;
    if (Miller_Rabin(n))
    {
        ans = fmin(ans, n);
        return;
    }

    long long p = n, k = c;
    while (p == n)
        p = Pollard_Rho(p, c--);

    find(p, k);
    find(n / p, k);
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--)
    {
        long long n;
        scanf("%lld", &n);

        ans = (1LL << 62);
        find(n, 120);

        if (ans == n)
            printf("Prime\n");
        else
            printf("%lld\n", ans);
    }

    return 0;
}
