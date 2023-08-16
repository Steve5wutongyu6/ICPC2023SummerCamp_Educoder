#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long long quick_pow(long long base, int index)
{
    long long result = 1;
    while (index)
    {
        if (index & 1)
            result *= base;
        base *= base;
        index >>= 1;
    }
    return result;
}

int main(int argc, char **argv)
{
    long long base = 2, sum;
    int index;
    int num, order;
    int T;
    while (scanf("%d", &T) != EOF)
    {
        while (T--)
        {
            scanf("%d %d", &num, &order);
            sum = quick_pow(base, num - order);
            printf("%lld\n", sum);
        }
    }
    return 0;
}
