#include <stdio.h>
#include <string.h>

const int N = 50000;
double p[N];

int init()
{
    p[0] = 0.5; // 这一行是新加的
    p[1] = 1;
    for (int i = 1; i < 50000; i++)
    {
        p[i + 1] = p[i] * (2 * i - 1) / (2 * i);
    }
}

int main()
{
    int cas, n;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d", &n);
        double ans = 0.5; // p[0]的值
        for (int i = 1; i < n; i++)
        {
            ans *= (2 * i - 1) / (double)(2 * i); // 计算p[n]的值
        }
        printf("%.4lf\n", );
    }
    return 0;
}