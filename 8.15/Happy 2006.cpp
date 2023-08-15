#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int pr[100]; // 存储 m 的质因数
int gcd(int a, int b)
{ // 求 a 和 b 的最大公约数
    if (b)
        return gcd(b, a % b);
    return a;
}

int main()
{
    int m, k;
    while (~scanf("%d%d", &m, &k))
    {                                    // 循环读入 m 和 k 的值
        long long ans = k;               // 初始化答案为 k
        long long up = k * 10LL, dw = 1; // 初始化上下界
        int n = 0, p = 2;                // 初始化质因数个数和质数 p
        while (m > 1)
        { // 分解质因数
            if (p * p > m)
            {                // 如果 p 的平方大于 m，说明 m 是质数
                pr[n++] = m; // 将 m 存入 pr 数组
                break;
            }
            if (m % p == 0)
            {                // 如果 m 能被 p 整除
                pr[n++] = p; // 将 p 存入 pr 数组
                while (m % p == 0)
                    m /= p; // 将 m 中的所有 p 因子除掉
            }
            p++; // p 自增
        }
        while (dw <= up)
        {                         // 二分查找
            ans = (up + dw) >> 1; // 计算中间值
            int nm = (1 << n);    // 计算 2^n
            long long num = 0;    // 初始化 num
            for (int i = 1; i < nm; i++)
            { // 枚举所有的因子
                int f = -1, x = i;
                for (int j = 0; j < n; j++)
                {
                    if (x & 1)
                    {
                        f = pr[j] * f * -1;
                    }
                    x >>= 1;
                }
                num += ans / f; // 计算 ans 中 f 的倍数的个数
            }
            int is = 1;
            for (int i = 0; i < n; i++)
            { // 判断 ans 是否为 m 的因子
                if (ans % pr[i] == 0)
                    is = 0;
            }
            if (ans - num < k)
            { // 如果 ans 中 f 的倍数的个数小于 k，说明答案在右半部分
                dw = ans + 1;
            }
            else if (ans - num > k || (ans - num == k && !is))
            { // 如果 ans 中 f 的倍数的个数大于 k 或者 ans 是 m 的因子，说明答案在左半部分
                up = ans - 1;
            }
            else
            { // 否则输出答案
                printf("%lld\n", ans);
                break;
            }
        }
    }
    return 0;
}