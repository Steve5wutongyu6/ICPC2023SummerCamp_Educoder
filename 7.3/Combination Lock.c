//Combination Lock
// Created by 五桶鱼 on 2023/7/3.

#include <stdio.h>

int main ()
{
    int a = 0, b = 0, c = 0, d = 0;
    while (1)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a == 0 && b == 0 && c == 0 && d == 0)
        {
            break;
        }
        int sum = 0;
        sum = 1080 + (a - b + 40) % 40 * 9 + (c - b + 40) % 40 * 9 + (c - d + 40) % 40 * 9;
        printf("%d\n", sum);
    }
}