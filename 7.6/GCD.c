#include <stdio.h>

int GCD(int i, int j)
{
    if (j % i == 0)
        return i;
    else
        GCD(j % i, i);
}

int main()
{
    int n, G;
    while ((scanf("%d", &n) == 1) && (n != 0))
    {
        G = 0;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                G += GCD(i, j);
        printf("%d\n", G);
    }
}
