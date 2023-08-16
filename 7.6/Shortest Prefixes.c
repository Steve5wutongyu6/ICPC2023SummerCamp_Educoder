#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char a[1002][25];
int s = 0, t = 0, cb[30001][26], ca[30001];
void insert(char ch[])
{
    int w = 0, l = strlen(ch + 1), p = 1, k;
    while (p <= l)
    {
        ca[w]++;
        k = ch[p] - 'a';
        if (!cb[w][k])
            cb[w][k] = ++s;
        w = cb[w][k];
        p++;
    }
    ca[w]++;
}
void find(char ch[])
{
    int w = 0, l = strlen(ch + 1), p = 1, k;
    while (p <= l)
    {
        if (ca[w] == 1 && w != 0)
            break;
        k = ch[p] - 'a';
        printf("%c", ch[p]);
        w = cb[w][k];
        p++;
    }
}
int main()
{
    while (scanf("%s", a[++t] + 1) != EOF)
        insert(a[t]);
    for (int i = 1; i <= t; i++)
    {
        printf("%s ", a[i] + 1);
        find(a[i]);
        printf("\n");
    }
    return 0;
}
