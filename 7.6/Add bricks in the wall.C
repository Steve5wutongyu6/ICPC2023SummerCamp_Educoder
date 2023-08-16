#include <stdio.h>

int a[9][9];

int print()
{
    int i, j;
    for (i = 0; i < 9; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j)
            {
                printf(" ");
            }
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int t, i, j;
    scanf("%d", &t);
    while (t--)
    {
        for (int i = 0; i < 9; i += 2)
        {
            for (int j = 0; j <= i; j += 2)
            {
                scanf("%d", &a[i][j]);
            }
        }

        for (int i = 8; i > 0; i -= 2)
        {
            for (int j = 1; j < i; j += 2)
            {
                a[i][j] = (a[i - 2][j - 1] - a[i][j - 1] - a[i][j + 1]) / 2;
            }
        }

        for (int i = 1; i < 9; i += 2)
        {
            for (int j = 0; j <= i; j++)
            {
                a[i][j] = a[i + 1][j] + a[i + 1][j + 1];
            }
        }
        print();
    }
    return 0;
}
