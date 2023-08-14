#include <stdio.h>
int ans, n, m;
int dp(int m, int n)
{
    if (m < 0)
        return 0;
    if (m == 0 || n == 1)
        return 1;
    return dp(m - n, n) + dp(m, n - 1);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &m, &n);
        ans = dp(m, n);
        printf("%d\n", ans);
    }
    return 0;
}