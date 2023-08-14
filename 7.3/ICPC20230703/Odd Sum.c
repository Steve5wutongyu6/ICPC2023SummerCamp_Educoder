// 求范围内所有奇数之和
// Created by 五桶鱼 on 2023/7/3
#include <stdio.h>

int main()
{
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int a = 0, b = 0;
        scanf("%d\n%d", &a, &b);
        int sum = 0, c = b + 1, d = 0;
        int e = c / 2, f = a / 2;
        sum = e * e - f * f;
        printf("Case %d: %d\n", i + 1, sum);
    }
}
