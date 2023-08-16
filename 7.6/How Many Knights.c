#include <stdio.h>

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int cal(int m,int n)
{
    if (n < m)
    {
        swap(&m, &n);
    }

    if (m == 1)
    {
        return n;
    }
    else if (m == 2)
    {
            return (n/4)*4 + (n%4>=2 ? 4:n%4*2);
    }
    else
    {
            return (m * n + 1) / 2;
    }
}

int main()
{
    int m, n;
    while (scanf("%d%d", &m, &n) != EOF && (m || n))
    {
            printf("%d knights may be placed on a %d row %d column board.\n",cal(m,n),m,n);
    }
    return 0;
}