#include <stdio.h>
#include <string.h>

int c[27][27] = {0};

void play_table()
{
    int i, j;
    for (i = 0; i <= 26; i++)
    {
        for (j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
                c[i][j] = 1;
            else
                c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
    c[0][0] = 0;
    return;
}

int main()
{
    play_table();
    char str[13];
    while (scanf("%s", str) != EOF)
    {
        int len = strlen(str);
        int i, j;
        for (i = 1; i < len; i++)
        {
            if (str[i - 1] >= str[i])
            {
                printf("0\n");
                break;
            }
        }
        if (i < len)
        {
            continue;
        }
        int sum = 0;
        for (i = 1; i < len; i++)
        {
            sum += c[26][i];
        }
        for (i = 0; i < len; i++)
        {
            char ch;
            if (i == 0)
                ch = 'a';
            else
                ch = str[i - 1] + 1;
            while (ch <= str[i] - 1)
            {
                sum += c['z' - ch][len - i - 1];
                ch++;
            }
        }
        printf("%d\n", sum + 1);
    }
    return 0;
}