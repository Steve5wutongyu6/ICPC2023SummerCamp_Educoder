#include <stdio.h>
#include <string.h>

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
    while (scanf("%d%d", &m, &k) != EOF)
    {                                    // 循环读入 m 和 k 的值