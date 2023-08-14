#include <stdio.h>
#include <stdlib.h>

#define MAXN 1010

int numbers[MAXN], n, ans;

int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

int abs(int x)
{
    return x > 0 ? x : -x;
}

int main()
{
    while (1)
    {
        n = 0;
        scanf("%d", &numbers[++n]);
        if (numbers[n] == 0)
        {
            break;
        }
        while (numbers[n] != 0)
        {
            scanf("%d", &numbers[++n]);
        }
        n--;
        for (int i = 1; i < n; i++)
        {
            numbers[i] = numbers[i] - numbers[i + 1];
        }
        ans = numbers[1];
        for (int i = 2; i < n; i++)
        {
            ans = gcd(numbers[i] == 0 ? ans : numbers[i], ans);
        }
        printf("%d\n", abs(ans));
    }
    return 0;
}